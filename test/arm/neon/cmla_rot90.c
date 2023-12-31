#define SIMDE_TEST_ARM_NEON_INSN cmla_rot90

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot90.h"

static int
test_simde_vcmla_rot90_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
    simde_float16 r_[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  -0.140),  SIMDE_FLOAT16_VALUE(   2.682),  SIMDE_FLOAT16_VALUE(   8.308),  SIMDE_FLOAT16_VALUE(  -2.440) },
      {  SIMDE_FLOAT16_VALUE(   1.452),  SIMDE_FLOAT16_VALUE(  -1.687),  SIMDE_FLOAT16_VALUE(   7.937),  SIMDE_FLOAT16_VALUE( -14.923) },
      {  SIMDE_FLOAT16_VALUE(   1.684),  SIMDE_FLOAT16_VALUE(   1.687),  SIMDE_FLOAT16_VALUE(   8.182),  SIMDE_FLOAT16_VALUE(   2.520) },
      {  SIMDE_FLOAT16_VALUE(   6.209),  SIMDE_FLOAT16_VALUE(   5.581),  SIMDE_FLOAT16_VALUE( -28.230),  SIMDE_FLOAT16_VALUE( -16.846) } },
    { {  SIMDE_FLOAT16_VALUE(   9.611),  SIMDE_FLOAT16_VALUE( -13.506),  SIMDE_FLOAT16_VALUE(   0.094),  SIMDE_FLOAT16_VALUE(   2.441) },
      {  SIMDE_FLOAT16_VALUE(   2.416),  SIMDE_FLOAT16_VALUE(   8.976),  SIMDE_FLOAT16_VALUE(  -7.384),  SIMDE_FLOAT16_VALUE(   5.362) },
      {  SIMDE_FLOAT16_VALUE(   1.179),  SIMDE_FLOAT16_VALUE(  13.865),  SIMDE_FLOAT16_VALUE(   0.001),  SIMDE_FLOAT16_VALUE(  -0.585) },
      {  SIMDE_FLOAT16_VALUE( 122.409),  SIMDE_FLOAT16_VALUE( -18.765),  SIMDE_FLOAT16_VALUE( -13.088),  SIMDE_FLOAT16_VALUE( -18.609) } },
    { {  SIMDE_FLOAT16_VALUE( -12.513),  SIMDE_FLOAT16_VALUE( -12.991),  SIMDE_FLOAT16_VALUE( -13.513),  SIMDE_FLOAT16_VALUE(  -8.631) },
      {  SIMDE_FLOAT16_VALUE(   6.419),  SIMDE_FLOAT16_VALUE(   8.364),  SIMDE_FLOAT16_VALUE( -14.860),  SIMDE_FLOAT16_VALUE(  13.580) },
      {  SIMDE_FLOAT16_VALUE( -10.080),  SIMDE_FLOAT16_VALUE(   6.990),  SIMDE_FLOAT16_VALUE(  14.752),  SIMDE_FLOAT16_VALUE(  -4.531) },
      {  SIMDE_FLOAT16_VALUE(  98.577),  SIMDE_FLOAT16_VALUE( -76.399),  SIMDE_FLOAT16_VALUE( 131.961),  SIMDE_FLOAT16_VALUE( 123.726) } },
    { {  SIMDE_FLOAT16_VALUE(  -4.502),  SIMDE_FLOAT16_VALUE(  14.053),  SIMDE_FLOAT16_VALUE(  10.374),  SIMDE_FLOAT16_VALUE(  -5.527) },
      {  SIMDE_FLOAT16_VALUE(  -0.420),  SIMDE_FLOAT16_VALUE(  11.441),  SIMDE_FLOAT16_VALUE(  -0.134),  SIMDE_FLOAT16_VALUE(  -3.783) },
      {  SIMDE_FLOAT16_VALUE(  -5.296),  SIMDE_FLOAT16_VALUE(   3.781),  SIMDE_FLOAT16_VALUE(   3.276),  SIMDE_FLOAT16_VALUE(  -5.049) },
      {  SIMDE_FLOAT16_VALUE(-166.000),  SIMDE_FLOAT16_VALUE(  -2.121),  SIMDE_FLOAT16_VALUE( -17.633),  SIMDE_FLOAT16_VALUE(  -4.308) } },
    { {  SIMDE_FLOAT16_VALUE(   6.607),  SIMDE_FLOAT16_VALUE(  10.572),  SIMDE_FLOAT16_VALUE(  -0.346),  SIMDE_FLOAT16_VALUE(  -1.252) },
      {  SIMDE_FLOAT16_VALUE( -14.280),  SIMDE_FLOAT16_VALUE(   6.335),  SIMDE_FLOAT16_VALUE(   4.912),  SIMDE_FLOAT16_VALUE(  -4.071) },
      {  SIMDE_FLOAT16_VALUE(  -1.537),  SIMDE_FLOAT16_VALUE(  -4.261),  SIMDE_FLOAT16_VALUE( -14.972),  SIMDE_FLOAT16_VALUE(  -7.073) },
      {  SIMDE_FLOAT16_VALUE( -68.511),  SIMDE_FLOAT16_VALUE(-155.229),  SIMDE_FLOAT16_VALUE( -20.069),  SIMDE_FLOAT16_VALUE( -13.223) } },
    { {  SIMDE_FLOAT16_VALUE(   3.036),  SIMDE_FLOAT16_VALUE( -13.840),  SIMDE_FLOAT16_VALUE( -13.745),  SIMDE_FLOAT16_VALUE(   2.964) },
      {  SIMDE_FLOAT16_VALUE(  -1.657),  SIMDE_FLOAT16_VALUE(   7.236),  SIMDE_FLOAT16_VALUE(   7.380),  SIMDE_FLOAT16_VALUE( -12.084) },
      {  SIMDE_FLOAT16_VALUE(  -9.699),  SIMDE_FLOAT16_VALUE(  -4.265),  SIMDE_FLOAT16_VALUE( -14.259),  SIMDE_FLOAT16_VALUE(  -0.411) },
      {  SIMDE_FLOAT16_VALUE(  90.447),  SIMDE_FLOAT16_VALUE(  18.668),  SIMDE_FLOAT16_VALUE(  21.558),  SIMDE_FLOAT16_VALUE(  21.463) } },
    { {  SIMDE_FLOAT16_VALUE(  -4.940),  SIMDE_FLOAT16_VALUE(   3.013),  SIMDE_FLOAT16_VALUE(  10.180),  SIMDE_FLOAT16_VALUE(   2.386) },
      {  SIMDE_FLOAT16_VALUE(  10.569),  SIMDE_FLOAT16_VALUE( -13.814),  SIMDE_FLOAT16_VALUE( -11.551),  SIMDE_FLOAT16_VALUE( -11.815) },
      {  SIMDE_FLOAT16_VALUE(   6.386),  SIMDE_FLOAT16_VALUE(  -2.869),  SIMDE_FLOAT16_VALUE(  11.024),  SIMDE_FLOAT16_VALUE(  -5.318) },
      {  SIMDE_FLOAT16_VALUE(  48.008),  SIMDE_FLOAT16_VALUE(  28.975),  SIMDE_FLOAT16_VALUE(  39.215),  SIMDE_FLOAT16_VALUE( -32.879) } },
    { {  SIMDE_FLOAT16_VALUE(   4.137),  SIMDE_FLOAT16_VALUE(  12.116),  SIMDE_FLOAT16_VALUE( -12.032),  SIMDE_FLOAT16_VALUE(   1.708) },
      {  SIMDE_FLOAT16_VALUE(  -6.426),  SIMDE_FLOAT16_VALUE(   3.480),  SIMDE_FLOAT16_VALUE(  -2.981),  SIMDE_FLOAT16_VALUE(  10.936) },
      {  SIMDE_FLOAT16_VALUE(  -7.426),  SIMDE_FLOAT16_VALUE(   5.276),  SIMDE_FLOAT16_VALUE(   7.479),  SIMDE_FLOAT16_VALUE(  -4.686) },
      {  SIMDE_FLOAT16_VALUE( -49.590),  SIMDE_FLOAT16_VALUE( -72.581),  SIMDE_FLOAT16_VALUE( -11.200),  SIMDE_FLOAT16_VALUE(  -9.778) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vld1_f16(test_vec[i].r);
    simde_float16x4_t r_ = simde_vcmla_rot90_f16(r, a, b);

    simde_test_arm_neon_assert_equal_f16x4(r_, simde_vld1_f16(test_vec[i].r_), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r_ = simde_vcmla_rot90_f16(a, b, r);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmla_rot90_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -736.61), SIMDE_FLOAT32_C(  -886.60) },
      { SIMDE_FLOAT32_C(   281.46), SIMDE_FLOAT32_C(   182.30) },
      { SIMDE_FLOAT32_C(   429.99), SIMDE_FLOAT32_C(  -897.20) },
      { SIMDE_FLOAT32_C(162057.17), SIMDE_FLOAT32_C(-250439.62) } },
    { { SIMDE_FLOAT32_C(   776.49), SIMDE_FLOAT32_C(   342.21) },
      { SIMDE_FLOAT32_C(  -299.64), SIMDE_FLOAT32_C(   786.30) },
      { SIMDE_FLOAT32_C(  -603.93), SIMDE_FLOAT32_C(   -76.17) },
      { SIMDE_FLOAT32_C(-269683.66), SIMDE_FLOAT32_C(-102615.98) } },
    { { SIMDE_FLOAT32_C(   513.95), SIMDE_FLOAT32_C(  -299.36) },
      { SIMDE_FLOAT32_C(  -719.19), SIMDE_FLOAT32_C(   762.89) },
      { SIMDE_FLOAT32_C(   552.54), SIMDE_FLOAT32_C(    14.06) },
      { SIMDE_FLOAT32_C(228931.28), SIMDE_FLOAT32_C(215310.77) } },
    { { SIMDE_FLOAT32_C(   529.94), SIMDE_FLOAT32_C(  -725.03) },
      { SIMDE_FLOAT32_C(   627.20), SIMDE_FLOAT32_C(   167.43) },
      { SIMDE_FLOAT32_C(   101.22), SIMDE_FLOAT32_C(   -38.51) },
      { SIMDE_FLOAT32_C(121492.99), SIMDE_FLOAT32_C(-454777.34) } },
    { { SIMDE_FLOAT32_C(  -773.64), SIMDE_FLOAT32_C(   578.09) },
      { SIMDE_FLOAT32_C(  -557.39), SIMDE_FLOAT32_C(  -616.25) },
      { SIMDE_FLOAT32_C(   304.61), SIMDE_FLOAT32_C(   452.27) },
      { SIMDE_FLOAT32_C(356552.59), SIMDE_FLOAT32_C(-321769.34) } },
    { { SIMDE_FLOAT32_C(   530.02), SIMDE_FLOAT32_C(   568.00) },
      { SIMDE_FLOAT32_C(   565.67), SIMDE_FLOAT32_C(  -188.52) },
      { SIMDE_FLOAT32_C(  -249.70), SIMDE_FLOAT32_C(    -4.33) },
      { SIMDE_FLOAT32_C(106829.66), SIMDE_FLOAT32_C(321296.22) } },
    { { SIMDE_FLOAT32_C(   -85.72), SIMDE_FLOAT32_C(  -473.21) },
      { SIMDE_FLOAT32_C(  -662.12), SIMDE_FLOAT32_C(   614.64) },
      { SIMDE_FLOAT32_C(  -686.90), SIMDE_FLOAT32_C(  -266.06) },
      { SIMDE_FLOAT32_C(290166.91), SIMDE_FLOAT32_C(313055.75) } },
    { { SIMDE_FLOAT32_C(  -461.53), SIMDE_FLOAT32_C(   827.04) },
      { SIMDE_FLOAT32_C(   434.59), SIMDE_FLOAT32_C(  -180.71) },
      { SIMDE_FLOAT32_C(   589.93), SIMDE_FLOAT32_C(   -12.87) },
      { SIMDE_FLOAT32_C(150044.33), SIMDE_FLOAT32_C(359410.44) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_rot90_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_rot90_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
    simde_float16 r_[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  -5.925),  SIMDE_FLOAT16_VALUE(  -3.510),  SIMDE_FLOAT16_VALUE(  -6.431),  SIMDE_FLOAT16_VALUE(   2.890),
         SIMDE_FLOAT16_VALUE(   3.018),  SIMDE_FLOAT16_VALUE(   7.405),  SIMDE_FLOAT16_VALUE(  -1.492),  SIMDE_FLOAT16_VALUE(   4.525) },
      {  SIMDE_FLOAT16_VALUE(  -8.925),  SIMDE_FLOAT16_VALUE(  14.973),  SIMDE_FLOAT16_VALUE(   8.675),  SIMDE_FLOAT16_VALUE(   0.624),
         SIMDE_FLOAT16_VALUE(   4.096),  SIMDE_FLOAT16_VALUE(  12.735),  SIMDE_FLOAT16_VALUE(   6.636),  SIMDE_FLOAT16_VALUE(   0.664) },
      {  SIMDE_FLOAT16_VALUE(   6.282),  SIMDE_FLOAT16_VALUE(  12.052),  SIMDE_FLOAT16_VALUE(  -0.562),  SIMDE_FLOAT16_VALUE(  -9.385),
         SIMDE_FLOAT16_VALUE( -12.117),  SIMDE_FLOAT16_VALUE( -12.088),  SIMDE_FLOAT16_VALUE(  -6.433),  SIMDE_FLOAT16_VALUE(  14.202) },
      {  SIMDE_FLOAT16_VALUE(  58.837),  SIMDE_FLOAT16_VALUE(  43.379),  SIMDE_FLOAT16_VALUE(  -2.365),  SIMDE_FLOAT16_VALUE(  15.686),
         SIMDE_FLOAT16_VALUE(-106.420),  SIMDE_FLOAT16_VALUE(  18.243),  SIMDE_FLOAT16_VALUE(  -9.438),  SIMDE_FLOAT16_VALUE(  44.230) } },
    { {  SIMDE_FLOAT16_VALUE(  14.689),  SIMDE_FLOAT16_VALUE(  -3.433),  SIMDE_FLOAT16_VALUE(   2.276),  SIMDE_FLOAT16_VALUE(  -8.421),
         SIMDE_FLOAT16_VALUE(  -4.940),  SIMDE_FLOAT16_VALUE(  14.830),  SIMDE_FLOAT16_VALUE(  -2.450),  SIMDE_FLOAT16_VALUE(  14.766) },
      {  SIMDE_FLOAT16_VALUE(   7.693),  SIMDE_FLOAT16_VALUE(   8.578),  SIMDE_FLOAT16_VALUE(   4.095),  SIMDE_FLOAT16_VALUE(  -5.754),
         SIMDE_FLOAT16_VALUE(   2.906),  SIMDE_FLOAT16_VALUE(   9.133),  SIMDE_FLOAT16_VALUE(   8.908),  SIMDE_FLOAT16_VALUE(   3.409) },
      {  SIMDE_FLOAT16_VALUE(   3.003),  SIMDE_FLOAT16_VALUE(   1.975),  SIMDE_FLOAT16_VALUE(  -1.403),  SIMDE_FLOAT16_VALUE( -11.537),
         SIMDE_FLOAT16_VALUE(   0.297),  SIMDE_FLOAT16_VALUE(   4.306),  SIMDE_FLOAT16_VALUE(  -8.942),  SIMDE_FLOAT16_VALUE(   5.547) },
      {  SIMDE_FLOAT16_VALUE(  32.451),  SIMDE_FLOAT16_VALUE( -24.435),  SIMDE_FLOAT16_VALUE( -49.857),  SIMDE_FLOAT16_VALUE( -46.021),
         SIMDE_FLOAT16_VALUE(-135.145),  SIMDE_FLOAT16_VALUE(  47.402),  SIMDE_FLOAT16_VALUE( -59.279),  SIMDE_FLOAT16_VALUE( 137.000) } },
    { {  SIMDE_FLOAT16_VALUE( -14.688),  SIMDE_FLOAT16_VALUE(  12.418),  SIMDE_FLOAT16_VALUE(  -5.602),  SIMDE_FLOAT16_VALUE(   0.779),
         SIMDE_FLOAT16_VALUE( -11.066),  SIMDE_FLOAT16_VALUE(  12.978),  SIMDE_FLOAT16_VALUE(   0.393),  SIMDE_FLOAT16_VALUE(  13.606) },
      {  SIMDE_FLOAT16_VALUE(  13.286),  SIMDE_FLOAT16_VALUE(  11.914),  SIMDE_FLOAT16_VALUE(   8.388),  SIMDE_FLOAT16_VALUE(   9.571),
         SIMDE_FLOAT16_VALUE(  -7.982),  SIMDE_FLOAT16_VALUE(   0.274),  SIMDE_FLOAT16_VALUE(  -0.335),  SIMDE_FLOAT16_VALUE(   5.778) },
      {  SIMDE_FLOAT16_VALUE(  11.050),  SIMDE_FLOAT16_VALUE(   1.433),  SIMDE_FLOAT16_VALUE(   8.886),  SIMDE_FLOAT16_VALUE(  -2.642),
         SIMDE_FLOAT16_VALUE(  10.621),  SIMDE_FLOAT16_VALUE(  -6.140),  SIMDE_FLOAT16_VALUE(  -1.531),  SIMDE_FLOAT16_VALUE(   1.137) },
      {  SIMDE_FLOAT16_VALUE(-137.000),  SIMDE_FLOAT16_VALUE( 166.500),  SIMDE_FLOAT16_VALUE(   1.430),  SIMDE_FLOAT16_VALUE(   3.892),
         SIMDE_FLOAT16_VALUE(   7.065),  SIMDE_FLOAT16_VALUE(-109.730),  SIMDE_FLOAT16_VALUE( -80.146),  SIMDE_FLOAT16_VALUE(  -3.421) } },
    { {  SIMDE_FLOAT16_VALUE(  -6.191),  SIMDE_FLOAT16_VALUE( -14.110),  SIMDE_FLOAT16_VALUE(  11.419),  SIMDE_FLOAT16_VALUE(   5.375),
         SIMDE_FLOAT16_VALUE(   0.801),  SIMDE_FLOAT16_VALUE(   6.866),  SIMDE_FLOAT16_VALUE(   6.863),  SIMDE_FLOAT16_VALUE(  13.601) },
      {  SIMDE_FLOAT16_VALUE(  -8.403),  SIMDE_FLOAT16_VALUE(   3.728),  SIMDE_FLOAT16_VALUE(   9.655),  SIMDE_FLOAT16_VALUE(  12.345),
         SIMDE_FLOAT16_VALUE( -10.872),  SIMDE_FLOAT16_VALUE(  -3.296),  SIMDE_FLOAT16_VALUE( -13.548),  SIMDE_FLOAT16_VALUE(   2.545) },
      {  SIMDE_FLOAT16_VALUE(  13.268),  SIMDE_FLOAT16_VALUE(   3.257),  SIMDE_FLOAT16_VALUE(   3.408),  SIMDE_FLOAT16_VALUE( -13.158),
         SIMDE_FLOAT16_VALUE( -11.069),  SIMDE_FLOAT16_VALUE(  -2.783),  SIMDE_FLOAT16_VALUE(  10.415),  SIMDE_FLOAT16_VALUE(  -0.034) },
      {  SIMDE_FLOAT16_VALUE(  65.870),  SIMDE_FLOAT16_VALUE( 121.823),  SIMDE_FLOAT16_VALUE( -62.946),  SIMDE_FLOAT16_VALUE(  38.738),
         SIMDE_FLOAT16_VALUE(  11.561),  SIMDE_FLOAT16_VALUE( -77.430),  SIMDE_FLOAT16_VALUE( -24.200),  SIMDE_FLOAT16_VALUE(-184.300) } },
    { {  SIMDE_FLOAT16_VALUE(   1.785),  SIMDE_FLOAT16_VALUE(  -8.301),  SIMDE_FLOAT16_VALUE(  -8.460),  SIMDE_FLOAT16_VALUE(   0.609),
         SIMDE_FLOAT16_VALUE( -10.735),  SIMDE_FLOAT16_VALUE(   6.056),  SIMDE_FLOAT16_VALUE( -11.417),  SIMDE_FLOAT16_VALUE( -13.397) },
      {  SIMDE_FLOAT16_VALUE(  -8.773),  SIMDE_FLOAT16_VALUE(  -8.168),  SIMDE_FLOAT16_VALUE( -11.868),  SIMDE_FLOAT16_VALUE(  -7.367),
         SIMDE_FLOAT16_VALUE(  -4.913),  SIMDE_FLOAT16_VALUE( -13.320),  SIMDE_FLOAT16_VALUE( -10.840),  SIMDE_FLOAT16_VALUE(  11.860) },
      {  SIMDE_FLOAT16_VALUE(  -6.123),  SIMDE_FLOAT16_VALUE(  -3.489),  SIMDE_FLOAT16_VALUE(  -8.537),  SIMDE_FLOAT16_VALUE( -10.453),
         SIMDE_FLOAT16_VALUE(  -4.821),  SIMDE_FLOAT16_VALUE(  -4.835),  SIMDE_FLOAT16_VALUE( -10.946),  SIMDE_FLOAT16_VALUE(   6.131) },
      {  SIMDE_FLOAT16_VALUE( -73.926),  SIMDE_FLOAT16_VALUE(  69.336),  SIMDE_FLOAT16_VALUE(  -4.050),  SIMDE_FLOAT16_VALUE( -17.681),
         SIMDE_FLOAT16_VALUE(  75.845),  SIMDE_FLOAT16_VALUE( -34.588),  SIMDE_FLOAT16_VALUE( 147.942),  SIMDE_FLOAT16_VALUE( 151.354) } },
    { {  SIMDE_FLOAT16_VALUE(  14.647),  SIMDE_FLOAT16_VALUE(  -2.045),  SIMDE_FLOAT16_VALUE(  10.220),  SIMDE_FLOAT16_VALUE(  -8.348),
         SIMDE_FLOAT16_VALUE(   6.587),  SIMDE_FLOAT16_VALUE(  -3.305),  SIMDE_FLOAT16_VALUE(  -9.557),  SIMDE_FLOAT16_VALUE(   2.332) },
      {  SIMDE_FLOAT16_VALUE(   8.919),  SIMDE_FLOAT16_VALUE(   4.558),  SIMDE_FLOAT16_VALUE(   5.005),  SIMDE_FLOAT16_VALUE(  -5.625),
         SIMDE_FLOAT16_VALUE(  12.715),  SIMDE_FLOAT16_VALUE( -12.113),  SIMDE_FLOAT16_VALUE(  13.247),  SIMDE_FLOAT16_VALUE(   2.094) },
      {  SIMDE_FLOAT16_VALUE(   9.285),  SIMDE_FLOAT16_VALUE(  14.178),  SIMDE_FLOAT16_VALUE(   5.845),  SIMDE_FLOAT16_VALUE(   9.424),
         SIMDE_FLOAT16_VALUE(  -2.782),  SIMDE_FLOAT16_VALUE(  10.683),  SIMDE_FLOAT16_VALUE(  14.862),  SIMDE_FLOAT16_VALUE(   3.444) },
      {  SIMDE_FLOAT16_VALUE(  18.606),  SIMDE_FLOAT16_VALUE(  -4.061),  SIMDE_FLOAT16_VALUE( -41.113),  SIMDE_FLOAT16_VALUE( -32.358),
         SIMDE_FLOAT16_VALUE( -42.815),  SIMDE_FLOAT16_VALUE( -31.340),  SIMDE_FLOAT16_VALUE(   9.979),  SIMDE_FLOAT16_VALUE(  34.336) } },
    { {  SIMDE_FLOAT16_VALUE(   8.817),  SIMDE_FLOAT16_VALUE(  -7.043),  SIMDE_FLOAT16_VALUE( -12.649),  SIMDE_FLOAT16_VALUE( -12.671),
         SIMDE_FLOAT16_VALUE(   2.329),  SIMDE_FLOAT16_VALUE(   2.135),  SIMDE_FLOAT16_VALUE(   4.207),  SIMDE_FLOAT16_VALUE(  -9.721) },
      {  SIMDE_FLOAT16_VALUE(   5.220),  SIMDE_FLOAT16_VALUE(   8.807),  SIMDE_FLOAT16_VALUE(  12.339),  SIMDE_FLOAT16_VALUE(  10.207),
         SIMDE_FLOAT16_VALUE(   9.658),  SIMDE_FLOAT16_VALUE(  -9.868),  SIMDE_FLOAT16_VALUE(  -2.763),  SIMDE_FLOAT16_VALUE(   5.120) },
      {  SIMDE_FLOAT16_VALUE(   4.632),  SIMDE_FLOAT16_VALUE( -10.959),  SIMDE_FLOAT16_VALUE(   0.167),  SIMDE_FLOAT16_VALUE(   3.886),
         SIMDE_FLOAT16_VALUE(  -0.714),  SIMDE_FLOAT16_VALUE(  -9.076),  SIMDE_FLOAT16_VALUE(  13.927),  SIMDE_FLOAT16_VALUE( -13.445) },
      {  SIMDE_FLOAT16_VALUE(  66.660),  SIMDE_FLOAT16_VALUE( -47.723),  SIMDE_FLOAT16_VALUE( 129.500),  SIMDE_FLOAT16_VALUE(-152.375),
         SIMDE_FLOAT16_VALUE(  20.354),  SIMDE_FLOAT16_VALUE(  11.544),  SIMDE_FLOAT16_VALUE(  63.699),  SIMDE_FLOAT16_VALUE(  13.414) } },
    { {  SIMDE_FLOAT16_VALUE(   2.576),  SIMDE_FLOAT16_VALUE(  13.801),  SIMDE_FLOAT16_VALUE(  -3.165),  SIMDE_FLOAT16_VALUE(  -0.554),
         SIMDE_FLOAT16_VALUE( -10.579),  SIMDE_FLOAT16_VALUE( -13.579),  SIMDE_FLOAT16_VALUE( -11.855),  SIMDE_FLOAT16_VALUE(  14.822) },
      {  SIMDE_FLOAT16_VALUE(   2.564),  SIMDE_FLOAT16_VALUE(  -0.754),  SIMDE_FLOAT16_VALUE(   5.758),  SIMDE_FLOAT16_VALUE(  -9.606),
         SIMDE_FLOAT16_VALUE(  14.397),  SIMDE_FLOAT16_VALUE(   9.319),  SIMDE_FLOAT16_VALUE( -13.317),  SIMDE_FLOAT16_VALUE(   0.681) },
      {  SIMDE_FLOAT16_VALUE(  10.154),  SIMDE_FLOAT16_VALUE(  -7.029),  SIMDE_FLOAT16_VALUE(   2.341),  SIMDE_FLOAT16_VALUE( -14.960),
         SIMDE_FLOAT16_VALUE(  -3.460),  SIMDE_FLOAT16_VALUE(   2.394),  SIMDE_FLOAT16_VALUE(  -2.692),  SIMDE_FLOAT16_VALUE( -14.327) },
      {  SIMDE_FLOAT16_VALUE(  20.560),  SIMDE_FLOAT16_VALUE(  28.357),  SIMDE_FLOAT16_VALUE(  -2.981),  SIMDE_FLOAT16_VALUE( -18.150),
         SIMDE_FLOAT16_VALUE( 123.083),  SIMDE_FLOAT16_VALUE(-193.103),  SIMDE_FLOAT16_VALUE( -12.786),  SIMDE_FLOAT16_VALUE(-211.712) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vld1q_f16(test_vec[i].r);
    simde_float16x8_t r_ = simde_vcmlaq_rot90_f16(r, a, b);
    simde_test_arm_neon_assert_equal_f16x8(r_, simde_vld1q_f16(test_vec[i].r_), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r_ = simde_vcmlaq_rot90_f16(a, b, r);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   809.81), SIMDE_FLOAT32_C(   702.36), SIMDE_FLOAT32_C(  -440.66), SIMDE_FLOAT32_C(    26.41) },
      { SIMDE_FLOAT32_C(   196.20), SIMDE_FLOAT32_C(   580.52), SIMDE_FLOAT32_C(   918.89), SIMDE_FLOAT32_C(  -116.23) },
      { SIMDE_FLOAT32_C(   484.07), SIMDE_FLOAT32_C(   711.80), SIMDE_FLOAT32_C(   891.23), SIMDE_FLOAT32_C(    40.72) },
      { SIMDE_FLOAT32_C(-407249.97), SIMDE_FLOAT32_C(138514.83), SIMDE_FLOAT32_C(  3960.86), SIMDE_FLOAT32_C( 24308.61) } },
    { { SIMDE_FLOAT32_C(   509.40), SIMDE_FLOAT32_C(  -504.44), SIMDE_FLOAT32_C(    19.20), SIMDE_FLOAT32_C(   170.91) },
      { SIMDE_FLOAT32_C(   886.34), SIMDE_FLOAT32_C(   555.20), SIMDE_FLOAT32_C(  -753.29), SIMDE_FLOAT32_C(   -56.21) },
      { SIMDE_FLOAT32_C(  -843.97), SIMDE_FLOAT32_C(  -640.31), SIMDE_FLOAT32_C(   469.39), SIMDE_FLOAT32_C(  -535.58) },
      { SIMDE_FLOAT32_C(279221.12), SIMDE_FLOAT32_C(-447745.69), SIMDE_FLOAT32_C( 10076.24), SIMDE_FLOAT32_C(-129280.38) } },
    { { SIMDE_FLOAT32_C(  -886.22), SIMDE_FLOAT32_C(   250.51), SIMDE_FLOAT32_C(   591.50), SIMDE_FLOAT32_C(   599.25) },
      { SIMDE_FLOAT32_C(   260.71), SIMDE_FLOAT32_C(  -574.11), SIMDE_FLOAT32_C(  -734.49), SIMDE_FLOAT32_C(    70.52) },
      { SIMDE_FLOAT32_C(  -871.75), SIMDE_FLOAT32_C(  -175.15), SIMDE_FLOAT32_C(  -903.07), SIMDE_FLOAT32_C(   324.45) },
      { SIMDE_FLOAT32_C(142948.55), SIMDE_FLOAT32_C( 65135.31), SIMDE_FLOAT32_C(-43162.18), SIMDE_FLOAT32_C(-439818.69) } },
    { { SIMDE_FLOAT32_C(  -594.62), SIMDE_FLOAT32_C(  -984.18), SIMDE_FLOAT32_C(  -791.78), SIMDE_FLOAT32_C(   889.45) },
      { SIMDE_FLOAT32_C(   727.61), SIMDE_FLOAT32_C(  -900.55), SIMDE_FLOAT32_C(   -69.84), SIMDE_FLOAT32_C(   237.02) },
      { SIMDE_FLOAT32_C(  -404.99), SIMDE_FLOAT32_C(   949.36), SIMDE_FLOAT32_C(  -592.07), SIMDE_FLOAT32_C(  -518.65) },
      { SIMDE_FLOAT32_C(-886708.25), SIMDE_FLOAT32_C(-715149.81), SIMDE_FLOAT32_C(-211409.52), SIMDE_FLOAT32_C(-62637.84) } },
    { { SIMDE_FLOAT32_C(   504.57), SIMDE_FLOAT32_C(  -345.36), SIMDE_FLOAT32_C(   425.14), SIMDE_FLOAT32_C(   660.60) },
      { SIMDE_FLOAT32_C(    14.33), SIMDE_FLOAT32_C(  -105.47), SIMDE_FLOAT32_C(  -874.99), SIMDE_FLOAT32_C(   128.10) },
      { SIMDE_FLOAT32_C(  -854.96), SIMDE_FLOAT32_C(   716.51), SIMDE_FLOAT32_C(  -272.64), SIMDE_FLOAT32_C(   405.75) },
      { SIMDE_FLOAT32_C(-37280.08), SIMDE_FLOAT32_C( -4232.50), SIMDE_FLOAT32_C(-84895.50), SIMDE_FLOAT32_C(-577612.62) } },
    { { SIMDE_FLOAT32_C(  -857.59), SIMDE_FLOAT32_C(    -7.13), SIMDE_FLOAT32_C(  -523.73), SIMDE_FLOAT32_C(  -729.34) },
      { SIMDE_FLOAT32_C(   817.72), SIMDE_FLOAT32_C(  -426.81), SIMDE_FLOAT32_C(   595.11), SIMDE_FLOAT32_C(  -776.90) },
      { SIMDE_FLOAT32_C(  -410.99), SIMDE_FLOAT32_C(   803.33), SIMDE_FLOAT32_C(  -887.46), SIMDE_FLOAT32_C(  -683.37) },
      { SIMDE_FLOAT32_C( -3454.15), SIMDE_FLOAT32_C( -5027.01), SIMDE_FLOAT32_C(-567511.75), SIMDE_FLOAT32_C(-434720.91) } },
    { { SIMDE_FLOAT32_C(   902.78), SIMDE_FLOAT32_C(    42.71), SIMDE_FLOAT32_C(   553.64), SIMDE_FLOAT32_C(  -502.21) },
      { SIMDE_FLOAT32_C(    -7.93), SIMDE_FLOAT32_C(   961.57), SIMDE_FLOAT32_C(   -20.86), SIMDE_FLOAT32_C(  -503.36) },
      { SIMDE_FLOAT32_C(  -383.79), SIMDE_FLOAT32_C(  -595.71), SIMDE_FLOAT32_C(  -842.76), SIMDE_FLOAT32_C(   630.53) },
      { SIMDE_FLOAT32_C(-41452.45), SIMDE_FLOAT32_C(  -934.40), SIMDE_FLOAT32_C(-253635.17), SIMDE_FLOAT32_C( 11106.63) } },
    { { SIMDE_FLOAT32_C(   298.82), SIMDE_FLOAT32_C(  -717.75), SIMDE_FLOAT32_C(  -241.36), SIMDE_FLOAT32_C(   443.86) },
      { SIMDE_FLOAT32_C(   998.76), SIMDE_FLOAT32_C(   486.00), SIMDE_FLOAT32_C(  -150.39), SIMDE_FLOAT32_C(  -858.84) },
      { SIMDE_FLOAT32_C(  -521.14), SIMDE_FLOAT32_C(   325.87), SIMDE_FLOAT32_C(  -588.18), SIMDE_FLOAT32_C(  -703.42) },
      { SIMDE_FLOAT32_C(348305.38), SIMDE_FLOAT32_C(-716534.12), SIMDE_FLOAT32_C(380616.53), SIMDE_FLOAT32_C(-67455.52) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_rot90_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_rot90_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -913.35), SIMDE_FLOAT64_C(   651.70) },
      { SIMDE_FLOAT64_C(  -202.18), SIMDE_FLOAT64_C(   611.89) },
      { SIMDE_FLOAT64_C(  -924.95), SIMDE_FLOAT64_C(   395.75) },
      { SIMDE_FLOAT64_C(-399693.66), SIMDE_FLOAT64_C(-131364.96) } },
    { { SIMDE_FLOAT64_C(  -917.75), SIMDE_FLOAT64_C(  -438.33) },
      { SIMDE_FLOAT64_C(    -0.32), SIMDE_FLOAT64_C(   810.69) },
      { SIMDE_FLOAT64_C(    11.74), SIMDE_FLOAT64_C(  -666.19) },
      { SIMDE_FLOAT64_C(355361.49), SIMDE_FLOAT64_C(  -525.92) } },
    { { SIMDE_FLOAT64_C(  -434.30), SIMDE_FLOAT64_C(  -744.37) },
      { SIMDE_FLOAT64_C(  -564.35), SIMDE_FLOAT64_C(   -95.18) },
      { SIMDE_FLOAT64_C(   956.50), SIMDE_FLOAT64_C(   334.31) },
      { SIMDE_FLOAT64_C(-69892.64), SIMDE_FLOAT64_C(420419.52) } },
    { { SIMDE_FLOAT64_C(   595.20), SIMDE_FLOAT64_C(   271.18) },
      { SIMDE_FLOAT64_C(   967.27), SIMDE_FLOAT64_C(   979.29) },
      { SIMDE_FLOAT64_C(   428.77), SIMDE_FLOAT64_C(   858.33) },
      { SIMDE_FLOAT64_C(-265135.09), SIMDE_FLOAT64_C(263162.61) } },
    { { SIMDE_FLOAT64_C(  -931.38), SIMDE_FLOAT64_C(   720.93) },
      { SIMDE_FLOAT64_C(   860.06), SIMDE_FLOAT64_C(  -977.02) },
      { SIMDE_FLOAT64_C(  -592.65), SIMDE_FLOAT64_C(   976.85) },
      { SIMDE_FLOAT64_C(703770.38), SIMDE_FLOAT64_C(621019.91) } },
    { { SIMDE_FLOAT64_C(   776.69), SIMDE_FLOAT64_C(  -506.00) },
      { SIMDE_FLOAT64_C(   628.55), SIMDE_FLOAT64_C(  -425.49) },
      { SIMDE_FLOAT64_C(  -894.11), SIMDE_FLOAT64_C(   703.60) },
      { SIMDE_FLOAT64_C(-216192.05), SIMDE_FLOAT64_C(-317342.70) } },
    { { SIMDE_FLOAT64_C(   970.25), SIMDE_FLOAT64_C(  -811.86) },
      { SIMDE_FLOAT64_C(  -734.73), SIMDE_FLOAT64_C(   -30.06) },
      { SIMDE_FLOAT64_C(   998.84), SIMDE_FLOAT64_C(   277.01) },
      { SIMDE_FLOAT64_C(-23405.67), SIMDE_FLOAT64_C(596774.91) } },
    { { SIMDE_FLOAT64_C(   303.75), SIMDE_FLOAT64_C(  -435.46) },
      { SIMDE_FLOAT64_C(   532.64), SIMDE_FLOAT64_C(   739.40) },
      { SIMDE_FLOAT64_C(   469.36), SIMDE_FLOAT64_C(   489.13) },
      { SIMDE_FLOAT64_C(322448.48), SIMDE_FLOAT64_C(-231454.28) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_rot90_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_rot90_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
