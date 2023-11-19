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
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 *   2023      Yung-Cheng Su <eric20607@gapp.nthu.edu.tw>
 */

#if !defined(SIMDE_ARM_NEON_USDOT_H)
#define SIMDE_ARM_NEON_USDOT_H

#include "types.h"

#include "add.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vusdot_s32(simde_int32x2_t r, simde_uint8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_MATMUL_INT8)
    return vusdot_s32(r, a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x2_private r_ = simde_int32x2_to_private(r);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_int8x8_private b_ = simde_int8x8_to_private(b);

    vuint8mf4_t va_low = __riscv_vlmul_trunc_v_u8m1_u8mf4(
      __riscv_vslidedown_vx_u8m1(a_.sv64, 0, 4));
    vuint8mf4_t va_high = __riscv_vlmul_trunc_v_u8m1_u8mf4(
      __riscv_vslidedown_vx_u8m1(a_.sv64, 4, 4));

    vint8mf4_t vb_low = __riscv_vlmul_trunc_v_i8m1_i8mf4(
      __riscv_vslidedown_vx_i8m1(b_.sv64, 0, 4));
    vint8mf4_t vb_high = __riscv_vlmul_trunc_v_i8m1_i8mf4(
      __riscv_vslidedown_vx_i8m1(b_.sv64, 4, 4));

    vint16mf2_t vd_low = __riscv_vwmulsu_vv_i16mf2(vb_low, va_low, 4);
    vint16mf2_t vd_high = __riscv_vwmulsu_vv_i16mf2(vb_high, va_high, 4);

    vint32m1_t vd = __riscv_vmv_v_x_i32m1(0, 4);

    vint32m1_t vd_low_wide = __riscv_vwcvt_x_x_v_i32m1 (vd_low, 4);
    vint32m1_t rst0 = __riscv_vredsum_vs_i32m1_i32m1(vd_low_wide, vd, 4);

    vint32m1_t vd_high_wide = __riscv_vwcvt_x_x_v_i32m1 (vd_high, 4);
    vint32m1_t rst1 = __riscv_vredsum_vs_i32m1_i32m1(vd_high_wide, vd, 4);
    r_.sv64 = __riscv_vslideup_vx_i32m1(
      __riscv_vadd_vx_i32m1(rst0, r_.values[0], 2),
      __riscv_vadd_vx_i32m1(rst1, r_.values[1], 2),
      1, 2);

    return simde_int32x2_from_private(r_);
  #else
    simde_int32x2_private r_;
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_int8x8_private b_ = simde_int8x8_to_private(b);
    for (int i = 0 ; i < 2 ; i++) {
      int32_t acc = 0;
      SIMDE_VECTORIZE_REDUCTION(+:acc)
      for (int j = 0 ; j < 4 ; j++) {
        const int idx = j + (i << 2);
        acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx]) * HEDLEY_STATIC_CAST(int32_t, b_.values[idx]);
      }
      r_.values[i] = acc;
    }
    return simde_vadd_s32(r, simde_int32x2_from_private(r_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(__ARM_FEATURE_MATMUL_INT8))
  #undef vusdot_s32
  #define vusdot_s32(r, a, b) simde_vusdot_s32((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vusdotq_s32(simde_int32x4_t r, simde_uint8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_MATMUL_INT8)
    return vusdotq_s32(r, a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x4_private r_  = simde_int32x4_to_private(r);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_int8x16_private b_ = simde_int8x16_to_private(b);

    vuint8mf4_t va_low = __riscv_vlmul_trunc_v_u8m1_u8mf4(
      __riscv_vslidedown_vx_u8m1(a_.sv128, 0, 4));
    vuint8mf4_t va_mid1 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
      __riscv_vslidedown_vx_u8m1(a_.sv128, 4, 4));
    vuint8mf4_t va_mid2 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
      __riscv_vslidedown_vx_u8m1(a_.sv128, 8, 4));
    vuint8mf4_t va_high = __riscv_vlmul_trunc_v_u8m1_u8mf4(
      __riscv_vslidedown_vx_u8m1(a_.sv128, 12, 4));

    vint8mf4_t vb_low = __riscv_vlmul_trunc_v_i8m1_i8mf4(
      __riscv_vslidedown_vx_i8m1(b_.sv128, 0, 4));
    vint8mf4_t vb_mid1 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
      __riscv_vslidedown_vx_i8m1(b_.sv128, 4, 4));
    vint8mf4_t vb_mid2 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
      __riscv_vslidedown_vx_i8m1(b_.sv128, 8, 4));
    vint8mf4_t vb_high = __riscv_vlmul_trunc_v_i8m1_i8mf4(
      __riscv_vslidedown_vx_i8m1(b_.sv128, 12, 4));

    vint16mf2_t vd_low = __riscv_vwmulsu_vv_i16mf2(vb_low, va_low, 4);
    vint16mf2_t vd_mid1 = __riscv_vwmulsu_vv_i16mf2(vb_mid1, va_mid1, 4);
    vint16mf2_t vd_mid2 = __riscv_vwmulsu_vv_i16mf2(vb_mid2, va_mid2, 4);
    vint16mf2_t vd_high = __riscv_vwmulsu_vv_i16mf2(vb_high, va_high, 4);

    vint32m1_t vd = __riscv_vmv_v_x_i32m1(0, 4);

    vint32m1_t vd_low_wide = __riscv_vwcvt_x_x_v_i32m1 (vd_low, 4);
    vint32m1_t rst0 = __riscv_vredsum_vs_i32m1_i32m1(vd_low_wide, vd, 4);

    vint32m1_t vd_mid1_wide = __riscv_vwcvt_x_x_v_i32m1 (vd_mid1, 4);
    vint32m1_t rst1 = __riscv_vredsum_vs_i32m1_i32m1(vd_mid1_wide, vd, 4);

    vint32m1_t vd_mid2_wide = __riscv_vwcvt_x_x_v_i32m1 (vd_mid2, 4);
    vint32m1_t rst2 = __riscv_vredsum_vs_i32m1_i32m1(vd_mid2_wide, vd, 4);

    vint32m1_t vd_high_wide = __riscv_vwcvt_x_x_v_i32m1 (vd_high, 4);
    vint32m1_t rst3 = __riscv_vredsum_vs_i32m1_i32m1(vd_high_wide, vd, 4);
    vint32m1_t r0 = __riscv_vslideup_vx_i32m1(__riscv_vadd_vx_i32m1(rst0, r_.values[0], 2), __riscv_vadd_vx_i32m1(rst1, r_.values[1], 2), 1, 2);
    vint32m1_t r1 = __riscv_vslideup_vx_i32m1(r0, __riscv_vadd_vx_i32m1(rst2, r_.values[2], 2), 2, 3);
    r_.sv128 = __riscv_vslideup_vx_i32m1(r1, __riscv_vadd_vx_i32m1(rst3, r_.values[3], 2), 3, 4);

    return simde_int32x4_from_private(r_);
  #else
    simde_int32x4_private r_;
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_int8x16_private b_ = simde_int8x16_to_private(b);
    for (int i = 0 ; i < 4 ; i++) {
      int32_t acc = 0;
      SIMDE_VECTORIZE_REDUCTION(+:acc)
      for (int j = 0 ; j < 4 ; j++) {
        const int idx = j + (i << 2);
        acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx]) * HEDLEY_STATIC_CAST(int32_t, b_.values[idx]);
      }
      r_.values[i] = acc;
    }
    return simde_vaddq_s32(r, simde_int32x4_from_private(r_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(__ARM_FEATURE_MATMUL_INT8))
  #undef vusdotq_s32
  #define vusdotq_s32(r, a, b) simde_vusdotq_s32((r), (a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_USDOT_H) */
