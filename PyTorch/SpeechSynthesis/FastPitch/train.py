# *****************************************************************************
#  Copyright (c) 2020, NVIDIA CORPORATION.  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#      * Redistributions of source code must retain the above copyright
#        notice, this list of conditions and the following disclaimer.
#      * Redistributions in binary form must reproduce the above copyright
#        notice, this list of conditions and the following disclaimer in the
#        documentation and/or other materials provided with the distribution.
#      * Neither the name of the NVIDIA CORPORATION nor the
#        names of its contributors may be used to endorse or promote products
#        derived from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#  DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE FOR ANY
#  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# *****************************************************************************

import argparse
import copy
import json
import glob
import os
import re
import time
from collections import defaultdict, OrderedDict
from contextlib import contextmanager

<<<<<<< HEAD
import torch
import numpy as np
=======
import numpy as np
import nvidia_dlprof_pytorch_nvtx as pyprof
import torch
import torch.cuda.profiler as profiler
>>>>>>> repo1
import torch.distributed as dist
from scipy.io.wavfile import write as write_wav
from torch.autograd import Variable
from torch.nn.parallel import DistributedDataParallel
from torch.nn.parameter import Parameter
from torch.utils.data import DataLoader
from torch.utils.data.distributed import DistributedSampler

<<<<<<< HEAD
import dllogger as DLLogger
from apex import amp
from apex.optimizers import FusedAdam, FusedLAMB
=======
import common.tb_dllogger as logger
from apex import amp
from apex.optimizers import FusedAdam, FusedLAMB
from apex.multi_tensor_apply import multi_tensor_applier
import amp_C
>>>>>>> repo1

import common
import data_functions
import loss_functions
import models
<<<<<<< HEAD
from common.log_helper import init_dllogger, TBLogger, unique_dllogger_fpath
=======
>>>>>>> repo1


def parse_args(parser):
    """
    Parse commandline arguments.
    """
    parser.add_argument('-o', '--output', type=str, required=True,
                        help='Directory to save checkpoints')
    parser.add_argument('-d', '--dataset-path', type=str, default='./',
                        help='Path to dataset')
    parser.add_argument('--log-file', type=str, default=None,
                        help='Path to a DLLogger log file')
<<<<<<< HEAD
=======
    parser.add_argument('--pyprof', action='store_true', help='Enable pyprof profiling')
>>>>>>> repo1

    training = parser.add_argument_group('training setup')
    training.add_argument('--epochs', type=int, required=True,
                          help='Number of total epochs to run')
    training.add_argument('--epochs-per-checkpoint', type=int, default=50,
                          help='Number of epochs per checkpoint')
    training.add_argument('--checkpoint-path', type=str, default=None,
                          help='Checkpoint path to resume training')
    training.add_argument('--resume', action='store_true',
                          help='Resume training from the last available checkpoint')
    training.add_argument('--seed', type=int, default=1234,
                          help='Seed for PyTorch random number generators')
    training.add_argument('--amp', action='store_true',
                          help='Enable AMP')
    training.add_argument('--cuda', action='store_true',
                          help='Run on GPU using CUDA')
<<<<<<< HEAD
    training.add_argument('--cudnn-enabled', action='store_true',
                          help='Enable cudnn')
    training.add_argument('--cudnn-benchmark', action='store_true',
                          help='Run cudnn benchmark')
=======
    training.add_argument('--cudnn-benchmark', action='store_true',
                          help='Enable cudnn benchmark mode')
>>>>>>> repo1
    training.add_argument('--ema-decay', type=float, default=0,
                          help='Discounting factor for training weights EMA')
    training.add_argument('--gradient-accumulation-steps', type=int, default=1,
                          help='Training steps to accumulate gradients for')

    optimization = parser.add_argument_group('optimization setup')
    optimization.add_argument('--optimizer', type=str, default='lamb',
                              help='Optimization algorithm')
    optimization.add_argument('-lr', '--learning-rate', type=float, required=True,
                              help='Learing rate')
    optimization.add_argument('--weight-decay', default=1e-6, type=float,
                              help='Weight decay')
    optimization.add_argument('--grad-clip-thresh', default=1000.0, type=float,
                              help='Clip threshold for gradients')
    optimization.add_argument('-bs', '--batch-size', type=int, required=True,
                              help='Batch size per GPU')
    optimization.add_argument('--warmup-steps', type=int, default=1000,
                              help='Number of steps for lr warmup')
    optimization.add_argument('--dur-predictor-loss-scale', type=float,
                              default=1.0, help='Rescale duration predictor loss')
    optimization.add_argument('--pitch-predictor-loss-scale', type=float,
                              default=1.0, help='Rescale pitch predictor loss')

    dataset = parser.add_argument_group('dataset parameters')
    dataset.add_argument('--training-files', type=str, required=True,
<<<<<<< HEAD
                         help='Path to training filelist')
    dataset.add_argument('--validation-files', type=str, required=True,
                         help='Path to validation filelist')
