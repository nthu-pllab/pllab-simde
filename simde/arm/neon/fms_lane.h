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

#if !defined(SIMDE_ARM_NEON_FMS_LANE_H)
#define SIMDE_ARM_NEON_FMS_LANE_H

#include "sub.h"
#include "dup_n.h"
#include "get_lane.h"
#include "mul.h"
#include "mul_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* simde_vfmsd_lane_f64 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vfmsd_lane_f64(a, b, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vfmsd_lane_f64(a, b, v, lane))
  #else
    #define simde_vfmsd_lane_f64(a, b, v, lane) vfmsd_lane_f64((a), (b), (v), (lane))
  #endif
#else
  #define simde_vfmsd_lane_f64(a, b, v, lane) \
  simde_vget_lane_f64( \
    simde_vsub_f64( \
      simde_vdup_n_f64(a), \
      simde_vdup_n_f64(simde_vmuld_lane_f64(b, v, lane)) \
    ), \
    0 \
  )
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsd_lane_f64
  #define vfmsd_lane_f64(a, b, v, lane) simde_vfmsd_lane_f64(a, b, v, lane)
#endif

/* simde_vfmsd_laneq_f64 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vfmsd_laneq_f64(a, b, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vfmsd_laneq_f64(a, b, v, lane))
  #else
    #define simde_vfmsd_laneq_f64(a, b, v, lane) vfmsd_laneq_f64((a), (b), (v), (lane))
  #endif
#else
  #define simde_vfmsd_laneq_f64(a, b, v, lane) \
  simde_vget_lane_f64( \
    simde_vsub_f64( \
      simde_vdup_n_f64(a), \
      simde_vdup_n_f64(simde_vmuld_laneq_f64(b, v, lane)) \
    ), \
    0 \
  )
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsd_laneq_f64
  #define vfmsd_laneq_f64(a, b, v, lane) simde_vfmsd_laneq_f64(a, b, v, lane)
#endif

/* simde_vfmsh_lane_f16 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && defined(SIMDE_ARM_NEON_FP16)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vfmsh_lane_f16(a, b, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vfmsh_lane_f16(a, b, v, lane))
  #else
    #define simde_vfmsh_lane_f16(a, b, v, lane) vfmsh_lane_f16((a), (b), (v), (lane))
  #endif
#else
  #define simde_vfmsh_lane_f16(a, b, v, lane) \
  simde_vget_lane_f16( \
    simde_vsub_f16( \
      simde_vdup_n_f16(a), \
      simde_vdup_n_f16(simde_vmulh_lane_f16(b, v, lane)) \
    ), \
    0 \
  )
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsh_lane_f16
  #define vfmsh_lane_f16(a, b, v, lane) simde_vfmsh_lane_f16(a, b, v, lane)
#endif

/* simde_vfmsh_laneq_f16 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && defined(SIMDE_ARM_NEON_FP16)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vfmsh_laneq_f16(a, b, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vfmsh_laneq_f16(a, b, v, lane))
  #else
    #define simde_vfmsh_laneq_f16(a, b, v, lane) vfmsh_laneq_f16((a), (b), (v), (lane))
  #endif
#else
  #define simde_vfmsh_laneq_f16(a, b, v, lane) \
  simde_vget_lane_f16( \
    simde_vsub_f16( \
      simde_vdup_n_f16(a), \
      simde_vdup_n_f16(simde_vmulh_laneq_f16(b, v, lane)) \
    ), \
    0 \
  )
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsh_laneq_f16
  #define vfmsh_laneq_f16(a, b, v, lane) simde_vfmsh_laneq_f16(a, b, v, lane)
#endif

/* simde_vfmss_lane_f32 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vfmss_lane_f32(a, b, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vfmss_lane_f32(a, b, v, lane))
  #else
    #define simde_vfmss_lane_f32(a, b, v, lane) vfmss_lane_f32((a), (b), (v), (lane))
  #endif
#else
  #define simde_vfmss_lane_f32(a, b, v, lane) \
  simde_vget_lane_f32( \
    simde_vsub_f32( \
      simde_vdup_n_f32(a), \
      simde_vdup_n_f32(simde_vmuls_lane_f32(b, v, lane)) \
    ), \
    0 \
  )
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmss_lane_f32
  #define vfmss_lane_f32(a, b, v, lane) simde_vfmss_lane_f32(a, b, v, lane)
#endif

/* simde_vfmss_laneq_f32 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vfmss_laneq_f32(a, b, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vfmss_laneq_f32(a, b, v, lane))
  #else
    #define simde_vfmss_laneq_f32(a, b, v, lane) vfmss_laneq_f32((a), (b), (v), (lane))
  #endif
#else
  #define simde_vfmss_laneq_f32(a, b, v, lane) \
  simde_vget_lane_f32( \
    simde_vsub_f32( \
      simde_vdup_n_f32(a), \
      simde_vdup_n_f32(simde_vmuls_laneq_f32(b, v, lane)) \
    ), \
    0 \
  )
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmss_laneq_f32
  #define vfmss_laneq_f32(a, b, v, lane) simde_vfmss_laneq_f32(a, b, v, lane)
#endif

/* simde_vfms_lane_f16 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && defined(SIMDE_ARM_NEON_FP16)
  #define simde_vfms_lane_f16(a, b, v, lane) vfms_lane_f16(a, b, v, lane)
#else
  #define simde_vfms_lane_f16(a, b, v, lane) simde_vsub_f16(a, simde_vmul_lane_f16(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_lane_f16
  #define vfms_lane_f16(a, b, v, lane) simde_vfms_lane_f16(a, b, v, lane)
#endif

/* simde_vfms_lane_f32 */
SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfms_lane_f32(simde_float32x2_t a, simde_float32x2_t b, simde_float32x2_t c, const int lane) 
  SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {

  simde_float32x2_private
    r_,
    a_ = simde_float32x2_to_private(a),
    b_ = simde_float32x2_to_private(b),
    c_ = simde_float32x2_to_private(c);

  #if defined(SIMDE_RISCV_V_NATIVE)
    r_.sv64 = __riscv_vfnmsac_vf_f32m1(a_.sv64 , c_.values[lane] , b_.sv64 , 2);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values - b_.values * c_.values[lane];
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] - (b_.values[i] * c_.values[lane]);
    }
  #endif
    
  return simde_float32x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfms_lane_f32(a, b, v, lane) vfms_lane_f32(a, b, v, lane)
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #undef simde_vfms_lane_f32
  #define simde_vfms_lane_f32(a, b, v, lane) simde_vsub_f32(a, simde_vmul_lane_f32(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_lane_f32
  #define vfms_lane_f32(a, b, v, lane) simde_vfms_lane_f32(a, b, v, lane)
