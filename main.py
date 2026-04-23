python -c "
import whisperx, parselmouth, librosa, torch
from transformers import Wav2Vec2Processor
print('WhisperX:', whisperx.__version__ if hasattr(whisperx, '__version__') else 'installed')
print('Parselmouth:', parselmouth.__version__)
print('Torch:', torch.__version__, '| CUDA:', torch.cuda.is_available(), '| MPS:', torch.backends.mps.is_available())
print('All good.')
 