=======
                         help='Path to training filelist. Separate multiple paths with commas.')
    dataset.add_argument('--validation-files', type=str, required=True,
                         help='Path to validation filelist. Separate multiple paths with commas.')
>>>>>>> repo1
    dataset.add_argument('--pitch-mean-std-file', type=str, default=None,
                         help='Path to pitch stats to be stored in the model')
    dataset.add_argument('--text-cleaners', nargs='*',
                         default=['english_cleaners'], type=str,
                         help='Type of text cleaners for input text')
<<<<<<< HEAD
=======
    dataset.add_argument('--symbol-set', type=str, default='english_basic',
                         help='Define symbol set for input text')

    cond = parser.add_argument_group('conditioning on additional attributes')
    cond.add_argument('--n-speakers', type=int, default=1,
                      help='Condition on speaker, value > 1 enables trainable speaker embeddings.')
>>>>>>> repo1

    distributed = parser.add_argument_group('distributed setup')
    distributed.add_argument('--local_rank', type=int, default=os.getenv('LOCAL_RANK', 0),
                             help='Rank of the process for multiproc. Do not set manually.')
    distributed.add_argument('--world_size', type=int, default=os.getenv('WORLD_SIZE', 1),
                             help='Number of processes for multiproc. Do not set manually.')
    return parser


def reduce_tensor(tensor, num_gpus):
    rt = tensor.clone()
    dist.all_reduce(rt, op=dist.ReduceOp.SUM)
<<<<<<< HEAD
    rt /= num_gpus
    return rt
=======
    return rt.true_divide(num_gpus)
>>>>>>> repo1


def init_distributed(args, world_size, rank):
    assert torch.cuda.is_available(), "Distributed mode requires CUDA."
    print("Initializing distributed training")

    # Set cuda device so everything is done on the right GPU.
    torch.cuda.set_device(rank % torch.cuda.device_count())

    # Initialize distributed communication
    dist.init_process_group(backend=('nccl' if args.cuda else 'gloo'),
                            init_method='env://')
    print("Done initializing distributed training")


def last_checkpoint(output):

    def corrupted(fpath):
        try:
            torch.load(fpath, map_location='cpu')
            return False
        except:
            print(f'WARNING: Cannot load {fpath}')
            return True

    saved = sorted(
        glob.glob(f'{output}/FastPitch_checkpoint_*.pt'),
        key=lambda f: int(re.search('_(\d+).pt', f).group(1)))

    if len(saved) >= 1 and not corrupted(saved[-1]):
        return saved[-1]
    elif len(saved) >= 2:
        return saved[-2]
    else:
        return None


def save_checkpoint(local_rank, model, ema_model, optimizer, epoch, total_iter,
                    config, amp_run, filepath):
    if local_rank != 0:
        return
<<<<<<< HEAD
=======

>>>>>>> repo1
    print(f"Saving model and optimizer state at epoch {epoch} to {filepath}")
    ema_dict = None if ema_model is None else ema_model.state_dict()
    checkpoint = {'epoch': epoch,
                  'iteration': total_iter,
                  'config': config,
                  'state_dict': model.state_dict(),
                  'ema_state_dict': ema_dict,
                  'optimizer': optimizer.state_dict()}
    if amp_run:
        checkpoint['amp'] = amp.state_dict()
    torch.save(checkpoint, filepath)


