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
import copy
<<<<<<< HEAD
import itertools
import math
=======
>>>>>>> repo1
import os
import random
import time

<<<<<<< HEAD
import toml
import torch
import numpy as np
from apex import amp

from dataset import AudioToTextDataLayer
from helpers import (add_ctc_labels, model_multi_gpu, monitor_asr_train_progress,
                     print_dict, print_once, process_evaluation_batch,
                     process_evaluation_epoch)
from model import AudioPreprocessing, CTCLossNM, GreedyCTCDecoder, Jasper
from optimizers import Novograd, AdamW


def lr_policy(initial_lr, step, N):
    """
    learning rate decay
    Args:
        initial_lr: base learning rate
        step: current iteration number
        N: total number of iterations over which learning rate is decayed
    """
    min_lr = 0.00001
    res = initial_lr * ((N - step) / N) ** 2
    return max(res, min_lr)


def save(model, ema_model, optimizer, epoch, output_dir, optim_level):
    """
    Saves model checkpoint
    Args:
        model: model
        ema_model: model with exponential averages of weights
        optimizer: optimizer
        epoch: epoch of model training
        output_dir: path to save model checkpoint
    """
    out_fpath = os.path.join(output_dir, f"Jasper_epoch{epoch}_checkpoint.pt")
    print_once(f"Saving {out_fpath}...")

    if torch.distributed.is_initialized():
        torch.distributed.barrier()
        rank = torch.distributed.get_rank()
    else:
        rank = 0

    if rank == 0:
        checkpoint = {
            'epoch': epoch,
            'state_dict': getattr(model, 'module', model).state_dict(),
            'optimizer': optimizer.state_dict(),
            'amp': amp.state_dict() if optim_level > 0 else None,

        }
        if ema_model is not None:
            checkpoint['ema_state_dict'] = getattr(ema_model, 'module', ema_model).state_dict()
        torch.save(checkpoint, out_fpath)

    print_once('Saved.')
=======
try:
    import nvidia_dlprof_pytorch_nvtx as pyprof
except ModuleNotFoundError:
    import pyprof

import torch
import numpy as np
import torch.cuda.profiler as profiler
import torch.distributed as dist
from apex import amp
from apex.parallel import DistributedDataParallel

from common import helpers
from common.dali.data_loader import DaliDataLoader
from common.dataset import AudioDataset, get_data_loader
from common.features import BaseFeatures, FilterbankFeatures
from common.helpers import (Checkpointer, greedy_wer, num_weights, print_once,
                            process_evaluation_epoch)
from common.optimizers import AdamW, lr_policy, Novograd
from common.tb_dllogger import flush_log, init_log, log
from jasper import config
from jasper.model import CTCLossNM, GreedyCTCDecoder, Jasper


