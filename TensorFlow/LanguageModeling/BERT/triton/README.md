<<<<<<< HEAD
# Deploying the BERT model using Triton Inference Server

## Table Of Contents

- [Solution Overview](#solution-overview)
- [Quick Start Guide](#quick-start-guide)
- [Performance](#performance)
  * [Advanced Details](#advanced-details)

## Solution Overview

The [NVIDIA Triton Inference Server](https://github.com/NVIDIA/triton-inference-server) provides a datacenter and cloud inferencing solution optimized for NVIDIA GPUs. The server provides an inference service via an HTTP or gRPC endpoint, allowing remote clients to request inferencing for any number of GPU or CPU models being managed by the server.
This subfolder of the BERT TensorFlow repository contains detailed performance analysis as well as scripts to run SQuAD fine-tuning on BERT model using Triton Inference Server.

A typical Triton Inference Server pipeline can be broken down into the following 8 steps:
1. Client serializes the inference request into a message and sends it to the server (Client Send)
2. Message travels over the network from the client to the server (Network)
3. Message arrives at server, and is deserialized (Server Receive)
4. Request is placed on the queue (Server Queue)
5. Request is removed from the queue and computed (Server Compute)
6. Completed request is serialized in a message and sent back to the client (Server Send)
7. Completed message travels over network from the server to the client (Network)
8. Completed message is deserialized by the client and processed as a completed inference request (Client Receive)

Generally, for local clients, steps 1-4 and 6-8 will only occupy a small fraction of time, compared to steps 5-6. As backend deep learning systems like BERT are rarely exposed directly to end users, but instead only interfacing with local front-end servers, for the sake of BERT, we can consider that all clients are local.
In this section, we will go over how to launch Triton Inference Server and client and get the best performant solution that fits your specific application needs.

Note: The following instructions are run from outside the container and call `docker run` commands as required.

## Quick Start Guide

The `run_triton.sh` script exports the TensorFlow BERT model as a `tensorflow_savedmodel` that Triton Inference Server accepts, builds a matching [Triton Inference Server model config](https://docs.nvidia.com/deeplearning/sdk/triton-inference-server-guide/docs/model_configuration.html#), starts the server on local host in a detached state, runs client on SQuAD v1.1 dataset and then evaluates the validity of predictions on the basis of exact match and F1 score all in one step.

```bash
bash triton/scripts/run_triton.sh <init_checkpoint> <batch_size> <precision> <use_xla> <seq_length> <doc_stride> <bert_model> <squad_version> <triton_version_name> <triton_model_name> <triton_export_model> <triton_dyn_batching_delay> <triton_engine_count> <triton_model_overwrite>
```

You can also run inference with a sample by passing `--question` and `--context` arguments to the client.

## Performance

Based on the figures 1 and 2 below, we recommend using the Dynamic Batcher with `max_batch_size = 8`, `max_queue_delay_microseconds` as large as possible to fit within your latency window (the values used below are extremely large to exaggerate their effect), and only 1 instance of the engine. The largest improvements to both throughput and latency come from increasing the batch size due to efficiency gains in the GPU with larger batches. The Dynamic Batcher combines the best of both worlds by efficiently batching together a large number of simultaneous requests, while also keeping latency down for infrequent requests. We recommend only 1 instance of the engine due to the negligible improvement to throughput at the cost of significant increases in latency. Many models can benefit from multiple engine instances but as the figures below show, that is not the case for this model.

![](../data/images/triton_base_summary.png?raw=true)

Figure 1: Latency vs Throughput for BERT Base, FP16, Sequence Length = 128 using various configurations available in Triton Inference Server

![](../data/images/triton_large_summary.png?raw=true)

Figure 2: Latency vs Throughput for BERT Large, FP16, Sequence Length = 384 using various configurations available in Triton Inference Server

### Advanced Details

This section digs deeper into the performance numbers and configurations corresponding to running Triton Inference Server for BERT fine tuning for Question Answering. It explains the tradeoffs in selecting maximum batch sizes, batching techniques and number of inference engines on the same GPU to understand how we arrived at the optimal configuration specified previously.

Results can be reproduced by running `generate_figures.sh`. It exports the TensorFlow BERT model as a `tensorflow_savedmodel` that Triton Inference Server accepts, builds a matching [Triton Inference Server model config](https://docs.nvidia.com/deeplearning/sdk/triton-inference-server-guide/docs/model_configuration.html#), starts the server on localhost in a detached state and runs [perf_client](https://docs.nvidia.com/deeplearning/sdk/triton-inference-server-guide/docs/client.html#performance-example-application) for various configurations.

```bash
bash triton/scripts/generate_figures.sh <bert_model> <seq_length> <precision> <init_checkpoint>
```

All results below are obtained on a single DGX-1 V100 32GB GPU for BERT Base, Sequence Length = 128 and FP16 precision running on a local server. Latencies are indicated by bar plots using the left axis. Throughput is indicated by the blue line plot using the right axis. X-axis indicates the concurrency - the maximum number of inference requests that can be in the pipeline at any given time. For example, when the concurrency is set to 1, the client waits for an inference request to be completed (Step 8) before it sends another to the server (Step 1).  A high number of concurrent requests can reduce the impact of network latency on overall throughput.

#### Maximum batch size

As we can see in Figure 3, the throughput at BS=1, Client Concurrent Requests = 64 is 119 and in Figure 4, the throughput at BS=8, Client Concurrent Requests = 8 is 517, respectively giving a speedup of ~4.3x

Note: We compare BS=1, Client Concurrent Requests = 64 to BS=8, Client Concurrent Requests = 8 to keep the Total Number of Outstanding Requests equal between the two different modes. Where Total Number of Outstanding Requests = Batch Size * Client Concurrent Requests. This is also why there are 8 times as many bars on the BS=1 chart than the BS=8 chart.

Increasing the batch size from 1 to 8 results in an increase in compute time by 1.8x (8.38ms to 15.46ms) showing that computation is more efficient at higher batch sizes. Hence, an optimal batch size would be the maximum batch size that can both fit in memory and is within the preferred latency threshold.

![](../data/images/triton_bs_1.png?raw=true)

Figure 3: Latency & Throughput vs Concurrency at Batch size = 1

![](../data/images/triton_bs_8.png?raw=true)

Figure 4: Latency & Throughput vs Concurrency at Batch size = 8

#### Batching techniques

Static batching is a feature of the inference server that allows inference requests to be served as they are received. It is preferred in scenarios where low latency is desired at the cost of throughput when the GPU is under utilized.

Dynamic batching is a feature of the inference server that allows inference requests to be combined by the server, so that a batch is created dynamically, resulting in an increased throughput. It is preferred in scenarios where we would like to maximize throughput and GPU utilization at the cost of higher latencies. You can set the [Dynamic Batcher parameters](https://docs.nvidia.com/deeplearning/sdk/triton-inference-server-master-branch-guide/docs/model_configuration.html#dynamic-batcher) `max_queue_delay_microseconds` to indicate the maximum amount of time you are willing to wait and ‘preferred_batchsize’ to indicate your optimal batch sizes in the Triton Inference Server model config.

Figures 5 and 6 emphasize the increase in overall throughput with dynamic batching. At low numbers of concurrent requests, the increased throughput comes at the cost of increasing latency as the requests are queued up to `max_queue_delay_microseconds`. The effect of `preferred_batchsize` for dynamic batching is visually depicted by the dip in Server Queue time at integer multiples of the preferred batch sizes. At higher numbers of concurrent requests, observe that the throughput approach a maximum limit as we saturate the GPU utilization.

![](../data/images/triton_static.png?raw=true)

Figure 5: Latency & Throughput vs Concurrency using Static Batching at `Batch size` = 1

![](../data/images/triton_dynamic.png?raw=true)

Figure 6: Latency & Throughput vs Concurrency using Dynamic Batching at `Batch size` = 1, `preferred_batchsize` = [4, 8] and `max_queue_delay_microseconds` = 5000

#### Model execution instance count

Triton Inference Server enables us to launch multiple engines in separate CUDA streams by setting the `instance_group_count` parameter to improve both latency and throughput. Multiple engines are useful when the model doesn’t saturate the GPU allowing the GPU to run multiple instances of the model in parallel.

Figures 7 and 8 show a drop in queue time as more models are available to serve an inference request. However, this is countered by an increase in compute time as multiple models compete for resources. Since BERT is a large model which utilizes the majority of the GPU, the benefit to running multiple engines is not seen.

![](../data/images/triton_ec_1.png?raw=true)

Figure 7: Latency & Throughput vs Concurrency at Batch size = 1, Engine Count = 1
(One copy of the model loaded in GPU memory)

![](../data/images/triton_ec_4.png?raw=true)

Figure 8: Latency & Throughput vs Concurrency at Batch size = 1, Engine count = 4
(Four copies the model loaded in GPU memory)
=======
# Deploying the BERT TensorFlow model using Triton Inference Server

This folder contains instructions for deployment and exemplary client application to run inference on

Triton Inference Server as well as detailed performance analysis.

## Table Of Contents

* [Solution Overview](#solution-overview)

* [Setup](#setup)

* [Quick Start Guide](#quick-start-guide)

* [Advanced](#advanced)

* [Running the Triton Inference Server](#running-the-triton-inference-server)

* [Running the Triton Inference Client](#running-the-triton-inference-client)

* [Performance](#performance)

* [Latency vs Throughput for TensorRT Engine](#latency-vs-throughput-for-tensorrt-engine)

* [Dynamic batching support](#dynamic-batching-support)

## Solution overview

The [NVIDIA Triton Inference Server](https://github.com/NVIDIA/triton-inference-server) provides a datacenter and cloud inferencing solution optimized for NVIDIA GPUs. The server provides an inference service via an HTTP/REST or gRPC endpoint, or by a C API endpoint, allowing remote clients to request inferencing for any number of GPU or CPU models being managed by the server.

A typical Triton Inference Server pipeline can be broken down into the following steps:

1. The client serializes the inference request into a message and sends it to the server (Client Send).

2. The message travels over the network from the client to the server (Network).

3. The message arrives at the server, and is deserialized (Server Receive).

4. The request is placed in the queue (Server Queue).

5. The request is removed from the queue and computed (Server Compute).

6. The completed request is serialized in a message and sent back to the client (Server Send).

7. The completed message then travels over the network from the server to the client (Network).

8. The completed message is deserialized by the client and processed as a completed inference request (Client Receive).

Generally, for local clients, steps 1-4 and 6-8 will only occupy a small fraction of time, compared to steps 5-6. As backend deep learning systems like BERT are rarely exposed directly to end users, but instead only interfacing with local front-end servers, for the sake of BERT, we can consider that all clients are local.

In this section, we will go over how to launch both the Triton Inference Server and the client and get the best performance solution that fits your specific application needs.

More information on how to perform inference using NVIDIA Triton Inference Server can be found in [triton/README.md](https://github.com/NVIDIA/DeepLearningExamples/blob/master/PyTorch/LanguageModeling/BERT/triton/README.md).

## Setup

The repository contains a folder `./triton/` with a `Dockerfile` which extends the latest TensorFlow NGC container and encapsulates some dependencies. Ensure you have the following components:

* [NVIDIA Docker](https://github.com/NVIDIA/nvidia-docker)

* [TensorFlow NGC container](https://ngc.nvidia.com/catalog/containers/nvidia:tensorflow)

* [Triton Inference Server NGC container 20.09](https://ngc.nvidia.com/catalog/containers/nvidia:tritonserver)

* [NVIDIA CUDA repository]([https://docs.nvidia.com/cuda/archive/10.2/index.html](https://docs.nvidia.com/cuda/archive/10.2/index.html)) for NVIDIA TensorRT 7.1.3

* [NVIDIA Volta](https://www.nvidia.com/en-us/data-center/volta-gpu-architecture/) or [Turing](https://www.nvidia.com/en-us/geforce/turing/) based GPU

## Quick Start Guide

Running the following scripts will build and launch the container containing all required dependencies for native TensorFlow as well as Triton. This is necessary for running inference and can also be used for data download, processing, and training of the model. For more information on the scripts and arguments, refer to the [Advanced](#advanced) section.

1. Clone the repository.

```bash
git clone https://github.com/NVIDIA/DeepLearningExamples

cd DeepLearningExamples/TensorFlow/LanguageModeling/BERT

```

2. Build a container that extends NGC TensorFlow, Triton Inference Server, and Triton Inference Client.

```bash
bash scripts/docker/build.sh

```

3. Download fine-tuned checkpoints and SQuAD dataset.

To download the data to `data/download`, run:  
  

```bash
bash scripts/docker/launch.sh triton/scripts/triton_data_download.sh

```

4. Run inference.


The Triton Inference Server can serve either of the following two BERT models:

4.1. TensorFlow SavedModel

The `run_triton_tf.sh` script starts the server on a local host in a detached state, runs the client on the SQuAD v1.1 dataset and then evaluates the validity of predictions on the basis of the exact match and F1 score all in one step.


The script exports the TensorFlow BERT model checkpoint as a `tensorflow_savedmodel` that Triton Inference Server accepts and builds a matching [Triton Inference Server model config](https://docs.nvidia.com/deeplearning/sdk/triton-inference-server-guide/docs/model_configuration.html) when `triton_export_model` is set to `true`.

```bash
bash triton/scripts/run_triton_tf.sh <init_checkpoint> <batch_size> <precision> <use_xla> <seq_length> <doc_stride> <bert_model> <squad_version> <triton_version_name> <triton_model_name> <triton_export_model> <triton_dyn_batching_delay> <triton_engine_count> <triton_model_overwrite>

```

Refer to the advanced section for details on launching client and server separately for debugging.

4.2. TensorRT Model

In order to use the BERT TensorRT engine, follow the steps underlined in [TensorRT Repository](https://github.com/NVIDIA/TensorRT/tree/master/demo/BERT) to build a TensorRT engine. Place it as `results/triton_models/<triton_model_name>/<triton_version_name>/model.plan` and use the `run_triton_trt.sh` script as follows.

```bash
bash triton/scripts/run_triton_trt.sh <batch_size> <seq_length> <doc_stride> <bert_model> <squad_version> <triton_version_name> <triton_model_name>

```

Notes:

-   [Triton Inference Server 20.09](https://docs.nvidia.com/deeplearning/triton-inference-server/release-notes/rel_20-09.html#rel_20-09) is compatible with [TensorRT 7.1.3](https://docs.nvidia.com/deeplearning/tensorrt/release-notes/index.html).


-   The current Triton Inference Server works with the TensorRT engine with `batch_size > 1`.


-   To use the performance client with dynamic batching, build an engine with -b <N> -b <N+1>` to support dynamic batches upto size N.


## Advanced

The following sections provide greater details about the Triton Inference Server pipeline and inference analysis and benchmarking results.

### Running the Triton Inference Server

Launch the Triton Inference Server in detached mode to run in background by default. To run in the foreground interactively, for debugging purposes, run:

```bash
DETACHED=”-it” bash scripts/docker/launch_server.sh

```

The script mounts and loads models at `$PWD/results/triton_models` to the server with all visible GPUs. In order to selectively choose the devices, set `NVIDIA_VISIBLE_DEVICES`.

### Running the Triton Inference Client

*Real data*

In order to run the client with real data, run:

```bash
bash triton/scripts/run_client.sh <batch_size> <seq_length> <doc_stride> <triton_version_name> <triton_model_name> <BERT_DIR> <ADDITIONAL_ARGS>

```

The script calls `triton/run_squad_triton_client.py` which preprocesses data and sends/receives requests to/from the server.

`ADDITIONAL_ARGS` must include either `--predict_file` to use the SQuAD dataset or a sample by passing `--question` and `--context`. Append with `--trt_engine` if running inference on a TensorRT engine server.

*Synthetic data*

In order to run the client with synthetic data for performance measurements, run:

```bash
bash triton/scripts/run_perf_client.sh <model_name> <model_version> <batch_size> <max_latency> <max_client_threads> <max_concurrency> <server_hostname>

```

The script waits until the server is up and running, sends requests as per the constraints set and writes results to `OUTPUT_FILE_CSV="/results/perf_client/${MODEL_NAME}/results_${TIMESTAMP}.csv`.

For more information about `perf_client`, refer to the [official documentation](https://docs.nvidia.com/deeplearning/triton-inference-server/master-user-guide/docs/optimization.html#perf-client).

## Performance

### Latency vs Throughput for TensorRT Engine

Performance numbers for BERT Large, sequence length=384 are obtained from [experiments](https://github.com/NVIDIA/TensorRT/tree/release/7.1/demo/BERT#inference-performance-nvidia-a100-40gb) on NVIDIA A100 with 1x A100 40G GPUs. Throughput is measured in samples/second, and latency in milliseconds.

![](../data/images/bert_trt_throughput_vs_latency.png?raw=true)

The plot above shows that throughput gains taper off from increasing batch size above 12. There is minimal gain in throughput going from batch size 12 to 128. However, running inference with a single large batch might be faster than running several small inference requests. Therefore, we choose to maximize batch size for Dynamic Batching with a maximum acceptable queuing delay of 1ms and maximum acceptable inference latency of 100ms.

### Dynamic Batching Support

The Triton server has a dynamic batching mechanism built in, that can be enabled. When it is enabled, the server creates

inference batches from the received requests. With dynamic batching enabled, the server will concatenate requests that come in within maximum queue delay time, into a single inference batch. To configure these parameters and run dynamic batching for a model, issue:  
  

```bash
#Set server config for dynamic batching with maximum queue delay  
echo "dynamic_batching { max_queue_delay_microseconds: 1000 }" >> results/triton_models/bert/config.pbtxt  

#Launch Server
DETACHED="-it" bash triton/scripts/launch_server.sh


#Run perf client in another terminal
bash triton/scripts/run_perf_client.sh bert 1 12

```

Note that the TensorRT engine takes 30+ minutes to build depending on the profile size. Loading it on TRITON server can be sped up by only loading only on required GPUs.

Performance results on a single A100 40G for various numbers of simultaneous requests are shown in the figure below.

![](../data/images/bert_triton_dynamic_batching_a100.png?raw=true)

The plot above shows that if we have a 100ms upper bound on latency, then a single GPU can handle up to 9 concurrent requests before throughput saturates. This leads to total throughput of ~1045 sequences per second.

## Release Notes

### Changelog


October 2020
Add scripts to use TensorRT engines for inference

September 2020
Update to TRITON 20.08

April 2020
TRTIS -> TRITON

October 2019
Initial release
>>>>>>> repo1
