# Copyright (c) 2017, Apple Inc. All rights reserved.
#
# Use of this source code is governed by a BSD-3-clause license that can be
# found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause

"""
List of all external dependencies for this package. Imported as
optional includes
"""
import platform as _platform
import re as _re
import sys as _sys

from packaging.version import Version

from coremltools import _logger as logger

_HAS_KMEANS1D = True
try:
    from . import kmeans1d as _kmeans1d
except:
    _kmeans1d = None
    _HAS_KMEANS1D = False


def _get_version(version):
    # matching 1.6.1, and 1.6.1rc, 1.6.1.dev
    version_regex = r"^\d+\.\d+\.\d+"
    version = _re.search(version_regex, str(version)).group(0)
    return Version(version)


def _warn_if_above_max_supported_version(package_name, package_version, max_supported_version):
    if _get_version(package_version) > Version(max_supported_version):
        logger.warning(
            "%s version %s has not been tested with coremltools. You may run into unexpected errors. "
            "%s %s is the most recent version that has been tested."
            % (package_name, package_version, package_name, max_supported_version)
        )


# ---------------------------------------------------------------------------------------

_IS_MACOS = _sys.platform == "darwin"
_MACOS_VERSION = ()

if _IS_MACOS:
    ver_str = _platform.mac_ver()[0]
    MACOS_VERSION = tuple([int(v) for v in ver_str.split(".")])

MSG_ONLY_MACOS = "Only supported on macOS"

# ---------------------------------------------------------------------------------------
_HAS_SKLEARN = True
_SKLEARN_VERSION = None
_SKLEARN_MIN_VERSION = "0.17"
_SKLEARN_MAX_VERSION = "1.5.1"


def __get_sklearn_version(version):
    # matching 0.15b, 0.16bf, etc
    version_regex = r"^\d+\.\d+"
    version = _re.search(version_regex, str(version)).group(0)
    return Version(version)


try:
    import sklearn

    _SKLEARN_VERSION = __get_sklearn_version(sklearn.__version__)
    if _SKLEARN_VERSION < Version(
        _SKLEARN_MIN_VERSION
    ) or _SKLEARN_VERSION > Version(_SKLEARN_MAX_VERSION):
        _HAS_SKLEARN = False
        logger.warning(
            (
                "scikit-learn version %s is not supported. Minimum required version: %s. "
                "Maximum required version: %s. "
                "Disabling scikit-learn conversion API."
            )
            % (sklearn.__version__, _SKLEARN_MIN_VERSION, _SKLEARN_MAX_VERSION)
        )
except:
    _HAS_SKLEARN = False
MSG_SKLEARN_NOT_FOUND = "Sklearn not found."

# ---------------------------------------------------------------------------------------
_HAS_LIBSVM = True
try:
    from libsvm import svm
except:
    _HAS_LIBSVM = False
MSG_LIBSVM_NOT_FOUND = "Libsvm not found."

# ---------------------------------------------------------------------------------------
_HAS_XGBOOST = True
_XGBOOST_MAX_VERSION = "1.4.2"
try:
    import xgboost
    _warn_if_above_max_supported_version("XGBoost", xgboost.__version__, _XGBOOST_MAX_VERSION)
except:
    _HAS_XGBOOST = False

# ---------------------------------------------------------------------------------------
_HAS_TF = True
_HAS_TF_1 = False
_HAS_TF_2 = False
_TF_1_MIN_VERSION = "1.12.0"
_TF_1_MAX_VERSION = "1.15.4"
_TF_2_MIN_VERSION = "2.1.0"
_TF_2_MAX_VERSION = "2.12.0"