#endif

/* simde_vfms_lane_f64 */
SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vfms_lane_f64(simde_float64x1_t a, simde_float64x1_t b, simde_float64x1_t c, const int lane) 
  SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {

  simde_float64x1_private
    r_,
    a_ = simde_float64x1_to_private(a),
    b_ = simde_float64x1_to_private(b),
    c_ = simde_float64x1_to_private(c);

  #if defined(SIMDE_RISCV_V_NATIVE)
    r_.sv64 = __riscv_vfnmsac_vf_f64m1(a_.sv64 , c_.values[lane] , b_.sv64 , 1);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values - b_.values * c_.values[lane];
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] - (b_.values[i] * c_.values[lane]);
    }
  #endif

  return simde_float64x1_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfms_lane_f64(a, b, v, lane) vfms_lane_f64((a), (b), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #undef simde_vfms_lane_f64
  #define simde_vfms_lane_f64(a, b, v, lane) simde_vsub_f64(a, simde_vmul_lane_f64(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_lane_f64
  #define vfms_lane_f64(a, b, v, lane) simde_vfms_lane_f64(a, b, v, lane)
#endif

/* simde_vfms_laneq_f16 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && defined(SIMDE_ARM_NEON_FP16)
  #define simde_vfms_laneq_f16(a, b, v, lane) vfms_laneq_f16((a), (b), (v), (lane))
#else
  #define simde_vfms_laneq_f16(a, b, v, lane) simde_vsub_f16(a, simde_vmul_laneq_f16(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_laneq_f16
  #define vfms_laneq_f16(a, b, v, lane) simde_vfms_laneq_f16(a, b, v, lane)
#endif

/* simde_vfms_laneq_f32 */
SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfms_laneq_f32(simde_float32x2_t a, simde_float32x2_t b, simde_float32x4_t c, const int lane)
  SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {

    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);
    simde_float32x4_private
      c_ = simde_float32x4_to_private(c);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vfnmsac_vf_f32m1(a_.sv64 , c_.values[lane] , b_.sv64 , 2);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values - b_.values * c_.values[lane];
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] - (b_.values[i] * c_.values[lane]);
      }
    #endif

    return simde_float32x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfms_laneq_f32(a, b, v, lane) vfms_laneq_f32((a), (b), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #undef simde_vfms_laneq_f32
  #define simde_vfms_laneq_f32(a, b, v, lane) simde_vsub_f32(a, simde_vmul_laneq_f32(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_laneq_f32
  #define vfms_laneq_f32(a, b, v, lane) simde_vfms_laneq_f32(a, b, v, lane)
#endif

/* simde_vfms_laneq_f64 */
SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vfms_laneq_f64(simde_float64x1_t a, simde_float64x1_t b, simde_float64x2_t c, const int lane)
  SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {

  simde_float64x1_private
    r_,
    a_ = simde_float64x1_to_private(a),
    b_ = simde_float64x1_to_private(b);
  simde_float64x2_private
    c_ = simde_float64x2_to_private(c);

  #if defined(SIMDE_RISCV_V_NATIVE)
    r_.sv64 = __riscv_vfnmsac_vf_f64m1(a_.sv64 , c_.values[lane] , b_.sv64 , 1);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values - b_.values * c_.values[lane];
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] - (b_.values[i] * c_.values[lane]);
    }
  #endif

  return simde_float64x1_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfms_laneq_f64(a, b, v, lane) vfms_laneq_f64((a), (b), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #undef simde_vfms_laneq_f64
  #define simde_vfms_laneq_f64(a, b, v, lane) simde_vsub_f64(a, simde_vmul_laneq_f64(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_laneq_f64
  #define vfms_laneq_f64(a, b, v, lane) simde_vfms_laneq_f64(a, b, v, lane)
#endif

/* simde_vfmsq_lane_f64 */
SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vfmsq_lane_f64(simde_float64x2_t a, simde_float64x2_t b, simde_float64x1_t c, const int lane)
  SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {

  simde_float64x2_private
    r_,
    a_ = simde_float64x2_to_private(a),
    b_ = simde_float64x2_to_private(b);
  simde_float64x1_private
    c_ = simde_float64x1_to_private(c);

  #if defined(SIMDE_RISCV_V_NATIVE)
    r_.sv128 = __riscv_vfnmsac_vf_f64m1(a_.sv128 , c_.values[lane] , b_.sv128 , 2);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values - b_.values * c_.values[lane];
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] - (b_.values[i] * c_.values[lane]);
    }
  #endif

  return simde_float64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfmsq_lane_f64(a, b, v, lane) vfmsq_lane_f64((a), (b), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #undef simde_vfmsq_lane_f64
  #define simde_vfmsq_lane_f64(a, b, v, lane) simde_vsubq_f64(a, simde_vmulq_lane_f64(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_lane_f64
  #define vfmsq_lane_f64(a, b, v, lane) simde_vfmsq_lane_f64(a, b, v, lane)
#endif

/* simde_vfmsq_lane_f16 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && defined(SIMDE_ARM_NEON_FP16)
  #define simde_vfmsq_lane_f16(a, b, v, lane) vfmsq_lane_f16((a), (b), (v), (lane))
#else
  #define simde_vfmsq_lane_f16(a, b, v, lane) simde_vsubq_f16(a, simde_vmulq_lane_f16(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_lane_f16
  #define vfmsq_lane_f16(a, b, v, lane) simde_vfmsq_lane_f16(a, b, v, lane)
#endif

/* simde_vfmsq_lane_f32 */
SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmsq_lane_f32(simde_float32x4_t a, simde_float32x4_t b, simde_float32x2_t c, const int lane)
  SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {

  simde_float32x4_private
    r_,
    a_ = simde_float32x4_to_private(a),
    b_ = simde_float32x4_to_private(b);
  simde_float32x2_private
    c_ = simde_float32x2_to_private(c);

  #if defined(SIMDE_RISCV_V_NATIVE)
    r_.sv128 = __riscv_vfnmsac_vf_f32m1(a_.sv128 , c_.values[lane] , b_.sv128 , 4);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values - b_.values * c_.values[lane];
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] - (b_.values[i] * c_.values[lane]);
    }
  #endif

  return simde_float32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfmsq_lane_f32(a, b, v, lane) vfmsq_lane_f32((a), (b), (v), (lane))