def load_checkpoint(local_rank, model, ema_model, optimizer, epoch, total_iter,
                    config, amp_run, filepath, world_size):
    if local_rank == 0:
        print(f'Loading model and optimizer state from {filepath}')
    checkpoint = torch.load(filepath, map_location='cpu')
    epoch[0] = checkpoint['epoch'] + 1
    total_iter[0] = checkpoint['iteration']
    config = checkpoint['config']

    sd = {k.replace('module.', ''): v
          for k, v in checkpoint['state_dict'].items()}
    getattr(model, 'module', model).load_state_dict(sd)
    optimizer.load_state_dict(checkpoint['optimizer'])

    if amp_run:
        amp.load_state_dict(checkpoint['amp'])

    if ema_model is not None:
        ema_model.load_state_dict(checkpoint['ema_state_dict'])


<<<<<<< HEAD
def validate(model, criterion, valset, batch_size, world_size, collate_fn,
             distributed_run, rank, batch_to_gpu, use_gt_durations=False):
    """Handles all the validation scoring and printing"""
    was_training = model.training
    model.eval()
=======
def validate(model, epoch, total_iter, criterion, valset, batch_size,
             collate_fn, distributed_run, batch_to_gpu, use_gt_durations=False,
             ema=False):
    """Handles all the validation scoring and printing"""
    was_training = model.training
    model.eval()

    tik = time.perf_counter()
>>>>>>> repo1
    with torch.no_grad():
        val_sampler = DistributedSampler(valset) if distributed_run else None
        val_loader = DataLoader(valset, num_workers=8, shuffle=False,
                                sampler=val_sampler,
                                batch_size=batch_size, pin_memory=False,
                                collate_fn=collate_fn)
        val_meta = defaultdict(float)
        val_num_frames = 0
        for i, batch in enumerate(val_loader):
            x, y, num_frames = batch_to_gpu(batch)
            y_pred = model(x, use_gt_durations=use_gt_durations)
            loss, meta = criterion(y_pred, y, is_training=False, meta_agg='sum')
<<<<<<< HEAD
=======

>>>>>>> repo1
            if distributed_run:
                for k,v in meta.items():
                    val_meta[k] += reduce_tensor(v, 1)
                val_num_frames += reduce_tensor(num_frames.data, 1).item()
            else:
                for k,v in meta.items():
                    val_meta[k] += v
                val_num_frames = num_frames.item()
<<<<<<< HEAD
        val_meta = {k: v / len(valset) for k,v in val_meta.items()}
        val_loss = val_meta['loss']

    if was_training:
        model.train()
    return val_loss.item(), val_meta, val_num_frames
=======

        val_meta = {k: v / len(valset) for k,v in val_meta.items()}

    val_meta['took'] = time.perf_counter() - tik

    logger.log((epoch,) if epoch is not None else (),
               tb_total_steps=total_iter,
               subset='val_ema' if ema else 'val',
               data=OrderedDict([
                   ('loss', val_meta['loss'].item()),
                   ('mel_loss', val_meta['mel_loss'].item()),
                   ('frames/s', num_frames.item() / val_meta['took']),
                   ('took', val_meta['took'])]),
    )

    if was_training:
        model.train()
    return val_meta
>>>>>>> repo1


def adjust_learning_rate(total_iter, opt, learning_rate, warmup_iters=None):
    if warmup_iters == 0:
        scale = 1.0
    elif total_iter > warmup_iters:
        scale = 1. / (total_iter ** 0.5)
    else:
        scale = total_iter / (warmup_iters ** 1.5)

    for param_group in opt.param_groups:
        param_group['lr'] = learning_rate * scale


def apply_ema_decay(model, ema_model, decay):
    if not decay:
        return
    st = model.state_dict()
    add_module = hasattr(model, 'module') and not hasattr(ema_model, 'module')
    for k,v in ema_model.state_dict().items():
        if add_module and not k.startswith('module.'):
            k = 'module.' + k
        v.copy_(decay * v + (1 - decay) * st[k])


<<<<<<< HEAD
=======
def apply_multi_tensor_ema(model_weight_list, ema_model_weight_list, decay, overflow_buf):
    if not decay:
        return
    amp_C.multi_tensor_axpby(65536, overflow_buf, [ema_model_weight_list, model_weight_list, ema_model_weight_list], decay, 1-decay, -1)


>>>>>>> repo1
def main():
    parser = argparse.ArgumentParser(description='PyTorch FastPitch Training',
                                     allow_abbrev=False)
    parser = parse_args(parser)
    args, _ = parser.parse_known_args()