def parse_args():
    parser = argparse.ArgumentParser(description='Jasper')

    training = parser.add_argument_group('training setup')
    training.add_argument('--epochs', default=400, type=int,
                          help='Number of epochs for the entire training; influences the lr schedule')
    training.add_argument("--warmup_epochs", default=0, type=int,
                          help='Initial epochs of increasing learning rate')
    training.add_argument("--hold_epochs", default=0, type=int,
                          help='Constant max learning rate epochs after warmup')
    training.add_argument('--epochs_this_job', default=0, type=int,
                          help=('Run for a number of epochs with no effect on the lr schedule.'
                                'Useful for re-starting the training.'))
    training.add_argument('--cudnn_benchmark', action='store_true', default=True,
                          help='Enable cudnn benchmark')
    training.add_argument('--amp', '--fp16', action='store_true', default=False,
                          help='Use mixed precision training')
    training.add_argument('--seed', default=42, type=int, help='Random seed')
    training.add_argument('--local_rank', default=os.getenv('LOCAL_RANK', 0),
                          type=int, help='GPU id used for distributed training')
    training.add_argument('--pre_allocate_range', default=None, type=int, nargs=2,
                          help='Warmup with batches of length [min, max] before training')
    training.add_argument('--pyprof', action='store_true', help='Enable pyprof profiling')

    optim = parser.add_argument_group('optimization setup')
    optim.add_argument('--batch_size', default=32, type=int,
                       help='Global batch size')
    optim.add_argument('--lr', default=1e-3, type=float,
                       help='Peak learning rate')
    optim.add_argument("--min_lr", default=1e-5, type=float,
                       help='minimum learning rate')
    optim.add_argument("--lr_policy", default='exponential', type=str,
                       choices=['exponential', 'legacy'], help='lr scheduler')
    optim.add_argument("--lr_exp_gamma", default=0.99, type=float,
                       help='gamma factor for exponential lr scheduler')
    optim.add_argument('--weight_decay', default=1e-3, type=float,
                       help='Weight decay for the optimizer')
    optim.add_argument('--grad_accumulation_steps', default=1, type=int,
                       help='Number of accumulation steps')
    optim.add_argument('--optimizer', default='novograd', type=str,
                       choices=['novograd', 'adamw'], help='Optimization algorithm')
    optim.add_argument('--ema', type=float, default=0.0,
                       help='Discount factor for exp averaging of model weights')

    io = parser.add_argument_group('feature and checkpointing setup')
    io.add_argument('--dali_device', type=str, choices=['none', 'cpu', 'gpu'],
                    default='gpu', help='Use DALI pipeline for fast data processing')
    io.add_argument('--resume', action='store_true',
                    help='Try to resume from last saved checkpoint.')
    io.add_argument('--ckpt', default=None, type=str,
                    help='Path to a checkpoint for resuming training')
    io.add_argument('--save_frequency', default=10, type=int,
                    help='Checkpoint saving frequency in epochs')
    io.add_argument('--keep_milestones', default=[100, 200, 300], type=int, nargs='+',
                    help='Milestone checkpoints to keep from removing')
    io.add_argument('--save_best_from', default=380, type=int,
                    help='Epoch on which to begin tracking best checkpoint (dev WER)')
    io.add_argument('--eval_frequency', default=200, type=int,
                    help='Number of steps between evaluations on dev set')
    io.add_argument('--log_frequency', default=25, type=int,
                    help='Number of steps between printing training stats')
    io.add_argument('--prediction_frequency', default=100, type=int,
                    help='Number of steps between printing sample decodings')
    io.add_argument('--model_config', type=str, required=True,
                    help='Path of the model configuration file')
    io.add_argument('--train_manifests', type=str, required=True, nargs='+',
                    help='Paths of the training dataset manifest file')
    io.add_argument('--val_manifests', type=str, required=True, nargs='+',
                    help='Paths of the evaluation datasets manifest files')
    io.add_argument('--max_duration', type=float,
                    help='Discard samples longer than max_duration')
    io.add_argument('--pad_to_max_duration', action='store_true', default=False,
                    help='Pad training sequences to max_duration')
    io.add_argument('--dataset_dir', required=True, type=str,
                    help='Root dir of dataset')
    io.add_argument('--output_dir', type=str, required=True,
                    help='Directory for logs and checkpoints')
    io.add_argument('--log_file', type=str, default=None,
                    help='Path to save the training logfile.')
    return parser.parse_args()


def reduce_tensor(tensor, num_gpus):
    rt = tensor.clone()
    dist.all_reduce(rt, op=dist.ReduceOp.SUM)
    return rt.true_divide(num_gpus)
>>>>>>> repo1


def apply_ema(model, ema_model, decay):
    if not decay:
        return
<<<<<<< HEAD
    st = model.state_dict()
    add_module = hasattr(model, 'module') and not hasattr(ema_model, 'module')
    for k,v in ema_model.state_dict().items():
        if add_module and not k.startswith('module.'):
            k = 'module.' + k
        v.copy_(decay * v + (1 - decay) * st[k])


