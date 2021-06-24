#!/bin/bash

# Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
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

<<<<<<< HEAD

echo "NVIDIA container build: ${NVIDIA_BUILD_ID}"

DATA_DIR=${1:-${DATA_DIR:-"/datasets/LibriSpeech"}}
MODEL_CONFIG=${2:-${MODEL_CONFIG:-"configs/jasper10x5dr_sp_offline_specaugment.toml"}}
RESULT_DIR=${3:-${RESULT_DIR:-"/results"}}
CHECKPOINT=${4:-${CHECKPOINT:-""}}
CREATE_LOGFILE=${5:-${CREATE_LOGFILE:-"true"}}
CUDNN_BENCHMARK=${6:-${CUDNN_BENCHMARK:-"true"}}
NUM_GPUS=${7:-${NUM_GPUS:-8}}
AMP=${8:-${AMP:-"false"}}
EPOCHS=${9:-${EPOCHS:-400}}
SEED=${10:-${SEED:-6}}
BATCH_SIZE=${11:-${BATCH_SIZE:-64}}
LEARNING_RATE=${12:-${LEARNING_RATE:-"0.015"}}
GRADIENT_ACCUMULATION_STEPS=${13:-${GRADIENT_ACCUMULATION_STEPS:-2}}
EMA=${EMA:-0.999}
SAVE_FREQUENCY=${SAVE_FREQUENCY:-10}

mkdir -p "$RESULT_DIR"

CMD="python3 -m torch.distributed.launch --nproc_per_node=$NUM_GPUS"
CMD+=" train.py"
CMD+=" --batch_size=$BATCH_SIZE"
CMD+=" --num_epochs=$EPOCHS"
CMD+=" --output_dir=$RESULT_DIR"
CMD+=" --model_toml=$MODEL_CONFIG"
CMD+=" --lr=$LEARNING_RATE"
CMD+=" --ema=$EMA"
CMD+=" --seed=$SEED"
CMD+=" --optimizer=novograd"
CMD+=" --dataset_dir=$DATA_DIR"
CMD+=" --val_manifest=$DATA_DIR/librispeech-dev-clean-wav.json"
CMD+=" --train_manifest=$DATA_DIR/librispeech-train-clean-100-wav.json"
CMD+=",$DATA_DIR/librispeech-train-clean-360-wav.json"
CMD+=",$DATA_DIR/librispeech-train-other-500-wav.json"
CMD+=" --weight_decay=1e-3"
CMD+=" --save_freq=$SAVE_FREQUENCY"
CMD+=" --eval_freq=100"
CMD+=" --train_freq=1"
CMD+=" --lr_decay"
CMD+=" --gradient_accumulation_steps=$GRADIENT_ACCUMULATION_STEPS "

[ "$AMP" == "true" ] && \
CMD+=" --amp"
[ "$CUDNN_BENCHMARK" = "true" ] && \
CMD+=" --cudnn"
[ -n "$CHECKPOINT" ] && \
CMD+=" --ckpt=${CHECKPOINT}"

if [ "$CREATE_LOGFILE" = "true" ] ; then
   export GBS=$(expr $BATCH_SIZE \* $NUM_GPUS)
   printf -v TAG "jasper_train_benchmark_amp-%s_gbs%d" "$AMP" $GBS
   DATESTAMP=`date +'%y%m%d%H%M%S'`
   LOGFILE=$RESULT_DIR/$TAG.$DATESTAMP.log
   printf "Logs written to %s\n" "$LOGFILE"
fi

set -x
if [ -z "$LOGFILE" ] ; then
   $CMD
else
   (
     $CMD
   ) |& tee $LOGFILE
fi
set +x
=======
export OMP_NUM_THREADS=1

