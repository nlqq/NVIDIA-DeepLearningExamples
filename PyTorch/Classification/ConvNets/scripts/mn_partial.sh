FLAGS=$1
STAGE_ID=$2
STAGE_LEN=$3

clear
rm GPU_*.log

python ../multiproc.py  \
    --nproc_per_node 4 \
        ../main.py /export/nfs/datasets/imageNet/imagenet2012  \
            -j10 -p 100  \
            --data-backend dali-gpu  \
            --raport-file report.json \
            --lr 2.048  \
            --batch-size 120 \
            --optimizer-batch-size 2048  \
            --static-loss-scale 128 \
            --warmup 8  \
            --arch mnasnet \
            --label-smoothing 0.1  \
            --lr-schedule cosine  \
            --mom 0.875  \
            --wd 3.0517578125e-05  \
            --workspace ./results \
            --epochs 250 
            #--run-epochs $STAGE_LEN \
          #  $FLAGS \
           # --resume ./results/checkpoint_$( expr $STAGE_ID - 1).pth.tar 
           # --checkpoint checkpoint_$STAGE_ID.pth.tar #-c fanin  \

