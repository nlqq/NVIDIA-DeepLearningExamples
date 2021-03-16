#!/bin/bash

git submodule update --init --recursive \
    && cd tensorrt-inference-server \
    && docker build --network=host -t tensorrtserver_client -f Dockerfile.client . \
    && cd -
docker build --network=host . --rm -t bert
    #&& git checkout r19.12 \
