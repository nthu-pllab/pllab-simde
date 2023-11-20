/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 *   2023      Yung-Cheng Su <eric20607@gapp.nthu.edu.tw>
 */

#if !defined(SIMDE_ARM_NEON_RND_H)
#define SIMDE_ARM_NEON_RND_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vrndh_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vrndh_f16(a);
  #else
    return simde_float16_from_float32(simde_math_truncf(simde_float16_to_float32(a)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrndh_f16
  #define vrndh_f16(a) simde_vrndh_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vrnd_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vrnd_f16(a);
  #else
    simde_float16x4_private
      r_,
      a_ = simde_float16x4_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE) && defined(SIMDE_ARCH_RISCV_ZVFH)
      r_.sv64 = __riscv_vfcvt_f_x_v_f16m1(
        __riscv_vfcvt_x_f_v_i16m1_rm(a_.sv64, 1, 4)
        , 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vrndh_f16(a_.values[i]);
      }
    #endif

    return simde_float16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrnd_f16
  #define vrnd_f16(a) simde_vrnd_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vrnd_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vrnd_f32(a);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vfcvt_f_x_v_f32m1(
        __riscv_vfcvt_x_f_v_i32m1_rm(a_.sv64, 1, 2)
        , 2);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && HEDLEY_HAS_BUILTIN(__builtin_elementwise_trunc)
      r_.values = __builtin_elementwise_trunc(a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_truncf(a_.values[i]);
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrnd_f32
  #define vrnd_f32(a) simde_vrnd_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vrnd_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrnd_f64(a);
  #else
    simde_float64x1_private
      r_,
      a_ = simde_float64x1_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vfcvt_f_x_v_f64m1(
        __riscv_vfcvt_x_f_v_i64m1_rm(a_.sv64, 1, 1)
        , 1);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && HEDLEY_HAS_BUILTIN(__builtin_elementwise_trunc)
      r_.values = __builtin_elementwise_trunc(a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_trunc(a_.values[i]);
      }
    #endif

    return simde_float64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrnd_f64
  #define vrnd_f64(a) simde_vrnd_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vrndq_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vrndq_f16(a);
  #else
    simde_float16x8_private
      r_,
      a_ = simde_float16x8_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE) && defined(SIMDE_ARCH_RISCV_ZVFH)
      r_.sv64 = __riscv_vfcvt_f_x_v_f16m1(
        __riscv_vfcvt_x_f_v_i16m1_rm(a_.sv64, 1, 8)
        , 8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vrndh_f16(a_.values[i]);
      }
    #endif

    return simde_float16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrndq_f16
  #define vrndq_f16(a) simde_vrndq_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vrndq_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vrndq_f32(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_trunc(a);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a);

    #if defined(SIMDE_X86_SSE4_1_NATIVE)
      r_.m128 = _mm_round_ps(a_.m128, _MM_FROUND_TO_ZERO);
    #elif defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
      r_.m128 = _mm_trunc_ps(a_.m128);
    #elif defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vfcvt_f_x_v_f32m1(
        __riscv_vfcvt_x_f_v_i32m1_rm(a_.sv64, 1, 4)
        , 4);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && HEDLEY_HAS_BUILTIN(__builtin_elementwise_trunc)
      r_.values = __builtin_elementwise_trunc(a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_truncf(a_.values[i]);
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrndq_f32
  #define vrndq_f32(a) simde_vrndq_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vrndq_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrndq_f64(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    return vec_trunc(a);
  #else
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a);

    #if defined(SIMDE_X86_SSE4_1_NATIVE)
      r_.m128d = _mm_round_pd(a_.m128d, _MM_FROUND_TO_ZERO);
    #elif defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
      r_.m128d = _mm_trunc_pd(a_.m128d);
    #elif defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vfcvt_f_x_v_f64m1(
        __riscv_vfcvt_x_f_v_i64m1_rm(a_.sv64, 1, 2)
        , 2);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && HEDLEY_HAS_BUILTIN(__builtin_elementwise_trunc)
      r_.values = __builtin_elementwise_trunc(a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_trunc(a_.values[i]);
      }
    #endif

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrndq_f64
  #define vrndq_f64(a) simde_vrndq_f64(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_RND_H) */
