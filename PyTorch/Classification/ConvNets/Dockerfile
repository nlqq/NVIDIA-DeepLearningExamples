<<<<<<< HEAD
ARG FROM_IMAGE_NAME=nvcr.io/nvidia/pytorch:20.06-py3
=======
ARG FROM_IMAGE_NAME=nvcr.io/nvidia/pytorch:21.03-py3
>>>>>>> repo1
FROM ${FROM_IMAGE_NAME}

ADD requirements.txt /workspace/
WORKDIR /workspace/
<<<<<<< HEAD
=======
RUN pip install nvidia-pyindex
>>>>>>> repo1
RUN pip install --no-cache-dir -r requirements.txt
ADD . /workspace/rn50
WORKDIR /workspace/rn50
