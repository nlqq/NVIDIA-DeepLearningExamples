# Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
#
# Licensed under the BSD 3-Clause License  (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# https://opensource.org/licenses/BSD-3-Clause
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
from PIL import Image
import argparse
import numpy as np
import json
import torch
<<<<<<< HEAD
import torch.backends.cudnn as cudnn
import torchvision.transforms as transforms
import image_classification.resnet as models
from image_classification.dataloaders import load_jpeg_from_file

try:
    from apex.fp16_utils import *
    from apex import amp
except ImportError:
    raise ImportError(
        "Please install apex from https://www.github.com/nvidia/apex to run this example."
    )


def add_parser_arguments(parser):
    model_names = models.resnet_versions.keys()
    model_configs = models.resnet_configs.keys()
=======
from torch.cuda.amp import autocast
import torch.backends.cudnn as cudnn

from image_classification import models
import torchvision.transforms as transforms

from image_classification.models import (
    resnet50,
    resnext101_32x4d,
    se_resnext101_32x4d,
    efficientnet_b0,
    efficientnet_b4,
    efficientnet_widese_b0,
    efficientnet_widese_b4,
    efficientnet_quant_b0,
    efficientnet_quant_b4,
)

def available_models():
    models = {
        m.name: m
        for m in [
            resnet50,
            resnext101_32x4d,
            se_resnext101_32x4d,
            efficientnet_b0,
            efficientnet_b4,
            efficientnet_widese_b0,
            efficientnet_widese_b4,
            efficientnet_quant_b0,
            efficientnet_quant_b4,
        ]
    }
    return models

def add_parser_arguments(parser):
    model_names = available_models().keys()
>>>>>>> repo1
    parser.add_argument("--image-size", default="224", type=int)
    parser.add_argument(
        "--arch",
        "-a",
        metavar="ARCH",
        default="resnet50",
        choices=model_names,
        help="model architecture: " + " | ".join(model_names) + " (default: resnet50)",
    )
    parser.add_argument(
<<<<<<< HEAD
        "--model-config",
        "-c",
        metavar="CONF",
        default="classic",
        choices=model_configs,
        help="model configs: " + " | ".join(model_configs) + "(default: classic)",
    )
    parser.add_argument("--weights", metavar="<path>", help="file with model weights")
    parser.add_argument(
        "--precision", metavar="PREC", default="FP16", choices=["AMP", "FP16", "FP32"]
    )
    parser.add_argument("--image", metavar="<path>", help="path to classified image")


def main(args):
    imgnet_classes = np.array(json.load(open("./LOC_synset_mapping.json", "r")))
    model = models.build_resnet(args.arch, args.model_config, 1000, verbose=False)

    if args.weights is not None:
        weights = torch.load(args.weights)
        model.load_state_dict(weights)

    model = model.cuda()

    if args.precision in ["AMP", "FP16"]:
        model = network_to_half(model)


    model.eval()

    with torch.no_grad():
        input = load_jpeg_from_file(
            args.image, cuda=True, fp16=args.precision != "FP32"
        )

        output = torch.nn.functional.softmax(model(input), dim=1).cpu().view(-1).numpy()
        top5 = np.argsort(output)[-5:][::-1]

        print(args.image)
        for c, v in zip(imgnet_classes[top5], output[top5]):
            print(f"{c}: {100*v:.1f}%")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="PyTorch ImageNet Training")

    add_parser_arguments(parser)
    args = parser.parse_args()

    cudnn.benchmark = True

    main(args)
=======
        "--precision", metavar="PREC", default="AMP", choices=["AMP", "FP32"]
    )
    parser.add_argument("--cpu", action="store_true", help="perform inference on CPU")
    parser.add_argument("--image", metavar="<path>", help="path to classified image")


def load_jpeg_from_file(path, image_size, cuda=True):
    img_transforms = transforms.Compose(
        [
            transforms.Resize(image_size + 32),
            transforms.CenterCrop(image_size),
            transforms.ToTensor(),
        ]
    )

    img = img_transforms(Image.open(path))
    with torch.no_grad():
        # mean and std are not multiplied by 255 as they are in training script
        # torch dataloader reads data into bytes whereas loading directly
        # through PIL creates a tensor with floats in [0,1] range
        mean = torch.tensor([0.485, 0.456, 0.406]).view(1, 3, 1, 1)
        std = torch.tensor([0.229, 0.224, 0.225]).view(1, 3, 1, 1)

        if cuda:
            mean = mean.cuda()
            std = std.cuda()
            img = img.cuda()
        img = img.float()

        input = img.unsqueeze(0).sub_(mean).div_(std)

    return input


def check_quant_weight_correctness(checkpoint_path, model):
    state_dict = torch.load(checkpoint_path, map_location=torch.device('cpu'))
    state_dict = {k[len("module."):] if k.startswith("module.") else k: v for k, v in state_dict.items()}
    quantizers_sd_keys = {f'{n[0]}._amax' for n in model.named_modules() if 'quantizer' in n[0]}
    sd_all_keys = quantizers_sd_keys | set(model.state_dict().keys())
    assert set(state_dict.keys()) == sd_all_keys, (f'Passed quantized architecture, but following keys are missing in '
                                                   f'checkpoint: {list(sd_all_keys - set(state_dict.keys()))}')


def main(args, model_args):
    imgnet_classes = np.array(json.load(open("./LOC_synset_mapping.json", "r")))
    model = available_models()[args.arch](**model_args.__dict__)
    if args.arch in ['efficientnet-quant-b0', 'efficientnet-quant-b4']:
        check_quant_weight_correctness(model_args.pretrained_from_file, model)
        
    if not args.cpu:
        model = model.cuda()
    model.eval()

    input = load_jpeg_from_file(args.image, args.image_size, cuda=not args.cpu)

    with torch.no_grad(), autocast(enabled = args.precision == "AMP"):
        output = torch.nn.functional.softmax(model(input), dim=1)

    output = output.float().cpu().view(-1).numpy()
    top5 = np.argsort(output)[-5:][::-1]

    print(args.image)
    for c, v in zip(imgnet_classes[top5], output[top5]):
        print(f"{c}: {100*v:.1f}%")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="PyTorch ImageNet Classification")

    add_parser_arguments(parser)
    args, rest = parser.parse_known_args()
    model_args, rest = available_models()[args.arch].parser().parse_known_args(rest)

    assert len(rest) == 0, f"Unknown args passed: {rest}"

    cudnn.benchmark = True

    main(args, model_args)
>>>>>>> repo1