<<<<<<< HEAD
    if 'LOCAL_RANK' in os.environ and 'WORLD_SIZE' in os.environ:
        local_rank = int(os.environ['LOCAL_RANK'])
        world_size = int(os.environ['WORLD_SIZE'])
    else:
        local_rank = args.rank
        world_size = args.world_size
    distributed_run = world_size > 1

    torch.manual_seed(args.seed + local_rank)
    np.random.seed(args.seed + local_rank)

    if local_rank == 0:
        if not os.path.exists(args.output):
            os.makedirs(args.output)

        log_fpath = args.log_file or os.path.join(args.output, 'nvlog.json')
        log_fpath = unique_dllogger_fpath(log_fpath)
        init_dllogger(log_fpath)
    else:
        init_dllogger(dummy=True)

    [DLLogger.log("PARAMETER", {k:v}) for k,v in vars(args).items()]
=======
    distributed_run = args.world_size > 1

    torch.manual_seed(args.seed + args.local_rank)
    np.random.seed(args.seed + args.local_rank)

    if args.local_rank == 0:
        if not os.path.exists(args.output):
            os.makedirs(args.output)

    log_fpath = args.log_file or os.path.join(args.output, 'nvlog.json')
    tb_subsets = ['train', 'val']
    if args.ema_decay > 0.0:
        tb_subsets.append('val_ema')

    logger.init(log_fpath, args.output, enabled=(args.local_rank == 0),
                tb_subsets=tb_subsets)
    logger.parameters(vars(args), tb_subset='train')
>>>>>>> repo1

    parser = models.parse_model_args('FastPitch', parser)
    args, unk_args = parser.parse_known_args()
    if len(unk_args) > 0:
        raise ValueError(f'Invalid options {unk_args}')

<<<<<<< HEAD
    torch.backends.cudnn.enabled = args.cudnn_enabled
    torch.backends.cudnn.benchmark = args.cudnn_benchmark

    if distributed_run:
        init_distributed(args, world_size, local_rank)
=======
    torch.backends.cudnn.benchmark = args.cudnn_benchmark

    if distributed_run:
        init_distributed(args, args.world_size, args.local_rank)
>>>>>>> repo1

    device = torch.device('cuda' if args.cuda else 'cpu')
    model_config = models.get_model_config('FastPitch', args)
    model = models.get_model('FastPitch', model_config, device)

    # Store pitch mean/std as params to translate from Hz during inference
<<<<<<< HEAD
    fpath = common.utils.stats_filename(
        args.dataset_path, args.training_files, 'pitch_char')
=======
>>>>>>> repo1
    with open(args.pitch_mean_std_file, 'r') as f:
        stats = json.load(f)
    model.pitch_mean[0] = stats['mean']
    model.pitch_std[0] = stats['std']

    kw = dict(lr=args.learning_rate, betas=(0.9, 0.98), eps=1e-9,
              weight_decay=args.weight_decay)
    if args.optimizer == 'adam':
        optimizer = FusedAdam(model.parameters(), **kw)
    elif args.optimizer == 'lamb':
        optimizer = FusedLAMB(model.parameters(), **kw)
    else:
        raise ValueError

    if args.amp:
        model, optimizer = amp.initialize(model, optimizer, opt_level="O1")

    if args.ema_decay > 0:
        ema_model = copy.deepcopy(model)
    else:
        ema_model = None

    if distributed_run:
        model = DistributedDataParallel(
            model, device_ids=[args.local_rank], output_device=args.local_rank,
            find_unused_parameters=True)

<<<<<<< HEAD
=======
    if args.pyprof:
        pyprof.init(enable_function_stack=True)

>>>>>>> repo1
    start_epoch = [1]
    start_iter = [0]

    assert args.checkpoint_path is None or args.resume is False, (
        "Specify a single checkpoint source")
    if args.checkpoint_path is not None:
        ch_fpath = args.checkpoint_path
    elif args.resume:
        ch_fpath = last_checkpoint(args.output)
    else:
        ch_fpath = None

    if ch_fpath is not None:
<<<<<<< HEAD
        load_checkpoint(local_rank, model, ema_model, optimizer, start_epoch,
                        start_iter, model_config, args.amp, ch_fpath,
                        world_size)
=======
        load_checkpoint(args.local_rank, model, ema_model, optimizer, start_epoch,
                        start_iter, model_config, args.amp, ch_fpath,
                        args.world_size)