try:
    import tensorflow

    tf_ver = _get_version(tensorflow.__version__)

    # TensorFlow
    if tf_ver < Version("2.0.0"):
        _HAS_TF_1 = True

    if tf_ver >= Version("2.0.0"):
        _HAS_TF_2 = True

    if _HAS_TF_1:
        logger.warning("Coremltools will drop support for conversion from TensorFlow 1.x models in the next release.")

        if tf_ver < Version(_TF_1_MIN_VERSION):
            logger.warning(
                (
                    "TensorFlow version %s is not supported. Minimum required version: %s ."
                    "TensorFlow conversion will be disabled."
                )
                % (tensorflow.__version__, _TF_1_MIN_VERSION)
            )
        _warn_if_above_max_supported_version("TensorFlow", tensorflow.__version__, _TF_1_MAX_VERSION)
    elif _HAS_TF_2:
        if tf_ver < Version(_TF_2_MIN_VERSION):
            logger.warning(
                (
                    "TensorFlow version %s is not supported. Minimum required version: %s ."
                    "TensorFlow conversion will be disabled."
                )
                % (tensorflow.__version__, _TF_2_MIN_VERSION)
            )
        _warn_if_above_max_supported_version("TensorFlow", tensorflow.__version__, _TF_2_MAX_VERSION)

except:
    _HAS_TF = False
    _HAS_TF_1 = False
    _HAS_TF_2 = False

MSG_TF1_NOT_FOUND = "TensorFlow 1.x not found."
MSG_TF2_NOT_FOUND = "TensorFlow 2.x not found."

# ---------------------------------------------------------------------------------------
_HAS_TORCH = True
_TORCH_MAX_VERSION = "2.7.0"
_HAS_TORCH_EXPORT_API = False
_CT_OPTIMIZE_TORCH_MIN_VERSION = "2.1.0"
_IMPORT_CT_OPTIMIZE_TORCH = False
try:
    import torch
    _warn_if_above_max_supported_version("Torch", torch.__version__, _TORCH_MAX_VERSION)

    torch_version = _get_version(torch.__version__)

    if torch_version >= Version("2.5.0"):
        _HAS_TORCH_EXPORT_API = True

    if torch_version >= Version(_CT_OPTIMIZE_TORCH_MIN_VERSION):
        _IMPORT_CT_OPTIMIZE_TORCH = True
    else:
        logger.warning(
            (
                f"Minimum required torch version for importing coremltools.optimize.torch is {_CT_OPTIMIZE_TORCH_MIN_VERSION}. "
                f"Got torch version {torch_version}."
            )
        )

except:
    _HAS_TORCH = False
MSG_TORCH_NOT_FOUND = "PyTorch not found."
MSG_TORCH_EXPORT_API_NOT_FOUND = "Torch.Export API not found."


_HAS_TORCH_VISION = True
try:
    import torchvision
except:
    _HAS_TORCH_VISION = False
MSG_TORCH_VISION_NOT_FOUND = "TorchVision not found."

_HAS_TORCH_AUDIO = True
try:
    import torchaudio
except:
    _HAS_TORCH_AUDIO = False
MSG_TORCH_AUDIO_NOT_FOUND = "TorchAudio not found."


_HAS_EXECUTORCH = True
try:
    import executorch
except:
    _HAS_EXECUTORCH = False
MSG_EXECUTORCH_NOT_FOUND = "Executorch not found."

_HAS_TORCHAO = True
try:
    import torchao
except:
    _HAS_TORCHAO = False
MSG_TORCHAO_NOT_FOUND = "Torchao not found."

# ---------------------------------------------------------------------------------------
try:
    import scipy
except:
    _HAS_SCIPY = False
else:
    _HAS_SCIPY = True

# ---------------------------------------------------------------------------------------
try:
    import transformers
except:
    _HAS_HF = False
else:
    _HAS_HF = True

# General utils
def version_ge(module, target_version):
    """
    Example usage:

    >>> import torch # v1.5.0
    >>> version_ge(torch, '1.6.0') # False
    """
    return Version(module.__version__) >= Version(target_version)

def version_lt(module, target_version):
    """See version_ge"""
    return Version(module.__version__) < Version(target_version)
