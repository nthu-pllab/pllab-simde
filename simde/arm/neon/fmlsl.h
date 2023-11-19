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

#if !defined(SIMDE_ARM_NEON_FMLSL_H)
#define SIMDE_ARM_NEON_FMLSL_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfmlsl_low_f16(simde_float32x2_t r, simde_float16x4_t a, simde_float16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
      defined(__ARM_FEATURE_FP16_FML)
    return vfmlsl_low_f16(r, a, b);
  #else
    simde_float32x2_private
      ret_,
      r_ = simde_float32x2_to_private(r);
    simde_float16x4_private
      a_ = simde_float16x4_to_private(a),
      b_ = simde_float16x4_to_private(b);

    #if defined(SIMDE_RISCV_V_NATIVE)
      vfloat16mf2_t b_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(b_.sv64);
      vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(a_.sv64);
      ret_.sv64 = __riscv_vfwnmsac_vv_f32m1(r_.sv64, b_mf2, a_mf2, 2);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
        ret_.values[i] = r_.values[i] -
          simde_float16_to_float32(a_.values[i]) * simde_float16_to_float32(b_.values[i]);
      }
    #endif

    return simde_float32x2_from_private(ret_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlsl_low_f16
  #define vfmlsl_low_f16(r, a, b) simde_vfmlsl_low_f16((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmlslq_low_f16(simde_float32x4_t r, simde_float16x8_t a, simde_float16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
      defined(__ARM_FEATURE_FP16_FML)
    return vfmlslq_low_f16(r, a, b);
  #else
    simde_float32x4_private
      ret_,
      r_ = simde_float32x4_to_private(r);
    simde_float16x8_private
      a_ = simde_float16x8_to_private(a),
      b_ = simde_float16x8_to_private(b);

    #if defined(SIMDE_RISCV_V_NATIVE)
      vfloat16mf2_t b_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(b_.sv128);
      vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(a_.sv128);
      ret_.sv128 = __riscv_vfwnmsac_vv_f32m1(r_.sv128, b_mf2, a_mf2, 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
        ret_.values[i] = r_.values[i] -
          simde_float16_to_float32(a_.values[i]) * simde_float16_to_float32(b_.values[i]);
      }
    #endif

    return simde_float32x4_from_private(ret_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlslq_low_f16
  #define vfmlslq_low_f16(r, a, b) simde_vfmlslq_low_f16((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfmlsl_high_f16(simde_float32x2_t r, simde_float16x4_t a, simde_float16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
      defined(__ARM_FEATURE_FP16_FML)
    return vfmlsl_high_f16(r, a, b);
  #else
    simde_float32x2_private
      ret_,
      r_ = simde_float32x2_to_private(r);
    simde_float16x4_private
      a_ = simde_float16x4_to_private(a),
      b_ = simde_float16x4_to_private(b);
    size_t high_offset = sizeof(a_.values) / sizeof(a_.values[0]) / 2;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vfloat16mf2_t b_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                      __riscv_vslidedown_vx_f16m1(b_.sv64, 2, 2));
      vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                      __riscv_vslidedown_vx_f16m1(a_.sv64, 2, 2));
      ret_.sv64 = __riscv_vfwnmsac_vv_f32m1(r_.sv64, b_mf2, a_mf2, 2);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
        ret_.values[i] = r_.values[i] -
          simde_float16_to_float32(a_.values[i+high_offset]) * simde_float16_to_float32(b_.values[i+high_offset]);
      }
    #endif

    return simde_float32x2_from_private(ret_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlsl_high_f16
  #define vfmlsl_high_f16(r, a, b) simde_vfmlsl_high_f16((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmlslq_high_f16(simde_float32x4_t r, simde_float16x8_t a, simde_float16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
      defined(__ARM_FEATURE_FP16_FML)
    return vfmlslq_high_f16(r, a, b);
  #else
    simde_float32x4_private
      ret_,
      r_ = simde_float32x4_to_private(r);
    simde_float16x8_private
      a_ = simde_float16x8_to_private(a),
      b_ = simde_float16x8_to_private(b);
    size_t high_offset = sizeof(a_.values) / sizeof(a_.values[0]) / 2;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vfloat16mf2_t b_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                      __riscv_vslidedown_vx_f16m1(b_.sv128, 4, 4));
      vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                      __riscv_vslidedown_vx_f16m1(a_.sv128, 4, 4));
      ret_.sv128 = __riscv_vfwnmsac_vv_f32m1(r_.sv128, b_mf2, a_mf2, 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
        ret_.values[i] = r_.values[i] -
          simde_float16_to_float32(a_.values[i+high_offset]) * simde_float16_to_float32(b_.values[i+high_offset]);
      }
    #endif

    return simde_float32x4_from_private(ret_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlslq_high_f16
  #define vfmlslq_high_f16(r, a, b) simde_vfmlslq_high_f16((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfmlsl_lane_low_f16(simde_float32x2_t r, simde_float16x4_t a, simde_float16x4_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_float32x2_private
    ret_,
    r_ = simde_float32x2_to_private(r);
  simde_float16x4_private
    a_ = simde_float16x4_to_private(a),
    b_ = simde_float16x4_to_private(b);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(a_.sv64);
    ret_.sv64 = __riscv_vfwnmsac_vf_f32m1(r_.sv64, b_.values[lane], a_mf2, 2);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x2_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlsl_lane_low_f16(r, a, b, lane) vfmlsl_lane_low_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlsl_lane_low_f16
  #define vfmlsl_lane_low_f16(r, a, b, lane) simde_vfmlsl_lane_low_f16((r), (a), (b), (lane));
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfmlsl_laneq_low_f16(simde_float32x2_t r, simde_float16x4_t a, simde_float16x8_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_float32x2_private
    ret_,
    r_ = simde_float32x2_to_private(r);
  simde_float16x4_private
    a_ = simde_float16x4_to_private(a);
  simde_float16x8_private
    b_ = simde_float16x8_to_private(b);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(a_.sv64);
    ret_.sv64 = __riscv_vfwnmsac_vf_f32m1(r_.sv64, b_.values[lane], a_mf2, 2);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x2_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlsl_laneq_low_f16(r, a, b, lane) vfmlsl_laneq_low_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlsl_laneq_low_f16
  #define vfmlsl_laneq_low_f16(r, a, b, lane) simde_vfmlsl_laneq_low_f16((r), (a), (b), (lane));
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmlslq_lane_low_f16(simde_float32x4_t r, simde_float16x8_t a, simde_float16x4_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_float32x4_private
    ret_,
    r_ = simde_float32x4_to_private(r);
  simde_float16x4_private
    b_ = simde_float16x4_to_private(b);
  simde_float16x8_private
    a_ = simde_float16x8_to_private(a);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(a_.sv128);
    ret_.sv128 = __riscv_vfwnmsac_vf_f32m1(r_.sv128, b_.values[lane], a_mf2, 4);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x4_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlslq_lane_low_f16(r, a, b, lane) vfmlslq_lane_low_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlslq_lane_low_f16
  #define vfmlslq_lane_low_f16(r, a, b, lane) simde_vfmlslq_lane_low_f16((r), (a), (b), (lane));
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmlslq_laneq_low_f16(simde_float32x4_t r, simde_float16x8_t a, simde_float16x8_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_float32x4_private
    ret_,
    r_ = simde_float32x4_to_private(r);
  simde_float16x8_private
    a_ = simde_float16x8_to_private(a),
    b_ = simde_float16x8_to_private(b);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(a_.sv128);
    ret_.sv128 = __riscv_vfwnmsac_vf_f32m1(r_.sv128, b_.values[lane], a_mf2, 4);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x4_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlslq_laneq_low_f16(r, a, b, lane) vfmlslq_laneq_low_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlslq_laneq_low_f16
  #define vfmlslq_laneq_low_f16(r, a, b, lane) simde_vfmlslq_laneq_low_f16((r), (a), (b), (lane));
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfmlsl_lane_high_f16(simde_float32x2_t r, simde_float16x4_t a, simde_float16x4_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_float32x2_private
    ret_,
    r_ = simde_float32x2_to_private(r);
  simde_float16x4_private
    a_ = simde_float16x4_to_private(a),
    b_ = simde_float16x4_to_private(b);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                    __riscv_vslidedown_vx_f16m1(a_.sv64, 2, 2));
    ret_.sv64 = __riscv_vfwnmsac_vf_f32m1(r_.sv64, b_.values[lane], a_mf2, 2);
  #else
    size_t high_offset = sizeof(a_.values) / sizeof(a_.values[0]) / 2;
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i+high_offset]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x2_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlsl_lane_high_f16(r, a, b, lane) vfmlsl_lane_high_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlsl_lane_high_f16
  #define vfmlsl_lane_high_f16(r, a, b, lane) simde_vfmlsl_lane_high_f16((r), (a), (b), (lane));
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfmlsl_laneq_high_f16(simde_float32x2_t r, simde_float16x4_t a, simde_float16x8_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_float32x2_private
    ret_,
    r_ = simde_float32x2_to_private(r);
  simde_float16x4_private
    a_ = simde_float16x4_to_private(a);
  simde_float16x8_private
    b_ = simde_float16x8_to_private(b);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                    __riscv_vslidedown_vx_f16m1(a_.sv64, 2, 2));
    ret_.sv64 = __riscv_vfwnmsac_vf_f32m1(r_.sv64, b_.values[lane], a_mf2, 2);
  #else
    size_t high_offset = sizeof(a_.values) / sizeof(a_.values[0]) / 2;
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i+high_offset]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x2_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlsl_laneq_high_f16(r, a, b, lane) vfmlsl_laneq_high_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlsl_laneq_high_f16
  #define vfmlsl_laneq_high_f16(r, a, b, lane) simde_vfmlsl_laneq_high_f16((r), (a), (b), (lane));
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmlslq_lane_high_f16(simde_float32x4_t r, simde_float16x8_t a, simde_float16x4_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_float32x4_private
    ret_,
    r_ = simde_float32x4_to_private(r);
  simde_float16x4_private
    b_ = simde_float16x4_to_private(b);
  simde_float16x8_private
    a_ = simde_float16x8_to_private(a);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                    __riscv_vslidedown_vx_f16m1(a_.sv128, 4, 4));
    ret_.sv128 = __riscv_vfwnmsac_vf_f32m1(r_.sv128, b_.values[lane], a_mf2, 4);
  #else
    size_t high_offset = sizeof(a_.values) / sizeof(a_.values[0]) / 2;
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i+high_offset]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x4_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlslq_lane_high_f16(r, a, b, lane) vfmlslq_lane_high_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlslq_lane_high_f16
  #define vfmlslq_lane_high_f16(r, a, b, lane) simde_vfmlslq_lane_high_f16((r), (a), (b), (lane));
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmlslq_laneq_high_f16(simde_float32x4_t r, simde_float16x8_t a, simde_float16x8_t b, const int lane)
   SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_float32x4_private
    ret_,
    r_ = simde_float32x4_to_private(r);
  simde_float16x8_private
    a_ = simde_float16x8_to_private(a),
    b_ = simde_float16x8_to_private(b);

  #if defined(SIMDE_RISCV_V_NATIVE)
    vfloat16mf2_t a_mf2 = __riscv_vlmul_trunc_v_f16m1_f16mf2(
                    __riscv_vslidedown_vx_f16m1(a_.sv128, 4, 4));
    ret_.sv128 = __riscv_vfwnmsac_vf_f32m1(r_.sv128, b_.values[lane], a_mf2, 4);
  #else
    size_t high_offset = sizeof(a_.values) / sizeof(a_.values[0]) / 2;
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(ret_.values) / sizeof(ret_.values[0])) ; i++) {
      ret_.values[i] = r_.values[i] -
        simde_float16_to_float32(a_.values[i+high_offset]) * simde_float16_to_float32(b_.values[lane]);
    }
  #endif

  return simde_float32x4_from_private(ret_);
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16) && \
    defined(__ARM_FEATURE_FP16_FML)
  #define simde_vfmlslq_laneq_high_f16(r, a, b, lane) vfmlslq_laneq_high_f16((r), (a), (b), (lane));
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vfmlslq_laneq_high_f16
  #define vfmlslq_laneq_high_f16(r, a, b, lane) simde_vfmlslq_laneq_high_f16((r), (a), (b), (lane));
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_FMLSL_H) */
