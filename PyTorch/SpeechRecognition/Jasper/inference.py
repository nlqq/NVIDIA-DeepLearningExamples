# Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#           http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
<<<<<<< HEAD
import itertools
from typing import List
from tqdm import tqdm
import math
import toml
from dataset import AudioToTextDataLayer
from helpers import process_evaluation_batch, process_evaluation_epoch, add_ctc_labels, print_dict, model_multi_gpu, __ctc_decoder_predictions_tensor
from model import AudioPreprocessing, GreedyCTCDecoder, JasperEncoderDecoder
from parts.features import audio_from_file
import torch
import torch.nn as nn
import apex
from apex import amp
import random
import numpy as np
import pickle
import time
import os

def parse_args():
    parser = argparse.ArgumentParser(description='Jasper')

    parser.register("type", "bool", lambda x: x.lower() in ("yes", "true", "t", "1"))

    parser.add_argument("--local_rank", default=None, type=int)
    parser.add_argument("--batch_size", default=16, type=int, help='data batch size')
    parser.add_argument("--steps", default=None, help='if not specified do evaluation on full dataset. otherwise only evaluates the specified number of iterations for each worker', type=int)
    parser.add_argument("--model_toml", type=str, help='relative model configuration path given dataset folder')
    parser.add_argument("--dataset_dir", type=str, help='absolute path to dataset folder')
    parser.add_argument("--val_manifest", type=str, help='relative path to evaluation dataset manifest file')
    parser.add_argument("--ckpt", default=None, type=str, required=True, help='path to model checkpoint')
    parser.add_argument("--max_duration", default=None, type=float, help='maximum duration of sequences. if None uses attribute from model configuration file')
    parser.add_argument("--pad_to", default=None, type=int, help="default is pad to value as specified in model configurations. if -1 pad to maximum duration. If > 0 pad batch to next multiple of value")
    parser.add_argument("--amp", "--fp16", action='store_true', help='use half precision')
    parser.add_argument("--cudnn_benchmark", action='store_true', help="enable cudnn benchmark")
    parser.add_argument("--save_prediction", type=str, default=None, help="if specified saves predictions in text form at this location")
    parser.add_argument("--logits_save_to", default=None, type=str, help="if specified will save logits to path")
    parser.add_argument("--seed", default=42, type=int, help='seed')
    parser.add_argument("--output_dir", default="results/", type=str, help="Output directory to store exported models. Only used if --export_model is used")
    parser.add_argument("--export_model", action='store_true', help="Exports the audio_featurizer, encoder and decoder using torch.jit to the output_dir")
    parser.add_argument("--wav", type=str, help='absolute path to .wav file (16KHz)')
    parser.add_argument("--cpu", action="store_true", help="Run inference on CPU")
    parser.add_argument("--ema", action="store_true", help="If available, load EMA model weights")

    # FIXME Unused, but passed by Triton helper scripts
    parser.add_argument("--pyt_fp16", action='store_true', help='use half precision')

    return parser.parse_args()

def calc_wer(data_layer, audio_processor,
             encoderdecoder, greedy_decoder,
             labels, args, device):

    encoderdecoder = encoderdecoder.module if hasattr(encoderdecoder, 'module') else encoderdecoder
    with torch.no_grad():
        # reset global_var_dict - results of evaluation will be stored there
        _global_var_dict = {
            'predictions': [],
            'transcripts': [],
            'logits' : [],
        }

        # Evaluation mini-batch for loop
        for it, data in enumerate(tqdm(data_layer.data_iterator)):

            tensors = [t.to(device) for t in data]
    
            t_audio_signal_e, t_a_sig_length_e, t_transcript_e, t_transcript_len_e = tensors

            t_processed_signal = audio_processor(t_audio_signal_e, t_a_sig_length_e)
            t_log_probs_e, _ = encoderdecoder.infer(t_processed_signal)
            t_predictions_e = greedy_decoder(t_log_probs_e)

            values_dict = dict(
                predictions=[t_predictions_e],
                transcript=[t_transcript_e],
                transcript_length=[t_transcript_len_e],
                output=[t_log_probs_e]
            )
            # values_dict will contain results from all workers
            process_evaluation_batch(values_dict, _global_var_dict, labels=labels)

            if args.steps is not None and it + 1 >= args.steps:
                break

        # final aggregation (over minibatches) and logging of results
        wer, _ = process_evaluation_epoch(_global_var_dict)

        return wer, _global_var_dict