#elif !defined(SIMDE_RISCV_V_NATIVE)
  #undef simde_vfmsq_lane_f32
  #define simde_vfmsq_lane_f32(a, b, v, lane) simde_vsubq_f32(a, simde_vmulq_lane_f32(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_lane_f32
  #define vfmsq_lane_f32(a, b, v, lane) simde_vfmsq_lane_f32(a, b, v, lane)
#endif

/* simde_vfmsq_laneq_f16 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && defined(SIMDE_ARM_NEON_FP16)
  #define simde_vfmsq_laneq_f16(a, b, v, lane) vfmsq_laneq_f16((a), (b), (v), (lane))
#else
  #define simde_vfmsq_laneq_f16(a, b, v, lane) \
  simde_vsubq_f16(a, simde_vmulq_laneq_f16(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_laneq_f16
  #define vfmsq_laneq_f16(a, b, v, lane) simde_vfmsq_laneq_f16(a, b, v, lane)
#endif

/* simde_vfmsq_laneq_f32 */
SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmsq_laneq_f32(simde_float32x4_t a, simde_float32x4_t b, simde_float32x4_t c, const int lane)
  SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {

  simde_float32x4_private
    r_,
    a_ = simde_float32x4_to_private(a),
    b_ = simde_float32x4_to_private(b),
    c_ = simde_float32x4_to_private(c);

  #if defined(SIMDE_RISCV_V_NATIVE)
    r_.sv128 = __riscv_vfnmsac_vf_f32m1(a_.sv128 , c_.values[lane] , b_.sv128 , 4);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values - b_.values * c_.values[lane];
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] - (b_.values[i] * c_.values[lane]);
    }
  #endif

  return simde_float32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfmsq_laneq_f32(a, b, v, lane) vfmsq_laneq_f32((a), (b), (v), (lane))
#else
  #undef simde_vfmsq_laneq_f32
  #define simde_vfmsq_laneq_f32(a, b, v, lane) \
  simde_vsubq_f32(a, simde_vmulq_laneq_f32(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_laneq_f32
  #define vfmsq_laneq_f32(a, b, v, lane) simde_vfmsq_laneq_f32(a, b, v, lane)
#endif

/* simde_vfmsq_laneq_f64 */
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA)
  #define simde_vfmsq_laneq_f64(a, b, v, lane) vfmsq_laneq_f64((a), (b), (v), (lane))
#else
  #define simde_vfmsq_laneq_f64(a, b, v, lane) \
  simde_vsubq_f64(a, simde_vmulq_laneq_f64(b, v, lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_laneq_f64
  #define vfmsq_laneq_f64(a, b, v, lane) simde_vfmsq_laneq_f64(a, b, v, lane)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_FMS_LANE_H) */
