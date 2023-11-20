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
 */

#if !defined(SIMDE_ARM_NEON_CLZ_H)
#define SIMDE_ARM_NEON_CLZ_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
uint8_t
simde_x_vclzb_u8(uint8_t a) {
  #if \
      defined(SIMDE_BUILTIN_SUFFIX_8_) && \
      ( \
        SIMDE_BUILTIN_HAS_8_(clz) || \
        HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
        HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
        HEDLEY_IBM_VERSION_CHECK(13,1,0) \
      )
    if (HEDLEY_UNLIKELY(a == 0))
      return 8 * sizeof(r);

    return HEDLEY_STATIC_CAST(uint8_t, SIMDE_BUILTIN_8_(clz)(HEDLEY_STATIC_CAST(unsigned SIMDE_BUILTIN_TYPE_8_, a)));
  #else
    uint8_t r;
    uint8_t shift;

    if (HEDLEY_UNLIKELY(a == 0))
      return 8 * sizeof(r);

    r =     HEDLEY_STATIC_CAST(uint8_t, (a > UINT8_C(0x0F)) << 2); a >>= r;
    shift = HEDLEY_STATIC_CAST(uint8_t, (a > UINT8_C(0x03)) << 1); a >>= shift; r |= shift;
    r |= (a >> 1);

    return ((8 * sizeof(r)) - 1) - r;
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
uint16_t
simde_x_vclzh_u16(uint16_t a) {
  #if \
      defined(SIMDE_BUILTIN_SUFFIX_16_) && \
      ( \
        SIMDE_BUILTIN_HAS_16_(clz) || \
        HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
        HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
        HEDLEY_IBM_VERSION_CHECK(13,1,0) \
      )
    if (HEDLEY_UNLIKELY(a == 0))
      return 8 * sizeof(r);

    return HEDLEY_STATIC_CAST(uint16_t, SIMDE_BUILTIN_16_(clz)(HEDLEY_STATIC_CAST(unsigned SIMDE_BUILTIN_TYPE_16_, a)));
  #else
    uint16_t r;
    uint16_t shift;

    if (HEDLEY_UNLIKELY(a == 0))
      return 8 * sizeof(r);

    r =     HEDLEY_STATIC_CAST(uint16_t, (a > UINT16_C(0x00FF)) << 3); a >>= r;
    shift = HEDLEY_STATIC_CAST(uint16_t, (a > UINT16_C(0x000F)) << 2); a >>= shift; r |= shift;
    shift = HEDLEY_STATIC_CAST(uint16_t, (a > UINT16_C(0x0003)) << 1); a >>= shift; r |= shift;
    r |= (a >> 1);

    return ((8 * sizeof(r)) - 1) - r;
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_x_vclzs_u32(uint32_t a) {
  #if \
      defined(SIMDE_BUILTIN_SUFFIX_32_) && \
      ( \
        SIMDE_BUILTIN_HAS_32_(clz) || \
        HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
        HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
        HEDLEY_IBM_VERSION_CHECK(13,1,0) \
      )
    if (HEDLEY_UNLIKELY(a == 0))
      return 8 * sizeof(a);

    return HEDLEY_STATIC_CAST(uint32_t, SIMDE_BUILTIN_32_(clz)(HEDLEY_STATIC_CAST(unsigned SIMDE_BUILTIN_TYPE_32_, a)));
  #else
    uint32_t r;
    uint32_t shift;

    if (HEDLEY_UNLIKELY(a == 0))
      return 8 * sizeof(a);

    r     = HEDLEY_STATIC_CAST(uint32_t, (a > UINT32_C(0xFFFF)) << 4); a >>= r;
    shift = HEDLEY_STATIC_CAST(uint32_t, (a > UINT32_C(0x00FF)) << 3); a >>= shift; r |= shift;
    shift = HEDLEY_STATIC_CAST(uint32_t, (a > UINT32_C(0x000F)) << 2); a >>= shift; r |= shift;
    shift = HEDLEY_STATIC_CAST(uint32_t, (a > UINT32_C(0x0003)) << 1); a >>= shift; r |= shift;
    r    |= (a >> 1);

    return ((8 * sizeof(r)) - 1) - r;
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
int8_t
simde_x_vclzb_s8(int8_t a) {
  return HEDLEY_STATIC_CAST(int8_t, simde_x_vclzb_u8(HEDLEY_STATIC_CAST(uint8_t, a)));
}

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_x_vclzh_s16(int16_t a) {
  return HEDLEY_STATIC_CAST(int16_t, simde_x_vclzh_u16(HEDLEY_STATIC_CAST(uint16_t, a)));
}

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_x_vclzs_s32(int32_t a) {
  return HEDLEY_STATIC_CAST(int32_t, simde_x_vclzs_u32(HEDLEY_STATIC_CAST(uint32_t, a)));
}

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vclz_s8(simde_int8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclz_s8(a);
  #else
    simde_int8x8_private
      a_ = simde_int8x8_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint8m1_t vsign;
      vuint8m1_t vx, vn;
      vbool8_t eq_zero_mask, neq_zero_mask, sle_mask;
      vsign = a_.sv64;
      vx = __riscv_vreinterpret_v_i8m1_u8m1(vsign);
      eq_zero_mask = __riscv_vmseq_vx_u8m1_b8(vx, 0, 8);
      neq_zero_mask = __riscv_vmnot_m_b8(eq_zero_mask, 8);
      vn = __riscv_vmv_v_x_u8m1(0, 8);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x0F, 8);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 4, 8);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 4, 8);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x3F, 8);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 2, 8);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 2, 8);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x7F, 8);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 1, 8);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 1, 8);
      vn = __riscv_vmerge_vxm_u8m1(vn, 8, eq_zero_mask, 8);
      r_.sv64 = __riscv_vreinterpret_v_u8m1_i8m1(vn);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzb_s8(a_.values[i]);
      }
    #endif

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclz_s8
  #define vclz_s8(a) simde_vclz_s8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vclz_s16(simde_int16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclz_s16(a);
  #else
    simde_int16x4_private
      a_ = simde_int16x4_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint16m1_t vsign;
      vuint16m1_t vx, vn;
      vbool16_t eq_zero_mask, neq_zero_mask, sle_mask;
      vsign = a_.sv64;
      vx = __riscv_vreinterpret_v_i16m1_u16m1(vsign);
      eq_zero_mask = __riscv_vmseq_vx_u16m1_b16(vx, 0, 4);
      neq_zero_mask = __riscv_vmnot_m_b16(eq_zero_mask, 4);
      vn = __riscv_vmv_v_x_u16m1(0, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 8, 4);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 8, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 4, 4);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 4, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 2, 4);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 2, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 1, 4);
      vn = __riscv_vmerge_vxm_u16m1(vn, 16, eq_zero_mask, 4);
      r_.sv64 = __riscv_vreinterpret_v_u16m1_i16m1(vn);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzh_s16(a_.values[i]);
      }
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclz_s16
  #define vclz_s16(a) simde_vclz_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vclz_s32(simde_int32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclz_s32(a);
  #else
    simde_int32x2_private
      a_ = simde_int32x2_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint32m1_t vsign;
      vuint32m1_t vx, vn;
      vbool32_t eq_zero_mask, neq_zero_mask, sle_mask;
      vsign = a_.sv64;
      vx = __riscv_vreinterpret_v_i32m1_u32m1(vsign);
      eq_zero_mask = __riscv_vmseq_vx_u32m1_b32(vx, 0, 2);
      neq_zero_mask = __riscv_vmnot_m_b32(eq_zero_mask, 2);
      vn = __riscv_vmv_v_x_u32m1(0, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0000FFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 16, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 16, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 8, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 8, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 4, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 4, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 2, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 2, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 1, 2);
      vn = __riscv_vmerge_vxm_u32m1(vn, 32, eq_zero_mask, 2);
      r_.sv64 = __riscv_vreinterpret_v_u32m1_i32m1(vn);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzs_s32(a_.values[i]);
      }
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclz_s32
  #define vclz_s32(a) simde_vclz_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vclz_u8(simde_uint8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclz_u8(a);
  #else
    simde_uint8x8_private
      a_ = simde_uint8x8_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint8m1_t vx, vn;
      vbool8_t eq_zero_mask, neq_zero_mask, sle_mask;
      vx = a_.sv64;
      eq_zero_mask = __riscv_vmseq_vx_u8m1_b8(vx, 0, 8);
      neq_zero_mask = __riscv_vmnot_m_b8(eq_zero_mask, 8);
      vn = __riscv_vmv_v_x_u8m1(0, 8);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x0F, 8);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 4, 8);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 4, 8);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x3F, 8);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 2, 8);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 2, 8);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x7F, 8);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 1, 8);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 1, 8);
      r_.sv64 = __riscv_vmerge_vxm_u8m1(vn, 8, eq_zero_mask, 8);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzb_u8(a_.values[i]);
      }
    #endif

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclz_u8
  #define vclz_u8(a) simde_vclz_u8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vclz_u16(simde_uint16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclz_u16(a);
  #else
    simde_uint16x4_private
      a_ = simde_uint16x4_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint16m1_t vx, vn;
      vbool16_t eq_zero_mask, neq_zero_mask, sle_mask;
      vx = a_.sv64;
      eq_zero_mask = __riscv_vmseq_vx_u16m1_b16(vx, 0, 4);
      neq_zero_mask = __riscv_vmnot_m_b16(eq_zero_mask, 4);
      vn = __riscv_vmv_v_x_u16m1(0, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 8, 4);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 8, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 4, 4);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 4, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 2, 4);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 2, 4);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFF, 4);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 1, 4);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 1, 4);
      r_.sv64 = __riscv_vmerge_vxm_u16m1(vn, 16, eq_zero_mask, 4);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzh_u16(a_.values[i]);
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclz_u16
  #define vclz_u16(a) simde_vclz_u16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vclz_u32(simde_uint32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclz_u32(a);
  #else
    simde_uint32x2_private
      a_ = simde_uint32x2_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint32m1_t vx, vn;
      vbool32_t eq_zero_mask, neq_zero_mask, sle_mask;
      vx = a_.sv64;
      eq_zero_mask = __riscv_vmseq_vx_u32m1_b32(vx, 0, 2);
      neq_zero_mask = __riscv_vmnot_m_b32(eq_zero_mask, 2);
      vn = __riscv_vmv_v_x_u32m1(0, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0000FFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 16, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 16, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 8, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 8, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 4, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 4, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 2, 2);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 2, 2);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFFFFFF, 2);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 1, 2);
      r_.sv64 = __riscv_vmerge_vxm_u32m1(vn, 32, eq_zero_mask, 2);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzs_u32(a_.values[i]);
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclz_u32
  #define vclz_u32(a) simde_vclz_u32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vclzq_s8(simde_int8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclzq_s8(a);
  #else
    simde_int8x16_private
      a_ = simde_int8x16_to_private(a),
      r_;

    #if defined(SIMDE_X86_GFNI_NATIVE)
      /* https://gist.github.com/animetosho/6cb732ccb5ecd86675ca0a442b3c0622 */
      a_.m128i = _mm_gf2p8affine_epi64_epi8(a_.m128i, _mm_set_epi32(HEDLEY_STATIC_CAST(int32_t, 0x80402010), HEDLEY_STATIC_CAST(int32_t, 0x08040201), HEDLEY_STATIC_CAST(int32_t, 0x80402010), HEDLEY_STATIC_CAST(int32_t, 0x08040201)), 0);
      a_.m128i = _mm_andnot_si128(_mm_add_epi8(a_.m128i, _mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, 0xff))), a_.m128i);
      r_.m128i = _mm_gf2p8affine_epi64_epi8(a_.m128i, _mm_set_epi32(HEDLEY_STATIC_CAST(int32_t, 0xaaccf0ff), 0, HEDLEY_STATIC_CAST(int32_t, 0xaaccf0ff), 0), 8);
    #elif defined(SIMDE_RISCV_V_NATIVE)
      vint8m1_t vsign;
      vuint8m1_t vx, vn;
      vbool8_t eq_zero_mask, neq_zero_mask, sle_mask;
      vsign = a_.sv128;
      vx = __riscv_vreinterpret_v_i8m1_u8m1(vsign);
      eq_zero_mask = __riscv_vmseq_vx_u8m1_b8(vx, 0, 16);
      neq_zero_mask = __riscv_vmnot_m_b8(eq_zero_mask, 16);
      vn = __riscv_vmv_v_x_u8m1(0, 16);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x0F, 16);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 4, 16);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 4, 16);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x3F, 16);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 2, 16);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 2, 16);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x7F, 16);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 1, 16);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 1, 16);
      vn = __riscv_vmerge_vxm_u8m1(vn, 8, eq_zero_mask, 16);
      r_.sv128 = __riscv_vreinterpret_v_u8m1_i8m1(vn);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzb_s8(a_.values[i]);
      }
    #endif

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclzq_s8
  #define vclzq_s8(a) simde_vclzq_s8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vclzq_s16(simde_int16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclzq_s16(a);
  #else
    simde_int16x8_private
      a_ = simde_int16x8_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint16m1_t vsign;
      vuint16m1_t vx, vn;
      vbool16_t eq_zero_mask, neq_zero_mask, sle_mask;
      vsign = a_.sv128;
      vx = __riscv_vreinterpret_v_i16m1_u16m1(vsign);
      eq_zero_mask = __riscv_vmseq_vx_u16m1_b16(vx, 0, 8);
      neq_zero_mask = __riscv_vmnot_m_b16(eq_zero_mask, 8);
      vn = __riscv_vmv_v_x_u16m1(0, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 8, 8);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 8, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 4, 8);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 4, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 2, 8);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 2, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 1, 8);
      vn = __riscv_vmerge_vxm_u16m1(vn, 16, eq_zero_mask, 8);
      r_.sv128 = __riscv_vreinterpret_v_u16m1_i16m1(vn);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzh_s16(a_.values[i]);
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclzq_s16
  #define vclzq_s16(a) simde_vclzq_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vclzq_s32(simde_int32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclzq_s32(a);
  #else
    simde_int32x4_private
      a_ = simde_int32x4_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint32m1_t vsign;
      vuint32m1_t vx, vn;
      vbool32_t eq_zero_mask, neq_zero_mask, sle_mask;
      vsign = a_.sv128;
      vx = __riscv_vreinterpret_v_i32m1_u32m1(vsign);
      eq_zero_mask = __riscv_vmseq_vx_u32m1_b32(vx, 0, 4);
      neq_zero_mask = __riscv_vmnot_m_b32(eq_zero_mask, 4);
      vn = __riscv_vmv_v_x_u32m1(0, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0000FFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 16, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 16, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 8, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 8, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 4, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 4, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 2, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 2, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 1, 4);
      vn = __riscv_vmerge_vxm_u32m1(vn, 32, eq_zero_mask, 4);
      r_.sv128 = __riscv_vreinterpret_v_u32m1_i32m1(vn);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzs_s32(a_.values[i]);
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclzq_s32
  #define vclzq_s32(a) simde_vclzq_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vclzq_u8(simde_uint8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclzq_u8(a);
  #else
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(a),
      r_;

    #if defined(SIMDE_X86_GFNI_NATIVE)
      a_.m128i = _mm_gf2p8affine_epi64_epi8(a_.m128i, _mm_set_epi32(HEDLEY_STATIC_CAST(int32_t, 0x80402010), HEDLEY_STATIC_CAST(int32_t, 0x08040201), HEDLEY_STATIC_CAST(int32_t, 0x80402010), HEDLEY_STATIC_CAST(int32_t, 0x08040201)), 0);
      a_.m128i = _mm_andnot_si128(_mm_add_epi8(a_.m128i, _mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, 0xff))), a_.m128i);
      r_.m128i = _mm_gf2p8affine_epi64_epi8(a_.m128i, _mm_set_epi32(HEDLEY_STATIC_CAST(int32_t, 0xaaccf0ff), 0, HEDLEY_STATIC_CAST(int32_t, 0xaaccf0ff), 0), 8);
    #elif defined(SIMDE_RISCV_V_NATIVE)
      vuint8m1_t vx, vn;
      vbool8_t eq_zero_mask, neq_zero_mask, sle_mask;
      vx = a_.sv128;
      eq_zero_mask = __riscv_vmseq_vx_u8m1_b8(vx, 0, 16);
      neq_zero_mask = __riscv_vmnot_m_b8(eq_zero_mask, 16);
      vn = __riscv_vmv_v_x_u8m1(0, 16);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x0F, 16);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 4, 16);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 4, 16);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x3F, 16);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 2, 16);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 2, 16);
      sle_mask = __riscv_vmsleu_vx_u8m1_b8_mu(neq_zero_mask, neq_zero_mask, vx, 0x7F, 16);
      vn = __riscv_vadd_vx_u8m1_mu(sle_mask, vn, vn, 1, 16);
      vx = __riscv_vsll_vx_u8m1_mu(sle_mask, vx, vx, 1, 16);
      r_.sv128 = __riscv_vmerge_vxm_u8m1(vn, 8, eq_zero_mask, 16);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzb_u8(a_.values[i]);
      }
    #endif

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclzq_u8
  #define vclzq_u8(a) simde_vclzq_u8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vclzq_u16(simde_uint16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclzq_u16(a);
  #else
    simde_uint16x8_private
      a_ = simde_uint16x8_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint16m1_t vx, vn;
      vbool16_t eq_zero_mask, neq_zero_mask, sle_mask;
      vx = a_.sv128;
      eq_zero_mask = __riscv_vmseq_vx_u16m1_b16(vx, 0, 8);
      neq_zero_mask = __riscv_vmnot_m_b16(eq_zero_mask, 8);
      vn = __riscv_vmv_v_x_u16m1(0, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 8, 8);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 8, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 4, 8);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 4, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 2, 8);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 2, 8);
      sle_mask = __riscv_vmsleu_vx_u16m1_b16_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFF, 8);
      vn = __riscv_vadd_vx_u16m1_mu(sle_mask, vn, vn, 1, 8);
      vx = __riscv_vsll_vx_u16m1_mu(sle_mask, vx, vx, 1, 8);
      r_.sv128 = __riscv_vmerge_vxm_u16m1(vn, 16, eq_zero_mask, 8);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzh_u16(a_.values[i]);
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclzq_u16
  #define vclzq_u16(a) simde_vclzq_u16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vclzq_u32(simde_uint32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vclzq_u32(a);
  #else
    simde_uint32x4_private
      a_ = simde_uint32x4_to_private(a),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint32m1_t vx, vn;
      vbool32_t eq_zero_mask, neq_zero_mask, sle_mask;
      vx = a_.sv128;
      eq_zero_mask = __riscv_vmseq_vx_u32m1_b32(vx, 0, 4);
      neq_zero_mask = __riscv_vmnot_m_b32(eq_zero_mask, 4);
      vn = __riscv_vmv_v_x_u32m1(0, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0000FFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 16, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 16, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x00FFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 8, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 8, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x0FFFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 4, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 4, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x3FFFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 2, 4);
      vx = __riscv_vsll_vx_u32m1_mu(sle_mask, vx, vx, 2, 4);
      sle_mask = __riscv_vmsleu_vx_u32m1_b32_mu(neq_zero_mask, neq_zero_mask, vx, 0x7FFFFFFF, 4);
      vn = __riscv_vadd_vx_u32m1_mu(sle_mask, vn, vn, 1, 4);
      r_.sv128 = __riscv_vmerge_vxm_u32m1(vn, 32, eq_zero_mask, 4);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_x_vclzs_u32(a_.values[i]);
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vclzq_u32
  #define vclzq_u32(a) simde_vclzq_u32(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_CLZ_H) */