def jit_export(audio, audio_len, audio_processor, encoderdecoder, greedy_decoder, args):

                print("##############")

                module_name = "{}_{}".format(os.path.basename(args.model_toml), "fp16" if args.amp else "fp32")

                if args.use_conv_mask:
                    module_name = module_name + "_noMaskConv"

                # Export just the featurizer
                print("exporting featurizer ...")
                traced_module_feat = torch.jit.script(audio_processor)
                traced_module_feat.save(os.path.join(args.output_dir, module_name + "_feat.pt"))

                # Export just the acoustic model
                print("exporting acoustic model ...")
                inp_postFeat, _ = audio_processor(audio, audio_len)
                traced_module_acoustic = torch.jit.trace(encoderdecoder, inp_postFeat)
                traced_module_acoustic.save(os.path.join(args.output_dir, module_name + "_acoustic.pt"))

                # Export just the decoder
                print("exporting decoder ...")

                inp_postAcoustic = encoderdecoder(inp_postFeat)
                traced_module_decode = torch.jit.script(greedy_decoder, inp_postAcoustic)
                traced_module_decode.save(os.path.join(args.output_dir, module_name + "_decoder.pt"))
                print("JIT export complete")

                return traced_module_feat, traced_module_acoustic, traced_module_decode

def run_once(audio_processor, encoderdecoder, greedy_decoder, audio, audio_len, labels, device):
            features, lens = audio_processor(audio, audio_len)
            if not device.type == 'cpu':
                torch.cuda.synchronize()
            t0 = time.perf_counter()
            # TorchScripted model does not support (features, lengths)
            if isinstance(encoderdecoder, torch.jit.TracedModule):
                t_log_probs_e = encoderdecoder(features)
            else:
                t_log_probs_e, _ = encoderdecoder.infer((features, lens))
            if not device.type == 'cpu':
                torch.cuda.synchronize()
            t1 = time.perf_counter()
            t_predictions_e = greedy_decoder(log_probs=t_log_probs_e)
            hypotheses = __ctc_decoder_predictions_tensor(t_predictions_e, labels=labels)
            print("INFERENCE TIME\t\t: {} ms".format((t1-t0)*1000.0))
            print("TRANSCRIPT\t\t:", hypotheses[0])


def eval(
         data_layer,
         audio_processor,
         encoderdecoder,
         greedy_decoder,
         labels,
         multi_gpu,
         device,
         args):
    """performs inference / evaluation
    Args:
        data_layer: data layer object that holds data loader
        audio_processor: data processing module
        encoderdecoder: acoustic model
        greedy_decoder: greedy decoder
        labels: list of labels as output vocabulary
        multi_gpu: true if using multiple gpus
        args: script input arguments
    """
    logits_save_to=args.logits_save_to

    with torch.no_grad():
        if args.wav:
            audio, audio_len = audio_from_file(args.wav)
            run_once(audio_processor, encoderdecoder, greedy_decoder, audio, audio_len, labels, device)
            if args.export_model:
                jit_audio_processor, jit_encoderdecoder, jit_greedy_decoder = jit_export(audio, audio_len, audio_processor, encoderdecoder,greedy_decoder,args)
                run_once(jit_audio_processor, jit_encoderdecoder, jit_greedy_decoder, audio, audio_len, labels, device)
            return
        wer, _global_var_dict = calc_wer(data_layer, audio_processor, encoderdecoder, greedy_decoder, labels, args, device)
        if (not multi_gpu or (multi_gpu and torch.distributed.get_rank() == 0)):
            print("==========>>>>>>Evaluation WER: {0}\n".format(wer))

            if args.save_prediction is not None:
                with open(args.save_prediction, 'w') as fp:
                    fp.write('\n'.join(_global_var_dict['predictions']))
            if logits_save_to is not None:
                logits = []
                for batch in _global_var_dict["logits"]:
                    for i in range(batch.shape[0]):
                        logits.append(batch[i].cpu().numpy())
                with open(logits_save_to, 'wb') as f:
                    pickle.dump(logits, f, protocol=pickle.HIGHEST_PROTOCOL)

            # if args.export_model:            
            #     feat, acoustic, decoder = jit_export(inp, audio_processor, encoderdecoder, greedy_decoder,args)
            #     wer_after = calc_wer(data_layer, feat, acoustic, decoder, labels, args)
            #     print("===>>>Before WER: {0}".format(wer))
            #     print("===>>>Traced WER: {0}".format(wer_after))
            #     print("===>>>Diff      : {0} %".format((wer_after - wer_before) * 100.0 / wer_before))
            #     print("")


