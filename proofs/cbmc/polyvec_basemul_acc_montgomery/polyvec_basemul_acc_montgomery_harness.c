// Copyright (c) 2024-2025 The mlkem-native project authors
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0 AND Apache-2.0
#include "poly_k.h"

void harness(void)
{
  poly *r;
  polyvec *a, *b;

  polyvec_basemul_acc_montgomery(r, a, b);
}