>>>>>>> repo1

    start_epoch = start_epoch[0]
    total_iter = start_iter[0]

    criterion = loss_functions.get_loss_function('FastPitch',
        dur_predictor_loss_scale=args.dur_predictor_loss_scale,
        pitch_predictor_loss_scale=args.pitch_predictor_loss_scale)

    collate_fn = data_functions.get_collate_function('FastPitch')
<<<<<<< HEAD
    trainset = data_functions.get_data_loader('FastPitch', args.dataset_path,
                                              args.training_files, args)
    valset = data_functions.get_data_loader('FastPitch', args.dataset_path,
                                            args.validation_files, args)
=======
    trainset = data_functions.get_data_loader('FastPitch',
                                              audiopaths_and_text=args.training_files,
                                              **vars(args))
    valset = data_functions.get_data_loader('FastPitch',
                                            audiopaths_and_text=args.validation_files,
                                            **vars(args))
>>>>>>> repo1
    if distributed_run:
        train_sampler, shuffle = DistributedSampler(trainset), False
    else:
        train_sampler, shuffle = None, True

    train_loader = DataLoader(trainset, num_workers=16, shuffle=shuffle,
                              sampler=train_sampler, batch_size=args.batch_size,
                              pin_memory=False, drop_last=True,
                              collate_fn=collate_fn)

    batch_to_gpu = data_functions.get_batch_to_gpu('FastPitch')

<<<<<<< HEAD
    model.train()

    train_tblogger = TBLogger(local_rank, args.output, 'train')
    val_tblogger = TBLogger(local_rank, args.output, 'val', dummies=True)
    if args.ema_decay > 0:
        val_ema_tblogger = TBLogger(local_rank, args.output, 'val_ema')

    val_loss = 0.0
    torch.cuda.synchronize()
    for epoch in range(start_epoch, args.epochs + 1):
        epoch_start_time = time.time()
=======
    if args.ema_decay:
        ema_model_weight_list, model_weight_list, overflow_buf_for_ema = init_multi_tensor_ema(model, ema_model)
    else:
        ema_model_weight_list, model_weight_list, overflow_buf_for_ema = None, None, None

    model.train()

    if args.pyprof:
        torch.autograd.profiler.emit_nvtx().__enter__()
        profiler.start()

    torch.cuda.synchronize()
    for epoch in range(start_epoch, args.epochs + 1):
        epoch_start_time = time.perf_counter()
>>>>>>> repo1

        epoch_loss = 0.0
        epoch_mel_loss = 0.0
        epoch_num_frames = 0
        epoch_frames_per_sec = 0.0

        if distributed_run:
            train_loader.sampler.set_epoch(epoch)

        accumulated_steps = 0
        iter_loss = 0
        iter_num_frames = 0
        iter_meta = {}

        epoch_iter = 0
        num_iters = len(train_loader) // args.gradient_accumulation_steps
        for batch in train_loader:
<<<<<<< HEAD
=======

>>>>>>> repo1
            if accumulated_steps == 0:
                if epoch_iter == num_iters:
                    break
                total_iter += 1
                epoch_iter += 1
<<<<<<< HEAD
                iter_start_time = time.time()
                start = time.perf_counter()

                old_lr = optimizer.param_groups[0]['lr']
                adjust_learning_rate(total_iter, optimizer, args.learning_rate,
                                     args.warmup_steps)
                new_lr = optimizer.param_groups[0]['lr']

                if new_lr != old_lr:
                    dllog_lrate_change = f'{old_lr:.2E} -> {new_lr:.2E}'
                    train_tblogger.log_value(total_iter, 'lrate', new_lr)
                else:
                    dllog_lrate_change = None
=======
                iter_start_time = time.perf_counter()

                adjust_learning_rate(total_iter, optimizer, args.learning_rate,
                                     args.warmup_steps)
>>>>>>> repo1

                model.zero_grad()

            x, y, num_frames = batch_to_gpu(batch)
            y_pred = model(x, use_gt_durations=True)
            loss, meta = criterion(y_pred, y)

            loss /= args.gradient_accumulation_steps
            meta = {k: v / args.gradient_accumulation_steps
                    for k, v in meta.items()}

            if args.amp:
                with amp.scale_loss(loss, optimizer) as scaled_loss:
                    scaled_loss.backward()
            else:
                loss.backward()

            if distributed_run:
