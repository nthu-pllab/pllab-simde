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

#if !defined(SIMDE_ARM_NEON_MMLAQ_H)
#define SIMDE_ARM_NEON_MMLAQ_H

#include "types.h"
#include "cgt.h"
#include "bsl.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmmlaq_s32(simde_int32x4_t r, simde_int8x16_t a, simde_int8x16_t b) {
  // I8MM is optional feature. src: https://patchwork.ffmpeg.org/project/ffmpeg/patch/20230530123043.52940-2-martin@martin.st/
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_MATMUL_INT8)
    return vmmlaq_s32(r, a, b);
  #else
    simde_int8x16_private
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);
    simde_int32x4_private
      r_ = simde_int32x4_to_private(r),
      ret;

    #if defined(SIMDE_RISCV_V_NATIVE)
        vint8mf4_t va_low0 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(a_.sv128, 0, 4));
         vint8mf4_t va_low1 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(a_.sv128, 4, 4));
        vint8mf4_t va_high0 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(a_.sv128, 8, 4));
        vint8mf4_t va_high1 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(a_.sv128, 12, 4));

        vint8mf4_t vb_low0 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 0, 4));
        vint8mf4_t vb_low1 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 4, 4));
        vint8mf4_t vb_high0 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 8, 4));
        vint8mf4_t vb_high1 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 12, 4));

        vint16mf2_t vd0_low0 = __riscv_vwmul_vv_i16mf2 (va_low0, vb_low0, 4);
        vint16mf2_t vd0_low1 = __riscv_vwmul_vv_i16mf2 (va_low1, vb_low1, 4);
        vint16mf2_t vd0_high0 = __riscv_vwmul_vv_i16mf2 (va_low0, vb_high0, 4);
        vint16mf2_t vd0_high1 = __riscv_vwmul_vv_i16mf2 (va_low1, vb_high1, 4);
        vint16mf2_t vd1_low0 = __riscv_vwmul_vv_i16mf2 (va_high0, vb_low0, 4);
        vint16mf2_t vd1_low1 = __riscv_vwmul_vv_i16mf2 (va_high1, vb_low1, 4);
        vint16mf2_t vd1_high0 = __riscv_vwmul_vv_i16mf2 (va_high0, vb_high0, 4);
        vint16mf2_t vd1_high1 = __riscv_vwmul_vv_i16mf2 (va_high1, vb_high1, 4);
       
        vint32m1_t vd = __riscv_vmv_v_x_i32m1(0, 4);
        
        vint32m1_t rst_00 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_low0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_low1, vd, 4), 1);
        vint32m1_t rst_01 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_high0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_high1, vd, 4), 1);
        vint32m1_t rst_10 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_low0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_low1, vd, 4), 1);
        vint32m1_t rst_11 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_high0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_high1, vd, 4), 1);
       
       r_.sv128 = __riscv_vslideup_vx_i32m1(
        __riscv_vslideup_vx_i32m1(
          __riscv_vslideup_vx_i32m1(
            __riscv_vadd_vx_i32m1(rst_00, c_.values[0], 4),
            __riscv_vadd_vx_i32m1(rst_01, c_.values[1], 4),
            1, 4),
          __riscv_vadd_vx_i32m1(rst_10, c_.values[2], 4),
          2, 4),
        __riscv_vadd_vx_i32m1(rst_11, c_.values[3], 4),
        3, 4);
    #else
      for (size_t k = 0 ; k < (sizeof(ret.values) / sizeof(ret.values[0])) ; k++) {
        ret.values[k] = r_.values[k];
        for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0]) / 2) ; i++) {
          ret.values[k] += a_.values[(k/2)*8+i] * b_.values[(k%2)*8+i];
        }
      }
    #endif

    return simde_int32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vmmlaq_s32
  #define vmmlaq_s32(r, a, b) simde_vmmlaq_s32((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmmlaq_u32(simde_uint32x4_t r, simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_MATMUL_INT8)
    return vmmlaq_u32(r, a, b);
  #else
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);
    simde_uint32x4_private
      r_ = simde_uint32x4_to_private(r),
      ret;

    #if defined(SIMDE_RISCV_V_NATIVE)

        vuint8mf4_t va_low0 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 0, 4));
         vuint8mf4_t va_low1 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 4, 4));
        vuint8mf4_t va_high0 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 8, 4));
        vuint8mf4_t va_high1 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 12, 4));

        vuint8mf4_t vb_low0 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(b_.sv128, 0, 4));
        vuint8mf4_t vb_low1 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(b_.sv128, 4, 4));
        vuint8mf4_t vb_high0 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(b_.sv128, 8, 4));
        vuint8mf4_t vb_high1 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(b_.sv128, 12, 4));

        vuint16mf2_t vd0_low0 = __riscv_vwmulu_vv_u16mf2(va_low0, vb_low0, 4);
        vuint16mf2_t vd0_low1 = __riscv_vwmulu_vv_u16mf2(va_low1, vb_low1, 4);
        vuint16mf2_t vd0_high0 = __riscv_vwmulu_vv_u16mf2(va_low0, vb_high0, 4);
        vuint16mf2_t vd0_high1 = __riscv_vwmulu_vv_u16mf2(va_low1, vb_high1, 4);
        vuint16mf2_t vd1_low0 = __riscv_vwmulu_vv_u16mf2(va_high0, vb_low0, 4);
        vuint16mf2_t vd1_low1 = __riscv_vwmulu_vv_u16mf2(va_high1, vb_low1, 4);
        vuint16mf2_t vd1_high0 = __riscv_vwmulu_vv_u16mf2(va_high0, vb_high0, 4);
        vuint16mf2_t vd1_high1 = __riscv_vwmulu_vv_u16mf2(va_high1, vb_high1, 4);
       
        vuint32m1_t vd = __riscv_vmv_v_x_u32m1(0, 4);
        
        vuint32m1_t rst_00 = __riscv_vadd_vv_u32m1(
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd0_low0, vd, 4),
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd0_low1, vd, 4), 1);
        vuint32m1_t rst_01 = __riscv_vadd_vv_u32m1(
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd0_high0, vd, 4),
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd0_high1, vd, 4), 1);
        vuint32m1_t rst_10 = __riscv_vadd_vv_u32m1(
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd1_low0, vd, 4),
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd1_low1, vd, 4), 1);
        vuint32m1_t rst_11 = __riscv_vadd_vv_u32m1(
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd1_high0, vd, 4),
          __riscv_vwredsumu_vs_u16mf2_u32m1(vd1_high1, vd, 4), 1);
       
       r_.sv128 = __riscv_vslideup_vx_u32m1(
        __riscv_vslideup_vx_u32m1(
          __riscv_vslideup_vx_u32m1(
            __riscv_vadd_vx_u32m1(rst_00, c_.values[0], 4),
            __riscv_vadd_vx_u32m1(rst_01, c_.values[1], 4),
            1, 4),
          __riscv_vadd_vx_u32m1(rst_10, c_.values[2], 4),
          2, 4),
        __riscv_vadd_vx_u32m1(rst_11, c_.values[3], 4),
        3, 4);
    #else
      for (size_t k = 0 ; k < (sizeof(ret.values) / sizeof(ret.values[0])) ; k++) {
        ret.values[k] = r_.values[k];
        for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0]) / 2) ; i++) {
          ret.values[k] += a_.values[(k/2)*8+i] * b_.values[(k%2)*8+i];
        }
      }
    #endif

    return simde_uint32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vmmlaq_u32
  #define vmmlaq_u32(r, a, b) simde_vmmlaq_u32((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vusmmlaq_s32(simde_int32x4_t r, simde_uint8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_MATMUL_INT8)
    return vusmmlaq_s32(r, a, b);
  #else
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(a);
    simde_int8x16_private
      b_ = simde_int8x16_to_private(b);
    simde_int32x4_private
      r_ = simde_int32x4_to_private(r),
      ret;

    #if defined(SIMDE_RISCV_V_NATIVE)

        vuint8mf4_t va_low0 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 0, 4));
        vuint8mf4_t va_low1 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 4, 4));
        vuint8mf4_t va_high0 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 8, 4));
        vuint8mf4_t va_high1 = __riscv_vlmul_trunc_v_u8m1_u8mf4(
          __riscv_vslidedown_vx_u8m1(a_.sv128, 12, 4));

        vint8mf4_t vb_low0 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 0, 4));
        vint8mf4_t vb_low1 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 4, 4));
        vint8mf4_t vb_high0 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 8, 4));
        vint8mf4_t vb_high1 = __riscv_vlmul_trunc_v_i8m1_i8mf4(
          __riscv_vslidedown_vx_i8m1(b_.sv128, 12, 4));

        vint16mf2_t vd0_low0 = __riscv_vwmulsu_vv_i16mf2 (vb_low0, va_low0, 4);
        vint16mf2_t vd0_low1 = __riscv_vwmulsu_vv_i16mf2 (vb_low1, va_low1, 4);
        vint16mf2_t vd0_high0 = __riscv_vwmulsu_vv_i16mf2 (vb_high0, va_low0, 4);
        vint16mf2_t vd0_high1 = __riscv_vwmulsu_vv_i16mf2 (vb_high1, va_low1, 4);
        vint16mf2_t vd1_low0 = __riscv_vwmulsu_vv_i16mf2 (vb_low0, va_high0, 4);
        vint16mf2_t vd1_low1 = __riscv_vwmulsu_vv_i16mf2 (vb_low1, va_high1, 4);
        vint16mf2_t vd1_high0 = __riscv_vwmulsu_vv_i16mf2 (vb_high0, va_high0, 4);
        vint16mf2_t vd1_high1 = __riscv_vwmulsu_vv_i16mf2 (vb_high1, va_high1, 4);
       
        vint32m1_t vd = __riscv_vmv_v_x_i32m1(0, 4);
        
        vint32m1_t rst_00 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_low0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_low1, vd, 4), 1);
        vint32m1_t rst_01 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_high0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd0_high1, vd, 4), 1);
        vint32m1_t rst_10 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_low0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_low1, vd, 4), 1);
        vint32m1_t rst_11 = __riscv_vadd_vv_i32m1(
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_high0, vd, 4),
          __riscv_vwredsum_vs_i16mf2_i32m1(vd1_high1, vd, 4), 1);
       
       r_.sv128 = __riscv_vslideup_vx_i32m1(
        __riscv_vslideup_vx_i32m1(
          __riscv_vslideup_vx_i32m1(
            __riscv_vadd_vx_i32m1(rst_00, c_.values[0], 4),
            __riscv_vadd_vx_i32m1(rst_01, c_.values[1], 4),
            1, 4),
          __riscv_vadd_vx_i32m1(rst_10, c_.values[2], 4),
          2, 4),
        __riscv_vadd_vx_i32m1(rst_11, c_.values[3], 4),
        3, 4);
    #else
      for (size_t k = 0 ; k < (sizeof(ret.values) / sizeof(ret.values[0])) ; k++) {
        ret.values[k] = r_.values[k];
        for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0]) / 2) ; i++) {
          ret.values[k] += a_.values[(k/2)*8+i] * b_.values[(k%2)*8+i];
        }
      }
    #endif

    return simde_int32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vusmmlaq_s32
  #define vusmmlaq_s32(r, a, b) simde_vusmmlaq_s32((r), (a), (b))
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MMLAQ_H) */
