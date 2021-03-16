#NV_VISIBLE_DEVICES=${NVIDIA_VISIBLE_DEVICES:-"all"}
DOCKER_BRIDGE=${1:-"bridge"}
NV_VISIBLE_DEVICES=${NVIDIA_VISIBLE_DEVICES:-"0,1"}

# Start TRTIS server in detached state
nvidia-docker run -d --rm \
   --shm-size=1g \
   --ulimit memlock=-1 \
   --ulimit stack=67108864 \
   --network=${DOCKER_BRIDGE} \
   -p 8000:8000 \
   -p 8001:8001 \
   -p 8002:8002 \
   --name trt_server_cont \
   -e NVIDIA_VISIBLE_DEVICES=$NV_VISIBLE_DEVICES \
   -v $PWD/results/trtis_models:/models \
   nvcr.io/nvidia/tensorrtserver:19.12-py3  trtserver --model-store=/models --strict-model-config=false --log-verbose=1
