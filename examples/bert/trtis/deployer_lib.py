#!/usr/bin/python

# Copyright (c) 2018, NVIDIA CORPORATION. All rights reserved. 
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License. 
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, 
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
# See the License for the specific language governing permissions and
# limitations under the License. 

import os
import sys
import json
import onnx
import torch
import argparse
import onnxruntime
# 


torch_type_to_trtis_type = {
    torch.bool:     'TYPE_BOOL', 
    torch.int8:     'TYPE_INT8', 
    torch.int16:    'TYPE_INT16', 
    torch.int32:    'TYPE_INT32', 
    torch.int64:    'TYPE_INT64', 
    torch.uint8:    'TYPE_UINT8', 
    torch.float16:  'TYPE_FP16', 
    torch.float32:  'TYPE_FP32', 
    torch.float64:  'TYPE_FP64'
}


CONFIG_TEMPLATE = r"""
name: "{model_name}"
platform: "{platform}"
max_batch_size: {max_batch_size}
input [
    {spec_inputs}
]
output [
    {spec_outputs}
]
{dynamic_batching}
instance_group [
    {{
        count: {engine_count}
        kind: KIND_GPU
        gpus: [ 0 ]
    }}
]"""


INPUT_TEMPLATE = r"""
{{
    name: "input__{num}"
    data_type: {type}
    dims: {dims}
    {reshape}
}},"""


OUTPUT_TEMPLATE = r""" 
{{
    name: "output__{num}"
    data_type: {type}
    dims: {dims}
    {reshape}
}},"""


def remove_empty_lines(text):
    ret = "".join([s for s in text.strip().splitlines(True) if s.strip()])
    return ret


def create_deployer(argv):
    parser = argparse.ArgumentParser()
    ## Required parameters
    method = parser.add_mutually_exclusive_group(required=True)
    method.add_argument('--ts-script',
                        action='store_true',
                        help='convert to torchscript using torch.jit.script')
    method.add_argument('--ts-trace',
                        action='store_true',
                        help='convert to torchscript using torch.jit.trace')
    method.add_argument('--onnx',
                        action='store_true',
                        help='convert to onnx using torch.onnx.export')
    # 
    arguments = parser.add_argument_group('trtis related flags')
    arguments.add_argument('--trtis-no-cuda',
                            action='store_true',
                            help='Use the CPU for tracing.')
    arguments.add_argument('--trtis-model-name',
                            type=str,
                            default="model",
                            help="exports to appropriate directory structure for TRTIS")
    arguments.add_argument("--trtis-model-version",
                            type=int,
                            default=1,
                            help="exports to appropriate directory structure for TRTIS")
    arguments.add_argument("--trtis-server-url",
                            type=str,
                            default="localhost:8001",
                            help="exports to appropriate directory structure for TRTIS")
    arguments.add_argument("--trtis-max-batch-size",
                            type=int,
                            default=8,
                            help="Specifies the 'max_batch_size' in the TRTIS model config.\
                                  See the TRTIS documentation for more info.")
    arguments.add_argument("--trtis-dyn-batching-delay",
                            type=float,
                            default=0,
                            help="Determines the dynamic_batching queue delay in milliseconds(ms) for\
                                  the TRTIS model config. Use '0' or '-1' to specify static batching.\
                                  See the TRTIS documentation for more info.")
    arguments.add_argument("--trtis-engine-count",
                            type=int,
                            default=1,
                            help="Specifies the 'instance_group' count value in the TRTIS model config.\
                                  See the TRTIS documentation for more info.")
    arguments.add_argument('--save-dir', type=str, default='./trtis_models', help='Saved model directory')
    arguments.add_argument('model_arguments', nargs=argparse.REMAINDER, help='arguments that will be ignored by deployer lib and will be forwarded to your deployer script')
    # 
    args = parser.parse_args(argv)
    lib = Lib(args)
    deployer = Deployer(args, lib)
    # 
    return deployer, args.model_arguments[1:]


