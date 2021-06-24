<<<<<<< HEAD
# Copyright (c) 2020 NVIDIA CORPORATION. All rights reserved.
=======
#! /bin/bash

# Copyright (c) 2021 NVIDIA CORPORATION. All rights reserved.
>>>>>>> repo1
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

<<<<<<< HEAD
#! /bin/bash
=======
# Examples:
# to run on GPU with a frequency limit of 3 using NVTabular:
#   ./prepare_dataset.sh 3 GPU NVTabular
#
# to run on GPU with a frequency limit of 15 using Spark GPU:
#   ./prepare_dataset.sh 15 GPU Spark
#
# to run on CPU with a frequency limit of 15 using Spark CPU:
#   ./prepare_dataset.sh 15 CPU
>>>>>>> repo1

set -e
set -x

ls -ltrash

<<<<<<< HEAD
download_dir=${download_dir:-'/data/dlrm/criteo'}
./verify_criteo_downloaded.sh ${download_dir}

spark_output_path=${spark_output_path:-'/data/dlrm/spark/output'}


if [ -f ${spark_output_path}/train/_SUCCESS ] \
   && [ -f ${spark_output_path}/validation/_SUCCESS ] \
   && [ -f ${spark_output_path}/test/_SUCCESS ]; then

   echo "Spark preprocessing already carried done"
else
   echo "Performing spark preprocessing"
   ./run_spark.sh ${download_dir} ${spark_output_path}
=======

rm -rf /data/dlrm/spark
rm -rf /data/dlrm/intermediate_binary
rm -rf /data/dlrm/output
rm -rf /data/dlrm/criteo_parquet
rm -rf /data/dlrm/binary_dataset


download_dir=${download_dir:-'/data/dlrm/criteo'}
./verify_criteo_downloaded.sh ${download_dir}

output_path=${output_path:-'/data/dlrm/output'}


if [ "$3" = "NVTabular" ]; then
    echo "Performing NVTabular preprocessing"
    ./run_NVTabular.sh ${download_dir} ${output_path} $1
    preprocessing_version=NVTabular
else
    if [ -f ${output_path}/train/_SUCCESS ] \
        && [ -f ${output_path}/validation/_SUCCESS ] \
        && [ -f ${output_path}/test/_SUCCESS ]; then

        echo "Spark preprocessing already carried out"
    else
        echo "Performing spark preprocessing"
        ./run_spark.sh $2 ${download_dir} ${output_path} $1
    fi
    preprocessing_version=Spark
>>>>>>> repo1
fi

conversion_intermediate_dir=${conversion_intermediate_dir:-'/data/dlrm/intermediate_binary'}
final_output_dir=${final_output_dir:-'/data/dlrm/binary_dataset'}

<<<<<<< HEAD

if [ -d ${final_output_dir}/train ] \
   && [ -d ${final_output_dir}/val ] \
=======
source ${DGX_VERSION}_config.sh

if [ -d ${final_output_dir}/train ] \
   && [ -d ${final_output_dir}/validation ] \
>>>>>>> repo1
   && [ -d ${final_output_dir}/test ] \
   && [ -f ${final_output_dir}/model_sizes.json ]; then

    echo "Final conversion already done"
else
    echo "Performing final conversion to a custom data format"
<<<<<<< HEAD
    python parquet_to_binary.py --parallel_jobs 40 --src_dir ${spark_output_path} \
                                --intermediate_dir  ${conversion_intermediate_dir} \
                                --dst_dir ${final_output_dir}

    cp "${spark_output_path}/model_size.json" "${final_output_dir}/model_size.json"

    python split_dataset.py --dataset "${final_output_dir}" --output "${final_output_dir}/split"
    rm ${final_output_dir}/train_data.bin
    rm ${final_output_dir}/val_data.bin
=======
    python parquet_to_binary.py --parallel_jobs ${TOTAL_CORES} --src_dir ${output_path} \
                                --intermediate_dir  ${conversion_intermediate_dir} \
                                --dst_dir ${final_output_dir}

    cp "${output_path}/model_size.json" "${final_output_dir}/model_size.json"

    python split_dataset.py --dataset "${final_output_dir}" --output "${final_output_dir}/split"
    rm ${final_output_dir}/train_data.bin
    rm ${final_output_dir}/validation_data.bin
>>>>>>> repo1
    rm ${final_output_dir}/test_data.bin

    mv ${final_output_dir}/split/* ${final_output_dir}
    rm -rf ${final_output_dir}/split
fi

echo "Done preprocessing the Criteo Kaggle Dataset"
<<<<<<< HEAD
echo "You can now start the training with: "
echo "python -m dlrm.scripts.main --mode train --dataset  ${final_output_dir}"
=======
>>>>>>> repo1
