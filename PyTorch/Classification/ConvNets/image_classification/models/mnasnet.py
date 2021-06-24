import torch.nn as nn
import torch
import math
from typing import List, Any, Optional
from collections import namedtuple, OrderedDict
from dataclasses import dataclass, replace

from .common import (
    LayerBuilder,
)

from .model import (
    Model,
    ModelParams,
    ModelArch,
    create_entrypoint,
    EntryPoint,
)


@dataclass
class MnasNetArch(ModelArch):
    block: Any
    stem_channels: int
    feature_channels: int
    kernel: List[int]
    stride: List[int]
    num_repeat: List[int]
    expansion: List[int]
    channels: List[int]
    default_image_size: int = 224
    activation: str = "relu6"

    def enumerate(self):
        return enumerate(
            zip(
                self.kernel, self.stride, self.num_repeat, self.expansion, self.channels
            )
        )

    def num_layers(self):
        def _f(l):
            return len(set(map(len, l)))

        l = [self.kernel, self.stride, self.num_repeat, self.expansion, self.channels]
        assert _f(l) == 1
        return len(self.kernel)


# }}}

# MnasNetParams {{{
@dataclass
class MnasNetParams(ModelParams):
    # dropout: float
    num_classes: int = 1000
    activation: str = "relu6"
    conv_init: str = "fan_in"

    def parser(self, name):
        p = super().parser(name)
        p.add_argument(
            "--num_classes",
            metavar="N",
            default=self.num_classes,
            type=int,
            help="number of classes",
        )
        p.add_argument(
            "--conv_init",
            default=self.conv_init,
            choices=["fan_in", "fan_out"],
            type=str,
            help="initialization mode for convolutional layers, see https://pytorch.org/docs/stable/nn.init.html#torch.nn.init.kaiming_normal_",
        )
        return p


# }}}


class MnasNet(nn.Module):
    def __init__(
        self,
        arch: MnasNetArch,
        num_classes: int = 1000,
        activation: str = "relu6",
        conv_init: str = "fan_in",
        stride: int = 1,
    ):
        super(MnasNet, self).__init__()
        self.width_mul = 1.0
        self.arch = arch
        self.num_layers = arch.num_layers()
        self.num_blocks = sum(arch.num_repeat)

        self.builder = LayerBuilder(
            LayerBuilder.Config(
                activation=activation,
                conv_init=conv_init,
                #   bn_momentum=bn_momentum,
                #   bn_epsilon=bn_epsilon,
            )
        )

        # assert input_size % 32 == 0
        # input_channel = int(32 * self.width_mul)  # stem_channels
        self.last_channel = int(1280 * self.width_mul) if self.width_mul > 1.0 else 1280

        # building first two layer

        self.stem = self._make_stem(arch.stem_channels)  # 32

        # building inverted residual blocks (MBConv)
        out_channels = 16
        plc = 0
        for i, (k, s, r, e, c) in arch.enumerate():
            # output_channel = int(c * self.width_mul)
            layer, out_channels = self._make_layer(
                block=arch.block,
                kernel_size=k,
                stride=s,
                num_repeat=r,
                expansion=e,
                in_channels=out_channels,
                out_channels=c,
                prev_layer_count=plc,
            )
            plc = plc + r
            setattr(self, f"layer{i+1}", layer)
        # building last several layers
        self.features = self._make_features(out_channels, arch.feature_channels)
        self.classifier = self._make_classifier(arch.feature_channels, num_classes)

        self._initialize_weights()

    def forward(self, x):
        x = self.stem(x)
        for i in range(self.num_layers):
            fn = getattr(self, f"layer{i+1}")
            x = fn(x)

        # x = x.view(-1, self.last_channel)
        x = self.features(x)
        x = x.view(-1, self.last_channel)
        x = self.classifier(x)
        
        return x

    def extract_features(self, x, layers=None):
        if layers is None:
            layers = [f"layer{i+1}" for i in range(self.num_layers)]

        run = [
            f"layer{i+1}"
            for i in range(self.num_layers)
            if "classifier" in layers
            or "features" in layers
            or any([f"layer{j+1}" in layers for j in range(i, self.num_layers)])
        ]
        if "features" in layers or "classifier" in layers:
            run.append("features")
        if "classifier" in layers:
            run.append("classifier")

        output = {}
        x = self.stem(x)
        for l in run:
            fn = getattr(self, l)
            x = fn(x)
            if l in layers:
                output[l] = x

        return output

    def _initialize_weights(self):
        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                n = m.kernel_size[0] * m.kernel_size[1] * m.out_channels
                m.weight.data.normal_(0, math.sqrt(2.0 / n))
                if m.bias is not None:
                    m.bias.data.zero_()
            elif isinstance(m, nn.BatchNorm2d):
                m.weight.data.fill_(1)
                m.bias.data.zero_()
            elif isinstance(m, nn.Linear):
                n = m.weight.size(1)
                m.weight.data.normal_(0, 0.01)
                m.bias.data.zero_()

    # helper functions {{{
    def _make_stem(self, stem_width):
        return nn.Sequential(
            OrderedDict(
                [
                    (
                        "conv3x3",
                        self.builder.conv3x3(
                            3, stem_width, stride=2, bn=True, act="relu6"
                        ),
                    ),
                    (
                        "seqconv3x3",  # input 32, output 16
                        self.builder.convDepSep(
                            3, stem_width, stem_width, stride=1, bn=True, act="relu6"
                        ),
                    ),
                    (
                        "conv1x1",
                        self.builder.conv1x1(
                            stem_width, 16, stride=1, bn=True, act=False
                        ),
                    ),
                ]
            )
        )

    def _make_features(self, in_channels, num_features):
        return nn.Sequential(
            OrderedDict(
                [
                    ("conv", self.builder.conv1x1(in_channels, num_features)),
                    #  ("bn", self.builder.batchnorm(num_features)),
                    # ("activation", self.builder.activation()),
                    ("pooling", nn.AdaptiveAvgPool2d(1)),
                ]
            )
        )

    def _make_classifier(self, num_features, num_classes):
        return nn.Sequential(
            OrderedDict(
                [
                    
                    # ("squeeze", LambdaLayer(lambda x: x.squeeze(-1).squeeze(-1))),
                    ("dropout", nn.Dropout()),
                    ("fc", nn.Linear(num_features, num_classes)),
                ]
            )
        )

    def _make_layer(
        self,
        block,
        kernel_size,
        stride,
        num_repeat,
        expansion,
        in_channels,
        out_channels,
        prev_layer_count,
    ):
        layers = []

        idx = 0

        blk = block(
            self.builder,
            kernel_size,
            in_channels,
            out_channels,
            expansion,
            stride,
        )
        layers.append((f"block{idx}", blk))

        for idx in range(1, num_repeat):

            blk = block(
                self.builder,
                kernel_size,
                out_channels,
                out_channels,
                expansion,
                1,  # stride
            )
            layers.append((f"block{idx}", blk))
        return nn.Sequential(OrderedDict(layers)), out_channels