def main(args):
    random.seed(args.seed)
    np.random.seed(args.seed)
    torch.manual_seed(args.seed)

    multi_gpu = args.local_rank is not None

    if args.cpu:
        assert(not multi_gpu)
        device = torch.device('cpu')
    else:
        assert(torch.cuda.is_available())
        device = torch.device('cuda')
        torch.backends.cudnn.benchmark = args.cudnn_benchmark
        print("CUDNN BENCHMARK ", args.cudnn_benchmark)

        if multi_gpu:
            print("DISTRIBUTED with ", torch.distributed.get_world_size())
            torch.cuda.set_device(args.local_rank)
            torch.distributed.init_process_group(backend='nccl', init_method='env://')

    optim_level = 3 if args.amp else 0

    jasper_model_definition = toml.load(args.model_toml)
    dataset_vocab = jasper_model_definition['labels']['labels']
    ctc_vocab = add_ctc_labels(dataset_vocab)

    val_manifest = args.val_manifest
    featurizer_config = jasper_model_definition['input_eval']
    featurizer_config["optimization_level"] = optim_level
    featurizer_config["fp16"] = args.amp

    args.use_conv_mask = jasper_model_definition['encoder'].get('convmask', True)
    if args.use_conv_mask and args.export_model:
        print('WARNING: Masked convs currently not supported for TorchScript. Disabling.')
        jasper_model_definition['encoder']['convmask'] = False

    if args.max_duration is not None:
        featurizer_config['max_duration'] = args.max_duration
    if args.pad_to is not None:
        featurizer_config['pad_to'] = args.pad_to

    if featurizer_config['pad_to'] == "max":
        featurizer_config['pad_to'] = -1

    print('=== model_config ===')
    print_dict(jasper_model_definition)
    print()
    print('=== feature_config ===')
    print_dict(featurizer_config)
    print()
    data_layer = None

    if args.wav is None:
        data_layer = AudioToTextDataLayer(
            dataset_dir=args.dataset_dir,
            featurizer_config=featurizer_config,
            manifest_filepath=val_manifest,
            labels=dataset_vocab,
            batch_size=args.batch_size,
            pad_to_max=featurizer_config['pad_to'] == -1,
            shuffle=False,
            multi_gpu=multi_gpu)
    audio_preprocessor = AudioPreprocessing(**featurizer_config)
    encoderdecoder = JasperEncoderDecoder(jasper_model_definition=jasper_model_definition, feat_in=1024, num_classes=len(ctc_vocab))

    if args.ckpt is not None:
        print("loading model from ", args.ckpt)

        if os.path.isdir(args.ckpt):
            exit(0)
        else:
            checkpoint = torch.load(args.ckpt, map_location="cpu")
            if args.ema and 'ema_state_dict' in checkpoint:
                print('Loading EMA state dict')
                sd = 'ema_state_dict'
            else:
                sd = 'state_dict'

            for k in audio_preprocessor.state_dict().keys():
                checkpoint[sd][k] = checkpoint[sd].pop("audio_preprocessor." + k)
            audio_preprocessor.load_state_dict(checkpoint[sd], strict=False)
            encoderdecoder.load_state_dict(checkpoint[sd], strict=False)

    greedy_decoder = GreedyCTCDecoder()

    # print("Number of parameters in encoder: {0}".format(model.jasper_encoder.num_weights()))
    if args.wav is None:
        N = len(data_layer)
        step_per_epoch = math.ceil(N / (args.batch_size * (1 if not torch.distributed.is_initialized() else torch.distributed.get_world_size())))

        if args.steps is not None:
            print('-----------------')
            print('Have {0} examples to eval on.'.format(args.steps * args.batch_size * (1 if not torch.distributed.is_initialized() else torch.distributed.get_world_size())))
            print('Have {0} steps / (gpu * epoch).'.format(args.steps))
            print('-----------------')
        else:
            print('-----------------')
            print('Have {0} examples to eval on.'.format(N))
            print('Have {0} steps / (gpu * epoch).'.format(step_per_epoch))
            print('-----------------')

    print ("audio_preprocessor.normalize: ", audio_preprocessor.featurizer.normalize)

    audio_preprocessor.to(device)
    encoderdecoder.to(device)

    if args.amp:
        encoderdecoder = amp.initialize(models=encoderdecoder,
                                        opt_level='O'+str(optim_level))

    encoderdecoder = model_multi_gpu(encoderdecoder, multi_gpu)
    audio_preprocessor.eval()
    encoderdecoder.eval()
    greedy_decoder.eval()

    eval(
        data_layer=data_layer,
        audio_processor=audio_preprocessor,
        encoderdecoder=encoderdecoder,
        greedy_decoder=greedy_decoder,
        labels=ctc_vocab,
        args=args,
        device=device,
        multi_gpu=multi_gpu)

