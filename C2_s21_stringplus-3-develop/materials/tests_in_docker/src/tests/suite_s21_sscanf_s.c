#include "s21_test.h"

START_TEST(sscanf_spec_s_1) {
  char format[] = "%s %s %s %s";
  char str[] = "One, Two, Three, Four";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
}
END_TEST

START_TEST(sscanf_spec_s_2) {
  char format[] = " %s \n%s\t%s %s ";
  char str[] = "One, Two, Three, Four";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
}
END_TEST

START_TEST(sscanf_spec_s_3) {
  char format[] = "%s %s %s %s";
  char str[] = "   One,\nTwo, Three,\tFour   ";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
}
END_TEST

START_TEST(sscanf_spec_s_4) {
  char format[] = "%4s %2s %*3s %2s";
  char str[] = "   One,\nTwo, Three,\tFour   ";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
}
END_TEST

START_TEST(sscanf_spec_s_5) {
  char format[] = "  %9s %2s \t %*10s %2s  ";
  char str[] = "123456789 MoreThenTwo Junk";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
}
END_TEST

START_TEST(sscanf_spec_s_6) {
  char format[] = "%s %s";
  char str[] = "text \t\n";
  char s1[20], s2[20] = {0}, s3[20], s4[20] = {0};

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_pstr_eq(s1, s3);
  ck_assert_pstr_eq(s2, s4);
}
END_TEST

START_TEST(sscanf_spec_s_7) {
  char format[] = "%s %s";
  char str[] = "text \t\n \0 text";
  char s1[20], s2[20] = {0}, s3[20], s4[20] = {0};

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_pstr_eq(s1, s3);
  ck_assert_pstr_eq(s2, s4);
}
END_TEST

START_TEST(sscanf_spec_s_8) {
  char format[] = "%ls %ls %ls %ls";
  char str[] = "One, Two, Three, Four";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
}
END_TEST

// START_TEST(sscanf_spec_s_9) {
//   char format[] = "%Ls %Ls %Ls %Ls";
//   char str[] = "One, Two, Three, Four";
//   char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30];
//
//   int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7);
//   int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_pstr_eq(s1, s2);
//   ck_assert_pstr_eq(s3, s4);
//   ck_assert_pstr_eq(s5, s6);
//   ck_assert_pstr_eq(s7, s8);
// }
// END_TEST

// START_TEST(sscanf_spec_s_10) {
//   char format[] = "%hs %hs %hs %hs";
//   char str[] = "One, Two, Three, Four";
//   char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30];
//
//   int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7);
//   int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_pstr_eq(s1, s2);
//   ck_assert_pstr_eq(s3, s4);
//   ck_assert_pstr_eq(s5, s6);
//   ck_assert_pstr_eq(s7, s8);
// }
// END_TEST

START_TEST(sscanf_spec_s_11) {
  char format[] = "%*s %s %s %s %s";
  char str[] = "   One,\nTwo, Three,\tFour Five   ";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
}
END_TEST

Suite *suite_s21_sscanf_s(void) {
  Suite *s = suite_create("\033[42m-=s21_scanf_s=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_s_1);
  tcase_add_test(tc, sscanf_spec_s_2);
  tcase_add_test(tc, sscanf_spec_s_3);
  tcase_add_test(tc, sscanf_spec_s_4);
  tcase_add_test(tc, sscanf_spec_s_5);
  tcase_add_test(tc, sscanf_spec_s_6);
  tcase_add_test(tc, sscanf_spec_s_7);
  tcase_add_test(tc, sscanf_spec_s_8);
  //  tcase_add_test(tc, sscanf_spec_s_9);
  //  tcase_add_test(tc, sscanf_spec_s_10);
  tcase_add_test(tc, sscanf_spec_s_11);

  suite_add_tcase(s, tc);
  return s;
}
