#!/bin/bash

NODE1=10.11.0.2:8
NODE2=10.11.0.3:8
NODE3=10.11.0.4:8
NODE4=10.11.0.5:8
MODEL=${1:-"resnet50-horovod"}
gpus=${2:-"0,1,2,3,4,5,6,7"}
bz_per_device=${3:-16}
# node_ips=${4:-$NODE1,$NODE2,$NODE3,$NODE4}
node_ips=${4:-$NODE1,$NODE2}

a=`expr ${#gpus} + 1`
NUM_GPU=`expr ${a} / 2`
total_bz=`expr ${bz_per_device} \* ${NUM_GPU}`
LR=$(awk -v total_bz="$total_bz" 'BEGIN{print  total_bz / 1000}')
node_num=$(echo $node_ips | tr ',' '\n' | wc -l)
np_num=`expr ${node_num} \* 8`
echo "Use gpus: $gpus"
echo "Batch size : $bz_per_device"
echo "Learning rate: $LR"

#LOG_FOLDER=../logs/benchmark_log/cnns/${MODEL}_${node_num}node_bz${bz_per_device}
#mkdir -p $LOG_FOLDER
#LOGFILE=${LOG_FOLDER}/${node_num}n${NUM_GPU}c_real.log

# export CUDA_VISIBLE_DEVICES=${gpus}
# -H 10.11.0.2:8,10.11.0.3:8,10.11.0.4:8,10.11.0.5:8 \
DATA_DIR=/data/image
export CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
#export LOCAL_RANK=0
#export RANK=0
#export WORLD_SIZE=8
#export MASTER_ADDR=10.11.0.2
#export MASTER_PORT=11122
/usr/local/mpi/bin/mpirun  -oversubscribe -np $np_num \
    -H $node_ips \
    -bind-to none -map-by slot \
    -x NCCL_DEBUG=INFO -x LD_LIBRARY_PATH -x PATH \
    --allow-run-as-root \
    -mca pml ob1 -mca btl ^openib \
    -mca plm_rsh_args "-p 11122 -q -o StrictHostKeyChecking=no" \
    -mca btl_tcp_if_include ib0 \
    -x NCCL_MIN_NRINGS=8 \
    -x NCCL_SOCKET_IFNAME=ib0 \
    python  ./multiproc.py --nnodes 1 --nproc_per_node 8 --master_addr 10.11.0.2 main.py /data/image  \
        --data-backend dali-cpu \
        --raport-file raport.json \
        -j 8 -p 1 --lr 2.048 --optimizer-batch-size -1 \
        --warmup 8 --arch resnet50 -c fanin \
        --label-smoothing 0.1 --lr-schedule cosine \
        --mom 0.875 --wd 3.0517578125e-05 \
        --workspace ${1:-./} -b 16 \
        --prof 120 --training-only --no-checkpoints

#echo "Writting log to ${LOGFILE}"

#    -x MXNET_SAFE_ACCUMULATION=1 --tag-output \
#python  ./multiproc.py --nnodes 1 --nproc_per_node 8 --master_addr 10.11.0.2 main.py /data/image \