if __name__=="__main__":
    args = parse_args()

    print_dict(vars(args))

    main(args)
=======
import math
import os
import random
import time
from heapq import nlargest
from itertools import chain, repeat
from pathlib import Path
from tqdm import tqdm

import dllogger
import torch
import numpy as np
import torch.distributed as distrib
from apex import amp
from apex.parallel import DistributedDataParallel
from dllogger import JSONStreamBackend, StdOutBackend, Verbosity

from jasper import config
from common import helpers
from common.dali.data_loader import DaliDataLoader
from common.dataset import (AudioDataset, FilelistDataset, get_data_loader,
                            SingleAudioDataset)
from common.features import BaseFeatures, FilterbankFeatures
from common.helpers import print_once, process_evaluation_epoch
from jasper.model import GreedyCTCDecoder, Jasper
from common.tb_dllogger import stdout_metric_format, unique_log_fpath


def get_parser():
    parser = argparse.ArgumentParser(description='Jasper')
    parser.add_argument('--batch_size', default=16, type=int,
                        help='Data batch size')
    parser.add_argument('--steps', default=0, type=int,
                        help='Eval this many steps for every worker')
    parser.add_argument('--warmup_steps', default=0, type=int,
                        help='Burn-in period before measuring latencies')
    parser.add_argument('--model_config', type=str, required=True,
                        help='Relative model config path given dataset folder')
    parser.add_argument('--dataset_dir', type=str,
                        help='Absolute path to dataset folder')
    parser.add_argument('--val_manifests', type=str, nargs='+',
                        help='Relative path to evaluation dataset manifest files')
    parser.add_argument('--ckpt', default=None, type=str,
                        help='Path to model checkpoint')
    parser.add_argument('--max_duration', default=None, type=float,
                        help='Filter out longer inputs (in seconds)')
    parser.add_argument('--pad_to_max_duration', action='store_true',
                        help='Pads every batch to max_duration')
    parser.add_argument('--amp', '--fp16', action='store_true',
                        help='Use FP16 precision')
    parser.add_argument('--cudnn_benchmark', action='store_true',
                        help='Enable cudnn benchmark')
    parser.add_argument('--cpu', action='store_true',
                        help='Run inference on CPU')
    parser.add_argument("--seed", default=None, type=int, help='Random seed')
    parser.add_argument('--local_rank', default=os.getenv('LOCAL_RANK', 0),
                        type=int, help='GPU id used for distributed training')

    io = parser.add_argument_group('feature and checkpointing setup')
    io.add_argument('--dali_device', type=str, choices=['none', 'cpu', 'gpu'],
                    default='gpu', help='Use DALI pipeline for fast data processing')
    io.add_argument('--save_predictions', type=str, default=None,
                    help='Save predictions in text form at this location')
    io.add_argument('--save_logits', default=None, type=str,
                    help='Save output logits under specified path')
    io.add_argument('--transcribe_wav', type=str,
                    help='Path to a single .wav file (16KHz)')
    io.add_argument('--transcribe_filelist', type=str,
                    help='Path to a filelist with one .wav path per line')
    io.add_argument('-o', '--output_dir', default='results/',
                    help='Output folder to save audio (file per phrase)')
    io.add_argument('--log_file', type=str, default=None,
                    help='Path to a DLLogger log file')
    io.add_argument('--ema', action='store_true',
                    help='Load averaged model weights')
    io.add_argument('--torchscript', action='store_true',
                    help='Evaluate with a TorchScripted model')
    io.add_argument('--torchscript_export', action='store_true',
                    help='Export the model with torch.jit to the output_dir')
    return parser


