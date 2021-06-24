#!/usr/bin/env bash

<<<<<<< HEAD
DATA_DIR="LJSpeech-1.1"

[ ! -n "$WAVEG_CH" ] && WAVEG_CH="pretrained_models/waveglow/waveglow_1076430_14000_amp.pt"
[ ! -n "$FASTPITCH_CH" ] && FASTPITCH_CH="output/FastPitch_checkpoint_1500.pt"
[ ! -n "$BS" ] && BS=32
[ ! -n "$PHRASES" ] && PHRASES="phrases/devset10.tsv"
[ ! -n "$OUTPUT_DIR" ] && OUTPUT_DIR="./output/audio_$(basename ${PHRASES} .tsv)"
[ "$AMP" == "true" ] && AMP_FLAG="--amp"
=======
: ${WAVEGLOW:="pretrained_models/waveglow/nvidia_waveglow256pyt_fp16.pt"}
: ${FASTPITCH:="output/FastPitch_checkpoint_1500.pt"}
: ${BS:=32}
: ${PHRASES:="phrases/devset10.tsv"}
: ${OUTPUT_DIR:="./output/audio_$(basename ${PHRASES} .tsv)"}
: ${AMP:=false}

[ "$AMP" = true ] && AMP_FLAG="--amp"

mkdir -p "$OUTPUT_DIR"
>>>>>>> repo1

python inference.py --cuda \
                    -i ${PHRASES} \
                    -o ${OUTPUT_DIR} \
<<<<<<< HEAD
                    --dataset-path ${DATA_DIR} \
                    --fastpitch ${FASTPITCH_CH} \
                    --waveglow ${WAVEG_CH} \
=======
                    --fastpitch ${FASTPITCH} \
                    --waveglow ${WAVEGLOW} \
>>>>>>> repo1
		    --wn-channels 256 \
                    --batch-size ${BS} \
                    ${AMP_FLAG}