: ${DATA_DIR:=${1:-"/datasets/LibriSpeech"}}
: ${MODEL_CONFIG:=${2:-"configs/jasper10x5dr_speedp-online_speca.yaml"}}
: ${OUTPUT_DIR:=${3:-"/results"}}
: ${CHECKPOINT:=${4:-}}
: ${RESUME:=true}
: ${CUDNN_BENCHMARK:=true}
: ${NUM_GPUS:=8}
: ${AMP:=false}
: ${BATCH_SIZE:=64}
: ${GRAD_ACCUMULATION_STEPS:=2}
: ${LEARNING_RATE:=0.01}
: ${MIN_LEARNING_RATE:=0.00001}
: ${LR_POLICY:=exponential}
: ${LR_EXP_GAMMA:=0.981}
: ${EMA:=0.999}
: ${SEED:=0}
: ${EPOCHS:=440}
: ${WARMUP_EPOCHS:=2}
: ${HOLD_EPOCHS:=140}
: ${SAVE_FREQUENCY:=10}
: ${EPOCHS_THIS_JOB:=0}
: ${DALI_DEVICE:="gpu"}
: ${PAD_TO_MAX_DURATION:=false}
: ${EVAL_FREQUENCY:=544}
: ${PREDICTION_FREQUENCY:=544}
: ${TRAIN_MANIFESTS:="$DATA_DIR/librispeech-train-clean-100-wav.json \
                      $DATA_DIR/librispeech-train-clean-360-wav.json \
                      $DATA_DIR/librispeech-train-other-500-wav.json"}
: ${VAL_MANIFESTS:="$DATA_DIR/librispeech-dev-clean-wav.json"}

mkdir -p "$OUTPUT_DIR"

ARGS="--dataset_dir=$DATA_DIR"
ARGS+=" --val_manifests $VAL_MANIFESTS"
ARGS+=" --train_manifests $TRAIN_MANIFESTS"
ARGS+=" --model_config=$MODEL_CONFIG"
ARGS+=" --output_dir=$OUTPUT_DIR"
ARGS+=" --lr=$LEARNING_RATE"
ARGS+=" --batch_size=$BATCH_SIZE"
ARGS+=" --min_lr=$MIN_LEARNING_RATE"
ARGS+=" --lr_policy=$LR_POLICY"
ARGS+=" --lr_exp_gamma=$LR_EXP_GAMMA"
ARGS+=" --epochs=$EPOCHS"
ARGS+=" --warmup_epochs=$WARMUP_EPOCHS"
ARGS+=" --hold_epochs=$HOLD_EPOCHS"
ARGS+=" --epochs_this_job=$EPOCHS_THIS_JOB"
ARGS+=" --ema=$EMA"
ARGS+=" --seed=$SEED"
ARGS+=" --optimizer=novograd"
ARGS+=" --weight_decay=1e-3"
ARGS+=" --save_frequency=$SAVE_FREQUENCY"
ARGS+=" --keep_milestones 100 200 300 400"
ARGS+=" --save_best_from=380"
ARGS+=" --log_frequency=1"
ARGS+=" --eval_frequency=$EVAL_FREQUENCY"
ARGS+=" --prediction_frequency=$PREDICTION_FREQUENCY"
ARGS+=" --grad_accumulation_steps=$GRAD_ACCUMULATION_STEPS "
ARGS+=" --dali_device=$DALI_DEVICE"

[ "$AMP" = true ] &&                 ARGS+=" --amp"
[ "$RESUME" = true ] &&              ARGS+=" --resume"
[ "$CUDNN_BENCHMARK" = true ] &&     ARGS+=" --cudnn_benchmark"
[ "$PAD_TO_MAX_DURATION" = true ] && ARGS+=" --pad_to_max_duration"
[ -n "$CHECKPOINT" ] &&              ARGS+=" --ckpt=$CHECKPOINT"
[ -n "$LOG_FILE" ] &&                ARGS+=" --log_file $LOG_FILE"
[ -n "$PRE_ALLOCATE" ] &&            ARGS+=" --pre_allocate_range $PRE_ALLOCATE"

DISTRIBUTED="-m torch.distributed.launch --nproc_per_node=$NUM_GPUS"
python $DISTRIBUTED train.py $ARGS
>>>>>>> repo1
