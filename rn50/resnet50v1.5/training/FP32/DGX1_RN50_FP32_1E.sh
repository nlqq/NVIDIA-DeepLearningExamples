#!/bin/bash

MODEL=${1:-"r50"}
bz_per_device=${2:-128}
node_num=${3:-1}
gpu_num=${4:-8}

LOG_FOLDER=ngc/pytorch/${node_num}n${gpu_num}g
mkdir -p $LOG_FOLDER
LOGFILE=${LOG_FOLDER}/${MODEL}_b${bz_per_device}_fp32_1.log



python ./multiproc.py --nproc_per_node ${gpu_num} ./main.py /data/image \
        --data-backend dali-cpu \
        --raport-file raport.json \
        -j8 -p 1 --lr 2.048 \
        --optimizer-batch-size -1 \
        --warmup 8 --arch resnet50 \
        -c fanin --label-smoothing 0.1 \
        --lr-schedule cosine --mom 0.125 \
        --wd 3.0517578125e-05 \
        --workspace ${1:-./} -b ${bz_per_device} \
        --epochs 1 --prof 120 \
        --training-only --no-checkpoints  2>&1 | tee ${LOGFILE}
                                            
echo "Writting log to ${LOGFILE}"
