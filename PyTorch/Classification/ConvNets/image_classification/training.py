# Copyright (c) 2018-2019, NVIDIA CORPORATION
# Copyright (c) 2017-      Facebook, Inc
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
#
# * Neither the name of the copyright holder nor the names of its
#   contributors may be used to endorse or promote products derived from
#   this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
<<<<<<< HEAD
import os
import time
=======
import math
import time

>>>>>>> repo1
import numpy as np
import torch
import torch.nn as nn
from torch.autograd import Variable
from . import logger as log
<<<<<<< HEAD
from . import resnet as models
from . import utils
import dllogger

# try:
#     from apex.parallel import DistributedDataParallel as DDP
#     from apex.fp16_utils import *
#     from apex import amp
# except ImportError:
#     raise ImportError(
#         "Please install apex from https://www.github.com/nvidia/apex to run this example."
#     )
=======
from . import models
from . import utils
import dllogger

from .optimizers import get_sgd_optimizer, get_rmsprop_optimizer
from .models.common import EMA
from torch.nn.parallel import DistributedDataParallel as DDP
from torch.cuda.amp import autocast
>>>>>>> repo1

ACC_METADATA = {"unit": "%", "format": ":.2f"}
IPS_METADATA = {"unit": "img/s", "format": ":.2f"}
TIME_METADATA = {"unit": "s", "format": ":.5f"}
LOSS_METADATA = {"format": ":.5f"}


class ModelAndLoss(nn.Module):
    def __init__(
        self,
<<<<<<< HEAD
        arch,
        loss,
        pretrained_weights=None,
        cuda=True,
        fp16=False,
        memory_format=torch.contiguous_format,
    ):
        super(ModelAndLoss, self).__init__()
        self.arch = arch

        print("=> creating model '{}'".format(arch))
        model = models.build_resnet(arch[0], arch[1], arch[2])
        if pretrained_weights is not None:
            print("=> using pre-trained model from a file '{}'".format(arch))
            model.load_state_dict(pretrained_weights)

        if cuda:
            model = model.cuda().to(memory_format=memory_format)
        if fp16:
            model = network_to_half(model)
=======
        model,
        loss,
        cuda=True,
        memory_format=torch.contiguous_format,
    ):
        super(ModelAndLoss, self).__init__()

        if cuda:
            model = model.cuda().to(memory_format=memory_format)
>>>>>>> repo1

        # define loss function (criterion) and optimizer
        criterion = loss()

        if cuda:
            criterion = criterion.cuda()

        self.model = model
        self.loss = criterion

    def forward(self, data, target):
        output = self.model(data)
        loss = self.loss(output, target)

        return loss, output

<<<<<<< HEAD
    def distributed(self):
        print("lyon depriciated >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> # self.model = DDP(self.model)")
        self.model = self.model
        # self.model = DDP(self.model)
=======
    def distributed(self, gpu_id):
        self.model = DDP(self.model, device_ids=[gpu_id], output_device=gpu_id)
>>>>>>> repo1

    def load_model_state(self, state):
        if not state is None:
            self.model.load_state_dict(state)


<<<<<<< HEAD
def get_optimizer(
    parameters,
    fp16,
    lr,
    momentum,
    weight_decay,
    nesterov=False,
    state=None,
    static_loss_scale=1.0,
    dynamic_loss_scale=False,
    bn_weight_decay=False,
):

    if bn_weight_decay:
        print(" ! Weight decay applied to BN parameters ")
        optimizer = torch.optim.SGD(
            [v for n, v in parameters],
            lr,
            momentum=momentum,
            weight_decay=weight_decay,
            nesterov=nesterov,
        )
    else:
        print(" ! Weight decay NOT applied to BN parameters ")
        bn_params = [v for n, v in parameters if "bn" in n]
        rest_params = [v for n, v in parameters if not "bn" in n]
        print(len(bn_params))
        print(len(rest_params))
        optimizer = torch.optim.SGD(
            [
                {"params": bn_params, "weight_decay": 0},
                {"params": rest_params, "weight_decay": weight_decay},
            ],
            lr,
            momentum=momentum,
            weight_decay=weight_decay,
            nesterov=nesterov,
        )
    if fp16:
        optimizer = FP16_Optimizer(
            optimizer,
            static_loss_scale=static_loss_scale,
            dynamic_loss_scale=dynamic_loss_scale,
            verbose=False,
        )

