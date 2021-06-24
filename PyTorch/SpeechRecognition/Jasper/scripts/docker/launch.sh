#!/bin/bash
<<<<<<< HEAD
SCRIPT_DIR=$(cd $(dirname $0); pwd)
JASPER_REPO=${JASPER_REPO:-"${SCRIPT_DIR}/../.."}

# Launch TRT JASPER container.

DATA_DIR=${1:-${DATA_DIR-"/datasets"}}
CHECKPOINT_DIR=${2:-${CHECKPOINT_DIR:-"/checkpoints"}}
RESULT_DIR=${3:-${RESULT_DIR:-"/results"}}
PROGRAM_PATH=${PROGRAM_PATH}
=======

SCRIPT_DIR=$(cd $(dirname $0); pwd)
: ${JASPER_REPO:="$SCRIPT_DIR/../.."}

: ${DATA_DIR:=${1:-"$JASPER_REPO/datasets"}}
: ${CHECKPOINT_DIR:=${2:-"$JASPER_REPO/checkpoints"}}
: ${OUTPUT_DIR:=${3:-"$JASPER_REPO/results"}}
: ${SCRIPT:=${4:-}}

mkdir -p $DATA_DIR
mkdir -p $CHECKPOINT_DIR
mkdir -p $OUTPUT_DIR
>>>>>>> repo1

MOUNTS=""
MOUNTS+=" -v $DATA_DIR:/datasets"
MOUNTS+=" -v $CHECKPOINT_DIR:/checkpoints"
<<<<<<< HEAD
MOUNTS+=" -v $RESULT_DIR:/results"
MOUNTS+=" -v ${JASPER_REPO}:/jasper"

echo $MOUNTS
nvidia-docker run -it --rm \
  --runtime=nvidia \
  --shm-size=4g \
  --ulimit memlock=-1 \
  --ulimit stack=67108864 \
  ${MOUNTS} \
  ${EXTRA_JASPER_ENV} \
  jasper:latest bash $PROGRAM_PATH
=======
MOUNTS+=" -v $OUTPUT_DIR:/results"
MOUNTS+=" -v $JASPER_REPO:/workspace/jasper"

echo $MOUNTS
docker run -it --rm --gpus all \
  --env PYTHONDONTWRITEBYTECODE=1 \
  --shm-size=4g \
  --ulimit memlock=-1 \
  --ulimit stack=67108864 \
  $MOUNTS \
  $EXTRA_JASPER_ENV \
  -w /workspace/jasper \
  jasper:latest bash $SCRIPT
>>>>>>> repo1
