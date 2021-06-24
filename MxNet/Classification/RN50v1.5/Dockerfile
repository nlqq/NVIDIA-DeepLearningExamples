<<<<<<< HEAD
FROM nvcr.io/nvidia/mxnet:19.07-py3
COPY . /workspace/rn50
WORKDIR /workspace/rn50
=======
ARG FROM_IMAGE_NAME=nvcr.io/nvidia/mxnet:20.12-py3

FROM $FROM_IMAGE_NAME

WORKDIR /workspace/rn50

COPY requirements.txt .
RUN pip install -r requirements.txt

COPY . .
>>>>>>> repo1
