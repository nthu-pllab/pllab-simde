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
 *   2020      Sean Maher <seanptmaher@gmail.com> (Copyright owned by Google, LLC)
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 *   2023      Yung-Cheng Su <eric20607@gapp.nthu.edu.tw>
 */

#if !defined(SIMDE_ARM_NEON_MUL_N_H)
#define SIMDE_ARM_NEON_MUL_N_H

#include "types.h"
#include "mul.h"
#include "dup_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vmul_n_f16(simde_float16x4_t a, simde_float16 b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vmul_n_f16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_float16x4_private
      r_,
      a_ = simde_float16x4_to_private(a);
    r_.sv64 = __riscv_vfmul_vf_f16m1 (a_.sv64, b, 4);
    return simde_float16x4_from_private(r_);
  #else
    return simde_vmul_f16(a, simde_vdup_n_f16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vmul_n_f16
  #define vmul_n_f16(a, b) simde_vmul_n_f16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vmul_n_f32(simde_float32x2_t a, simde_float32 b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_n_f32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a);
    r_.sv64 = __riscv_vfmul_vf_f32m1 (a_.sv64, b, 2);
    return simde_float32x2_from_private(r_);
  #else
    return simde_vmul_f32(a, simde_vdup_n_f32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_n_f32
  #define vmul_n_f32(a, b) simde_vmul_n_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vmul_n_f64(simde_float64x1_t a, simde_float64 b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmul_n_f64(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_float64x1_private
      r_,
      a_ = simde_float64x1_to_private(a);
    r_.sv64 = __riscv_vfmul_vf_f64m1 (a_.sv64, b, 1);
    return simde_float64x1_from_private(r_);
  #else
    return simde_vmul_f64(a, simde_vdup_n_f64(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmul_n_f64
  #define vmul_n_f64(a, b) simde_vmul_n_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vmul_n_s16(simde_int16x4_t a, int16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_n_s16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a);
    r_.sv64 = __riscv_vmul_vx_i16m1(a_.sv64, b, 4);
    return simde_int16x4_from_private(r_);
  #else
    return simde_vmul_s16(a, simde_vdup_n_s16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_n_s16
  #define vmul_n_s16(a, b) simde_vmul_n_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vmul_n_s32(simde_int32x2_t a, int32_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_n_s32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a);
    r_.sv64 = __riscv_vmul_vx_i32m1(a_.sv64, b, 2);
    return simde_int32x2_from_private(r_);
  #else
    return simde_vmul_s32(a, simde_vdup_n_s32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_n_s32
  #define vmul_n_s32(a, b) simde_vmul_n_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vmul_n_u16(simde_uint16x4_t a, uint16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_n_u16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a);
    r_.sv64 = __riscv_vmul_vx_u16m1(a_.sv64, b, 4);
    return simde_uint16x4_from_private(r_);
  #else
    return simde_vmul_u16(a, simde_vdup_n_u16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_n_u16
  #define vmul_n_u16(a, b) simde_vmul_n_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vmul_n_u32(simde_uint32x2_t a, uint32_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_n_u32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a);
    r_.sv64 = __riscv_vmul_vx_u32m1(a_.sv64, b, 2);
    return simde_uint32x2_from_private(r_);
  #else
    return simde_vmul_u32(a, simde_vdup_n_u32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_n_u32
  #define vmul_n_u32(a, b) simde_vmul_n_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vmulq_n_f16(simde_float16x8_t a, simde_float16 b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vmulq_n_f16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_float16x8_private
      r_,
      a_ = simde_float16x8_to_private(a);
    r_.sv128 = __riscv_vfmul_vf_f16m1 (a_.sv128, b, 8);
    return simde_float16x8_from_private(r_);
  #else
    return simde_vmulq_f16(a, simde_vdupq_n_f16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vmulq_n_f16
  #define vmulq_n_f16(a, b) simde_vmulq_n_f16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vmulq_n_f32(simde_float32x4_t a, simde_float32 b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_n_f32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_float32x4_private
    r_,
    a_ = simde_float32x4_to_private(a);
    r_.sv128 = __riscv_vfmul_vf_f32m1 (a_.sv128, b, 4);
    return simde_float32x4_from_private(r_);
  #else
    return simde_vmulq_f32(a, simde_vdupq_n_f32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_n_f32
  #define vmulq_n_f32(a, b) simde_vmulq_n_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vmulq_n_f64(simde_float64x2_t a, simde_float64 b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmulq_n_f64(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a);
    r_.sv128 = __riscv_vfmul_vf_f64m1 (a_.sv128, b, 2);
    return simde_float64x2_from_private(r_);
  #else
    return simde_vmulq_f64(a, simde_vdupq_n_f64(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmulq_n_f64
  #define vmulq_n_f64(a, b) simde_vmulq_n_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vmulq_n_s16(simde_int16x8_t a, int16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_n_s16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a);
    r_.sv128 = __riscv_vmul_vx_i16m1(a_.sv128, b, 8);
    return simde_int16x8_from_private(r_);
  #else
    return simde_vmulq_s16(a, simde_vdupq_n_s16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_n_s16
  #define vmulq_n_s16(a, b) simde_vmulq_n_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmulq_n_s32(simde_int32x4_t a, int32_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_n_s32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a);
    r_.sv128 = __riscv_vmul_vx_i32m1(a_.sv128, b, 4);
    return simde_int32x4_from_private(r_);
  #else
    return simde_vmulq_s32(a, simde_vdupq_n_s32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_n_s32
  #define vmulq_n_s32(a, b) simde_vmulq_n_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vmulq_n_u16(simde_uint16x8_t a, uint16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_n_u16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a);
    r_.sv128 = __riscv_vmul_vx_u16m1(a_.sv128, b, 8);
    return simde_uint16x8_from_private(r_);
  #else
    return simde_vmulq_u16(a, simde_vdupq_n_u16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_n_u16
  #define vmulq_n_u16(a, b) simde_vmulq_n_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmulq_n_u32(simde_uint32x4_t a, uint32_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_n_u32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a);
    r_.sv128 = __riscv_vmul_vx_u32m1(a_.sv128, b, 4);
    return simde_uint32x4_from_private(r_);
  #else
    return simde_vmulq_u32(a, simde_vdupq_n_u32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_n_u32
  #define vmulq_n_u32(a, b) simde_vmulq_n_u32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MUL_N_H) */
