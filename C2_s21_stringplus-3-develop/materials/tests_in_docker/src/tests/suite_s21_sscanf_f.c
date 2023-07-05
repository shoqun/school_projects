#include "s21_test.h"

START_TEST(sscanf_spec_f_1) {
  char format[] = "%f %f %f";
  char str[] = "  123 +198 -87";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_f_2) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_f_3) {
  char format[] = "%f %f %f %f";
  char str[] = "NAN nan -INF +inf";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_f_4) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_f_5) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_f_6) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_f_7) {
  char format[] = "%f";
  char str[] = "999e5000";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_f_8) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_9) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_10) {
  char format[] = "%*f %7f %*f %*f";
  char str[] = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_f_11) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_f_12) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_13) {
  char format[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_14) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_15) {
  char format[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_18) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_19) {
  char format[] = "%7f %7f %5fq %6f %*f q%*f";
  char str[] = "-1.3e-10 -1.3e+10 1.3e1q 1.4 1.3eq 1.4e2";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_20) {
  char format[] = "%f %f %*f %f %f %f";
  char str[] = "0x1416 0x1F.16 0X12 0x12e120 0xabcde.abcde";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_f_21) {
  char format[] = "%f %f %f %f %f %f";
  char str[] = "1.1e4932 1.2E4932 1.3e4932 -1.1e4932 -1.2e4932 -1.3e4932";
  float d1 = 0, d2 = 0;
  float dd1 = 0, dd2 = 0;
  float f1 = 0, f2 = 0;
  float ff1 = 0, ff2 = 0;
  float g1 = 0, g2 = 0;
  float gg1 = 0, gg2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &g1, &gg1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &g2, &gg2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(dd1, dd2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(ff1, ff2);
  ck_assert_float_eq(g1, g2);
  ck_assert_float_eq(gg1, gg2);
}
END_TEST

START_TEST(sscanf_spec_f_22) {
  char format[] = "%3f %3f %4f %4f";
  char str[] = "NAN nan -INF +inf";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(q1);
  ck_assert_float_infinite(z1);
  ck_assert_float_infinite(w1);
}
END_TEST

// START_TEST(sscanf_spec_f_23) {
//   char format[] = "%4f %3f %2f %1f";
//   char str[] = "0x1416 0x14.16 0x12 0x12c.ab";
//   float d1, d2;
//   float q1 = 0, q2 = 0;
//   float z1 = 0, z2 = 0;
//   float w1 = 0, w2 = 0;
//
//   int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
//   int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_float_eq(d1, d2);
//   ck_assert_float_eq(q1, q2);
//   ck_assert_float_eq(z1, z2);
//   ck_assert_float_eq(w1, w2);
// }
// END_TEST

START_TEST(sscanf_spec_f_24) {
  char format[] = "%f %f %f %f";
  char str[] = "01416 014 012 012";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_lf_1) {
  char format[] = "%lf %lf %lf %lf %lf %lf";
  char str[] = "1.1e4932 1.2e4932 1.3e4932 -1.1e4932 -1.2e4932 -1.3e4932";
  double d1 = 0, d2 = 0;
  double dd1 = 0, dd2 = 0;
  double f1 = 0, f2 = 0;
  double ff1 = 0, ff2 = 0;
  double g1 = 0, g2 = 0;
  double gg1 = 0, gg2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &g1, &gg1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &g2, &gg2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(dd1, dd2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(ff1, ff2);
  ck_assert_float_eq(g1, g2);
  ck_assert_float_eq(gg1, gg2);
}
END_TEST

START_TEST(sscanf_spec_Lf_1) {
  char format[] = "%Lf %Lf %Lf %Lf %Lf %Lf";
  char str[] = "1.1e4932 1.2e4932 1.3e4932 -1.1e4932 -1.2e4932 -1.3e4932";
  long double d1 = 0, d2 = 0;
  long double dd1 = 0, dd2 = 0;
  long double f1 = 0, f2 = 0;
  long double ff1 = 0, ff2 = 0;
  long double g1 = 0, g2 = 0;
  long double gg1 = 0, gg2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &g1, &gg1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &g2, &gg2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(dd1, dd2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(ff1, ff2);
  ck_assert_float_eq(g1, g2);
  ck_assert_float_eq(gg1, gg2);
}
END_TEST

Suite *suite_s21_sscanf_f(void) {
  Suite *s = suite_create("\033[42m-=s21_scanf_f=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_f_1);
  tcase_add_test(tc, sscanf_spec_f_2);
  tcase_add_test(tc, sscanf_spec_f_3);
  tcase_add_test(tc, sscanf_spec_f_4);
  tcase_add_test(tc, sscanf_spec_f_5);
  tcase_add_test(tc, sscanf_spec_f_6);
  tcase_add_test(tc, sscanf_spec_f_7);
  tcase_add_test(tc, sscanf_spec_f_8);
  tcase_add_test(tc, sscanf_spec_f_9);
  tcase_add_test(tc, sscanf_spec_f_10);
  tcase_add_test(tc, sscanf_spec_f_11);
  tcase_add_test(tc, sscanf_spec_f_12);
  tcase_add_test(tc, sscanf_spec_f_13);
  tcase_add_test(tc, sscanf_spec_f_14);
  tcase_add_test(tc, sscanf_spec_f_15);
  tcase_add_test(tc, sscanf_spec_f_18);
  tcase_add_test(tc, sscanf_spec_f_19);
  tcase_add_test(tc, sscanf_spec_f_20);
  tcase_add_test(tc, sscanf_spec_f_21);
  tcase_add_test(tc, sscanf_spec_f_22);
  //  tcase_add_test(tc, sscanf_spec_f_23);
  tcase_add_test(tc, sscanf_spec_f_24);

  tcase_add_test(tc, sscanf_spec_lf_1);
  tcase_add_test(tc, sscanf_spec_Lf_1);
  suite_add_tcase(s, tc);
  return s;
}