=======
def get_optimizer(parameters, lr, args, state=None):
    if args.optimizer == 'sgd':
        optimizer = get_sgd_optimizer(parameters, lr, momentum=args.momentum,
                                      weight_decay=args.weight_decay, nesterov=args.nesterov,
                                      bn_weight_decay=args.bn_weight_decay)
    elif args.optimizer == 'rmsprop':
        optimizer = get_rmsprop_optimizer(parameters, lr, alpha=args.rmsprop_alpha, momentum=args.momentum,
                                          weight_decay=args.weight_decay,
                                          eps=args.rmsprop_eps,
                                          bn_weight_decay=args.bn_weight_decay)
>>>>>>> repo1
    if not state is None:
        optimizer.load_state_dict(state)

    return optimizer


def lr_policy(lr_fn, logger=None):
    if logger is not None:
        logger.register_metric(
            "lr", log.LR_METER(), verbosity=dllogger.Verbosity.VERBOSE
        )

    def _alr(optimizer, iteration, epoch):
        lr = lr_fn(iteration, epoch)

        if logger is not None:
            logger.log_metric("lr", lr)
        for param_group in optimizer.param_groups:
            param_group["lr"] = lr

    return _alr


def lr_step_policy(base_lr, steps, decay_factor, warmup_length, logger=None):
    def _lr_fn(iteration, epoch):
        if epoch < warmup_length:
            lr = base_lr * (epoch + 1) / warmup_length
        else:
            lr = base_lr
            for s in steps:
                if epoch >= s:
                    lr *= decay_factor
        return lr

    return lr_policy(_lr_fn, logger=logger)


def lr_linear_policy(base_lr, warmup_length, epochs, logger=None):
    def _lr_fn(iteration, epoch):
        if epoch < warmup_length:
            lr = base_lr * (epoch + 1) / warmup_length
        else:
            e = epoch - warmup_length
            es = epochs - warmup_length
            lr = base_lr * (1 - (e / es))
        return lr

    return lr_policy(_lr_fn, logger=logger)


<<<<<<< HEAD
def lr_cosine_policy(base_lr, warmup_length, epochs, logger=None):
=======
def lr_cosine_policy(base_lr, warmup_length, epochs, end_lr = 0, logger=None):
>>>>>>> repo1
    def _lr_fn(iteration, epoch):
        if epoch < warmup_length:
            lr = base_lr * (epoch + 1) / warmup_length
        else:
            e = epoch - warmup_length
            es = epochs - warmup_length
<<<<<<< HEAD
            lr = 0.5 * (1 + np.cos(np.pi * e / es)) * base_lr
=======
            lr = end_lr + (0.5 * (1 + np.cos(np.pi * e / es)) * (base_lr - end_lr))
>>>>>>> repo1
        return lr

    return lr_policy(_lr_fn, logger=logger)


def lr_exponential_policy(
<<<<<<< HEAD
    base_lr, warmup_length, epochs, final_multiplier=0.001, logger=None
):
    es = epochs - warmup_length
    epoch_decay = np.power(2, np.log2(final_multiplier) / es)
=======
    base_lr, warmup_length, epochs, final_multiplier=0.001, decay_factor=None, decay_step=1, logger=None
):
    """Exponential lr policy. Setting decay factor parameter overrides final_multiplier"""
    es = epochs - warmup_length

    if decay_factor is not None:
        epoch_decay = decay_factor
    else:
        epoch_decay = np.power(2, np.log2(final_multiplier) / math.floor(es/decay_step))
>>>>>>> repo1

    def _lr_fn(iteration, epoch):
        if epoch < warmup_length:
            lr = base_lr * (epoch + 1) / warmup_length
        else:
            e = epoch - warmup_length
<<<<<<< HEAD
            lr = base_lr * (epoch_decay ** e)
=======
            lr = base_lr * (epoch_decay ** math.floor(e/decay_step))
>>>>>>> repo1
        return lr

    return lr_policy(_lr_fn, logger=logger)


