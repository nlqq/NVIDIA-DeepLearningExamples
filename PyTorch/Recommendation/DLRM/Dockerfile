<<<<<<< HEAD
# Copyright (c) 2020 NVIDIA CORPORATION. All rights reserved.
=======
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
ARG FROM_IMAGE_NAME=nvcr.io/nvidia/pytorch:20.06-py3
FROM ${FROM_IMAGE_NAME}

RUN apt update && \
    apt install -y openjdk-8-jdk && \
    curl http://archive.apache.org/dist/spark/spark-2.4.5/spark-2.4.5-bin-hadoop2.7.tgz -o /opt/spark-2.4.5-bin-hadoop2.7.tgz && \
    tar zxf /opt/spark-2.4.5-bin-hadoop2.7.tgz -C /opt/ && \
    rm /opt/spark-2.4.5-bin-hadoop2.7.tgz

=======
ARG FROM_IMAGE_NAME=nvcr.io/nvidia/pytorch:21.04-py3
FROM ${FROM_IMAGE_NAME}

>>>>>>> repo1
ADD requirements.txt .
RUN pip install -r requirements.txt

WORKDIR /workspace/dlrm

COPY . .

<<<<<<< HEAD
=======
RUN chmod +x bind.sh
>>>>>>> repo1
RUN pip install --no-cache-dir -e .
