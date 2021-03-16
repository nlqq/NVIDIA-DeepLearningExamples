# Set the number of devices to use

export TRTIS_MODEL_OVERWRITE=True
NV_VISIBLE_DEVICES=0

bert_model=${1:-"large"}
precision=${2:-"fp32"}
init_checkpoint=${3:-"/workspace/checkpoints/bert_qa_fp32.pt"}

MODEL_NAME="bert_${bert_model}_${precision}"
BERT_DIR="/workspace/bert"
# Create common bridge for client and server
BRIDGE_NAME="trtisnet"
docker network create ${BRIDGE_NAME}

# Start Server
echo Starting server...
SERVER_ID=$( ./trtis/launch_trtis_server.sh ${BRIDGE_NAME} )
SERVER_IP=$( docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' ${SERVER_ID} )


EXPORT_MODEL_ARGS="${BERT_DIR} ${precision} 1 ${MODEL_NAME}"
PERF_CLIENT_ARGS="50000 10 20"

# Restart Server
restart_server() {
docker kill trt_server_cont
SERVER_ID=$( ./trtis/launch_trtis_server.sh ${BRIDGE_NAME} )
SERVER_IP=$( docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' ${SERVER_ID} )
}

# Clean up
cleanup() {
    docker kill trt_server_cont
    docker network rm ${BRIDGE_NAME}
}
trap cleanup EXIT

############## Dynamic Batching Comparison ##############
SERVER_BATCH_SIZE=8
CLIENT_BATCH_SIZE=1
TRTIS_ENGINE_COUNT=1

# Dynamic batching 10 ms
TRTIS_DYN_BATCHING_DELAY=10
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} ${PERF_CLIENT_ARGS} ${SERVER_IP} ${BRIDGE_NAME}

# Dynamic batching 5 ms
TRTIS_DYN_BATCHING_DELAY=5
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} ${PERF_CLIENT_ARGS} ${SERVER_IP} ${BRIDGE_NAME}

# Dynamic batching 2 ms
TRTIS_DYN_BATCHING_DELAY=2
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} ${PERF_CLIENT_ARGS} ${SERVER_IP} ${BRIDGE_NAME}


# Static Batching (i.e. Dynamic batching 0 ms)
TRTIS_DYN_BATCHING_DELAY=0
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} ${PERF_CLIENT_ARGS} ${SERVER_IP} ${BRIDGE_NAME}

############## Engine Count Comparison ##############
SERVER_BATCH_SIZE=1
CLIENT_BATCH_SIZE=1
TRTIS_DYN_BATCHING_DELAY=0

# Engine Count = 4
TRTIS_ENGINE_COUNT=4
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} ${PERF_CLIENT_ARGS} ${SERVER_IP} ${BRIDGE_NAME}

# Engine Count = 2
TRTIS_ENGINE_COUNT=2
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} ${PERF_CLIENT_ARGS} ${SERVER_IP} ${BRIDGE_NAME}

# Engine Count = 1
TRTIS_ENGINE_COUNT=1
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} ${PERF_CLIENT_ARGS} ${SERVER_IP} ${BRIDGE_NAME}


############## Batch Size Comparison ##############
# BATCH=1 Generate model and perf
SERVER_BATCH_SIZE=1
CLIENT_BATCH_SIZE=1
TRTIS_ENGINE_COUNT=1
TRTIS_DYN_BATCHING_DELAY=0

./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} 1000 10 64 ${SERVER_IP} ${BRIDGE_NAME}

# BATCH=2 Generate model and perf
SERVER_BATCH_SIZE=2
CLIENT_BATCH_SIZE=2
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} 1000 10 32 ${SERVER_IP} ${BRIDGE_NAME}

# BATCH=4 Generate model and perf
SERVER_BATCH_SIZE=4
CLIENT_BATCH_SIZE=4
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} 1000 10 16 ${SERVER_IP} ${BRIDGE_NAME}

# BATCH=8 Generate model and perf
SERVER_BATCH_SIZE=8
CLIENT_BATCH_SIZE=8
./trtis/export_model.sh ${NV_VISIBLE_DEVICES} ${BRIDGE_NAME} ${init_checkpoint} ${SERVER_BATCH_SIZE} ${EXPORT_MODEL_ARGS} ${TRTIS_DYN_BATCHING_DELAY} ${TRTIS_ENGINE_COUNT} ${TRTIS_MODEL_OVERWRITE}
restart_server
sleep 15
./trtis/run_perf_client.sh ${MODEL_NAME} 1 ${precision} ${CLIENT_BATCH_SIZE} 1000 10 8 ${SERVER_IP} ${BRIDGE_NAME}