def train(
        data_layer,
        data_layer_eval,
        model,
        ema_model,
        ctc_loss,
        greedy_decoder,
        optimizer,
        optim_level,
        labels,
        multi_gpu,
        args,
        fn_lr_policy=None):
    """Trains model
    Args:
        data_layer: training data layer
        data_layer_eval: evaluation data layer
        model: model ( encapsulates data processing, encoder, decoder)
        ctc_loss: loss function
        greedy_decoder: greedy ctc decoder
        optimizer: optimizer
        optim_level: AMP optimization level
        labels: list of output labels
        multi_gpu: true if multi gpu training
        args: script input argument list
        fn_lr_policy: learning rate adjustment function
    """
    def eval(model, name=''):
        """Evaluates model on evaluation dataset
        """
        with torch.no_grad():
            _global_var_dict = {
                'EvalLoss': [],
                'predictions': [],
                'transcripts': [],
            }
            eval_dataloader = data_layer_eval.data_iterator
            for data in eval_dataloader:
                tensors = []
                for d in data:
                    if isinstance(d, torch.Tensor):
                        tensors.append(d.cuda())
                    else:
                        tensors.append(d)
                t_audio_signal_e, t_a_sig_length_e, t_transcript_e, t_transcript_len_e = tensors

                model.eval()
                if optim_level == 1:
                  with amp.disable_casts():
                      t_processed_signal_e, t_processed_sig_length_e = audio_preprocessor(t_audio_signal_e, t_a_sig_length_e) 
                else:
                  t_processed_signal_e, t_processed_sig_length_e = audio_preprocessor(t_audio_signal_e, t_a_sig_length_e)
                if jasper_encoder.use_conv_mask:
                    t_log_probs_e, t_encoded_len_e = model.forward((t_processed_signal_e, t_processed_sig_length_e))
                else:
                    t_log_probs_e = model.forward(t_processed_signal_e)
                t_loss_e = ctc_loss(log_probs=t_log_probs_e, targets=t_transcript_e, input_length=t_encoded_len_e, target_length=t_transcript_len_e)
                t_predictions_e = greedy_decoder(log_probs=t_log_probs_e)

                values_dict = dict(
                    loss=[t_loss_e],
                    predictions=[t_predictions_e],
                    transcript=[t_transcript_e],
                    transcript_length=[t_transcript_len_e]
                )
                process_evaluation_batch(values_dict, _global_var_dict, labels=labels)

            # final aggregation across all workers and minibatches) and logging of results
            wer, eloss = process_evaluation_epoch(_global_var_dict)

            if name != '':
                name = '_' + name

            print_once(f"==========>>>>>>Evaluation{name} Loss: {eloss}\n")
            print_once(f"==========>>>>>>Evaluation{name} WER: {wer}\n")

    print_once("Starting .....")
    start_time = time.time()

    train_dataloader = data_layer.data_iterator
    epoch = args.start_epoch
    step = epoch * args.step_per_epoch

    audio_preprocessor = model.module.audio_preprocessor if hasattr(model, 'module') else model.audio_preprocessor
    data_spectr_augmentation = model.module.data_spectr_augmentation if hasattr(model, 'module') else model.data_spectr_augmentation
    jasper_encoder = model.module.jasper_encoder if hasattr(model, 'module') else model.jasper_encoder

    while True:
        if multi_gpu:
            data_layer.sampler.set_epoch(epoch)
        print_once("Starting epoch {0}, step {1}".format(epoch, step))
        last_epoch_start = time.time()
        batch_counter = 0
        average_loss = 0
        for data in train_dataloader:
            tensors = []
            for d in data:
                if isinstance(d, torch.Tensor):
                    tensors.append(d.cuda())
                else:
                    tensors.append(d)

            if batch_counter == 0:

                if fn_lr_policy is not None:
                    adjusted_lr = fn_lr_policy(step)
                    for param_group in optimizer.param_groups:
                            param_group['lr'] = adjusted_lr
                optimizer.zero_grad()
                last_iter_start = time.time()

            t_audio_signal_t, t_a_sig_length_t, t_transcript_t, t_transcript_len_t = tensors
            model.train()
            if optim_level == 1:
              with amp.disable_casts():
                  t_processed_signal_t, t_processed_sig_length_t = audio_preprocessor(t_audio_signal_t, t_a_sig_length_t)
            else:
              t_processed_signal_t, t_processed_sig_length_t = audio_preprocessor(t_audio_signal_t, t_a_sig_length_t)
            t_processed_signal_t = data_spectr_augmentation(t_processed_signal_t)
            if jasper_encoder.use_conv_mask:
                t_log_probs_t, t_encoded_len_t = model.forward((t_processed_signal_t, t_processed_sig_length_t))
            else:
                t_log_probs_t = model.forward(t_processed_signal_t)

            t_loss_t = ctc_loss(log_probs=t_log_probs_t, targets=t_transcript_t, input_length=t_encoded_len_t, target_length=t_transcript_len_t)
            if args.gradient_accumulation_steps > 1:
                    t_loss_t = t_loss_t / args.gradient_accumulation_steps

            if 0 < optim_level <= 3:
                with amp.scale_loss(t_loss_t, optimizer) as scaled_loss:
                    scaled_loss.backward()
            else:
                t_loss_t.backward()
            batch_counter += 1
            average_loss += t_loss_t.item()

            if batch_counter % args.gradient_accumulation_steps == 0:
                optimizer.step()

                if step % args.train_frequency == 0:
                    t_predictions_t = greedy_decoder(log_probs=t_log_probs_t)

                    e_tensors = [t_predictions_t, t_transcript_t, t_transcript_len_t]
                    train_wer = monitor_asr_train_progress(e_tensors, labels=labels)
                    print_once("Loss@Step: {0}  ::::::: {1}".format(step, str(average_loss)))
                    print_once("Step time: {0} seconds".format(time.time() - last_iter_start))
                if step > 0 and step % args.eval_frequency == 0:
                    print_once("Doing Evaluation ....................... ......  ... .. . .")
                    eval(model)
                    if args.ema > 0:
                        eval(ema_model, 'EMA')

                step += 1
                batch_counter = 0
                average_loss = 0
                if args.num_steps is not None and step >= args.num_steps:
                    break

        if args.num_steps is not None and step >= args.num_steps:
            break
        print_once("Finished epoch {0} in {1}".format(epoch, time.time() - last_epoch_start))
        epoch += 1
        if epoch % args.save_frequency == 0 and epoch > 0:
            save(model, ema_model, optimizer, epoch, args.output_dir, optim_level)
        if args.num_steps is None and epoch >= args.num_epochs:
            break
    print_once("Done in {0}".format(time.time() - start_time))
    print_once("Final Evaluation ....................... ......  ... .. . .")
    eval(model)
    if args.ema > 0:
        eval(ema_model, 'EMA')
    save(model, ema_model, optimizer, epoch, args.output_dir, optim_level)