class Lib:
    def __init__(self, args):
        self.args = args
        self.platform = None
    
    def set_platform(self, platform):
        self.platform = platform
    
    def prepare_inputs(self, dataloader, device):
        ''' load sample inputs to device '''
        inputs = []
        for batch in dataloader:
            if type(batch) is torch.Tensor:
                batch_d = batch.to(device)
                batch_d = (batch_d,)
                inputs.append(batch_d)
            else:
                batch_d = []
                for x in batch:
                    assert type(x) is torch.Tensor, "input is not a tensor"
                    batch_d.append(x.to(device))
                batch_d = tuple(batch_d)
                inputs.append(batch_d)
        return inputs
    
    def get_tuple_of_shapes(self, l):
        ''' l :: list of tuples of tensors '''
        tensor_tuple = l[0]
        shapes = [list(x.shape) for x in tensor_tuple]
        for tensor_tuple in l:
            assert len(tensor_tuple) == len(shapes), "tensors with varying shape lengths are not supported"
            for i,x in enumerate(tensor_tuple):
                for j in range(len(x.shape)):
                    if shapes[i][j] != x.shape[j] or j == 0:
                        shapes[i][j] = -1
        shapes = tuple(shapes)
        return shapes
    
    def run_models(self, model, converted_model, inputs):
        ''' run the models '''
        outputs = []
        converted_outputs = []
        for input in inputs:
            with torch.no_grad():
                output = model(*input)
                converted_output = converted_model(*input)
            if type(output) is torch.Tensor:
                output = [output]
                converted_output = [converted_output]
            outputs.append(output)
            converted_outputs.append(converted_output)
        return outputs, converted_outputs
    
    def compute_errors(self, outputs, converted_outputs):
        ''' returns the list of errors '''
        errors = []
        for output,converted_output in zip(outputs,converted_outputs):
            for x,y in zip(output, converted_output):
                error = abs(x - y).max().item()
                errors.append(error)
        return errors
    
    def write_config(self, config_filename, 
                     input_shapes, input_types, 
                     output_shapes, output_types):
        ''' writes TRTIS config file '''
        assert self.platform is not None, "error - platform is not set"
        
        config_template = CONFIG_TEMPLATE
        input_template = INPUT_TEMPLATE
        spec_inputs = r""""""
        for i,(shape,typ) in enumerate(zip(input_shapes,input_types)):
            d = {
                'num' : str(i), 
                'type': torch_type_to_trtis_type[typ],
                'dims': str([1]) if len(shape) == 1 else str(list(shape)[1:]) # first dimension is the batch size 
            }
            d['reshape'] = 'reshape: { shape: [ ] }' if len(shape) == 1 else ''
            spec_inputs += input_template.format_map(d)
        spec_inputs = spec_inputs[:-1]
        
        output_template = OUTPUT_TEMPLATE
        spec_outputs = r""""""
        for i,(shape,typ) in enumerate(zip(output_shapes,output_types)):
            d = {
                'num' : str(i), 
                'type': torch_type_to_trtis_type[typ],
                'dims': str([1]) if len(shape) == 1 else str(list(shape)[1:]) # first dimension is the batch size 
            }
            d['reshape'] = 'reshape: { shape: [ ] }' if len(shape) == 1 else ''
            spec_outputs += output_template.format_map(d)
        spec_outputs = spec_outputs[:-1]
        
        batching_str = ""
        max_batch_size = self.args.trtis_max_batch_size
        
        if (self.args.trtis_dyn_batching_delay > 0):
            # Use only full and half full batches 
            pref_batch_size = [int(max_batch_size / 2.0), max_batch_size]
            
            batching_str = r"""
    dynamic_batching {{
        preferred_batch_size: [{0}]
        max_queue_delay_microseconds: {1}
    }}""".format(", ".join([str(x) for x in pref_batch_size]), int(self.args.trtis_dyn_batching_delay * 1000.0))
        
        config_values = {
            "model_name":       self.args.trtis_model_name, 
            "platform":         self.platform, 
            "max_batch_size":   max_batch_size, 
            "spec_inputs":      spec_inputs, 
            "spec_outputs":     spec_outputs, 
            "dynamic_batching": batching_str, 
            "gpu_list":         ", ".join([str(x) for x in range(torch.cuda.device_count())]), 
            "engine_count":     self.args.trtis_engine_count
        }
        
        # write config 
        with open(config_filename, "w") as file:
            final_config_str = config_template.format_map(config_values)
            final_config_str = remove_empty_lines(final_config_str)
            file.write(final_config_str)


