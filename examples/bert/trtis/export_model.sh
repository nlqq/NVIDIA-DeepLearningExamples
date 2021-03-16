NV_VISIBLE_DEVICES=${1:-"all"}
DOCKER_BRIDGE=${2:-"host"}
checkpoint=${3:-"/workspace/checkpoints/bert_qa_fp32.pt"}
batch_size=${4:-"8"}
BERT_DIR=${5:-"/workspace/bert"}
precision=${6:-"fp32"}
trtis_model_version=${7:-1}
trtis_model_name=${8:-"bertQA-ts"}
trtis_dyn_batching_delay=${9:-0}
trtis_engine_count=${10:-1}
trtis_model_overwrite=${11:-"False"}

CMD="python trtis/deployer.py \
    --ts-script \
    --save-dir /results/trtis_models \
    --trtis-model-name ${trtis_model_name} \
    --trtis-model-version ${trtis_model_version} \
    --trtis-max-batch-size ${batch_size} \
    --trtis-dyn-batching-delay ${trtis_dyn_batching_delay} \
    --trtis-engine-count ${trtis_engine_count} \
    -- --checkpoint ${checkpoint} \
    --config_file ${BERT_DIR}/bert_config.json \
    --vocab_file /workspace/bert/vocab/vocab \
    --do_lower_case "

if [[ $precision == "fp16" ]]; then
    CMD+="--fp16 "
fi

bash scripts/docker/launch.sh "${CMD}" ${NV_VISIBLE_DEVICES} ${DOCKER_BRIDGE}