def main(args):
    random.seed(args.seed)
    np.random.seed(args.seed)
    torch.manual_seed(args.seed)
    assert(torch.cuda.is_available())
    torch.backends.cudnn.benchmark = args.cudnn

    # set up distributed training
    if args.local_rank is not None:
        torch.cuda.set_device(args.local_rank)
        torch.distributed.init_process_group(backend='nccl', init_method='env://')


    multi_gpu = torch.distributed.is_initialized()
    if multi_gpu:
        print_once("DISTRIBUTED TRAINING with {} gpus".format(torch.distributed.get_world_size()))

    # define amp optimiation level
    optim_level = 1 if args.amp else 0

    jasper_model_definition = toml.load(args.model_toml)
    dataset_vocab = jasper_model_definition['labels']['labels']
    ctc_vocab = add_ctc_labels(dataset_vocab)

    train_manifest = args.train_manifest
    val_manifest = args.val_manifest
    featurizer_config = jasper_model_definition['input']
    featurizer_config_eval = jasper_model_definition['input_eval']
    featurizer_config["optimization_level"] = optim_level
    featurizer_config_eval["optimization_level"] = optim_level

    sampler_type = featurizer_config.get("sampler", 'default')
    perturb_config = jasper_model_definition.get('perturb', None)
    if args.pad_to_max:
        assert(args.max_duration > 0)
        featurizer_config['max_duration'] = args.max_duration
        featurizer_config_eval['max_duration'] = args.max_duration
        featurizer_config['pad_to'] = -1
        featurizer_config_eval['pad_to'] = -1

    print_once('model_config')
    print_dict(jasper_model_definition)

    if args.gradient_accumulation_steps < 1:
        raise ValueError('Invalid gradient accumulation steps parameter {}'.format(args.gradient_accumulation_steps))
    if args.batch_size % args.gradient_accumulation_steps != 0:
        raise ValueError('gradient accumulation step {} is not divisible by batch size {}'.format(args.gradient_accumulation_steps, args.batch_size))


    data_layer = AudioToTextDataLayer(
                                    dataset_dir=args.dataset_dir,
                                    featurizer_config=featurizer_config,
                                    perturb_config=perturb_config,
                                    manifest_filepath=train_manifest,
                                    labels=dataset_vocab,
                                    batch_size=args.batch_size // args.gradient_accumulation_steps,
                                    multi_gpu=multi_gpu,
                                    pad_to_max=args.pad_to_max,
                                    sampler=sampler_type)

    data_layer_eval = AudioToTextDataLayer(
                                    dataset_dir=args.dataset_dir,
                                    featurizer_config=featurizer_config_eval,
                                    manifest_filepath=val_manifest,
                                    labels=dataset_vocab,
                                    batch_size=args.batch_size,
                                    multi_gpu=multi_gpu,
                                    pad_to_max=args.pad_to_max
                                    )

    model = Jasper(feature_config=featurizer_config, jasper_model_definition=jasper_model_definition, feat_in=1024, num_classes=len(ctc_vocab))

    ctc_loss = CTCLossNM( num_classes=len(ctc_vocab))
    greedy_decoder = GreedyCTCDecoder()

    print_once("Number of parameters in encoder: {0}".format(model.jasper_encoder.num_weights()))
    print_once("Number of parameters in decode: {0}".format(model.jasper_decoder.num_weights()))

    N = len(data_layer)
    if sampler_type == 'default':
        args.step_per_epoch = math.ceil(N / (args.batch_size * (1 if not torch.distributed.is_initialized() else torch.distributed.get_world_size())))
    elif sampler_type == 'bucket':
        args.step_per_epoch = int(len(data_layer.sampler) / args.batch_size )

    print_once('-----------------')
    print_once('Have {0} examples to train on.'.format(N))
    print_once('Have {0} steps / (gpu * epoch).'.format(args.step_per_epoch))
    print_once('-----------------')

    fn_lr_policy = lambda s: lr_policy(args.lr, s, args.num_epochs * args.step_per_epoch)


    model.cuda()

    if args.optimizer_kind == "novograd":
        optimizer = Novograd(model.parameters(),
                        lr=args.lr,
                        weight_decay=args.weight_decay)
    elif args.optimizer_kind == "adam":
        optimizer = AdamW(model.parameters(),
                        lr=args.lr,
                        weight_decay=args.weight_decay)
    else:
        raise ValueError("invalid optimizer choice: {}".format(args.optimizer_kind))

    if 0 < optim_level <= 3:
        model, optimizer = amp.initialize(
            min_loss_scale=1.0,
            models=model,
            optimizers=optimizer,
            opt_level='O' + str(optim_level))
