<<<<<<< HEAD
def relocated():
    raise ValueError(
        "NVIDIA entrypoints moved to branch torchhub \n"
        "Use torch.hub.load('NVIDIA/DeepLearningExamples:torchhub', ...) to access the models"
    )


def nvidia_ncf(**kwargs):
    """Entrypoints moved to branch torchhub
    """
    relocated()


def nvidia_tacotron2(**kwargs):
    """Entrypoints moved to branch torchhub
    """
    relocated()


def nvidia_waveglow(**kwargs):
    """Entrypoints moved to branch torchhub
    """
    relocated()


def nvidia_ssd_processing_utils():
    """Entrypoints moved to branch torchhub
    """
    relocated()


def nvidia_ssd(**kwargs):
    """Entrypoints moved to branch torchhub
    """
    relocated()
=======
import os
import sys

from PyTorch.Detection.SSD.src import nvidia_ssd, nvidia_ssd_processing_utils
sys.path.append(os.path.join(sys.path[0], 'PyTorch/Detection/SSD'))

from PyTorch.SpeechSynthesis.Tacotron2.tacotron2 import nvidia_tacotron2
from PyTorch.SpeechSynthesis.Tacotron2.tacotron2 import nvidia_tts_utils
from PyTorch.SpeechSynthesis.Tacotron2.waveglow import nvidia_waveglow
sys.path.append(os.path.join(sys.path[0], 'PyTorch/SpeechSynthesis/Tacotron2'))
>>>>>>> repo1
