/*
 * Copyright (c) 2024 The mlkem-native project authors
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * WARNING: This file is auto-generated from scripts/autogen
 *          Do not modify it directly.
 */

#include "../../../common.h"

#if defined(MLKEM_NATIVE_ARITH_BACKEND_AARCH64_CLEAN) || \
    defined(MLKEM_NATIVE_ARITH_BACKEND_AARCH64_OPT)

#include <stdint.h>
#include "arith_native_aarch64.h"

/*
 * Lookup table used by rejection sampling of the public matrix.
 * See autogen for details.
 */
ALIGN const uint8_t rej_uniform_table[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 0 */,
    0,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 1 */,
    2,  3,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 2 */,
    0,  1,  2,  3,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 3 */,
    4,  5,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 4 */,
    0,  1,  4,  5,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 5 */,
    2,  3,  4,  5,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 6 */,
    0,  1,  2,  3,  4,  5,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 7 */,
    6,  7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 8 */,
    0,  1,  6,  7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 9 */,
    2,  3,  6,  7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 10 */,
    0,  1,  2,  3,  6,  7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 11 */,
    4,  5,  6,  7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 12 */,
    0,  1,  4,  5,  6,  7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 13 */,
    2,  3,  4,  5,  6,  7,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 14 */,
    0,  1,  2,  3,  4,  5,  6,  7,  -1, -1, -1, -1, -1, -1, -1, -1 /* 15 */,
    8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 16 */,
    0,  1,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 17 */,
    2,  3,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 18 */,
    0,  1,  2,  3,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 19 */,
    4,  5,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 20 */,
    0,  1,  4,  5,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 21 */,
    2,  3,  4,  5,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 22 */,
    0,  1,  2,  3,  4,  5,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1 /* 23 */,
    6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 24 */,
    0,  1,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 25 */,
    2,  3,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 26 */,
    0,  1,  2,  3,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1 /* 27 */,
    4,  5,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 28 */,
    0,  1,  4,  5,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1 /* 29 */,
    2,  3,  4,  5,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, -1 /* 30 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1 /* 31 */,
    10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 32 */,
    0,  1,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 33 */,
    2,  3,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 34 */,
    0,  1,  2,  3,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 35 */,
    4,  5,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 36 */,
    0,  1,  4,  5,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 37 */,
    2,  3,  4,  5,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 38 */,
    0,  1,  2,  3,  4,  5,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 39 */,
    6,  7,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 40 */,
    0,  1,  6,  7,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 41 */,
    2,  3,  6,  7,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 42 */,
    0,  1,  2,  3,  6,  7,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 43 */,
    4,  5,  6,  7,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 44 */,
    0,  1,  4,  5,  6,  7,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 45 */,
    2,  3,  4,  5,  6,  7,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 46 */,
    0,  1,  2,  3,  4,  5,  6,  7,  10, 11, -1, -1, -1, -1, -1, -1 /* 47 */,
    8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 48 */,
    0,  1,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 49 */,
    2,  3,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 50 */,
    0,  1,  2,  3,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 51 */,
    4,  5,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 52 */,
    0,  1,  4,  5,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 53 */,
    2,  3,  4,  5,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 54 */,
    0,  1,  2,  3,  4,  5,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1 /* 55 */,
    6,  7,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 56 */,
    0,  1,  6,  7,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 57 */,
    2,  3,  6,  7,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 58 */,
    0,  1,  2,  3,  6,  7,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1 /* 59 */,
    4,  5,  6,  7,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1, -1, -1 /* 60 */,
    0,  1,  4,  5,  6,  7,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1 /* 61 */,
    2,  3,  4,  5,  6,  7,  8,  9,  10, 11, -1, -1, -1, -1, -1, -1 /* 62 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, -1, -1, -1, -1 /* 63 */,
    12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 64 */,
    0,  1,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 65 */,
    2,  3,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 66 */,
    0,  1,  2,  3,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 67 */,
    4,  5,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 68 */,
    0,  1,  4,  5,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 69 */,
    2,  3,  4,  5,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 70 */,
    0,  1,  2,  3,  4,  5,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 71 */,
    6,  7,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 72 */,
    0,  1,  6,  7,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 73 */,
    2,  3,  6,  7,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 74 */,
    0,  1,  2,  3,  6,  7,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 75 */,
    4,  5,  6,  7,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 76 */,
    0,  1,  4,  5,  6,  7,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 77 */,
    2,  3,  4,  5,  6,  7,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 78 */,
    0,  1,  2,  3,  4,  5,  6,  7,  12, 13, -1, -1, -1, -1, -1, -1 /* 79 */,
    8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 80 */,
    0,  1,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 81 */,
    2,  3,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 82 */,
    0,  1,  2,  3,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 83 */,
    4,  5,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 84 */,
    0,  1,  4,  5,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 85 */,
    2,  3,  4,  5,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 86 */,
    0,  1,  2,  3,  4,  5,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1 /* 87 */,
    6,  7,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 88 */,
    0,  1,  6,  7,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 89 */,
    2,  3,  6,  7,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 90 */,
    0,  1,  2,  3,  6,  7,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1 /* 91 */,
    4,  5,  6,  7,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 92 */,
    0,  1,  4,  5,  6,  7,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1 /* 93 */,
    2,  3,  4,  5,  6,  7,  8,  9,  12, 13, -1, -1, -1, -1, -1, -1 /* 94 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  12, 13, -1, -1, -1, -1 /* 95 */,
    10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 96 */,
    0,  1,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 97 */,
    2,  3,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 98 */,
    0,  1,  2,  3,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 99 */,
    4,  5,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 100 */,
    0,  1,  4,  5,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 101 */,
    2,  3,  4,  5,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 102 */,
    0,  1,  2,  3,  4,  5,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 103 */,
    6,  7,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 104 */,
    0,  1,  6,  7,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 105 */,
    2,  3,  6,  7,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 106 */,
    0,  1,  2,  3,  6,  7,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 107 */,
    4,  5,  6,  7,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 108 */,
    0,  1,  4,  5,  6,  7,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 109 */,
    2,  3,  4,  5,  6,  7,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 110 */,
    0,  1,  2,  3,  4,  5,  6,  7,  10, 11, 12, 13, -1, -1, -1, -1 /* 111 */,
    8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 112 */,
    0,  1,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 113 */,
    2,  3,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 114 */,
    0,  1,  2,  3,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 115 */,
    4,  5,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 116 */,
    0,  1,  4,  5,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 117 */,
    2,  3,  4,  5,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 118 */,
    0,  1,  2,  3,  4,  5,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1 /* 119 */,
    6,  7,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1 /* 120 */,
    0,  1,  6,  7,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 121 */,
    2,  3,  6,  7,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 122 */,
    0,  1,  2,  3,  6,  7,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1 /* 123 */,
    4,  5,  6,  7,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1, -1, -1 /* 124 */,
    0,  1,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1 /* 125 */,
    2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, -1, -1, -1, -1 /* 126 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, -1, -1 /* 127 */,
    14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 128 */,
    0,  1,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 129 */,
    2,  3,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 130 */,
    0,  1,  2,  3,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 131 */,
    4,  5,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 132 */,
    0,  1,  4,  5,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 133 */,
    2,  3,  4,  5,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 134 */,
    0,  1,  2,  3,  4,  5,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 135 */,
    6,  7,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 136 */,
    0,  1,  6,  7,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 137 */,
    2,  3,  6,  7,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 138 */,
    0,  1,  2,  3,  6,  7,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 139 */,
    4,  5,  6,  7,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 140 */,
    0,  1,  4,  5,  6,  7,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 141 */,
    2,  3,  4,  5,  6,  7,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 142 */,
    0,  1,  2,  3,  4,  5,  6,  7,  14, 15, -1, -1, -1, -1, -1, -1 /* 143 */,
    8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 144 */,
    0,  1,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 145 */,
    2,  3,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 146 */,
    0,  1,  2,  3,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 147 */,
    4,  5,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 148 */,
    0,  1,  4,  5,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 149 */,
    2,  3,  4,  5,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 150 */,
    0,  1,  2,  3,  4,  5,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1 /* 151 */,
    6,  7,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 152 */,
    0,  1,  6,  7,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 153 */,
    2,  3,  6,  7,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 154 */,
    0,  1,  2,  3,  6,  7,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1 /* 155 */,
    4,  5,  6,  7,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 156 */,
    0,  1,  4,  5,  6,  7,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1 /* 157 */,
    2,  3,  4,  5,  6,  7,  8,  9,  14, 15, -1, -1, -1, -1, -1, -1 /* 158 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  14, 15, -1, -1, -1, -1 /* 159 */,
    10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 160 */,
    0,  1,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 161 */,
    2,  3,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 162 */,
    0,  1,  2,  3,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 163 */,
    4,  5,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 164 */,
    0,  1,  4,  5,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 165 */,
    2,  3,  4,  5,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 166 */,
    0,  1,  2,  3,  4,  5,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 167 */,
    6,  7,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 168 */,
    0,  1,  6,  7,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 169 */,
    2,  3,  6,  7,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 170 */,
    0,  1,  2,  3,  6,  7,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 171 */,
    4,  5,  6,  7,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 172 */,
    0,  1,  4,  5,  6,  7,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 173 */,
    2,  3,  4,  5,  6,  7,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 174 */,
    0,  1,  2,  3,  4,  5,  6,  7,  10, 11, 14, 15, -1, -1, -1, -1 /* 175 */,
    8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 176 */,
    0,  1,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 177 */,
    2,  3,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 178 */,
    0,  1,  2,  3,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 179 */,
    4,  5,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 180 */,
    0,  1,  4,  5,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 181 */,
    2,  3,  4,  5,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 182 */,
    0,  1,  2,  3,  4,  5,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1 /* 183 */,
    6,  7,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 184 */,
    0,  1,  6,  7,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 185 */,
    2,  3,  6,  7,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 186 */,
    0,  1,  2,  3,  6,  7,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1 /* 187 */,
    4,  5,  6,  7,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1, -1, -1 /* 188 */,
    0,  1,  4,  5,  6,  7,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1 /* 189 */,
    2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 14, 15, -1, -1, -1, -1 /* 190 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 14, 15, -1, -1 /* 191 */,
    12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 192 */,
    0,  1,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 193 */,
    2,  3,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 194 */,
    0,  1,  2,  3,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 195 */,
    4,  5,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 196 */,
    0,  1,  4,  5,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 197 */,
    2,  3,  4,  5,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 198 */,
    0,  1,  2,  3,  4,  5,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 199 */,
    6,  7,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 200 */,
    0,  1,  6,  7,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 201 */,
    2,  3,  6,  7,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 202 */,
    0,  1,  2,  3,  6,  7,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 203 */,
    4,  5,  6,  7,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 204 */,
    0,  1,  4,  5,  6,  7,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 205 */,
    2,  3,  4,  5,  6,  7,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 206 */,
    0,  1,  2,  3,  4,  5,  6,  7,  12, 13, 14, 15, -1, -1, -1, -1 /* 207 */,
    8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 208 */,
    0,  1,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 209 */,
    2,  3,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 210 */,
    0,  1,  2,  3,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 211 */,
    4,  5,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 212 */,
    0,  1,  4,  5,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 213 */,
    2,  3,  4,  5,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 214 */,
    0,  1,  2,  3,  4,  5,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1 /* 215 */,
    6,  7,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 216 */,
    0,  1,  6,  7,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 217 */,
    2,  3,  6,  7,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 218 */,
    0,  1,  2,  3,  6,  7,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1 /* 219 */,
    4,  5,  6,  7,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 220 */,
    0,  1,  4,  5,  6,  7,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1 /* 221 */,
    2,  3,  4,  5,  6,  7,  8,  9,  12, 13, 14, 15, -1, -1, -1, -1 /* 222 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  12, 13, 14, 15, -1, -1 /* 223 */,
    10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* 224 */,
    0,  1,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 225 */,
    2,  3,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 226 */,
    0,  1,  2,  3,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 227 */,
    4,  5,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 228 */,
    0,  1,  4,  5,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 229 */,
    2,  3,  4,  5,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 230 */,
    0,  1,  2,  3,  4,  5,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 231 */,
    6,  7,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 232 */,
    0,  1,  6,  7,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 233 */,
    2,  3,  6,  7,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 234 */,
    0,  1,  2,  3,  6,  7,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 235 */,
    4,  5,  6,  7,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 236 */,
    0,  1,  4,  5,  6,  7,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 237 */,
    2,  3,  4,  5,  6,  7,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 238 */,
    0,  1,  2,  3,  4,  5,  6,  7,  10, 11, 12, 13, 14, 15, -1, -1 /* 239 */,
    8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1 /* 240 */,
    0,  1,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 241 */,
    2,  3,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 242 */,
    0,  1,  2,  3,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 243 */,
    4,  5,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 244 */,
    0,  1,  4,  5,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 245 */,
    2,  3,  4,  5,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 246 */,
    0,  1,  2,  3,  4,  5,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1 /* 247 */,
    6,  7,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1 /* 248 */,
    0,  1,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 249 */,
    2,  3,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 250 */,
    0,  1,  2,  3,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1 /* 251 */,
    4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1, -1, -1 /* 252 */,
    0,  1,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1 /* 253 */,
    2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, -1, -1 /* 254 */,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15 /* 255 */,
};

#else

MLKEM_NATIVE_EMPTY_CU(aarch64_rej_uniform_table)

#endif