=======

    sd = getattr(model, 'module', model).state_dict()
    for k, v in ema_model.state_dict().items():
        v.copy_(decay * v + (1 - decay) * sd[k])


@torch.no_grad()
def evaluate(epoch, step, val_loader, val_feat_proc, labels, model,
             ema_model, ctc_loss, greedy_decoder, use_amp, use_dali=False):

    for model, subset in [(model, 'dev'), (ema_model, 'dev_ema')]:
        if model is None:
            continue

        model.eval()
        start_time = time.time()
        agg = {'losses': [], 'preds': [], 'txts': []}

        for batch in val_loader:
            if use_dali:
                # with DALI, the data is already on GPU
                feat, feat_lens, txt, txt_lens = batch
                if val_feat_proc is not None:
                    feat, feat_lens = val_feat_proc(feat, feat_lens, use_amp)
            else:
                batch = [t.cuda(non_blocking=True) for t in batch]
                audio, audio_lens, txt, txt_lens = batch
                feat, feat_lens = val_feat_proc(audio, audio_lens, use_amp)

            log_probs, enc_lens = model.forward(feat, feat_lens)
            loss = ctc_loss(log_probs, txt, enc_lens, txt_lens)
            pred = greedy_decoder(log_probs)

            agg['losses'] += helpers.gather_losses([loss])
            agg['preds'] += helpers.gather_predictions([pred], labels)
            agg['txts'] += helpers.gather_transcripts([txt], [txt_lens], labels)

        wer, loss = process_evaluation_epoch(agg)
        log((epoch,), step, subset, {'loss': loss, 'wer': 100.0 * wer,
                                     'took': time.time() - start_time})
        model.train()
    return wer