# }}}


class InvertedResidualBlock(nn.Module):
    def __init__(
        self,
        builder: LayerBuilder,
        depsep_kernel_size: int,
        in_channels: int,
        out_channels: int,
        stride: int,
        expand_ratio: int,
    ):
        super(InvertedResidualBlock, self).__init__()
        self.stride = stride
        print("```````````````````````stride: ", self.stride)
        assert stride in [1, 2]
        self.residual = self.stride == 1 and in_channels == out_channels
        hidden_dim = in_channels * expand_ratio

        self.expand = (
            None
            if in_channels == hidden_dim
            else builder.conv1x1(in_channels, hidden_dim, bn=True, act=True)
        )
        self.depsep = builder.convDepSep(
            depsep_kernel_size, hidden_dim, hidden_dim, stride, bn=True, act=True
        )
        self.proj = builder.conv1x1(hidden_dim, out_channels, bn=True)

    def forward(self, x):
        if not self.residual:
            return self.proj(self.depsep(x if self.expand is None else self.expand(x)))
            # return self.out(x)
        b = self.proj(self.depsep(x if self.expand is None else self.expand(x)))
        multiplication_factor = 0.0
        return torch.add(x, alpha=multiplication_factor, other=b)

        # return x + self.out(x)


def inverted_residual(
    builder: LayerBuilder,
    depsep_kernel_size: int,
    in_channels: int,
    out_channels: int,
    stride: int,
    expand_ratio: int,
):
    return InvertedResidualBlock(
        builder,
        depsep_kernel_size,
        in_channels,
        out_channels,
        expand_ratio,
        stride,
    )


mnasnet_layers = MnasNetArch(
    block=inverted_residual,
    stem_channels=32,
    feature_channels=1280,
    kernel=[3, 5, 5, 3, 5, 3],
    stride=[2, 2, 2, 1, 2, 1],
    num_repeat=[3, 3, 3, 2, 4, 1],
    expansion=[3, 3, 6, 6, 6, 6],
    channels=[24, 40, 80, 96, 192, 320],
    default_image_size=224,
)


def _m(*args, **kwargs):
    return Model(constructor=MnasNet, *args, **kwargs)


architectures = {"mnasnet": _m(arch=mnasnet_layers, params=MnasNetParams())}


def _ce(n):
    return EntryPoint(n, architectures[n])


mnasnet = _ce("mnasnet")