def get_train_step(
<<<<<<< HEAD
    model_and_loss, optimizer, fp16, use_amp=False, batch_size_multiplier=1
=======
    model_and_loss, optimizer, scaler, use_amp=False, batch_size_multiplier=1
>>>>>>> repo1
):
    def _step(input, target, optimizer_step=True):
        input_var = Variable(input)
        target_var = Variable(target)
<<<<<<< HEAD
        loss, output = model_and_loss(input_var, target_var)
        if torch.distributed.is_initialized():
            reduced_loss = utils.reduce_tensor(loss.data)
        else:
            reduced_loss = loss.data

        if fp16:
            optimizer.backward(loss)
        elif use_amp:
            with amp.scale_loss(loss, optimizer) as scaled_loss:
                scaled_loss.backward()
        else:
            loss.backward()

        if optimizer_step:
            opt = (
                optimizer.optimizer
                if isinstance(optimizer, FP16_Optimizer)
                else optimizer
            )
            for param_group in opt.param_groups:
                for param in param_group["params"]:
                    param.grad /= batch_size_multiplier

            optimizer.step()
=======

        with autocast(enabled=use_amp):
            loss, output = model_and_loss(input_var, target_var)
            loss /= batch_size_multiplier
            if torch.distributed.is_initialized():
                reduced_loss = utils.reduce_tensor(loss.data)
            else:
                reduced_loss = loss.data

        scaler.scale(loss).backward()

        if optimizer_step:
            scaler.step(optimizer)
            scaler.update()
>>>>>>> repo1
            optimizer.zero_grad()

        torch.cuda.synchronize()

        return reduced_loss

    return _step


def train(
    train_loader,
    model_and_loss,
    optimizer,
<<<<<<< HEAD
    lr_scheduler,
    fp16,
    logger,
    epoch,
=======
    scaler,
    lr_scheduler,
    logger,
    epoch,
    steps_per_epoch,
    timeout_handler,
    ema=None,
>>>>>>> repo1
    use_amp=False,
    prof=-1,
    batch_size_multiplier=1,
    register_metrics=True,
):
<<<<<<< HEAD

=======
    interrupted = False
>>>>>>> repo1
    if register_metrics and logger is not None:
        logger.register_metric(
            "train.loss",
            log.LOSS_METER(),
            verbosity=dllogger.Verbosity.DEFAULT,
            metadata=LOSS_METADATA,
        )
        logger.register_metric(
            "train.compute_ips",
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=IPS_METADATA,
        )
        logger.register_metric(
            "train.total_ips",
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.DEFAULT,
            metadata=IPS_METADATA,
        )
        logger.register_metric(
            "train.data_time",
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=TIME_METADATA,
        )
        logger.register_metric(
            "train.compute_time",
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=TIME_METADATA,
        )

    step = get_train_step(
        model_and_loss,
        optimizer,
<<<<<<< HEAD
        fp16,
=======
        scaler=scaler,
>>>>>>> repo1
        use_amp=use_amp,
        batch_size_multiplier=batch_size_multiplier,
    )

    model_and_loss.train()
    end = time.time()

    optimizer.zero_grad()

    data_iter = enumerate(train_loader)
    if logger is not None:
<<<<<<< HEAD
        data_iter = logger.iteration_generator_wrapper(data_iter)
    if prof > 0:
        data_iter = utils.first_n(prof, data_iter)
=======
        data_iter = logger.iteration_generator_wrapper(data_iter, mode='train')
>>>>>>> repo1

    for i, (input, target) in data_iter:
        bs = input.size(0)
        lr_scheduler(optimizer, i, epoch)
        data_time = time.time() - end

        optimizer_step = ((i + 1) % batch_size_multiplier) == 0
        loss = step(input, target, optimizer_step=optimizer_step)
<<<<<<< HEAD
=======
        if ema is not None:
            ema(model_and_loss, epoch*steps_per_epoch+i)
>>>>>>> repo1

        it_time = time.time() - end

        if logger is not None:
<<<<<<< HEAD
            logger.log_metric("train.loss", to_python_float(loss), bs)
            logger.log_metric("train.compute_ips", calc_ips(bs, it_time - data_time))
            logger.log_metric("train.total_ips", calc_ips(bs, it_time))