def main():
    args = parse_args()

    assert(torch.cuda.is_available())
    assert args.prediction_frequency % args.log_frequency == 0

    torch.backends.cudnn.benchmark = args.cudnn_benchmark

    # set up distributed training
    multi_gpu = int(os.environ.get('WORLD_SIZE', 1)) > 1
    if multi_gpu:
        torch.cuda.set_device(args.local_rank)
        dist.init_process_group(backend='nccl', init_method='env://')
        world_size = dist.get_world_size()
        print_once(f'Distributed training with {world_size} GPUs\n')
    else:
        world_size = 1

    torch.manual_seed(args.seed + args.local_rank)
    np.random.seed(args.seed + args.local_rank)
    random.seed(args.seed + args.local_rank)

    init_log(args)

    cfg = config.load(args.model_config)
    config.apply_duration_flags(cfg, args.max_duration, args.pad_to_max_duration)

    symbols = helpers.add_ctc_blank(cfg['labels'])

    assert args.grad_accumulation_steps >= 1
    assert args.batch_size % args.grad_accumulation_steps == 0
    batch_size = args.batch_size // args.grad_accumulation_steps

    print_once('Setting up datasets...')
    train_dataset_kw, train_features_kw = config.input(cfg, 'train')
    val_dataset_kw, val_features_kw = config.input(cfg, 'val')

    use_dali = args.dali_device in ('cpu', 'gpu')
    if use_dali:
        assert train_dataset_kw['ignore_offline_speed_perturbation'], \
            "DALI doesn't support offline speed perturbation"

        # pad_to_max_duration is not supported by DALI - have simple padders
        if train_features_kw['pad_to_max_duration']:
            train_feat_proc = BaseFeatures(
                pad_align=train_features_kw['pad_align'],
                pad_to_max_duration=True,
                max_duration=train_features_kw['max_duration'],
                sample_rate=train_features_kw['sample_rate'],
                window_size=train_features_kw['window_size'],
                window_stride=train_features_kw['window_stride'])
            train_features_kw['pad_to_max_duration'] = False
        else:
            train_feat_proc = None

        if val_features_kw['pad_to_max_duration']:
            val_feat_proc = BaseFeatures(
                pad_align=val_features_kw['pad_align'],
                pad_to_max_duration=True,
                max_duration=val_features_kw['max_duration'],
                sample_rate=val_features_kw['sample_rate'],
                window_size=val_features_kw['window_size'],
                window_stride=val_features_kw['window_stride'])
            val_features_kw['pad_to_max_duration'] = False
        else:
            val_feat_proc = None

        train_loader = DaliDataLoader(gpu_id=args.local_rank,
                                      dataset_path=args.dataset_dir,
                                      config_data=train_dataset_kw,
                                      config_features=train_features_kw,
                                      json_names=args.train_manifests,
                                      batch_size=batch_size,
                                      grad_accumulation_steps=args.grad_accumulation_steps,
                                      pipeline_type="train",
                                      device_type=args.dali_device,
                                      symbols=symbols)

        val_loader = DaliDataLoader(gpu_id=args.local_rank,
                                    dataset_path=args.dataset_dir,
                                    config_data=val_dataset_kw,
                                    config_features=val_features_kw,
                                    json_names=args.val_manifests,
                                    batch_size=batch_size,
                                    pipeline_type="val",
                                    device_type=args.dali_device,
                                    symbols=symbols)
    else:
        train_dataset_kw, train_features_kw = config.input(cfg, 'train')
        train_dataset = AudioDataset(args.dataset_dir,
                                     args.train_manifests,
                                     symbols,
                                     **train_dataset_kw)
        train_loader = get_data_loader(train_dataset,
                                       batch_size,
                                       multi_gpu=multi_gpu,
                                       shuffle=True,
                                       num_workers=4)
        train_feat_proc = FilterbankFeatures(**train_features_kw)

        val_dataset_kw, val_features_kw = config.input(cfg, 'val')
        val_dataset = AudioDataset(args.dataset_dir,
                                   args.val_manifests,
                                   symbols,
                                   **val_dataset_kw)
        val_loader = get_data_loader(val_dataset,
                                     batch_size,
                                     multi_gpu=multi_gpu,
                                     shuffle=False,
                                     num_workers=4,
                                     drop_last=False)
        val_feat_proc = FilterbankFeatures(**val_features_kw)

        dur = train_dataset.duration / 3600
        dur_f = train_dataset.duration_filtered / 3600
        nsampl = len(train_dataset)
        print_once(f'Training samples: {nsampl} ({dur:.1f}h, '
                   f'filtered {dur_f:.1f}h)')

    if train_feat_proc is not None:
        train_feat_proc.cuda()
    if val_feat_proc is not None:
        val_feat_proc.cuda()

    steps_per_epoch = len(train_loader) // args.grad_accumulation_steps

    # set up the model
    model = Jasper(encoder_kw=config.encoder(cfg),
                   decoder_kw=config.decoder(cfg, n_classes=len(symbols)))
    model.cuda()
    ctc_loss = CTCLossNM(n_classes=len(symbols))
    greedy_decoder = GreedyCTCDecoder()

    print_once(f'Model size: {num_weights(model) / 10**6:.1f}M params\n')

    # optimization
    kw = {'lr': args.lr, 'weight_decay': args.weight_decay}
    if args.optimizer == "novograd":
        optimizer = Novograd(model.parameters(), **kw)
    elif args.optimizer == "adamw":
        optimizer = AdamW(model.parameters(), **kw)
    else:
        raise ValueError(f'Invalid optimizer "{args.optimizer}"')

    adjust_lr = lambda step, epoch, optimizer: lr_policy(
        step, epoch, args.lr, optimizer, steps_per_epoch=steps_per_epoch,
        warmup_epochs=args.warmup_epochs, hold_epochs=args.hold_epochs,
        num_epochs=args.epochs, policy=args.lr_policy, min_lr=args.min_lr,
        exp_gamma=args.lr_exp_gamma)

    if args.amp:
        model, optimizer = amp.initialize(
            min_loss_scale=1.0, models=model, optimizers=optimizer,
            opt_level='O1', max_loss_scale=512.0)
>>>>>>> repo1

    if args.ema > 0:
        ema_model = copy.deepcopy(model)
    else:
        ema_model = None

<<<<<<< HEAD
    model = model_multi_gpu(model, multi_gpu)

    if args.ckpt is not None:
        print_once("loading model from {}".format(args.ckpt))
        checkpoint = torch.load(args.ckpt, map_location="cpu")
        if hasattr(model, 'module'):
            model.module.load_state_dict(checkpoint['state_dict'], strict=True)
        else:
            model.load_state_dict(checkpoint['state_dict'], strict=True)

        if args.ema > 0:
            if 'ema_state_dict' in checkpoint:
                if hasattr(ema_model, 'module'):
                    ema_model.module.load_state_dict(checkpoint['ema_state_dict'], strict=True)
                else:
                    ema_model.load_state_dict(checkpoint['ema_state_dict'], strict=True)
            else:
                print_once('WARNING: ema_state_dict not found in the checkpoint')
                print_once('WARNING: initializing EMA model with regular params')
                if hasattr(ema_model, 'module'):
                    ema_model.module.load_state_dict(checkpoint['state_dict'], strict=True)
                else:
                    ema_model.load_state_dict(checkpoint['state_dict'], strict=True)

        optimizer.load_state_dict(checkpoint['optimizer'])

        if optim_level > 0:
            amp.load_state_dict(checkpoint['amp'])

        args.start_epoch = checkpoint['epoch']
    else:
        args.start_epoch = 0

    train(data_layer, data_layer_eval, model, ema_model,
          ctc_loss=ctc_loss, \
          greedy_decoder=greedy_decoder, \
          optimizer=optimizer, \
          labels=ctc_vocab, \
          optim_level=optim_level, \
          multi_gpu=multi_gpu, \
          fn_lr_policy=fn_lr_policy if args.lr_decay else None, \
          args=args)


