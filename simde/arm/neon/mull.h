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
 *   2023      Yung-Cheng Su <eric20607@gapp.nthu.edu.tw>
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_MULL_H)
#define SIMDE_ARM_NEON_MULL_H

#include "types.h"
#include "mul.h"
#include "movl.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vmull_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmull_s8(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int8x8_private
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);
    simde_int16x8_private r_;

    vint8mf2_t a_mf2 = __riscv_vlmul_trunc_v_i8m1_i8mf2(a_.sv64);
    vint8mf2_t b_mf2 = __riscv_vlmul_trunc_v_i8m1_i8mf2(b_.sv64);
    r_.sv128 = __riscv_vwmul_vv_i16m1(a_mf2, b_mf2, 8);

    return simde_int16x8_from_private(r_);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128)
    return simde_vmulq_s16(simde_vmovl_s8(a), simde_vmovl_s8(b));
  #else
    simde_int16x8_private r_;
    simde_int8x8_private
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && !defined(SIMDE_BUG_GCC_100761)
      __typeof__(r_.values) av, bv;
      SIMDE_CONVERT_VECTOR_(av, a_.values);
      SIMDE_CONVERT_VECTOR_(bv, b_.values);
      r_.values = av * bv;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(int16_t, a_.values[i]) * HEDLEY_STATIC_CAST(int16_t, b_.values[i]);
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_s8
  #define vmull_s8(a, b) simde_vmull_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmull_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmull_s16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int16x4_private
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);
    simde_int32x4_private r_;

    vint16mf2_t a_mf2 = __riscv_vlmul_trunc_v_i16m1_i16mf2(a_.sv64);
    vint16mf2_t b_mf2 = __riscv_vlmul_trunc_v_i16m1_i16mf2(b_.sv64);
    r_.sv128 = __riscv_vwmul_vv_i32m1(a_mf2, b_mf2, 4);

    return simde_int32x4_from_private(r_);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128)
    return simde_vmulq_s32(simde_vmovl_s16(a), simde_vmovl_s16(b));
  #else
    simde_int32x4_private r_;
    simde_int16x4_private
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && !defined(SIMDE_BUG_GCC_100761)
      __typeof__(r_.values) av, bv;
      SIMDE_CONVERT_VECTOR_(av, a_.values);
      SIMDE_CONVERT_VECTOR_(bv, b_.values);
      r_.values = av * bv;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(int32_t, a_.values[i]) * HEDLEY_STATIC_CAST(int32_t, b_.values[i]);
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_s16
  #define vmull_s16(a, b) simde_vmull_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vmull_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmull_s32(a, b);
  #else
    simde_int64x2_private r_;
    simde_int32x2_private
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint32mf2_t a_mf2 = __riscv_vlmul_trunc_v_i32m1_i32mf2(a_.sv64);
      vint32mf2_t b_mf2 = __riscv_vlmul_trunc_v_i32m1_i32mf2(b_.sv64);
      r_.sv128 = __riscv_vwmul_vv_i64m1(a_mf2, b_mf2, 2);
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      __typeof__(r_.values) av, bv;
      SIMDE_CONVERT_VECTOR_(av, a_.values);
      SIMDE_CONVERT_VECTOR_(bv, b_.values);
      r_.values = av * bv;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(int64_t, a_.values[i]) * HEDLEY_STATIC_CAST(int64_t, b_.values[i]);
      }
    #endif

    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_s32
  #define vmull_s32(a, b) simde_vmull_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vmull_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmull_u8(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint8x8_private
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);
    simde_uint16x8_private r_;

    vuint8mf2_t a_mf2 = __riscv_vlmul_trunc_v_u8m1_u8mf2(a_.sv64);
    vuint8mf2_t b_mf2 = __riscv_vlmul_trunc_v_u8m1_u8mf2(b_.sv64);
    r_.sv128 = __riscv_vwmulu_vv_u16m1(a_mf2, b_mf2, 8);

    return simde_uint16x8_from_private(r_);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128)
    return simde_vmulq_u16(simde_vmovl_u8(a), simde_vmovl_u8(b));
  #else
    simde_uint16x8_private r_;
    simde_uint8x8_private
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && !defined(SIMDE_BUG_GCC_100761)
      __typeof__(r_.values) av, bv;
      SIMDE_CONVERT_VECTOR_(av, a_.values);
      SIMDE_CONVERT_VECTOR_(bv, b_.values);
      r_.values = av * bv;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i]) * HEDLEY_STATIC_CAST(uint16_t, b_.values[i]);
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_u8
  #define vmull_u8(a, b) simde_vmull_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmull_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmull_u16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x4_private
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);
    simde_uint32x4_private r_;

    vuint16mf2_t a_mf2 = __riscv_vlmul_trunc_v_u16m1_u16mf2(a_.sv64);
    vuint16mf2_t b_mf2 = __riscv_vlmul_trunc_v_u16m1_u16mf2(b_.sv64);
    r_.sv128 = __riscv_vwmulu_vv_u32m1(a_mf2, b_mf2, 4);

    return simde_uint32x4_from_private(r_);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128)
    return simde_vmulq_u32(simde_vmovl_u16(a), simde_vmovl_u16(b));
  #else
    simde_uint32x4_private r_;
    simde_uint16x4_private
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && !defined(SIMDE_BUG_GCC_100761)
      __typeof__(r_.values) av, bv;
      SIMDE_CONVERT_VECTOR_(av, a_.values);
      SIMDE_CONVERT_VECTOR_(bv, b_.values);
      r_.values = av * bv;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[i]);
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_u16
  #define vmull_u16(a, b) simde_vmull_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vmull_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmull_u32(a, b);
  #else
    simde_uint64x2_private r_;
    simde_uint32x2_private
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b);

    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint32mf2_t a_mf2 = __riscv_vlmul_trunc_v_u32m1_u32mf2(a_.sv64);
      vuint32mf2_t b_mf2 = __riscv_vlmul_trunc_v_u32m1_u32mf2(b_.sv64);
      r_.sv128 = __riscv_vwmulu_vv_u64m1(a_mf2, b_mf2, 4);
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      __typeof__(r_.values) av, bv;
      SIMDE_CONVERT_VECTOR_(av, a_.values);
      SIMDE_CONVERT_VECTOR_(bv, b_.values);
      r_.values = av * bv;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) * HEDLEY_STATIC_CAST(uint64_t, b_.values[i]);
      }
    #endif

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_u32
  #define vmull_u32(a, b) simde_vmull_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_poly16x8_t
