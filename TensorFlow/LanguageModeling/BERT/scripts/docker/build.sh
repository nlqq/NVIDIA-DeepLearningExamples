#!/bin/bash

<<<<<<< HEAD
docker pull nvcr.io/nvidia/tritonserver:20.06-v1-py3
=======
docker pull nvcr.io/nvidia/tritonserver:20.09-py3
>>>>>>> repo1

docker build . --rm -t bert
