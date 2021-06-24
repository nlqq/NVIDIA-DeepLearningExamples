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
DATASET=${2:-${DATASET:-"dev-clean"}}
MODEL_CONFIG=${3:-${MODEL_CONFIG:-"configs/jasper10x5dr_sp_offline_specaugment.toml"}}
RESULT_DIR=${4:-${RESULT_DIR:-"/results"}}
CHECKPOINT=${5:-${CHECKPOINT:-"/checkpoints/jasper_fp16.pt"}}
CREATE_LOGFILE=${6:-${CREATE_LOGFILE:-"true"}}
CUDNN_BENCHMARK=${7:-${CUDNN_BENCHMARK:-"true"}}
AMP=${8:-${AMP:-"false"}}
NUM_STEPS=${9:-${NUM_STEPS:-"-1"}}
MAX_DURATION=${10:-${MAX_DURATION:-"36"}}
SEED=${11:-${SEED:-0}}
BATCH_SIZE=${12:-${BATCH_SIZE:-64}}

mkdir -p "$RESULT_DIR"

CMD=" python inference_benchmark.py"
CMD+=" --batch_size=$BATCH_SIZE"
CMD+=" --model_toml=$MODEL_CONFIG"
CMD+=" --seed=$SEED"
CMD+=" --dataset_dir=$DATA_DIR"
CMD+=" --val_manifest $DATA_DIR/librispeech-${DATASET}-wav.json "
CMD+=" --ckpt=$CHECKPOINT"
CMD+=" --max_duration=$MAX_DURATION"
CMD+=" --pad_to=-1"
[ "$AMP" == "true" ] && \
CMD+=" --amp"
[ "$NUM_STEPS" -gt 0 ] && \
CMD+=" --steps $NUM_STEPS"
[ "$CUDNN_BENCHMARK" = "true" ] && \
CMD+=" --cudnn"

if [ "$CREATE_LOGFILE" = "true" ] ; then
   export GBS=$(expr $BATCH_SIZE )
   printf -v TAG "jasper_train_benchmark_amp-%s_gbs%d" "$AMP" $GBS
   DATESTAMP=`date +'%y%m%d%H%M%S'`
   LOGFILE="${RESULT_DIR}/${TAG}.${DATESTAMP}.log"
   printf "Logs written to %s\n" "$LOGFILE"
fi

set -x
if [ -z "$LOGFILE" ] ; then
   $CMD
else
   (
     $CMD
   ) |& tee "$LOGFILE"
   grep 'latency' "$LOGFILE"
fi
set +x
=======
set -a

: ${OUTPUT_DIR:=${3:-"/results"}}
: ${CUDNN_BENCHMARK:=true}
: ${PAD_TO_MAX_DURATION:=true}
: ${NUM_WARMUP_STEPS:=10}
: ${NUM_STEPS:=500}

: ${AMP:=false}
: ${DALI_DEVICE:="cpu"}
: ${BATCH_SIZE_SEQ:="1 2 4 8 16"}
: ${MAX_DURATION_SEQ:="2 7 16.7"}

for MAX_DURATION in $MAX_DURATION_SEQ; do
  for BATCH_SIZE in $BATCH_SIZE_SEQ; do

    LOG_FILE="$OUTPUT_DIR/perf-infer_dali-${DALI_DEVICE}_amp-${AMP}_dur${MAX_DURATION}_bs${BATCH_SIZE}.json"
    bash ./scripts/inference.sh "$@"

  done
done
>>>>>>> repo1