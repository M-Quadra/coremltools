#  Copyright (c) 2020, Apple Inc. All rights reserved.
#
#  Use of this source code is governed by a BSD-3-clause license that can be
#  found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause

import math

import numpy as np
import sympy as sm

from coremltools import _logger as logger

from .annotate import annotate, class_annotate, delay_type
from .type_bool import bool
from .type_spec import Type


def make_int(width_, unsigned_):
    delay_type_int = getattr(delay_type, unsigned_ + "int" + str(width_))

    @class_annotate()
    class int:
        _width = width_
        _unsigned = unsigned_

        @classmethod
        @property
        def width(self):
            return self._width

        @classmethod
        @property
        def unsigned(self):
            return self._unsigned

        @annotate(v=delay_type_int)
        def __init__(self, v=0):
            self._val = v

        @property
        def val(self):
            return self._val

        @val.setter
        def val(self, v):
            from .type_mapping import (builtin_to_string, nptype_from_builtin,
                                       numpy_type_to_builtin_type)

            if not isinstance(v, (np.generic, np.ndarray, sm.Basic)):
                try:
                    v = np.array(v)
                except Exception:
                    raise ValueError(
                        f"types should have value of numpy type or Symbols, got {type(v)} instead"
                    )

            if isinstance(v, sm.Basic):
                self._val = v
            elif isinstance(v, np.integer):
                v_type = numpy_type_to_builtin_type(v.dtype)
                if v_type.get_bitwidth() <= self.get_bitwidth() and (
                    v >= 0 or v < 0 and not self.is_unsigned()
                ):
                    self._val = v
                else:
                    self._val = v.astype(nptype_from_builtin(self.__class__))
                    logger.warning(
                        f"Saving value type of {v.dtype} into a builtin type of "
                        f"{builtin_to_string(self.__class__)}, might overflow or loses precision!"
                    )
            else:
                self._val = v.astype(nptype_from_builtin(self.__class__))
                logger.warning(
                    f"Saving value type of {v.dtype} into a builtin type of "
                    f"{builtin_to_string(self.__class__)}, might be incompatible or loses precision!"
                )

        @classmethod
        def __type_info__(cls):
            return Type(cls._unsigned + "int" + str(cls._width), python_class=cls)

        @classmethod
        def get_bitwidth(cls):
            return cls._width

        @classmethod
        def is_unsigned(cls):
            return cls._unsigned == "u"

        @annotate(delay_type_int, other=delay_type_int)
        def __add__(self, other):
            assert isinstance(other, int)
            return int(self.val + other.val)

        @annotate(delay_type_int, other=delay_type_int)
        def __sub__(self, other):
            assert isinstance(other, int)
            return int(self.val - other.val)

        @annotate(delay_type_int, other=delay_type_int)
        def __mul__(self, other):
            assert isinstance(other, int)
            return int(self.val * other.val)

        @annotate(delay_type_int, other=delay_type_int)
        def __div__(self, other):
            assert isinstance(other, int)
            return int(self.val // other.val)

        @annotate(delay_type_int, other=delay_type_int)
        def __mod__(self, other):
            assert isinstance(other, int)
            return int(self.val % other.val)

        @annotate(delay_type.bool, other=delay_type_int)
        def __lt__(self, other):
            return bool(self.val < other.val)

        @annotate(delay_type.bool, other=delay_type_int)
        def __gt__(self, other):
            return bool(self.val > other.val)

        @annotate(delay_type.bool, other=delay_type_int)
        def __le__(self, other):
            return bool(self.val <= other.val)

        @annotate(delay_type.bool, other=delay_type_int)
        def __ge__(self, other):
            return bool(self.val >= other.val)

        @annotate(delay_type.bool, other=delay_type_int)
        def __eq__(self, other):
            return bool(self.val == other.val)

        @annotate(delay_type.bool, other=delay_type_int)
        def __ne__(self, other):
            return bool(self.val != other.val)

        @annotate(delay_type.bool)
        def __bool__(self):
            return self.val != 0

        @annotate(delay_type_int)
        def __int__(self):
            return int(self)

        @annotate(delay_type.double)
        def __double__(self):
            return float(self.val)

        @annotate(delay_type.str)
        def __str__(self):
            return str(self.val)

        @annotate(delay_type.double)
        def __log__(self):
            return math.log(self.val)

        @annotate(delay_type.double)
        def __exp__(self):
            return math.exp(self.val)

        @annotate(delay_type_int)
        def __neg__(self):
            return int(-self.val)

    return int


int4 = make_int(4, "")
int8 = make_int(8, "")
int16 = make_int(16, "")
int32 = make_int(32, "")
int64 = make_int(64, "")

uint1 = make_int(1, "u")
uint2 = make_int(2, "u")
uint3 = make_int(3, "u")
uint4 = make_int(4, "u")
uint6 = make_int(6, "u")
uint8 = make_int(8, "u")
uint16 = make_int(16, "u")
uint32 = make_int(32, "u")
uint64 = make_int(64, "u")
uint = uint64

_INT_TYPES = (
    int4,
    int8,
    int16,
    int32,
    int64,
    uint1,
    uint2,
    uint3,
    uint4,
    uint6,
    uint8,
    uint16,
    uint32,
    uint64,
)

# The key name for storing type info in `np.dtype.metadata`.
SUB_BYTE_DTYPE_METADATA_KEY = "true_dtype"
# Uses np.int8/uint8 as np doesn't natively support sub-byte type (such as int4/uint4) yet.
np_int4_dtype = np.dtype(np.int8, metadata={SUB_BYTE_DTYPE_METADATA_KEY: int4})
np_uint1_dtype = np.dtype(np.uint8, metadata={SUB_BYTE_DTYPE_METADATA_KEY: uint1})
np_uint2_dtype = np.dtype(np.uint8, metadata={SUB_BYTE_DTYPE_METADATA_KEY: uint2})
np_uint3_dtype = np.dtype(np.uint8, metadata={SUB_BYTE_DTYPE_METADATA_KEY: uint3})
np_uint4_dtype = np.dtype(np.uint8, metadata={SUB_BYTE_DTYPE_METADATA_KEY: uint4})
np_uint6_dtype = np.dtype(np.uint8, metadata={SUB_BYTE_DTYPE_METADATA_KEY: uint6})

_SUB_BYTE_TYPES = (int4, uint1, uint2, uint3, uint4, uint6)


def is_int(t):
    return any(t is i or isinstance(t, i) for i in _INT_TYPES)


def is_signed_int(t):
    return is_int(t) and t._unsigned == ""


def is_unsigned_int(t):
    return is_int(t) and t._unsigned == "u"


def is_sub_byte(t):
    """Determines if a type (or instance) is sub-byte (less than 8-bit data type)."""
    return t in _SUB_BYTE_TYPES or isinstance(t, _SUB_BYTE_TYPES)