simde_vmull_p8(simde_poly8x8_t a, simde_poly8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmull_p8(a, b);
  #else
    simde_uint8x8_private
      a_ = simde_uint8x8_to_private(simde_vreinterpret_u8_p8(a)),
      b_ = simde_uint8x8_to_private(simde_vreinterpret_u8_p8(b));
    simde_uint16x8_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      /*
      vuint16m2_t a_temp16 = __riscv_vwcvtu_x_x_v_u16m2(a_.sv64, 8), b_temp16 = __riscv_vwcvtu_x_x_v_u16m2(b_.sv64, 8);
      vuint32m4_t a_temp32 = __riscv_vwcvtu_x_x_v_u32m4(a_temp16, 8), b_temp32 = __riscv_vwcvtu_x_x_v_u32m4(b_temp16, 8);
      vuint64m8_t a_temp64 = __riscv_vwcvtu_x_x_v_u64m8(a_temp32, 8), b_temp64 = __riscv_vwcvtu_x_x_v_u64m8(b_temp32, 8);
   
      vuint64m8_t temp64 = __riscv_vclmul_vv_u64m8(a_temp64, b_temp64, 8);
      vuint32m4_t temp32 = __riscv_vncvt_x_x_w_u32m4(temp64, 8);
      vuint16m2_t temp16 = __riscv_vncvt_x_x_w_u16m2(temp32, 8);
      r_.sv128 =  __riscv_vlmul_trunc_v_u16m2_u16m1(temp16);
      */

      uint8_t p1 = UINT8_C(0x11), p2 = UINT8_C(0x22), p4 = UINT8_C(0x44), p8 = UINT8_C(0x88);
      uint16_t q1 = UINT16_C(0x1111), q2 = UINT16_C(0x2222), q4 = UINT16_C(0x4444), q8 = UINT16_C(0x8888);
      vuint8m1_t
        x0 = __riscv_vand_vx_u8m1(a_.sv64, p1, 8), x1 = __riscv_vand_vx_u8m1(a_.sv64, p2, 8),
        x2 = __riscv_vand_vx_u8m1(a_.sv64, p4, 8), x3 = __riscv_vand_vx_u8m1(a_.sv64, p8, 8),
        y0 = __riscv_vand_vx_u8m1(b_.sv64, p1, 8), y1 = __riscv_vand_vx_u8m1(b_.sv64, p2, 8),
        y2 = __riscv_vand_vx_u8m1(b_.sv64, p4, 8), y3 = __riscv_vand_vx_u8m1(b_.sv64, p8, 8);
    
      vuint16m2_t
        a0 = __riscv_vwmulu_vv_u16m2(x0, y0, 8), a1 = __riscv_vwmulu_vv_u16m2(x0, y1, 8),
        a2 = __riscv_vwmulu_vv_u16m2(x0, y2, 8), a3 = __riscv_vwmulu_vv_u16m2(x0, y3, 8),
        b0 = __riscv_vwmulu_vv_u16m2(x1, y3, 8), b1 = __riscv_vwmulu_vv_u16m2(x1, y0, 8),
        b2 = __riscv_vwmulu_vv_u16m2(x1, y1, 8), b3 = __riscv_vwmulu_vv_u16m2(x1, y2, 8),
        c0 = __riscv_vwmulu_vv_u16m2(x2, y2, 8), c1 = __riscv_vwmulu_vv_u16m2(x2, y3, 8),
        c2 = __riscv_vwmulu_vv_u16m2(x2, y0, 8), c3 = __riscv_vwmulu_vv_u16m2(x2, y1, 8),
        d0 = __riscv_vwmulu_vv_u16m2(x3, y1, 8), d1 = __riscv_vwmulu_vv_u16m2(x3, y2, 8),
        d2 = __riscv_vwmulu_vv_u16m2(x3, y3, 8), d3 = __riscv_vwmulu_vv_u16m2(x3, y0, 8);
    
      vuint16m2_t
        z0 = __riscv_vxor_vv_u16m2(__riscv_vxor_vv_u16m2(a0, b0, 8), __riscv_vxor_vv_u16m2(c0, d0, 8), 8),
        z1 = __riscv_vxor_vv_u16m2(__riscv_vxor_vv_u16m2(a1, b1, 8), __riscv_vxor_vv_u16m2(c1, d1, 8), 8),
        z2 = __riscv_vxor_vv_u16m2(__riscv_vxor_vv_u16m2(a2, b2, 8), __riscv_vxor_vv_u16m2(c2, d2, 8), 8),
        z3 = __riscv_vxor_vv_u16m2(__riscv_vxor_vv_u16m2(a3, b3, 8), __riscv_vxor_vv_u16m2(c3, d3, 8), 8);
    
        z0 = __riscv_vand_vx_u16m2(z0, q1, 8), z1 = __riscv_vand_vx_u16m2(z1, q2, 8),
        z2 = __riscv_vand_vx_u16m2(z2, q4, 8), z3 = __riscv_vand_vx_u16m2(z3, q8, 8);
    
      r_.sv128 = __riscv_vlmul_trunc_v_u16m2_u16m1(__riscv_vor_vv_u16m2(__riscv_vor_vv_u16m2(z0, z1, 8), __riscv_vor_vv_u16m2(z2, z3, 8), 8));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        uint16_t extend_op2 = HEDLEY_STATIC_CAST(uint16_t, b_.values[i]);
        uint16_t result = 0;
        for(size_t j = 0; j < 8; ++j) {
          if (a_.values[i] & (1 << j)) {
            result = HEDLEY_STATIC_CAST(uint16_t, result ^ (extend_op2 << j));
          }
        }
        r_.values[i] = result;
      }
    #endif
      
    return simde_vreinterpretq_p16_u16(simde_uint16x8_from_private(r_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_p8
  #define vmull_p8(a, b) simde_vmull_p8((a), (b))
#endif

#if !defined(SIMDE_TARGET_NOT_SUPPORT_INT128_TYPE)
SIMDE_FUNCTION_ATTRIBUTES
simde_poly128_t
simde_vmull_p64(simde_poly64_t a, simde_poly64_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARCH_ARM_CRYPTO)
    return vmull_p64(a, b);
  #else
    simde_poly128_t extend_op2 = HEDLEY_STATIC_CAST(simde_poly128_t, b);
    simde_poly128_t result = 0;

    SIMDE_VECTORIZE
    for(size_t j = 0; j < 64; ++j) {
      if (a & (1ull << j)) {
        result = result ^ (extend_op2 << j);
      }
    }

    return result;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_p64
  #define vmull_p64(a, b) simde_vmull_p64((a), (b))
#endif

#endif /* !defined(SIMDE_TARGET_NOT_SUPPORT_INT128_TYPE) */

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MULL_H) */
