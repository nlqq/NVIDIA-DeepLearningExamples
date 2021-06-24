# Copyright (c) 2020, NVIDIA CORPORATION. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
<<<<<<< HEAD
""" Scripts that simplifies running evaluation benchmark """
=======
""" Script that simplifies running evaluation benchmark """
>>>>>>> repo1

import argparse
import os
import shutil
import subprocess


<<<<<<< HEAD
def main():
    # CLI flags
    parser = argparse.ArgumentParser(description="MaskRCNN evaluation benchmark")
    parser.add_argument('--batch_size', type=int, required=True)
    parser.add_argument('--amp', action='store_true')
    parser.add_argument('--data_dir', type=str, default='/data')
    parser.add_argument('--model_dir', type=str, default='/tmp/model')
    parser.add_argument('--weights_dir', type=str, default='/model')

    flags = parser.parse_args()
    main_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../mask_rcnn_main.py'))
=======
class CustomFormatter(argparse.ArgumentDefaultsHelpFormatter, argparse.RawTextHelpFormatter):
    pass


if __name__ == '__main__':

    # CLI flags
    # noinspection PyTypeChecker
    parser = argparse.ArgumentParser(
        description=(
            'NVIDIA MaskRCNN TF2 evaluation benchmark'
            '\n\nNote: Any additional flags not specified below will be passed to main.py'
        ),
        formatter_class=lambda prog: CustomFormatter(prog, max_help_position=100)
    )
    parser.add_argument('--batch_size', type=int, required=True,
                        help='Batch size used during training')
    parser.add_argument('--amp', action='store_true',
                        help='Enable automatic mixed precision')
    parser.add_argument('--no_xla', action='store_true',
                        help='Disables XLA - accelerated linear algebra')
    parser.add_argument('--data_dir', type=str, metavar='DIR', default='/data',
                        help='Input directory containing the dataset')
    parser.add_argument('--weights_dir', type=str, metavar='DIR', default='/weights',
                        help='Directory containing pre-trained resnet weights')

    flags, remainder = parser.parse_known_args()

    main_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../main.py'))
    checkpoint_path = os.path.join(flags.weights_dir, "rn50_tf_amp_ckpt_v20.06.0/nvidia_rn50_tf_amp")
>>>>>>> repo1

    # build command
    cmd = (
        f'python {main_path}'
<<<<<<< HEAD
        f' --mode eval'
        f' --model_dir "{flags.model_dir}"'
        f' --checkpoint "{os.path.join(flags.weights_dir, "resnet/resnet-nhwc-2018-02-07/model.ckpt-112603")}"'
        f' --validation_file_pattern "{os.path.join(flags.data_dir, "val*.tfrecord")}"'
        f' --val_json_file "{os.path.join(flags.data_dir, "annotations/instances_val2017.json")}"' 
        f' --num_steps_per_eval 200'
        f' --eval_samples 1200' 
        f' --use_batched_nms'
        f' --nouse_custom_box_proposals_op'
        f' --xla'
        f' --eval_batch_size {flags.batch_size}'
        f' {"--amp" if flags.amp else ""}'
    )

    # print command
    line = '-' * shutil.get_terminal_size()[0]
    print(line, cmd, line, sep='\n')

    # run model
    subprocess.call(cmd, shell=True)


if __name__ == '__main__':
    main()
=======
        f' infer'
        f' --data_dir "{flags.data_dir}"'
        f' --backbone_checkpoint "{checkpoint_path}"'
        f' --eval_samples {200 * flags.batch_size}'
        f' --log_warmup_steps 100'
        f' --log_every 10'
        f' --eval_batch_size {flags.batch_size}'
    )

    if not flags.no_xla:
        cmd += ' --xla'
    if flags.amp:
        cmd += ' --amp'
    if remainder:
        cmd += ' ' + ' '.join(remainder)

    # print command
    line = '-' * shutil.get_terminal_size()[0]
    print(line, cmd, line, sep='\n', flush=True)

    # run model
    exit(subprocess.call(cmd, shell=True))
>>>>>>> repo1
