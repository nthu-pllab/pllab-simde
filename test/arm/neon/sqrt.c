#define SIMDE_TEST_ARM_NEON_INSN sqrt

#include "test-neon.h"
#include "../../../simde/arm/neon/sqrt.h"

static int
test_simde_vsqrth_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    simde_float16_t r;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(14.90),
      SIMDE_FLOAT16_VALUE(3.86)  },
    { SIMDE_FLOAT16_VALUE(1.34),
      SIMDE_FLOAT16_VALUE(1.16) },
    { SIMDE_FLOAT16_VALUE(17.19),
      SIMDE_FLOAT16_VALUE(4.15) },
    { SIMDE_FLOAT16_VALUE(2.64),
      SIMDE_FLOAT16_VALUE(1.63) },
    { SIMDE_FLOAT16_VALUE(12.54),
      SIMDE_FLOAT16_VALUE(3.54) },
    { SIMDE_FLOAT16_VALUE(3.75),
      SIMDE_FLOAT16_VALUE(1.94) },
    { SIMDE_FLOAT16_VALUE(2.83),
      SIMDE_FLOAT16_VALUE(1.68) },
    { SIMDE_FLOAT16_VALUE(13.95),
      SIMDE_FLOAT16_VALUE(3.73) },
    { SIMDE_FLOAT16_VALUE(8.32),
      SIMDE_FLOAT16_VALUE(2.88) },
    { SIMDE_FLOAT16_VALUE(14.00),
      SIMDE_FLOAT16_VALUE(3.74) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t r = simde_vsqrth_f16(test_vec[i].a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vsqrt_f16 (SIMDE_MUNIT_TEST_ARGS) {
    struct {
      simde_float16_t a[4];
      simde_float16_t r[4];
    } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(27.93), SIMDE_FLOAT16_VALUE(10.08), SIMDE_FLOAT16_VALUE(9.30), SIMDE_FLOAT16_VALUE(11.22) },
      { SIMDE_FLOAT16_VALUE(5.28), SIMDE_FLOAT16_VALUE(3.18), SIMDE_FLOAT16_VALUE(3.05), SIMDE_FLOAT16_VALUE(3.35) } },
    { { SIMDE_FLOAT16_VALUE(15.66), SIMDE_FLOAT16_VALUE(10.82), SIMDE_FLOAT16_VALUE(12.12), SIMDE_FLOAT16_VALUE(29.63) },
      { SIMDE_FLOAT16_VALUE(3.96), SIMDE_FLOAT16_VALUE(3.29), SIMDE_FLOAT16_VALUE(3.48), SIMDE_FLOAT16_VALUE(5.44) } },
    { { SIMDE_FLOAT16_VALUE(9.58), SIMDE_FLOAT16_VALUE(0.73), SIMDE_FLOAT16_VALUE(25.50), SIMDE_FLOAT16_VALUE(28.03) },
      { SIMDE_FLOAT16_VALUE(3.10), SIMDE_FLOAT16_VALUE(0.85), SIMDE_FLOAT16_VALUE(5.05), SIMDE_FLOAT16_VALUE(5.29) } },
    { { SIMDE_FLOAT16_VALUE(17.38), SIMDE_FLOAT16_VALUE(7.14), SIMDE_FLOAT16_VALUE(29.60), SIMDE_FLOAT16_VALUE(7.30) },
      { SIMDE_FLOAT16_VALUE(4.17), SIMDE_FLOAT16_VALUE(2.67), SIMDE_FLOAT16_VALUE(5.44), SIMDE_FLOAT16_VALUE(2.70) } },
    { { SIMDE_FLOAT16_VALUE(17.10), SIMDE_FLOAT16_VALUE(20.07), SIMDE_FLOAT16_VALUE(24.99), SIMDE_FLOAT16_VALUE(19.04) },
      { SIMDE_FLOAT16_VALUE(4.13), SIMDE_FLOAT16_VALUE(4.48), SIMDE_FLOAT16_VALUE(5.00), SIMDE_FLOAT16_VALUE(4.36) } },
    { { SIMDE_FLOAT16_VALUE(22.22), SIMDE_FLOAT16_VALUE(29.40), SIMDE_FLOAT16_VALUE(18.64), SIMDE_FLOAT16_VALUE(19.27) },
      { SIMDE_FLOAT16_VALUE(4.71), SIMDE_FLOAT16_VALUE(5.42), SIMDE_FLOAT16_VALUE(4.32), SIMDE_FLOAT16_VALUE(4.39) } },
    { { SIMDE_FLOAT16_VALUE(18.40), SIMDE_FLOAT16_VALUE(24.71), SIMDE_FLOAT16_VALUE(6.33), SIMDE_FLOAT16_VALUE(22.61) },
      { SIMDE_FLOAT16_VALUE(4.29), SIMDE_FLOAT16_VALUE(4.97), SIMDE_FLOAT16_VALUE(2.52), SIMDE_FLOAT16_VALUE(4.75) } },
    { { SIMDE_FLOAT16_VALUE(19.57), SIMDE_FLOAT16_VALUE(25.27), SIMDE_FLOAT16_VALUE(21.44), SIMDE_FLOAT16_VALUE(21.66) },
      { SIMDE_FLOAT16_VALUE(4.42), SIMDE_FLOAT16_VALUE(5.03), SIMDE_FLOAT16_VALUE(4.63), SIMDE_FLOAT16_VALUE(4.65) } },
    { { SIMDE_FLOAT16_VALUE(14.01), SIMDE_FLOAT16_VALUE(25.21), SIMDE_FLOAT16_VALUE(20.26), SIMDE_FLOAT16_VALUE(3.23) },
      { SIMDE_FLOAT16_VALUE(3.74), SIMDE_FLOAT16_VALUE(5.02), SIMDE_FLOAT16_VALUE(4.50), SIMDE_FLOAT16_VALUE(1.80) } },
    { { SIMDE_FLOAT16_VALUE(14.15), SIMDE_FLOAT16_VALUE(25.08), SIMDE_FLOAT16_VALUE(19.10), SIMDE_FLOAT16_VALUE(25.72) },
      { SIMDE_FLOAT16_VALUE(3.76), SIMDE_FLOAT16_VALUE(5.01), SIMDE_FLOAT16_VALUE(4.37), SIMDE_FLOAT16_VALUE(5.07) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_float16x4_t a, r;

      a = simde_vld1_f16(test_vec[i].a);
      r = simde_vsqrt_f16(a);

      simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
    }

    return 0;
}

static int
test_simde_vsqrt_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(255.87), SIMDE_FLOAT32_C(943.43) },
      { SIMDE_FLOAT32_C(16.00), SIMDE_FLOAT32_C(30.72) } },
    { { SIMDE_FLOAT32_C(250.05), SIMDE_FLOAT32_C(276.70) },
      { SIMDE_FLOAT32_C(15.81), SIMDE_FLOAT32_C(16.63) } },
    { { SIMDE_FLOAT32_C(249.60), SIMDE_FLOAT32_C(220.60) },
      { SIMDE_FLOAT32_C(15.80), SIMDE_FLOAT32_C(14.85) } },
    { { SIMDE_FLOAT32_C(334.91), SIMDE_FLOAT32_C(691.17) },
      { SIMDE_FLOAT32_C(18.30), SIMDE_FLOAT32_C(26.29) } },
    { { SIMDE_FLOAT32_C(664.12), SIMDE_FLOAT32_C(144.33) },
      { SIMDE_FLOAT32_C(25.77), SIMDE_FLOAT32_C(12.01) } },
    { { SIMDE_FLOAT32_C(107.89), SIMDE_FLOAT32_C(915.17) },
      { SIMDE_FLOAT32_C(10.39), SIMDE_FLOAT32_C(30.25) } },
    { { SIMDE_FLOAT32_C(951.87), SIMDE_FLOAT32_C(949.51) },
      { SIMDE_FLOAT32_C(30.85), SIMDE_FLOAT32_C(30.81) } },
    { { SIMDE_FLOAT32_C(943.48), SIMDE_FLOAT32_C(897.40) },
      { SIMDE_FLOAT32_C(30.72), SIMDE_FLOAT32_C(29.96) } },
    { { SIMDE_FLOAT32_C(420.47), SIMDE_FLOAT32_C(892.05) },
      { SIMDE_FLOAT32_C(20.51), SIMDE_FLOAT32_C(29.87) } },
    { { SIMDE_FLOAT32_C(30.16), SIMDE_FLOAT32_C(596.51) },
      { SIMDE_FLOAT32_C(5.49), SIMDE_FLOAT32_C(24.42) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, r;

    a = simde_vld1_f32(test_vec[i].a);
    r = simde_vsqrt_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vsqrt_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(3896.76) },
      { SIMDE_FLOAT64_C(62.42) } },
    { { SIMDE_FLOAT64_C(971.73) },
      { SIMDE_FLOAT64_C(31.17) } },
    { { SIMDE_FLOAT64_C(3227.46) },
      { SIMDE_FLOAT64_C(56.81) } },
    { { SIMDE_FLOAT64_C(3649.56) },
      { SIMDE_FLOAT64_C(60.41) } },
    { { SIMDE_FLOAT64_C(2741.38) },
      { SIMDE_FLOAT64_C(52.36) } },
    { { SIMDE_FLOAT64_C(1774.65) },
      { SIMDE_FLOAT64_C(42.13) } },
    { { SIMDE_FLOAT64_C(2370.86) },
      { SIMDE_FLOAT64_C(48.69) } },
    { { SIMDE_FLOAT64_C(3416.49) },
      { SIMDE_FLOAT64_C(58.45) } },
    { { SIMDE_FLOAT64_C(1455.69) },
      { SIMDE_FLOAT64_C(38.15) } },
    { { SIMDE_FLOAT64_C(3986.21) },
      { SIMDE_FLOAT64_C(63.14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vsqrt_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vsqrtq_f16 (SIMDE_MUNIT_TEST_ARGS) {
    struct {
      simde_float16_t a[8];
      simde_float16_t r[8];
    } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(10.75), SIMDE_FLOAT16_VALUE(3.14), SIMDE_FLOAT16_VALUE(3.83), SIMDE_FLOAT16_VALUE(2.77), SIMDE_FLOAT16_VALUE(12.19), SIMDE_FLOAT16_VALUE(1.99), SIMDE_FLOAT16_VALUE(1.01), SIMDE_FLOAT16_VALUE(15.86) },
      { SIMDE_FLOAT16_VALUE(3.28), SIMDE_FLOAT16_VALUE(1.77), SIMDE_FLOAT16_VALUE(1.96), SIMDE_FLOAT16_VALUE(1.67), SIMDE_FLOAT16_VALUE(3.49), SIMDE_FLOAT16_VALUE(1.41), SIMDE_FLOAT16_VALUE(1.00), SIMDE_FLOAT16_VALUE(3.98) } },
    { { SIMDE_FLOAT16_VALUE(13.23), SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(10.84), SIMDE_FLOAT16_VALUE(13.04), SIMDE_FLOAT16_VALUE(1.81), SIMDE_FLOAT16_VALUE(1.07), SIMDE_FLOAT16_VALUE(17.89), SIMDE_FLOAT16_VALUE(12.24) },
      { SIMDE_FLOAT16_VALUE(3.64), SIMDE_FLOAT16_VALUE(4.45), SIMDE_FLOAT16_VALUE(3.29), SIMDE_FLOAT16_VALUE(3.61), SIMDE_FLOAT16_VALUE(1.34), SIMDE_FLOAT16_VALUE(1.04), SIMDE_FLOAT16_VALUE(4.23), SIMDE_FLOAT16_VALUE(3.50) } },
    { { SIMDE_FLOAT16_VALUE(19.11), SIMDE_FLOAT16_VALUE(7.79), SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(3.96), SIMDE_FLOAT16_VALUE(11.17), SIMDE_FLOAT16_VALUE(13.91), SIMDE_FLOAT16_VALUE(19.04), SIMDE_FLOAT16_VALUE(8.31) },
      { SIMDE_FLOAT16_VALUE(4.37), SIMDE_FLOAT16_VALUE(2.79), SIMDE_FLOAT16_VALUE(3.86), SIMDE_FLOAT16_VALUE(1.99), SIMDE_FLOAT16_VALUE(3.34), SIMDE_FLOAT16_VALUE(3.73), SIMDE_FLOAT16_VALUE(4.36), SIMDE_FLOAT16_VALUE(2.88) } },
    { { SIMDE_FLOAT16_VALUE(3.38), SIMDE_FLOAT16_VALUE(15.99), SIMDE_FLOAT16_VALUE(5.80), SIMDE_FLOAT16_VALUE(1.50), SIMDE_FLOAT16_VALUE(11.15), SIMDE_FLOAT16_VALUE(8.01), SIMDE_FLOAT16_VALUE(9.98), SIMDE_FLOAT16_VALUE(11.56) },
      { SIMDE_FLOAT16_VALUE(1.84), SIMDE_FLOAT16_VALUE(4.00), SIMDE_FLOAT16_VALUE(2.41), SIMDE_FLOAT16_VALUE(1.22), SIMDE_FLOAT16_VALUE(3.34), SIMDE_FLOAT16_VALUE(2.83), SIMDE_FLOAT16_VALUE(3.16), SIMDE_FLOAT16_VALUE(3.40) } },
    { { SIMDE_FLOAT16_VALUE(5.72), SIMDE_FLOAT16_VALUE(4.72), SIMDE_FLOAT16_VALUE(13.35), SIMDE_FLOAT16_VALUE(5.27), SIMDE_FLOAT16_VALUE(14.93), SIMDE_FLOAT16_VALUE(8.37), SIMDE_FLOAT16_VALUE(9.29), SIMDE_FLOAT16_VALUE(12.19) },
      { SIMDE_FLOAT16_VALUE(2.39), SIMDE_FLOAT16_VALUE(2.17), SIMDE_FLOAT16_VALUE(3.65), SIMDE_FLOAT16_VALUE(2.30), SIMDE_FLOAT16_VALUE(3.86), SIMDE_FLOAT16_VALUE(2.89), SIMDE_FLOAT16_VALUE(3.05), SIMDE_FLOAT16_VALUE(3.49) } },
    { { SIMDE_FLOAT16_VALUE(0.56), SIMDE_FLOAT16_VALUE(15.39), SIMDE_FLOAT16_VALUE(2.96), SIMDE_FLOAT16_VALUE(14.04), SIMDE_FLOAT16_VALUE(3.69), SIMDE_FLOAT16_VALUE(16.17), SIMDE_FLOAT16_VALUE(10.27), SIMDE_FLOAT16_VALUE(8.75) },
      { SIMDE_FLOAT16_VALUE(0.75), SIMDE_FLOAT16_VALUE(3.92), SIMDE_FLOAT16_VALUE(1.72), SIMDE_FLOAT16_VALUE(3.75), SIMDE_FLOAT16_VALUE(1.92), SIMDE_FLOAT16_VALUE(4.02), SIMDE_FLOAT16_VALUE(3.20), SIMDE_FLOAT16_VALUE(2.96) } },
    { { SIMDE_FLOAT16_VALUE(6.87), SIMDE_FLOAT16_VALUE(17.75), SIMDE_FLOAT16_VALUE(10.49), SIMDE_FLOAT16_VALUE(12.41), SIMDE_FLOAT16_VALUE(10.46), SIMDE_FLOAT16_VALUE(13.51), SIMDE_FLOAT16_VALUE(14.18), SIMDE_FLOAT16_VALUE(3.12) },
      { SIMDE_FLOAT16_VALUE(2.62), SIMDE_FLOAT16_VALUE(4.21), SIMDE_FLOAT16_VALUE(3.24), SIMDE_FLOAT16_VALUE(3.52), SIMDE_FLOAT16_VALUE(3.23), SIMDE_FLOAT16_VALUE(3.68), SIMDE_FLOAT16_VALUE(3.77), SIMDE_FLOAT16_VALUE(1.76) } },
    { { SIMDE_FLOAT16_VALUE(16.66), SIMDE_FLOAT16_VALUE(2.38), SIMDE_FLOAT16_VALUE(5.49), SIMDE_FLOAT16_VALUE(15.56), SIMDE_FLOAT16_VALUE(5.03), SIMDE_FLOAT16_VALUE(15.19), SIMDE_FLOAT16_VALUE(19.95), SIMDE_FLOAT16_VALUE(2.03) },
      { SIMDE_FLOAT16_VALUE(4.08), SIMDE_FLOAT16_VALUE(1.54), SIMDE_FLOAT16_VALUE(2.34), SIMDE_FLOAT16_VALUE(3.94), SIMDE_FLOAT16_VALUE(2.24), SIMDE_FLOAT16_VALUE(3.90), SIMDE_FLOAT16_VALUE(4.47), SIMDE_FLOAT16_VALUE(1.42) } },
    { { SIMDE_FLOAT16_VALUE(8.75), SIMDE_FLOAT16_VALUE(7.36), SIMDE_FLOAT16_VALUE(16.08), SIMDE_FLOAT16_VALUE(10.14), SIMDE_FLOAT16_VALUE(18.98), SIMDE_FLOAT16_VALUE(3.88), SIMDE_FLOAT16_VALUE(10.48), SIMDE_FLOAT16_VALUE(15.78) },
      { SIMDE_FLOAT16_VALUE(2.96), SIMDE_FLOAT16_VALUE(2.71), SIMDE_FLOAT16_VALUE(4.01), SIMDE_FLOAT16_VALUE(3.18), SIMDE_FLOAT16_VALUE(4.36), SIMDE_FLOAT16_VALUE(1.97), SIMDE_FLOAT16_VALUE(3.24), SIMDE_FLOAT16_VALUE(3.97) } },
    { { SIMDE_FLOAT16_VALUE(16.48), SIMDE_FLOAT16_VALUE(13.25), SIMDE_FLOAT16_VALUE(2.25), SIMDE_FLOAT16_VALUE(15.60), SIMDE_FLOAT16_VALUE(17.74), SIMDE_FLOAT16_VALUE(6.29), SIMDE_FLOAT16_VALUE(1.11), SIMDE_FLOAT16_VALUE(14.10) },
      { SIMDE_FLOAT16_VALUE(4.06), SIMDE_FLOAT16_VALUE(3.64), SIMDE_FLOAT16_VALUE(1.50), SIMDE_FLOAT16_VALUE(3.95), SIMDE_FLOAT16_VALUE(4.21), SIMDE_FLOAT16_VALUE(2.51), SIMDE_FLOAT16_VALUE(1.05), SIMDE_FLOAT16_VALUE(3.75) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_float16x8_t a, r;

      a = simde_vld1q_f16(test_vec[i].a);
      r = simde_vsqrtq_f16(a);

      simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
    }

    return 0;
}

static int
test_simde_vsqrtq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(898.16), SIMDE_FLOAT32_C(436.83), SIMDE_FLOAT32_C(941.91), SIMDE_FLOAT32_C(130.36) },
      { SIMDE_FLOAT32_C(29.97), SIMDE_FLOAT32_C(20.90), SIMDE_FLOAT32_C(30.69), SIMDE_FLOAT32_C(11.42) } },
    { { SIMDE_FLOAT32_C(946.72), SIMDE_FLOAT32_C(848.19), SIMDE_FLOAT32_C(947.07), SIMDE_FLOAT32_C(24.60) },
      { SIMDE_FLOAT32_C(30.77), SIMDE_FLOAT32_C(29.12), SIMDE_FLOAT32_C(30.77), SIMDE_FLOAT32_C(4.96) } },
    { { SIMDE_FLOAT32_C(511.81), SIMDE_FLOAT32_C(423.44), SIMDE_FLOAT32_C(105.77), SIMDE_FLOAT32_C(642.15) },
      { SIMDE_FLOAT32_C(22.62), SIMDE_FLOAT32_C(20.58), SIMDE_FLOAT32_C(10.28), SIMDE_FLOAT32_C(25.34) } },
    { { SIMDE_FLOAT32_C(394.76), SIMDE_FLOAT32_C(296.91), SIMDE_FLOAT32_C(606.33), SIMDE_FLOAT32_C(821.66) },
      { SIMDE_FLOAT32_C(19.87), SIMDE_FLOAT32_C(17.23), SIMDE_FLOAT32_C(24.62), SIMDE_FLOAT32_C(28.66) } },
    { { SIMDE_FLOAT32_C(529.20), SIMDE_FLOAT32_C(427.34), SIMDE_FLOAT32_C(115.65), SIMDE_FLOAT32_C(758.21) },
      { SIMDE_FLOAT32_C(23.00), SIMDE_FLOAT32_C(20.67), SIMDE_FLOAT32_C(10.75), SIMDE_FLOAT32_C(27.54) } },
    { { SIMDE_FLOAT32_C(567.66), SIMDE_FLOAT32_C(227.63), SIMDE_FLOAT32_C(704.04), SIMDE_FLOAT32_C(584.28) },
      { SIMDE_FLOAT32_C(23.83), SIMDE_FLOAT32_C(15.09), SIMDE_FLOAT32_C(26.53), SIMDE_FLOAT32_C(24.17) } },
    { { SIMDE_FLOAT32_C(922.13), SIMDE_FLOAT32_C(627.68), SIMDE_FLOAT32_C(890.72), SIMDE_FLOAT32_C(977.81) },
      { SIMDE_FLOAT32_C(30.37), SIMDE_FLOAT32_C(25.05), SIMDE_FLOAT32_C(29.84), SIMDE_FLOAT32_C(31.27) } },
    { { SIMDE_FLOAT32_C(651.46), SIMDE_FLOAT32_C(390.03), SIMDE_FLOAT32_C(164.80), SIMDE_FLOAT32_C(529.63) },
      { SIMDE_FLOAT32_C(25.52), SIMDE_FLOAT32_C(19.75), SIMDE_FLOAT32_C(12.84), SIMDE_FLOAT32_C(23.01) } },
    { { SIMDE_FLOAT32_C(92.82), SIMDE_FLOAT32_C(762.54), SIMDE_FLOAT32_C(539.12), SIMDE_FLOAT32_C(63.76) },
      { SIMDE_FLOAT32_C(9.63), SIMDE_FLOAT32_C(27.61), SIMDE_FLOAT32_C(23.22), SIMDE_FLOAT32_C(7.98) } },
    { { SIMDE_FLOAT32_C(944.37), SIMDE_FLOAT32_C(504.86), SIMDE_FLOAT32_C(894.52), SIMDE_FLOAT32_C(430.50) },
      { SIMDE_FLOAT32_C(30.73), SIMDE_FLOAT32_C(22.47), SIMDE_FLOAT32_C(29.91), SIMDE_FLOAT32_C(20.75) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vsqrtq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vsqrtq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(1501.67), SIMDE_FLOAT64_C(3408.26) },
      { SIMDE_FLOAT64_C(38.75), SIMDE_FLOAT64_C(58.38) } },
    { { SIMDE_FLOAT64_C(1094.55), SIMDE_FLOAT64_C(3293.01) },
      { SIMDE_FLOAT64_C(33.08), SIMDE_FLOAT64_C(57.38) } },
    { { SIMDE_FLOAT64_C(2202.11), SIMDE_FLOAT64_C(1239.65) },
      { SIMDE_FLOAT64_C(46.93), SIMDE_FLOAT64_C(35.21) } },
    { { SIMDE_FLOAT64_C(252.00), SIMDE_FLOAT64_C(452.15) },
      { SIMDE_FLOAT64_C(15.87), SIMDE_FLOAT64_C(21.26) } },
    { { SIMDE_FLOAT64_C(2604.02), SIMDE_FLOAT64_C(3478.61) },
      { SIMDE_FLOAT64_C(51.03), SIMDE_FLOAT64_C(58.98) } },
    { { SIMDE_FLOAT64_C(2077.18), SIMDE_FLOAT64_C(3121.04) },
      { SIMDE_FLOAT64_C(45.58), SIMDE_FLOAT64_C(55.87) } },
    { { SIMDE_FLOAT64_C(2819.71), SIMDE_FLOAT64_C(2570.87) },
      { SIMDE_FLOAT64_C(53.10), SIMDE_FLOAT64_C(50.70) } },
    { { SIMDE_FLOAT64_C(3336.66), SIMDE_FLOAT64_C(2003.93) },
      { SIMDE_FLOAT64_C(57.76), SIMDE_FLOAT64_C(44.77) } },
    { { SIMDE_FLOAT64_C(2249.24), SIMDE_FLOAT64_C(30.55) },
      { SIMDE_FLOAT64_C(47.43), SIMDE_FLOAT64_C(5.53) } },
    { { SIMDE_FLOAT64_C(3238.95), SIMDE_FLOAT64_C(1018.00) },
      { SIMDE_FLOAT64_C(56.91), SIMDE_FLOAT64_C(31.91) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vsqrtq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsqrth_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqrt_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqrt_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqrt_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqrtq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqrtq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqrtq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