def parse_args():
    parser = argparse.ArgumentParser(description='Jasper')
    parser.add_argument("--local_rank", default=None, type=int)
    parser.add_argument("--batch_size", default=16, type=int, help='data batch size')
    parser.add_argument("--num_epochs", default=10, type=int, help='number of training epochs. if number of steps if specified will overwrite this')
    parser.add_argument("--num_steps", default=None, type=int, help='if specified overwrites num_epochs and will only train for this number of iterations')
    parser.add_argument("--save_freq", dest="save_frequency", default=300, type=int, help='number of epochs until saving checkpoint. will save at the end of training too.')
    parser.add_argument("--eval_freq", dest="eval_frequency", default=200, type=int, help='number of iterations until doing evaluation on full dataset')
    parser.add_argument("--train_freq", dest="train_frequency", default=25, type=int, help='number of iterations until printing training statistics on the past iteration')
    parser.add_argument("--lr", default=1e-3, type=float, help='learning rate')
    parser.add_argument("--weight_decay", default=1e-3, type=float, help='weight decay rate')
    parser.add_argument("--train_manifest", type=str, required=True, help='relative path given dataset folder of training manifest file')
    parser.add_argument("--model_toml", type=str, required=True, help='relative path given dataset folder of model configuration file')
    parser.add_argument("--val_manifest", type=str, required=True, help='relative path given dataset folder of evaluation manifest file')
    parser.add_argument("--max_duration", type=float, help='maximum duration of audio samples for training and evaluation')
    parser.add_argument("--pad_to_max", action="store_true", default=False, help="pad sequence to max_duration")
    parser.add_argument("--gradient_accumulation_steps", default=1, type=int, help='number of accumulation steps')
    parser.add_argument("--optimizer", dest="optimizer_kind", default="novograd", type=str, help='optimizer')
    parser.add_argument("--dataset_dir", dest="dataset_dir", required=True, type=str, help='root dir of dataset')
    parser.add_argument("--lr_decay", action="store_true", default=False, help='use learning rate decay')
    parser.add_argument("--cudnn", action="store_true", default=False, help="enable cudnn benchmark")
    parser.add_argument("--amp", "--fp16", action="store_true", default=False, help="use mixed precision training")
    parser.add_argument("--output_dir", type=str, required=True, help='saves results in this directory')
    parser.add_argument("--ckpt", default=None, type=str, help="if specified continues training from given checkpoint. Otherwise starts from beginning")
    parser.add_argument("--seed", default=42, type=int, help='seed')
    parser.add_argument("--ema", type=float, default=0.0, help='discount factor for exponential averaging of model weights during training')
    args=parser.parse_args()
    return args


if __name__=="__main__":
    args = parse_args()
    print_dict(vars(args))
    main(args)
