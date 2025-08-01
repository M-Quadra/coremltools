#  Copyright (c) 2020, Apple Inc. All rights reserved.
#
#  Use of this source code is governed by a BSD-3-clause license that can be
#  found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause

from coremltools._deps import _HAS_TORCH

register_torch_op = None

if _HAS_TORCH:
    from . import dim_order_ops, ops, quantization_ops
    from .dialect_ops import (torch_tensor_assign, torch_upsample_bilinear,
                              torch_upsample_nearest_neighbor)
    from .torch_op_registry import is_torch_fx_node_supported, register_torch_op