<<<<<<< HEAD
                reduced_loss = reduce_tensor(loss.data, world_size).item()
                reduced_num_frames = reduce_tensor(num_frames.data, 1).item()
                meta = {k: reduce_tensor(v, world_size) for k,v in meta.items()}
=======
                reduced_loss = reduce_tensor(loss.data, args.world_size).item()
                reduced_num_frames = reduce_tensor(num_frames.data, 1).item()
                meta = {k: reduce_tensor(v, args.world_size) for k,v in meta.items()}
>>>>>>> repo1
            else:
                reduced_loss = loss.item()
                reduced_num_frames = num_frames.item()
            if np.isnan(reduced_loss):
                raise Exception("loss is NaN")

            accumulated_steps += 1
            iter_loss += reduced_loss
            iter_num_frames += reduced_num_frames
            iter_meta = {k: iter_meta.get(k, 0) + meta.get(k, 0) for k in meta}

            if accumulated_steps % args.gradient_accumulation_steps == 0:

<<<<<<< HEAD
                train_tblogger.log_grads(total_iter, model)
=======
                logger.log_grads_tb(total_iter, model)
>>>>>>> repo1
                if args.amp:
                    torch.nn.utils.clip_grad_norm_(
                        amp.master_params(optimizer), args.grad_clip_thresh)
                else:
                    torch.nn.utils.clip_grad_norm_(
                        model.parameters(), args.grad_clip_thresh)

                optimizer.step()
<<<<<<< HEAD
                apply_ema_decay(model, ema_model, args.ema_decay)

                iter_stop_time = time.time()
                iter_time = iter_stop_time - iter_start_time
                frames_per_sec = iter_num_frames / iter_time
                epoch_frames_per_sec += frames_per_sec
                epoch_loss += iter_loss
                epoch_num_frames += iter_num_frames
                iter_mel_loss = iter_meta['mel_loss'].item()
                epoch_mel_loss += iter_mel_loss

                DLLogger.log((epoch, epoch_iter, num_iters), OrderedDict([
                    ('train_loss', iter_loss), ('train_mel_loss', iter_mel_loss),
                    ('train_frames/s', frames_per_sec), ('took', iter_time),
                    ('lrate_change', dllog_lrate_change)
                ]))
                train_tblogger.log_meta(total_iter, iter_meta)
=======
                apply_multi_tensor_ema(model_weight_list, ema_model_weight_list, args.ema_decay, overflow_buf_for_ema)

                iter_time = time.perf_counter() - iter_start_time
                iter_mel_loss = iter_meta['mel_loss'].item()
                epoch_frames_per_sec += iter_num_frames / iter_time
                epoch_loss += iter_loss
                epoch_num_frames += iter_num_frames
                epoch_mel_loss += iter_mel_loss

                logger.log((epoch, epoch_iter, num_iters),
                           tb_total_steps=total_iter,
                           subset='train',
                           data=OrderedDict([
                               ('loss', iter_loss),
                               ('mel_loss', iter_mel_loss),
                               ('frames/s', iter_num_frames / iter_time),
                               ('took', iter_time),
                               ('lrate', optimizer.param_groups[0]['lr'])]),
                )
>>>>>>> repo1

                accumulated_steps = 0
                iter_loss = 0
                iter_num_frames = 0
                iter_meta = {}

        # Finished epoch