=======
            logger.log_metric("train.loss", loss.item(), bs)
            logger.log_metric("train.compute_ips", utils.calc_ips(bs, it_time - data_time))
            logger.log_metric("train.total_ips", utils.calc_ips(bs, it_time))
>>>>>>> repo1
            logger.log_metric("train.data_time", data_time)
            logger.log_metric("train.compute_time", it_time - data_time)

        end = time.time()
<<<<<<< HEAD


def get_val_step(model_and_loss):
=======
        if prof > 0 and (i + 1 >= prof):
            time.sleep(5)
            break
        if ((i+1) % 20 == 0) and timeout_handler.interrupted:
            time.sleep(5)
            interrupted = True
            break

    return interrupted


def get_val_step(model_and_loss, use_amp=False):
>>>>>>> repo1
    def _step(input, target):
        input_var = Variable(input)
        target_var = Variable(target)

<<<<<<< HEAD
        with torch.no_grad():
            loss, output = model_and_loss(input_var, target_var)

        prec1, prec5 = utils.accuracy(output.data, target, topk=(1, 5))

        if torch.distributed.is_initialized():
            reduced_loss = utils.reduce_tensor(loss.data)
            prec1 = utils.reduce_tensor(prec1)
            prec5 = utils.reduce_tensor(prec5)
        else:
            reduced_loss = loss.data
=======
        with torch.no_grad(), autocast(enabled=use_amp):
            loss, output = model_and_loss(input_var, target_var)

            prec1, prec5 = utils.accuracy(output.data, target, topk=(1, 5))

            if torch.distributed.is_initialized():
                reduced_loss = utils.reduce_tensor(loss.data)
                prec1 = utils.reduce_tensor(prec1)
                prec5 = utils.reduce_tensor(prec5)
            else:
                reduced_loss = loss.data
>>>>>>> repo1

        torch.cuda.synchronize()

        return reduced_loss, prec1, prec5

    return _step


