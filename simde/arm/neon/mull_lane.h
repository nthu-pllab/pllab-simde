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
 *   2021      Evan Nemerson <evan@nemerson.com>
 *   2023      Yung-Cheng Su <eric20607@gapp.nthu.edu.tw>
 */

#if !defined(SIMDE_ARM_NEON_MULL_LANE_H)
#define SIMDE_ARM_NEON_MULL_LANE_H

#include "mull.h"
#include "dup_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmull_lane_s16(simde_int16x4_t a, simde_int16x4_t b, const int lane) {
  simde_int16x4_private
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);
    simde_int32x4_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vint16mf2_t a_mf2 = __riscv_vlmul_trunc_v_i16m1_i16mf2(a_.sv64);
    r_.sv128 = __riscv_vwmul_vx_i32m1(a_mf2, b_.values[lane], 4);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int32_t, a_.values[i]) * HEDLEY_STATIC_CAST(int32_t, b_.values[lane]);
    }
  #endif
  return simde_int32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_s16(a, v, lane) vmull_lane_s16((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_lane_s16(a, v, lane) simde_vmull_s16((a), simde_vdup_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_s16
  #define vmull_lane_s16(a, v, lane) simde_vmull_lane_s16((a), (v), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vmull_lane_s32(simde_int32x2_t a, simde_int32x2_t b, const int lane) {
  simde_int32x2_private
    a_ = simde_int32x2_to_private(a),
    b_ = simde_int32x2_to_private(b);
  simde_int64x2_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vint32mf2_t a_mf2 = __riscv_vlmul_trunc_v_i32m1_i32mf2(a_.sv64);
    r_.sv128 = __riscv_vwmul_vx_i64m1(a_mf2, b_.values[lane], 2);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int64_t, a_.values[i]) * HEDLEY_STATIC_CAST(int64_t, b_.values[lane]);
    }
  #endif
  return simde_int64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_s32(a, v, lane) vmull_lane_s32((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_lane_s32(a, v, lane) simde_vmull_s32((a), simde_vdup_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_s32
  #define vmull_lane_s32(a, v, lane) simde_vmull_lane_s32((a), (v), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmull_lane_u16(simde_uint16x4_t a, simde_uint16x4_t b, const int lane) {

  simde_uint16x4_private
    a_ = simde_uint16x4_to_private(a),
    b_ = simde_uint16x4_to_private(b);
  simde_uint32x4_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vuint16mf2_t a_mf2 = __riscv_vlmul_trunc_v_u16m1_u16mf2(a_.sv64);
    r_.sv128 = __riscv_vwmulu_vx_u32m1(a_mf2, b_.values[lane], 4);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[lane]);
    }
  #endif
  return simde_uint32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_u16(a, v, lane) vmull_lane_u16((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_lane_u16(a, v, lane) simde_vmull_u16((a), simde_vdup_lane_u16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_u16
  #define vmull_lane_u16(a, v, lane) simde_vmull_lane_u16((a), (v), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vmull_lane_u32(simde_uint32x2_t a, simde_uint32x2_t b, const int lane) {

  simde_uint32x2_private
    a_ = simde_uint32x2_to_private(a),
    b_ = simde_uint32x2_to_private(b);
  simde_uint64x2_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vuint32mf2_t a_mf2 = __riscv_vlmul_trunc_v_u32m1_u32mf2(a_.sv64);
    r_.sv128 = __riscv_vwmulu_vx_u64m1(a_mf2, b_.values[lane], 2);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) * HEDLEY_STATIC_CAST(uint64_t, b_.values[lane]);
    }
  #endif
  return simde_uint64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_u32(a, v, lane) vmull_lane_u32((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_lane_u32(a, v, lane) simde_vmull_u32((a), simde_vdup_lane_u32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_u32
  #define vmull_lane_u32(a, v, lane) simde_vmull_lane_u32((a), (v), (lane))
#endif

simde_int32x4_t
simde_vmull_laneq_s16(simde_int16x4_t a, simde_int16x8_t b, const int lane) {
  simde_int16x4_private
    a_ = simde_int16x4_to_private(a);
  simde_int16x8_private
    b_ = simde_int16x8_to_private(b);
  simde_int32x4_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vint16mf2_t a_mf2 = __riscv_vlmul_trunc_v_i16m1_i16mf2(a_.sv64);
    r_.sv128 = __riscv_vwmul_vx_i32m1(a_mf2, b_.values[lane], 4);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int32_t, a_.values[i]) * HEDLEY_STATIC_CAST(int32_t, b_.values[lane]);
    }
  #endif
  return simde_int32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_s16(a, v, lane) vmull_laneq_s16((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_laneq_s16(a, v, lane) simde_vmull_s16((a), simde_vdup_laneq_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_s16
  #define vmull_laneq_s16(a, v, lane) simde_vmull_laneq_s16((a), (v), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vmull_laneq_s32(simde_int32x2_t a, simde_int32x4_t b, const int lane) {

  simde_int32x2_private
    a_ = simde_int32x2_to_private(a);
  simde_int32x4_private
    b_ = simde_int32x4_to_private(b);
  simde_int64x2_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vint32mf2_t a_mf2 = __riscv_vlmul_trunc_v_i32m1_i32mf2(a_.sv64);
    r_.sv128 = __riscv_vwmul_vx_i64m1(a_mf2, b_.values[lane], 2);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int64_t, a_.values[i]) * HEDLEY_STATIC_CAST(int64_t, b_.values[lane]);
    }
  #endif
  return simde_int64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_s32(a, v, lane) vmull_laneq_s32((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_laneq_s32(a, v, lane) simde_vmull_s32((a), simde_vdup_laneq_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_s32
  #define vmull_laneq_s32(a, v, lane) simde_vmull_laneq_s32((a), (v), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmull_laneq_u16(simde_uint16x4_t a, simde_uint16x8_t b, const int lane) {

  simde_uint16x4_private
    a_ = simde_uint16x4_to_private(a);
  simde_uint16x8_private
    b_ = simde_uint16x8_to_private(b);
  simde_uint32x4_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vuint16mf2_t a_mf2 = __riscv_vlmul_trunc_v_u16m1_u16mf2(a_.sv64);
    r_.sv128 = __riscv_vwmulu_vx_u32m1(a_mf2, b_.values[lane], 4);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[lane]);
    }
  #endif
  return simde_uint32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_u16(a, v, lane) vmull_laneq_u16((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_laneq_u16(a, v, lane) simde_vmull_u16((a), simde_vdup_laneq_u16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_u16
  #define vmull_laneq_u16(a, v, lane) simde_vmull_laneq_u16((a), (v), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vmull_laneq_u32(simde_uint32x2_t a, simde_uint32x4_t b, const int lane) {

  simde_uint32x2_private
    a_ = simde_uint32x2_to_private(a);
  simde_uint32x4_private
    b_ = simde_uint32x4_to_private(b);
  simde_uint64x2_private r_;
  #if defined(SIMDE_RISCV_V_NATIVE)
    vuint32mf2_t a_mf2 = __riscv_vlmul_trunc_v_u32m1_u32mf2(a_.sv64);
    r_.sv128 = __riscv_vwmulu_vx_u64m1(a_mf2, b_.values[lane], 2);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) * HEDLEY_STATIC_CAST(uint64_t, b_.values[lane]);
    }
  #endif
  return simde_uint64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_u32(a, v, lane) vmull_laneq_u32((a), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #define simde_vmull_laneq_u32(a, v, lane) simde_vmull_u32((a), simde_vdup_laneq_u32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_u32
  #define vmull_laneq_u32(a, v, lane) simde_vmull_laneq_u32((a), (v), (lane))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MULL_LANE_H) */