=======
    if multi_gpu:
        model = DistributedDataParallel(model)

    if args.pyprof:
        pyprof.init(enable_function_stack=True)

    # load checkpoint
    meta = {'best_wer': 10**6, 'start_epoch': 0}
    checkpointer = Checkpointer(args.output_dir, 'Jasper',
                                args.keep_milestones, args.amp)
    if args.resume:
        args.ckpt = checkpointer.last_checkpoint() or args.ckpt

    if args.ckpt is not None:
        checkpointer.load(args.ckpt, model, ema_model, optimizer, meta)

    start_epoch = meta['start_epoch']
    best_wer = meta['best_wer']
    epoch = 1
    step = start_epoch * steps_per_epoch + 1

    if args.pyprof:
        torch.autograd.profiler.emit_nvtx().__enter__()
        profiler.start()

    # training loop
    model.train()

    # pre-allocate
    if args.pre_allocate_range is not None:
        n_feats = train_features_kw['n_filt']
        pad_align = train_features_kw['pad_align']
        a, b = args.pre_allocate_range
        for n_frames in range(a, b + pad_align, pad_align):
            print_once(f'Pre-allocation ({batch_size}x{n_feats}x{n_frames})...')

            feat = torch.randn(batch_size, n_feats, n_frames, device='cuda')
            feat_lens = torch.ones(batch_size, device='cuda').fill_(n_frames)
            txt = torch.randint(high=len(symbols)-1, size=(batch_size, 100),
                                device='cuda')
            txt_lens = torch.ones(batch_size, device='cuda').fill_(100)
            log_probs, enc_lens = model(feat, feat_lens)
            del feat
            loss = ctc_loss(log_probs, txt, enc_lens, txt_lens)
            loss.backward()
            model.zero_grad()

    for epoch in range(start_epoch + 1, args.epochs + 1):
        if multi_gpu and not use_dali:
            train_loader.sampler.set_epoch(epoch)

        epoch_utts = 0
        accumulated_batches = 0
        epoch_start_time = time.time()

        for batch in train_loader:

            if accumulated_batches == 0:
                adjust_lr(step, epoch, optimizer)
                optimizer.zero_grad()
                step_loss = 0
                step_utts = 0
                step_start_time = time.time()

            if use_dali:
                # with DALI, the data is already on GPU
                feat, feat_lens, txt, txt_lens = batch
                if train_feat_proc is not None:
                    feat, feat_lens = train_feat_proc(feat, feat_lens, args.amp)
            else:
                batch = [t.cuda(non_blocking=True) for t in batch]
                audio, audio_lens, txt, txt_lens = batch
                feat, feat_lens = train_feat_proc(audio, audio_lens, args.amp)

            log_probs, enc_lens = model(feat, feat_lens)

            loss = ctc_loss(log_probs, txt, enc_lens, txt_lens)
            loss /= args.grad_accumulation_steps

            if torch.isnan(loss).any():
                print_once(f'WARNING: loss is NaN; skipping update')
            else:
                if multi_gpu:
                    step_loss += reduce_tensor(loss.data, world_size).item()
                else:
                    step_loss += loss.item()

                if args.amp:
                    with amp.scale_loss(loss, optimizer) as scaled_loss:
                        scaled_loss.backward()
                else:
                    loss.backward()
                step_utts += batch[0].size(0) * world_size
                epoch_utts += batch[0].size(0) * world_size
                accumulated_batches += 1

            if accumulated_batches % args.grad_accumulation_steps == 0:
                optimizer.step()
                apply_ema(model, ema_model, args.ema)

                if step % args.log_frequency == 0:
                    preds = greedy_decoder(log_probs)
                    wer, pred_utt, ref = greedy_wer(preds, txt, txt_lens, symbols)

                    if step % args.prediction_frequency == 0:
                        print_once(f'  Decoded:   {pred_utt[:90]}')
                        print_once(f'  Reference: {ref[:90]}')

                    step_time = time.time() - step_start_time
                    log((epoch, step % steps_per_epoch or steps_per_epoch, steps_per_epoch),
                        step, 'train',
                        {'loss': step_loss,
                         'wer': 100.0 * wer,
                         'throughput': step_utts / step_time,
                         'took': step_time,
                         'lrate': optimizer.param_groups[0]['lr']})

                step_start_time = time.time()

                if step % args.eval_frequency == 0:
                    wer = evaluate(epoch, step, val_loader, val_feat_proc,
                                   symbols, model, ema_model, ctc_loss,
                                   greedy_decoder, args.amp, use_dali)

                    if wer < best_wer and epoch >= args.save_best_from:
                        checkpointer.save(model, ema_model, optimizer, epoch,
                                          step, best_wer, is_best=True)
                        best_wer = wer

                step += 1
                accumulated_batches = 0
                # end of step

            # DALI iterator need to be exhausted;
            # if not using DALI, simulate drop_last=True with grad accumulation
            if not use_dali and step > steps_per_epoch * epoch:
                break

        epoch_time = time.time() - epoch_start_time
        log((epoch,), None, 'train_avg', {'throughput': epoch_utts / epoch_time,
                                          'took': epoch_time})

        if epoch % args.save_frequency == 0 or epoch in args.keep_milestones:
            checkpointer.save(model, ema_model, optimizer, epoch, step, best_wer)

        if 0 < args.epochs_this_job <= epoch - start_epoch:
            print_once(f'Finished after {args.epochs_this_job} epochs.')
            break
        # end of epoch

    if args.pyprof:
        profiler.stop()
        torch.autograd.profiler.emit_nvtx().__exit__(None, None, None)

    log((), None, 'train_avg', {'throughput': epoch_utts / epoch_time})

    if epoch == args.epochs:
        evaluate(epoch, step, val_loader, val_feat_proc, symbols, model,
                 ema_model, ctc_loss, greedy_decoder, args.amp, use_dali)

        checkpointer.save(model, ema_model, optimizer, epoch, step, best_wer)
    flush_log()


if __name__ == "__main__":
    main()
>>>>>>> repo1