def validate(
<<<<<<< HEAD
    val_loader, model_and_loss, fp16, logger, epoch, prof=-1, register_metrics=True
):
    if register_metrics and logger is not None:
        logger.register_metric(
            "val.top1",
=======
    val_loader,
    model_and_loss,
    logger,
    epoch,
    use_amp=False,
    prof=-1,
    register_metrics=True,
    prefix="val",
):
    if register_metrics and logger is not None:
        logger.register_metric(
            f"{prefix}.top1",
>>>>>>> repo1
            log.ACC_METER(),
            verbosity=dllogger.Verbosity.DEFAULT,
            metadata=ACC_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.top5",
=======
            f"{prefix}.top5",
>>>>>>> repo1
            log.ACC_METER(),
            verbosity=dllogger.Verbosity.DEFAULT,
            metadata=ACC_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.loss",
=======
            f"{prefix}.loss",
>>>>>>> repo1
            log.LOSS_METER(),
            verbosity=dllogger.Verbosity.DEFAULT,
            metadata=LOSS_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.compute_ips",
=======
            f"{prefix}.compute_ips",
>>>>>>> repo1
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=IPS_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.total_ips",
=======
            f"{prefix}.total_ips",
>>>>>>> repo1
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.DEFAULT,
            metadata=IPS_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.data_time",
=======
            f"{prefix}.data_time",
>>>>>>> repo1
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=TIME_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.compute_latency",
=======
            f"{prefix}.compute_latency",
>>>>>>> repo1
            log.PERF_METER(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=TIME_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.compute_latency_at100",
=======
            f"{prefix}.compute_latency_at100",
>>>>>>> repo1
            log.LAT_100(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=TIME_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.compute_latency_at99",
=======
            f"{prefix}.compute_latency_at99",
>>>>>>> repo1
            log.LAT_99(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=TIME_METADATA,
        )
        logger.register_metric(
<<<<<<< HEAD
            "val.compute_latency_at95",
=======
            f"{prefix}.compute_latency_at95",
>>>>>>> repo1
            log.LAT_95(),
            verbosity=dllogger.Verbosity.VERBOSE,
            metadata=TIME_METADATA,
        )

<<<<<<< HEAD
    step = get_val_step(model_and_loss)
=======
    step = get_val_step(model_and_loss, use_amp=use_amp)
>>>>>>> repo1

    top1 = log.AverageMeter()
    # switch to evaluate mode
    model_and_loss.eval()

    end = time.time()

    data_iter = enumerate(val_loader)
    if not logger is None:
<<<<<<< HEAD
        data_iter = logger.iteration_generator_wrapper(data_iter, val=True)
    if prof > 0:
        data_iter = utils.first_n(prof, data_iter)
=======
        data_iter = logger.iteration_generator_wrapper(data_iter, mode='val')
>>>>>>> repo1

    for i, (input, target) in data_iter:
        bs = input.size(0)
        data_time = time.time() - end

        loss, prec1, prec5 = step(input, target)

        it_time = time.time() - end

<<<<<<< HEAD
        top1.record(to_python_float(prec1), bs)
        if logger is not None:
            logger.log_metric("val.top1", to_python_float(prec1), bs)
            logger.log_metric("val.top5", to_python_float(prec5), bs)
            logger.log_metric("val.loss", to_python_float(loss), bs)
            logger.log_metric("val.compute_ips", calc_ips(bs, it_time - data_time))
            logger.log_metric("val.total_ips", calc_ips(bs, it_time))
            logger.log_metric("val.data_time", data_time)
            logger.log_metric("val.compute_latency", it_time - data_time)
            logger.log_metric("val.compute_latency_at95", it_time - data_time)
            logger.log_metric("val.compute_latency_at99", it_time - data_time)
            logger.log_metric("val.compute_latency_at100", it_time - data_time)

        end = time.time()
=======
        top1.record(prec1.item(), bs)
        if logger is not None:
            logger.log_metric(f"{prefix}.top1", prec1.item(), bs)
            logger.log_metric(f"{prefix}.top5", prec5.item(), bs)
            logger.log_metric(f"{prefix}.loss", loss.item(), bs)
            logger.log_metric(f"{prefix}.compute_ips", utils.calc_ips(bs, it_time - data_time))
            logger.log_metric(f"{prefix}.total_ips", utils.calc_ips(bs, it_time))
            logger.log_metric(f"{prefix}.data_time", data_time)
            logger.log_metric(f"{prefix}.compute_latency", it_time - data_time)
            logger.log_metric(f"{prefix}.compute_latency_at95", it_time - data_time)
            logger.log_metric(f"{prefix}.compute_latency_at99", it_time - data_time)
            logger.log_metric(f"{prefix}.compute_latency_at100", it_time - data_time)

        end = time.time()
        if (prof > 0) and (i + 1 >= prof):
            time.sleep(5)
            break
>>>>>>> repo1

    return top1.get_val()


# Train loop {{{
<<<<<<< HEAD
def calc_ips(batch_size, time):
    world_size = (
        torch.distributed.get_world_size() if torch.distributed.is_initialized() else 1
    )
    tbs = world_size * batch_size
    return tbs / time
=======
>>>>>>> repo1


def train_loop(
    model_and_loss,
    optimizer,
<<<<<<< HEAD
    lr_scheduler,
    train_loader,
    val_loader,
    fp16,
    logger,
    should_backup_checkpoint,
=======
    scaler,
    lr_scheduler,
    train_loader,
    val_loader,
    logger,
    should_backup_checkpoint,
    steps_per_epoch,
    ema=None,
    model_ema=None,
>>>>>>> repo1
    use_amp=False,
    batch_size_multiplier=1,
    best_prec1=0,
    start_epoch=0,
    end_epoch=0,
<<<<<<< HEAD
=======
    early_stopping_patience=-1,
>>>>>>> repo1
    prof=-1,
    skip_training=False,
    skip_validation=False,
    save_checkpoints=True,
    checkpoint_dir="./",
    checkpoint_filename="checkpoint.pth.tar",
):
<<<<<<< HEAD

    prec1 = -1

    print(f"RUNNING EPOCHS FROM {start_epoch} TO {end_epoch}")
    for epoch in range(start_epoch, end_epoch):
        if logger is not None:
            logger.start_epoch()
        if not skip_training:
            train(
                train_loader,
                model_and_loss,
                optimizer,
                lr_scheduler,
                fp16,
                logger,
                epoch,
                use_amp=use_amp,
                prof=prof,
                register_metrics=epoch == start_epoch,
                batch_size_multiplier=batch_size_multiplier,
            )

        if not skip_validation:
            prec1, nimg = validate(
                val_loader,
                model_and_loss,
                fp16,
                logger,
                epoch,
                prof=prof,
                register_metrics=epoch == start_epoch,
            )
        if logger is not None:
            logger.end_epoch()

        if save_checkpoints and (
            not torch.distributed.is_initialized() or torch.distributed.get_rank() == 0
        ):
            if not skip_validation:
                is_best = logger.metrics["val.top1"]["meter"].get_epoch() > best_prec1
                best_prec1 = max(
                    logger.metrics["val.top1"]["meter"].get_epoch(), best_prec1
                )
            else:
                is_best = False
                best_prec1 = 0

            if should_backup_checkpoint(epoch):
                backup_filename = "checkpoint-{}.pth.tar".format(epoch + 1)
            else:
                backup_filename = None
            utils.save_checkpoint(
                {
                    "epoch": epoch + 1,
                    "arch": model_and_loss.arch,
                    "state_dict": model_and_loss.model.state_dict(),
                    "best_prec1": best_prec1,
                    "optimizer": optimizer.state_dict(),
                },
                is_best,
                checkpoint_dir=checkpoint_dir,
                backup_filename=backup_filename,
                filename=checkpoint_filename,
            )


=======
    prec1 = -1
    use_ema = (model_ema is not None) and (ema is not None)

    if early_stopping_patience > 0:
        epochs_since_improvement = 0
    backup_prefix = checkpoint_filename[:-len("checkpoint.pth.tar")] if \
        checkpoint_filename.endswith("checkpoint.pth.tar") else ""
    
    print(f"RUNNING EPOCHS FROM {start_epoch} TO {end_epoch}")
    with utils.TimeoutHandler() as timeout_handler:
        interrupted = False
        for epoch in range(start_epoch, end_epoch):
            if logger is not None:
                logger.start_epoch()
            if not skip_training:
                interrupted = train(
                    train_loader,
                    model_and_loss,
                    optimizer,
                    scaler,
                    lr_scheduler,
                    logger,
                    epoch,
                    steps_per_epoch,
                    timeout_handler,
                    ema=ema,
                    use_amp=use_amp,
                    prof=prof,
                    register_metrics=epoch == start_epoch,
                    batch_size_multiplier=batch_size_multiplier,
                )

            if not skip_validation:
                prec1, nimg = validate(
                    val_loader,
                    model_and_loss,
                    logger,
                    epoch,
                    use_amp=use_amp,
                    prof=prof,
                    register_metrics=epoch == start_epoch,
                )
                if use_ema:
                    model_ema.load_state_dict({k.replace('module.', ''): v for k, v in ema.state_dict().items()})
                    prec1, nimg = validate(
                        val_loader,
                        model_ema,
                        logger,
                        epoch,
                        prof=prof,
                        register_metrics=epoch == start_epoch,
                        prefix='val_ema'
                    )

                if prec1 > best_prec1:
                    is_best = True
                    best_prec1 = prec1
                else:
                    is_best = False
            else:
                is_best = True
                best_prec1 = 0

            if logger is not None:
                logger.end_epoch()

            if save_checkpoints and (
                not torch.distributed.is_initialized() or torch.distributed.get_rank() == 0
            ):
                if should_backup_checkpoint(epoch):
                    backup_filename = "{}checkpoint-{}.pth.tar".format(backup_prefix, epoch + 1)
                else:
                    backup_filename = None
                checkpoint_state = {
                    "epoch": epoch + 1,
                    "state_dict": model_and_loss.model.state_dict(),
                    "best_prec1": best_prec1,
                    "optimizer": optimizer.state_dict(),
                }
                if use_ema:
                    checkpoint_state["state_dict_ema"] = ema.state_dict()

                utils.save_checkpoint(
                    checkpoint_state,
                    is_best,
                    checkpoint_dir=checkpoint_dir,
                    backup_filename=backup_filename,
                    filename=checkpoint_filename,
                )
            if early_stopping_patience > 0:
                if not is_best:
                    epochs_since_improvement += 1
                else:
                    epochs_since_improvement = 0
                if epochs_since_improvement >= early_stopping_patience:
                    break
            if interrupted:
                break
>>>>>>> repo1
# }}}
