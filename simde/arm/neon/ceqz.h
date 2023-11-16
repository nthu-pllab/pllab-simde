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
 */

#if !defined(SIMDE_ARM_NEON_CEQZ_H)
#define SIMDE_ARM_NEON_CEQZ_H

#include "ceq.h"
#include "dup_n.h"
#include "types.h"
#include "reinterpret.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vceqz_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vceqz_f16(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x4_private r_;
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    vuint16m1_t vs_0 = __riscv_vmv_v_x_u16m1(UINT16_C(0), 4);
    vbool16_t mask = __riscv_vmfeq_vf_f16m1_b16(a_.sv64, 0.0, 4);
    r_.sv64 = __riscv_vmerge_vxm_u16m1(vs_0, -1, mask, 4);
    return simde_uint16x4_from_private(r_);
  #else
    return simde_vceq_f16(a, simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vceqz_f16
  #define vceqz_f16(a) simde_vceqz_f16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vceqz_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_f32(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x2_private r_;
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    vuint32m1_t vs_0 = __riscv_vmv_v_x_u32m1(UINT32_C(0), 2);
    vbool32_t mask = __riscv_vmfeq_vf_f32m1_b32(a_.sv64, 0.0f, 2);
    r_.sv64 = __riscv_vmerge_vxm_u32m1(vs_0, -1, mask, 2);
    return simde_uint32x2_from_private(r_);
  #else
    return simde_vceq_f32(a, simde_vdup_n_f32(0.0f));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_f32
  #define vceqz_f32(a) simde_vceqz_f32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vceqz_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_f64(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x1_private r_;
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    vuint64m1_t vs_0 = __riscv_vmv_v_x_u64m1(UINT64_C(0), 1);
    vbool64_t mask = __riscv_vmfeq_vf_f64m1_b64(a_.sv64, 0.0, 1);
    r_.sv64 = __riscv_vmerge_vxm_u64m1(vs_0, -1, mask, 1);
    return simde_uint64x1_from_private(r_);
  #else
    return simde_vceq_f64(a, simde_vdup_n_f64(0.0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vceqz_f64
  #define vceqz_f64(a) simde_vceqz_f64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vceqz_s8(simde_int8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_s8(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint8x8_private r_;
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    vuint8m1_t vs_0 = __riscv_vmv_v_x_u8m1(UINT8_C(0), 8);
    vbool8_t mask = __riscv_vmseq_vx_i8m1_b8(a_.sv64, 0, 8);
    r_.sv64 = __riscv_vmerge_vxm_u8m1(vs_0, -1, mask, 8);
    return simde_uint8x8_from_private(r_);
  #else
    return simde_vceq_s8(a, simde_vdup_n_s8(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_s8
  #define vceqz_s8(a) simde_vceqz_s8((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vceqz_s16(simde_int16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_s16(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x4_private r_;
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    vuint16m1_t vs_0 = __riscv_vmv_v_x_u16m1(UINT16_C(0), 4);
    vbool16_t mask = __riscv_vmseq_vx_i16m1_b16(a_.sv64, 0, 4);
    r_.sv64 = __riscv_vmerge_vxm_u16m1(vs_0, -1, mask, 4);
    return simde_uint16x4_from_private(r_);
  #else
    return simde_vceq_s16(a, simde_vdup_n_s16(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_s16
  #define vceqz_s16(a) simde_vceqz_s16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vceqz_s32(simde_int32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_s32(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x2_private r_;
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    vuint32m1_t vs_0 = __riscv_vmv_v_x_u32m1(UINT32_C(0), 2);
    vbool32_t mask = __riscv_vmseq_vx_i32m1_b32(a_.sv64, 0, 2);
    r_.sv64 = __riscv_vmerge_vxm_u32m1(vs_0, -1, mask, 2);
    return simde_uint32x2_from_private(r_);
  #else
    return simde_vceq_s32(a, simde_vdup_n_s32(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_s32
  #define vceqz_s32(a) simde_vceqz_s32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vceqz_s64(simde_int64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_s64(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x1_private r_;
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    vuint64m1_t vs_0 = __riscv_vmv_v_x_u64m1(UINT64_C(0), 1);
    vbool64_t mask = __riscv_vmseq_vx_i64m1_b64(a_.sv64, 0, 1);
    r_.sv64 = __riscv_vmerge_vxm_u64m1(vs_0, -1, mask, 1);
    return simde_uint64x1_from_private(r_);
  #else
    return simde_vceq_s64(a, simde_vdup_n_s64(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_s64
  #define vceqz_s64(a) simde_vceqz_s64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vceqz_u8(simde_uint8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_u8(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint8x8_private r_;
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    vuint8m1_t vs_0 = __riscv_vmv_v_x_u8m1(UINT8_C(0), 8);
    vbool8_t mask = __riscv_vmseq_vx_u8m1_b8(a_.sv64, 0, 8);
    r_.sv64 = __riscv_vmerge_vxm_u8m1(vs_0, -1, mask, 8);
    return simde_uint8x8_from_private(r_);
  #else
    return simde_vceq_u8(a, simde_vdup_n_u8(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_u8
  #define vceqz_u8(a) simde_vceqz_u8((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vceqz_u16(simde_uint16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_u16(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x4_private r_;
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    vuint16m1_t vs_0 = __riscv_vmv_v_x_u16m1(UINT16_C(0), 4);
    vbool16_t mask = __riscv_vmseq_vx_u16m1_b16(a_.sv64, 0, 4);
    r_.sv64 = __riscv_vmerge_vxm_u16m1(vs_0, -1, mask, 4);
    return simde_uint16x4_from_private(r_);
  #else
    return simde_vceq_u16(a, simde_vdup_n_u16(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_u16
  #define vceqz_u16(a) simde_vceqz_u16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vceqz_u32(simde_uint32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_u32(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x2_private r_;
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    vuint32m1_t vs_0 = __riscv_vmv_v_x_u32m1(UINT32_C(0), 2);
    vbool32_t mask = __riscv_vmseq_vx_u32m1_b32(a_.sv64, 0, 2);
    r_.sv64 = __riscv_vmerge_vxm_u32m1(vs_0, -1, mask, 2);
    return simde_uint32x2_from_private(r_);
  #else
    return simde_vceq_u32(a, simde_vdup_n_u32(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_u32
  #define vceqz_u32(a) simde_vceqz_u32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vceqz_u64(simde_uint64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqz_u64(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x1_private r_;
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    vuint64m1_t vs_0 = __riscv_vmv_v_x_u64m1(UINT64_C(0), 1);
    vbool64_t mask = __riscv_vmseq_vx_u64m1_b64(a_.sv64, 0, 1);
    r_.sv64 = __riscv_vmerge_vxm_u64m1(vs_0, -1, mask, 1);
    return simde_uint64x1_from_private(r_);
  #else
    return simde_vceq_u64(a, simde_vdup_n_u64(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqz_u64
  #define vceqz_u64(a) simde_vceqz_u64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vceqzq_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vceqzq_f16(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x8_private r_;
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    vuint16m1_t vs_0 = __riscv_vmv_v_x_u16m1(UINT16_C(0), 8);
    vbool16_t mask = __riscv_vmfeq_vf_f16m1_b16(a_.sv128, 0.0, 8);
    r_.sv128 = __riscv_vmerge_vxm_u16m1(vs_0, -1, mask, 8);
    return simde_uint16x8_from_private(r_);
  #else
    return simde_vceqq_f16(a, simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_f16
  #define vceqzq_f16(a) simde_vceqzq_f16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vceqzq_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_f32(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private r_;
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    vuint32m1_t vs_0 = __riscv_vmv_v_x_u32m1(UINT32_C(0), 4);
    vbool32_t mask = __riscv_vmfeq_vf_f32m1_b32(a_.sv128, 0.0, 4);
    r_.sv128 = __riscv_vmerge_vxm_u32m1(vs_0, -1, mask, 4);
    return simde_uint32x4_from_private(r_);
  #else
    return simde_vceqq_f32(a, simde_vdupq_n_f32(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_f32
  #define vceqzq_f32(a) simde_vceqzq_f32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vceqzq_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_f64(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x2_private r_;
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    vuint64m1_t vs_0 = __riscv_vmv_v_x_u64m1(UINT64_C(0), 2);
    vbool64_t mask = __riscv_vmfeq_vf_f64m1_b64(a_.sv128, 0.0, 2);
    r_.sv128 = __riscv_vmerge_vxm_u64m1(vs_0, -1, mask, 2);
    return simde_uint64x2_from_private(r_);
  #else
    return simde_vceqq_f64(a, simde_vdupq_n_f64(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_f64
  #define vceqzq_f64(a) simde_vceqzq_f64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vceqzq_s8(simde_int8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_s8(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint8x16_private r_;
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    vuint8m1_t vs_0 = __riscv_vmv_v_x_u8m1(UINT8_C(0), 16);
    vbool8_t mask = __riscv_vmseq_vx_i8m1_b8(a_.sv128, 0, 16);
    r_.sv128 = __riscv_vmerge_vxm_u8m1(vs_0, -1, mask, 16);
    return simde_uint8x16_from_private(r_);
  #else
    return simde_vceqq_s8(a, simde_vdupq_n_s8(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_s8
  #define vceqzq_s8(a) simde_vceqzq_s8((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vceqzq_s16(simde_int16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_s16(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x8_private r_;
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    vuint16m1_t vs_0 = __riscv_vmv_v_x_u16m1(UINT16_C(0), 8);
    vbool16_t mask = __riscv_vmseq_vx_i16m1_b16(a_.sv128, 0, 8);
    r_.sv128 = __riscv_vmerge_vxm_u16m1(vs_0, -1, mask, 8);
    return simde_uint16x8_from_private(r_);
  #else
    return simde_vceqq_s16(a, simde_vdupq_n_s16(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_s16
  #define vceqzq_s16(a) simde_vceqzq_s16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vceqzq_s32(simde_int32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_s32(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private r_;
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    vuint32m1_t vs_0 = __riscv_vmv_v_x_u32m1(UINT32_C(0), 4);
    vbool32_t mask = __riscv_vmseq_vx_i32m1_b32(a_.sv128, 0, 4);
    r_.sv128 = __riscv_vmerge_vxm_u32m1(vs_0, -1, mask, 4);
    return simde_uint32x4_from_private(r_);
  #else
    return simde_vceqq_s32(a, simde_vdupq_n_s32(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_s32
  #define vceqzq_s32(a) simde_vceqzq_s32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vceqzq_s64(simde_int64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_s64(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x2_private r_;
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    vuint64m1_t vs_0 = __riscv_vmv_v_x_u64m1(UINT64_C(0), 2);
    vbool64_t mask = __riscv_vmseq_vx_i64m1_b64(a_.sv128, 0, 2);
    r_.sv128 = __riscv_vmerge_vxm_u64m1(vs_0, -1, mask, 2);
    return simde_uint64x2_from_private(r_);
  #else
    return simde_vceqq_s64(a, simde_vdupq_n_s64(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_s64
  #define vceqzq_s64(a) simde_vceqzq_s64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vceqzq_u8(simde_uint8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_u8(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint8x16_private r_;
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    vuint8m1_t vs_0 = __riscv_vmv_v_x_u8m1(UINT8_C(0), 16);
    vbool8_t mask = __riscv_vmseq_vx_u8m1_b8(a_.sv128, 0, 16);
    r_.sv128 = __riscv_vmerge_vxm_u8m1(vs_0, -1, mask, 16);
    return simde_uint8x16_from_private(r_);
  #else
    return simde_vceqq_u8(a, simde_vdupq_n_u8(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_u8
  #define vceqzq_u8(a) simde_vceqzq_u8((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vceqzq_u16(simde_uint16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_u16(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x8_private r_;
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    vuint16m1_t vs_0 = __riscv_vmv_v_x_u16m1(UINT16_C(0), 8);
    vbool16_t mask = __riscv_vmseq_vx_u16m1_b16(a_.sv128, 0, 8);
    r_.sv128 = __riscv_vmerge_vxm_u16m1(vs_0, -1, mask, 8);
    return simde_uint16x8_from_private(r_);
  #else
    return simde_vceqq_u16(a, simde_vdupq_n_u16(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_u16
  #define vceqzq_u16(a) simde_vceqzq_u16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vceqzq_u32(simde_uint32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_u32(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private r_;
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    vuint32m1_t vs_0 = __riscv_vmv_v_x_u32m1(UINT32_C(0), 4);
    vbool32_t mask = __riscv_vmseq_vx_u32m1_b32(a_.sv128, 0, 4);
    r_.sv128 = __riscv_vmerge_vxm_u32m1(vs_0, -1 , mask, 4);
    return simde_uint32x4_from_private(r_);
  #else
    return simde_vceqq_u32(a, simde_vdupq_n_u32(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_u32
  #define vceqzq_u32(a) simde_vceqzq_u32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vceqzq_u64(simde_uint64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzq_u64(a);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x2_private r_;
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    vuint64m1_t vs_0 = __riscv_vmv_v_x_u64m1(UINT64_C(0), 2);
    vbool64_t mask = __riscv_vmseq_vx_u64m1_b64(a_.sv128, 0, 2);
    r_.sv128 = __riscv_vmerge_vxm_u64m1(vs_0, -1, mask, 2);
    return simde_uint64x2_from_private(r_);
  #else
    return simde_vceqq_u64(a, simde_vdupq_n_u64(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzq_u64
  #define vceqzq_u64(a) simde_vceqzq_u64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vceqzd_s64(int64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return HEDLEY_STATIC_CAST(uint64_t, vceqzd_s64(a));
  #else
    return simde_vceqd_s64(a, INT64_C(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzd_s64
  #define vceqzd_s64(a) simde_vceqzd_s64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vceqzd_u64(uint64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzd_u64(a);
  #else
    return simde_vceqd_u64(a, UINT64_C(0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzd_u64
  #define vceqzd_u64(a) simde_vceqzd_u64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint16_t
simde_vceqzh_f16(simde_float16 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vceqzh_f16(a);
  #else
    return simde_vceqh_f16(a, SIMDE_FLOAT16_VALUE(0.0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vceqzh_f16
  #define vceqzh_f16(a) simde_vceqzh_f16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vceqzs_f32(simde_float32_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzs_f32(a);
  #else
    return simde_vceqs_f32(a, SIMDE_FLOAT32_C(0.0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzs_f32
  #define vceqzs_f32(a) simde_vceqzs_f32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vceqzd_f64(simde_float64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vceqzd_f64(a);
  #else
    return simde_vceqd_f64(a, SIMDE_FLOAT64_C(0.0));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vceqzd_f64
  #define vceqzd_f64(a) simde_vceqzd_f64((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_CEQZ_H) */
