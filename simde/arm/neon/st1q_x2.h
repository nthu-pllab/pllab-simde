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
 */

#if !defined(SIMDE_ARM_NEON_ST1Q_X2_H)
#define SIMDE_ARM_NEON_ST1Q_X2_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_BUG_INTEL_857088)

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_f16_x2(simde_float16_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_float16x8x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    vst1q_f16_x2(ptr, val);
  #else
    simde_float16_t buf[16];
    simde_float16x8_private a_[2] = {simde_float16x8_to_private(val.val[0]),
                                     simde_float16x8_to_private(val.val[1])};
    for (size_t i = 0; i < 16; i++) {
      buf[i] = a_[i / 8].values[i % 8];
    }
    simde_memcpy(ptr, buf, 32);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_f16_x2
  #define vst1q_f16_x2(a, b) simde_vst1q_f16_x2((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_f32_x2(simde_float32 ptr[HEDLEY_ARRAY_PARAM(8)], simde_float32x4x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_f32_x2(ptr, val);
  #else
    simde_vst1q_f32(ptr, val.val[0]);
    simde_vst1q_f32(ptr+4, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_f32_x2
  #define vst1q_f32_x2(ptr, val) simde_vst1q_f32_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_f64_x2(simde_float64 ptr[HEDLEY_ARRAY_PARAM(4)], simde_float64x2x2_t val) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst1q_f64_x2(ptr, val);
  #else
    simde_vst1q_f64(ptr, val.val[0]);
    simde_vst1q_f64(ptr+2, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vst1q_f64_x2
  #define vst1q_f64_x2(ptr, val) simde_vst1q_f64_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s8_x2(int8_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_int8x16x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s8_x2(ptr, val);
  #else
    simde_vst1q_s8(ptr, val.val[0]);
    simde_vst1q_s8(ptr+16, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s8_x2
  #define vst1q_s8_x2(ptr, val) simde_vst1q_s8_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s16_x2(int16_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_int16x8x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s16_x2(ptr, val);
  #else
    simde_vst1q_s16(ptr, val.val[0]);
    simde_vst1q_s16(ptr+8, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s16_x2
  #define vst1q_s16_x2(ptr, val) simde_vst1q_s16_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s32_x2(int32_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_int32x4x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s32_x2(ptr, val);
  #else
    simde_vst1q_s32(ptr, val.val[0]);
    simde_vst1q_s32(ptr+4, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s32_x2
  #define vst1q_s32_x2(ptr, val) simde_vst1q_s32_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s64_x2(int64_t ptr[HEDLEY_ARRAY_PARAM(4)], simde_int64x2x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s64_x2(ptr, val);
  #else
    simde_vst1q_s64(ptr, val.val[0]);
    simde_vst1q_s64(ptr+2, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s64_x2
  #define vst1q_s64_x2(ptr, val) simde_vst1q_s64_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u8_x2(uint8_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_uint8x16x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u8_x2(ptr, val);
  #else
    simde_vst1q_u8(ptr, val.val[0]);
    simde_vst1q_u8(ptr+16, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u8_x2
  #define vst1q_u8_x2(ptr, val) simde_vst1q_u8_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u16_x2(uint16_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_uint16x8x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u16_x2(ptr, val);
  #else
    simde_vst1q_u16(ptr, val.val[0]);
    simde_vst1q_u16(ptr+8, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u16_x2
  #define vst1q_u16_x2(ptr, val) simde_vst1q_u16_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u32_x2(uint32_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_uint32x4x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u32_x2(ptr, val);
  #else
    simde_vst1q_u32(ptr, val.val[0]);
    simde_vst1q_u32(ptr+4, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u32_x2
  #define vst1q_u32_x2(ptr, val) simde_vst1q_u32_x2((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u64_x2(uint64_t ptr[HEDLEY_ARRAY_PARAM(4)], simde_uint64x2x2_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u64_x2(ptr, val);
  #else
    simde_vst1q_u64(ptr, val.val[0]);
    simde_vst1q_u64(ptr+2, val.val[1]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u64_x2
  #define vst1q_u64_x2(ptr, val) simde_vst1q_u64_x2((ptr), (val))
#endif

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ST1Q_X2_H) */