def durs_to_percentiles(durations, ratios):
    durations = np.asarray(durations) * 1000  # in ms
    latency = durations

    latency = latency[5:]
    mean_latency = np.mean(latency)

    latency_worst = nlargest(math.ceil((1 - min(ratios)) * len(latency)), latency)
    latency_ranges = get_percentile(ratios, latency_worst, len(latency))
    latency_ranges[0.5] = mean_latency
    return latency_ranges


def get_percentile(ratios, arr, nsamples):
    res = {}
    for a in ratios:
        idx = max(int(nsamples * (1 - a)), 0)
        res[a] = arr[idx]
    return res


def torchscript_export(data_loader, audio_processor, model, greedy_decoder,
                       output_dir, use_amp, use_conv_masks, model_config, device,
                       save):

    audio_processor.to(device)

    for batch in data_loader:
        batch = [t.to(device, non_blocking=True) for t in batch]
        audio, audio_len, _, _ = batch
        feats, feat_lens = audio_processor(audio, audio_len)
        break

    print("\nExporting featurizer...")
    print("\nNOTE: Dithering causes warnings about non-determinism.\n")
    ts_feat = torch.jit.trace(audio_processor, (audio, audio_len))

    print("\nExporting acoustic model...")
    model(feats, feat_lens)
    ts_acoustic = torch.jit.trace(model, (feats, feat_lens))

    print("\nExporting decoder...")
    log_probs = model(feats, feat_lens)
    ts_decoder = torch.jit.script(greedy_decoder, log_probs)
    print("\nJIT export complete.")

    if save:
        precision = "fp16" if use_amp else "fp32"
        module_name = f'{os.path.basename(model_config)}_{precision}'
        ts_feat.save(os.path.join(output_dir, module_name + "_feat.pt"))
        ts_acoustic.save(os.path.join(output_dir, module_name + "_acoustic.pt"))
        ts_decoder.save(os.path.join(output_dir, module_name + "_decoder.pt"))

    return ts_feat, ts_acoustic, ts_decoder


