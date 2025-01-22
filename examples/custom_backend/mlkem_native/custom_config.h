/*
 * Copyright (c) 2024 The mlkem-native project authors
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MLKEM_NATIVE_CONFIG_H
#define MLKEM_NATIVE_CONFIG_H

/******************************************************************************
 * Name:        MLKEM_K
 *
 * Description: Determines the security level for ML-KEM
 *              - MLKEM_K=2 corresponds to ML-KEM-512
 *              - MLKEM_K=3 corresponds to ML-KEM-768
 *              - MLKEM_K=4 corresponds to ML-KEM-1024
 *
 *              This can also be set using CFLAGS.
 *
 *****************************************************************************/
#define MLKEM_K 3 /* We want MLKEM-768 */

/******************************************************************************
 * Name:        MLKEM_NATIVE_CONFIG_FILE
 *
 * Description: If defined, this is a header that will be included instead
 *              of mlkem/config.h.
 *
 *              When you need to build mlkem-native in multiple configurations,
 *              this can be a convenient alternative to configuration via
 *              CFLAGS.
 *
 *****************************************************************************/
/* No need to set this -- we _are_ already in a custom config */
/* #define MLKEM_NATIVE_CONFIG_FILE "config.h" */

/******************************************************************************
 * Name:        MLKEM_NAMESPACE_PREFIX
 *
 * Description: The prefix to use to namespace global symbols
 *              from mlkem/.
 *****************************************************************************/
#define MLKEM_NAMESPACE_PREFIX CUSTOM_TINY_SHA3

/******************************************************************************
 * Name:        MLKEM_USE_NATIVE_BACKEND_ARITH
 *
 * Description: Determines whether an native arithmetic backend should be used.
 *
 *              The arithmetic backend covers performance critical functions
 *              such as the number-theoretic transform (NTT).
 *
 *              If this option is unset, the C backend will be used.
 *
 *              If this option is set, the arithmetic backend to be use is
 *              determined by MLKEM_NATIVE_ARITH_BACKEND: If the latter is
 *              unset, the default backend for your the target architecture
 *              will be used. If set, it must be the name of a backend metadata
 *              file.
 *
 *              This can also be set using CFLAGS.
 *
 *****************************************************************************/
/* No native arithmetic backend */
/* #define MLKEM_USE_NATIVE_BACKEND_ARITH */

/******************************************************************************
 * Name:        MLKEM_NATIVE_ARITH_BACKEND_FILE
 *
 * Description: The arithmetic backend to use.
 *
 *              If MLKEM_USE_NATIVE_BACKEND_ARITH is unset, this option
 *              is ignored.
 *
 *              If MLKEM_USE_NATIVE_BACKEND_ARITH is set, this option must
 *              either be undefined or the filename of an arithmetic backend.
 *              If unset, the default backend will be used.
 *
 *              This can be set using CFLAGS.
 *
 *****************************************************************************/
/* #define MLKEM_NATIVE_ARITH_BACKEND_FILE "native/default.h" */

/******************************************************************************
 * Name:        MLKEM_USE_NATIVE_BACKEND_FIPS202
 *
 * Description: Determines whether an native FIPS202 backend should be used.
 *
 *              The FIPS202 backend covers 1x/2x/4x-fold Keccak-f1600, which is
 *              the performance bottleneck of SHA3 and SHAKE.
 *
 *              If this option is unset, the C backend will be used.
 *
 *              If this option is set, the FIPS202 backend to be use is
 *              determined by MLKEM_NATIVE_FIPS202_BACKEND: If the latter is
 *              unset, the default backend for your the target architecture
 *              will be used. If set, it must be the name of a backend metadata
 *              file.
 *
 *              This can also be set using CFLAGS.
 *
 *****************************************************************************/
#define MLKEM_USE_NATIVE_BACKEND_FIPS202

/******************************************************************************
 * Name:        MLKEM_NATIVE_FIPS202_BACKEND_FILE
 *
 * Description: The FIPS-202 backend to use.
 *
 *              If MLKEM_USE_NATIVE_BACKEND_FIPS202 is set, this option must
 *              either be undefined or the filename of a FIPS202 backend.
 *              If unset, the default backend will be used.
 *
 *              This can be set using CFLAGS.
 *
 *****************************************************************************/
#define MLKEM_NATIVE_FIPS202_BACKEND_FILE "fips202/native/custom/custom.h"

/******************************************************************************
 * Name:        MLKEM_NATIVE_API_STANDARD
 *
 * Description: Define this to extend api.h to also export key sizes and public
 *              API in the CRYPTO_xxx and crypto_kem_xxx format as used e.g. by
 *              SUPERCOP.
 *
 *****************************************************************************/
#define MLKEM_NATIVE_API_STANDARD

#endif /* MLkEM_NATIVE_CONFIG_H */