<<<<<<< HEAD
        epoch_stop_time = time.time()
        epoch_time = epoch_stop_time - epoch_start_time

        DLLogger.log((epoch,), data=OrderedDict([
            ('avg_train_loss', epoch_loss / epoch_iter),
            ('avg_train_mel_loss', epoch_mel_loss / epoch_iter),
            ('avg_train_frames/s', epoch_num_frames / epoch_time),
            ('took', epoch_time)
        ]))

        tik = time.time()
        val_loss, meta, num_frames = validate(
            model, criterion, valset, args.batch_size, world_size, collate_fn,
            distributed_run, local_rank, batch_to_gpu, use_gt_durations=True)
        tok = time.time()

        DLLogger.log((epoch,), data=OrderedDict([
            ('val_loss', val_loss),
            ('val_mel_loss', meta['mel_loss'].item()),
            ('val_frames/s', num_frames / (tok - tik)),
            ('took', tok - tik),
        ]))
        val_tblogger.log_meta(total_iter, meta)

        if args.ema_decay > 0:
            tik_e = time.time()
            val_loss_e, meta_e, num_frames_e = validate(
                ema_model, criterion, valset, args.batch_size, world_size,
                collate_fn, distributed_run, local_rank, batch_to_gpu,
                use_gt_durations=True)
            tok_e = time.time()

            DLLogger.log((epoch,), data=OrderedDict([
                ('val_ema_loss', val_loss_e),
                ('val_ema_mel_loss', meta_e['mel_loss'].item()),
                ('val_ema_frames/s', num_frames_e / (tok_e - tik_e)),
                ('took', tok_e - tik_e),
            ]))
            val_ema_tblogger.log_meta(total_iter, meta)

        if (epoch > 0 and args.epochs_per_checkpoint > 0 and
            (epoch % args.epochs_per_checkpoint == 0) and local_rank == 0):

            checkpoint_path = os.path.join(
                args.output, f"FastPitch_checkpoint_{epoch}.pt")
            save_checkpoint(local_rank, model, ema_model, optimizer, epoch,
                            total_iter, model_config, args.amp, checkpoint_path)
        if local_rank == 0:
            DLLogger.flush()

    # Finished training
    DLLogger.log((), data=OrderedDict([
        ('avg_train_loss', epoch_loss / epoch_iter),
        ('avg_train_mel_loss', epoch_mel_loss / epoch_iter),
        ('avg_train_frames/s', epoch_num_frames / epoch_time),
    ]))
    DLLogger.log((), data=OrderedDict([
        ('val_loss', val_loss),
        ('val_mel_loss', meta['mel_loss'].item()),
        ('val_frames/s', num_frames / (tok - tik)),
    ]))
    if local_rank == 0:
        DLLogger.flush()
=======
        epoch_time = time.perf_counter() - epoch_start_time

        logger.log((epoch,),
                   tb_total_steps=None,
                   subset='train_avg',
                   data=OrderedDict([
                       ('loss', epoch_loss / epoch_iter),
                       ('mel_loss', epoch_mel_loss / epoch_iter),
                       ('frames/s', epoch_num_frames / epoch_time),
                       ('took', epoch_time)]),
        )

        validate(model, epoch, total_iter, criterion, valset, args.batch_size,
                 collate_fn, distributed_run, batch_to_gpu,
                 use_gt_durations=True)

        if args.ema_decay > 0:
            validate(ema_model, epoch, total_iter, criterion, valset,
                     args.batch_size, collate_fn, distributed_run, batch_to_gpu,
                     use_gt_durations=True, ema=True)

        if (epoch > 0 and args.epochs_per_checkpoint > 0 and
            (epoch % args.epochs_per_checkpoint == 0) and args.local_rank == 0):

            checkpoint_path = os.path.join(
                args.output, f"FastPitch_checkpoint_{epoch}.pt")
            save_checkpoint(args.local_rank, model, ema_model, optimizer, epoch,
                            total_iter, model_config, args.amp, checkpoint_path)
        logger.flush()

    # Finished training
    if args.pyprof:
        profiler.stop()
        torch.autograd.profiler.emit_nvtx().__exit__(None, None, None)

    logger.log((),
               tb_total_steps=None,
               subset='train_avg',
               data=OrderedDict([
                   ('loss', epoch_loss / epoch_iter),
                   ('mel_loss', epoch_mel_loss / epoch_iter),
                   ('frames/s', epoch_num_frames / epoch_time),
                   ('took', epoch_time)]),
    )
    validate(model, None, total_iter, criterion, valset, args.batch_size,
             collate_fn, distributed_run, batch_to_gpu, use_gt_durations=True)

    if (epoch > 0 and args.epochs_per_checkpoint > 0 and
        (epoch % args.epochs_per_checkpoint != 0) and args.local_rank == 0):
        checkpoint_path = os.path.join(
            args.output, f"FastPitch_checkpoint_{epoch}.pt")
        save_checkpoint(args.local_rank, model, ema_model, optimizer, epoch,
                        total_iter, model_config, args.amp, checkpoint_path)
>>>>>>> repo1


if __name__ == '__main__':
    main()