class Deployer:
    def __init__(self, args, lib):
        self.args = args
        self.lib = lib
    
    def deploy(self, dataloader, model):
        ''' deploy the model and test for correctness with dataloader '''
        if self.args.ts_script or self.args.ts_trace:
            self.lib.set_platform("pytorch_libtorch")
            self.to_trtis_torchscript(dataloader, model)
        elif self.args.onnx:
            self.lib.set_platform("onnxruntime_onnx")
            self.to_trtis_onnx(dataloader, model)
        else:
            assert False, "error"
    
    def to_trtis_onnx(self, dataloader, model):
        if self.args.trtis_no_cuda:
            device = torch.device('cpu')
        else:
            device = torch.device('cuda')
        
        # prepare model 
        model.to(device)
        model.eval()
        
        # prepare inputs
        inputs = self.lib.prepare_inputs(dataloader, device)
        
        # generate outputs
        outputs = []
        for input in inputs:
            with torch.no_grad():
                output = model(*input)
            if type(output) is torch.Tensor:
                output = [output]
            outputs.append(output)
        
        # generate input shapes - dynamic tensor shape support 
        input_shapes = self.lib.get_tuple_of_shapes(inputs)
        
        # generate output shapes - dynamic tensor shape support 
        output_shapes = self.lib.get_tuple_of_shapes(outputs)
        
        # generate input types 
        input_types = [x.dtype for x in inputs[0]]
        
        # generate output types
        output_types = [x.dtype for x in outputs[0]]
        
        # get input names
        rng = range(len(input_types))
        input_names = ["input__" + str(num) for num in rng]
        
        # get output names
        rng = range(len(output_types))
        output_names = ["output__" + str(num) for num in rng]
        
        # prepare save path
        model_folder = os.path.join(self.args.save_dir, self.args.trtis_model_name)
        version_folder = os.path.join(model_folder, str(self.args.trtis_model_version))
        if not os.path.exists(version_folder):
            os.makedirs(version_folder)
        final_model_path = os.path.join(version_folder, 'model.onnx')
        
        assert not model.training, "internal error - model should be in eval() mode! "
        
        # get indices of dynamic input and output shapes
        dynamic_axes = {}
        for input_name,input_shape in zip(input_names,input_shapes):
            dynamic_axes[input_name] = [i for i,x in enumerate(input_shape) if x == -1]
        for output_name,output_shape in zip(output_names,output_shapes):
            dynamic_axes[output_name] = [i for i,x in enumerate(output_shape) if x == -1]
        
        # export the model
        with torch.no_grad():
            torch.onnx.export(model, inputs[0], final_model_path, verbose=False, 
                              input_names=input_names, output_names=output_names, 
                              dynamic_axes=dynamic_axes)
        
        # syntactic error check
        converted_model = onnx.load(final_model_path)
        # check that the IR is well formed
        onnx.checker.check_model(converted_model)
        
        # load the model
        session = onnxruntime.InferenceSession(final_model_path, None)
        
        class ONNX_model:
            def __init__(self, session, input_names, device):
                self.session = session
                self.input_names = input_names
                        
            def to_numpy(self, tensor):
                return tensor.detach().cpu().numpy() if tensor.requires_grad else tensor.cpu().numpy()
            
            def __call__(self, *inputs):
                inp = [(input_name, inputs[i]) for i,input_name in enumerate(self.input_names)]
                inp = {input_name : self.to_numpy(x) for input_name,x in inp}
                outputs = self.session.run(None, inp)
                outputs = [torch.from_numpy(output) for output in outputs]
                outputs = [output.to(device) for output in outputs]
                if len(outputs) == 1:
                    outputs = outputs[0]
                return outputs
        
        # switch to eval mode
        converted_model = ONNX_model(session, input_names, device)
        
        assert not model.training, "internal error - model should be in eval() mode! "
        
        # run both models on inputs
        outputs, converted_outputs = self.lib.run_models(model, converted_model, inputs)
        
        # generate output shapes - dynamic tensor shape support
        output_shapes = self.lib.get_tuple_of_shapes(outputs)
        
        # check for errors
        errors = self.lib.compute_errors(outputs, converted_outputs)
        
        print("maximal absolute error: ", max(errors))
        print()
        
        # write TRTIS config
        config_filename = os.path.join(model_folder, "config.pbtxt")
        self.lib.write_config(config_filename, 
                              input_shapes, input_types, 
                              output_shapes, output_types)
    
    def to_trtis_torchscript(self, dataloader, model):
        
        if self.args.trtis_no_cuda:
            device = torch.device('cpu')
        else:
            device = torch.device('cuda')
        
        # prepare model 
        model.to(device)
        model.eval()
        
        # prepare inputs
        inputs = self.lib.prepare_inputs(dataloader, device)
        
        # generate input shapes - dynamic tensor shape support 
        input_shapes = self.lib.get_tuple_of_shapes(inputs)
        
        # generate input types 
        input_types = [x.dtype for x in inputs[0]]
        
        # prepare save path 
        model_folder = os.path.join(self.args.save_dir, self.args.trtis_model_name)
        version_folder = os.path.join(model_folder, str(self.args.trtis_model_version))
        if not os.path.exists(version_folder):
            os.makedirs(version_folder)
        final_model_path = os.path.join(version_folder, 'model.pt')
        
        assert not model.training, "internal error - model should be in eval() mode! "
        
        # convert the model 
        with torch.no_grad():
            if self.args.ts_trace: # trace it 
                converted_model = torch.jit.trace(model, inputs[0])
            if self.args.ts_script: # script it 
                converted_model = torch.jit.script(model)
        
        # save the model 
        torch.jit.save(converted_model, final_model_path)
        
        # load the model 
        converted_model = torch.jit.load(final_model_path)
        converted_model.eval() # WAR for bug : by default, converted_model gets loaded in training mode
        
        assert not model.training, "internal error - model should be in eval() mode! "
        assert not converted_model.training, "internal error - converted model should be in eval() mode! "
        
        # run both models on inputs
        outputs, converted_outputs = self.lib.run_models(model, converted_model, inputs)
        
        # generate output shapes - dynamic tensor shape support 
        output_shapes = self.lib.get_tuple_of_shapes(outputs)
        
        # generate output types 
        output_types = [x.dtype for x in outputs[0]]
        
        # check for errors
        errors = self.lib.compute_errors(outputs, converted_outputs)
        
        print("maximal absolute error: ", max(errors))
        print()
        
        # now we build the config for TRTIS 
        config_filename = os.path.join(model_folder, "config.pbtxt")
        self.lib.write_config(config_filename, 
                              input_shapes, input_types, 
                              output_shapes, output_types)