def main():

    parser = get_parser()
    args = parser.parse_args()

    log_fpath = args.log_file or str(Path(args.output_dir, 'nvlog_infer.json'))
    log_fpath = unique_log_fpath(log_fpath)
    dllogger.init(backends=[JSONStreamBackend(Verbosity.DEFAULT, log_fpath),
                            StdOutBackend(Verbosity.VERBOSE,
                                          metric_format=stdout_metric_format)])

    [dllogger.log("PARAMETER", {k: v}) for k, v in vars(args).items()]

    for step in ['DNN', 'data+DNN', 'data']:
        for c in [0.99, 0.95, 0.9, 0.5]:
            cs = 'avg' if c == 0.5 else f'{int(100*c)}%'
            dllogger.metadata(f'{step.lower()}_latency_{c}',
                              {'name': f'{step} latency {cs}',
                               'format': ':>7.2f', 'unit': 'ms'})
    dllogger.metadata(
        'eval_wer', {'name': 'WER', 'format': ':>3.2f', 'unit': '%'})

    if args.cpu:
        device = torch.device('cpu')
    else:
        assert torch.cuda.is_available()
        device = torch.device('cuda')
        torch.backends.cudnn.benchmark = args.cudnn_benchmark

    if args.seed is not None:
        torch.manual_seed(args.seed + args.local_rank)
        np.random.seed(args.seed + args.local_rank)
        random.seed(args.seed + args.local_rank)

    # set up distributed training
    multi_gpu = not args.cpu and int(os.environ.get('WORLD_SIZE', 1)) > 1
    if multi_gpu:
        torch.cuda.set_device(args.local_rank)
        distrib.init_process_group(backend='nccl', init_method='env://')
        print_once(f'Inference with {distrib.get_world_size()} GPUs')

    cfg = config.load(args.model_config)

    if args.max_duration is not None:
        cfg['input_val']['audio_dataset']['max_duration'] = args.max_duration
        cfg['input_val']['filterbank_features']['max_duration'] = args.max_duration

    if args.pad_to_max_duration:
        assert cfg['input_val']['audio_dataset']['max_duration'] > 0
        cfg['input_val']['audio_dataset']['pad_to_max_duration'] = True
        cfg['input_val']['filterbank_features']['pad_to_max_duration'] = True

    symbols = helpers.add_ctc_blank(cfg['labels'])

    use_dali = args.dali_device in ('cpu', 'gpu')
    dataset_kw, features_kw = config.input(cfg, 'val')

    measure_perf = args.steps > 0

    # dataset
    if args.transcribe_wav or args.transcribe_filelist:

        if use_dali:
            print("DALI supported only with input .json files; disabling")
            use_dali = False

        assert not args.pad_to_max_duration
        assert not (args.transcribe_wav and args.transcribe_filelist)

        if args.transcribe_wav:
            dataset = SingleAudioDataset(args.transcribe_wav)
        else:
            dataset = FilelistDataset(args.transcribe_filelist)

        data_loader = get_data_loader(dataset,
                                      batch_size=1,
                                      multi_gpu=multi_gpu,
                                      shuffle=False,
                                      num_workers=0,
                                      drop_last=(True if measure_perf else False))

        _, features_kw = config.input(cfg, 'val')
        feat_proc = FilterbankFeatures(**features_kw)

    elif use_dali:
        # pad_to_max_duration is not supported by DALI - have simple padders
        if features_kw['pad_to_max_duration']:
            feat_proc = BaseFeatures(
                pad_align=features_kw['pad_align'],
                pad_to_max_duration=True,
                max_duration=features_kw['max_duration'],
                sample_rate=features_kw['sample_rate'],
                window_size=features_kw['window_size'],
                window_stride=features_kw['window_stride'])
            features_kw['pad_to_max_duration'] = False
        else:
            feat_proc = None

        data_loader = DaliDataLoader(
            gpu_id=args.local_rank or 0,
            dataset_path=args.dataset_dir,
            config_data=dataset_kw,
            config_features=features_kw,
            json_names=args.val_manifests,
            batch_size=args.batch_size,
            pipeline_type=("train" if measure_perf else "val"),  # no drop_last 
            device_type=args.dali_device,
            symbols=symbols)

    else:
        dataset = AudioDataset(args.dataset_dir,
                               args.val_manifests,
                               symbols,
                               **dataset_kw)

        data_loader = get_data_loader(dataset,
                                      args.batch_size,
                                      multi_gpu=multi_gpu,
                                      shuffle=False,
                                      num_workers=4,
                                      drop_last=False)

        feat_proc = FilterbankFeatures(**features_kw)

    model = Jasper(encoder_kw=config.encoder(cfg),
                   decoder_kw=config.decoder(cfg, n_classes=len(symbols)))

    if args.ckpt is not None:
        print(f'Loading the model from {args.ckpt} ...')
        checkpoint = torch.load(args.ckpt, map_location="cpu")
        key = 'ema_state_dict' if args.ema else 'state_dict'
        state_dict = helpers.convert_v1_state_dict(checkpoint[key])
        model.load_state_dict(state_dict, strict=True)

    model.to(device)
    model.eval()

    if feat_proc is not None:
        feat_proc.to(device)
        feat_proc.eval()

    if args.amp:
        model = model.half()

    if args.torchscript:
        greedy_decoder = GreedyCTCDecoder()

        feat_proc, model, greedy_decoder = torchscript_export(
            data_loader, feat_proc, model, greedy_decoder, args.output_dir,
            use_amp=args.amp, use_conv_masks=True, model_toml=args.model_toml,
            device=device, save=args.torchscript_export)

    if multi_gpu:
        model = DistributedDataParallel(model)

    agg = {'txts': [], 'preds': [], 'logits': []}
    dur = {'data': [], 'dnn': [], 'data+dnn': []}

    looped_loader = chain.from_iterable(repeat(data_loader))
    greedy_decoder = GreedyCTCDecoder()

    sync = lambda: torch.cuda.synchronize() if device.type == 'cuda' else None

    steps = args.steps + args.warmup_steps or len(data_loader)
    with torch.no_grad():

        for it, batch in enumerate(tqdm(looped_loader, initial=1, total=steps)):

            if use_dali:
                feats, feat_lens, txt, txt_lens = batch
                if feat_proc is not None:
                    feats, feat_lens = feat_proc(feats, feat_lens)
            else:
                batch = [t.to(device, non_blocking=True) for t in batch]
                audio, audio_lens, txt, txt_lens = batch
                feats, feat_lens = feat_proc(audio, audio_lens)

            sync()
            t1 = time.perf_counter()

            if args.amp:
                feats = feats.half()

            if model.encoder.use_conv_masks:
                log_probs, log_prob_lens = model(feats, feat_lens)
            else:
                log_probs = model(feats, feat_lens)

            preds = greedy_decoder(log_probs)

            sync()
            t2 = time.perf_counter()

            # burn-in period; wait for a new loader due to num_workers
            if it >= 1 and (args.steps == 0 or it >= args.warmup_steps):
                dur['data'].append(t1 - t0)
                dur['dnn'].append(t2 - t1)
                dur['data+dnn'].append(t2 - t0)

            if txt is not None:
                agg['txts'] += helpers.gather_transcripts([txt], [txt_lens],
                                                          symbols)
            agg['preds'] += helpers.gather_predictions([preds], symbols)
            agg['logits'].append(log_probs)

            if it + 1 == steps:
                break

            sync()
            t0 = time.perf_counter()

        # communicate the results
        if args.transcribe_wav:
            for idx, p in enumerate(agg['preds']):
                print_once(f'Prediction {idx+1: >3}: {p}')

        elif args.transcribe_filelist:
            pass

        elif not multi_gpu or distrib.get_rank() == 0:
            wer, _ = process_evaluation_epoch(agg)

            dllogger.log(step=(), data={'eval_wer': 100 * wer})

        if args.save_predictions:
            with open(args.save_predictions, 'w') as f:
                f.write('\n'.join(agg['preds']))

        if args.save_logits:
            logits = torch.cat(agg['logits'], dim=0).cpu()
            torch.save(logits, args.save_logits)

    # report timings
    if len(dur['data']) >= 20:
        ratios = [0.9, 0.95, 0.99]
        for stage in dur:
            lat = durs_to_percentiles(dur[stage], ratios)
            for k in [0.99, 0.95, 0.9, 0.5]:
                kk = str(k).replace('.', '_')
                dllogger.log(step=(), data={f'{stage.lower()}_latency_{kk}': lat[k]})

    else:
        print_once('Not enough samples to measure latencies.')


if __name__ == "__main__":
    main()
>>>>>>> repo1
