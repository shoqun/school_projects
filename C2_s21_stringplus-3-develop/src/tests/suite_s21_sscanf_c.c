#include "s21_test.h"

START_TEST(sscanf_spec_c_1) {
  char format[] = "%c";
  char str[] = "s";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n junk \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_3) {
  char format[] = "  \n\t%c\n\t  ";
  char str[] = "\t\n\n  123 \n\t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta and junk";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  12";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_7) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_8) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_spec_c_9) {
  char format[] = "%4c";
  char str[] = "123";
  char s1[5] = {'\0'}, s2[5] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, s1);
  int16_t res2 = sscanf(str, format, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_spec_c_10) {
  char format[] = "%10c";
  char str[] = "1234567890";
  char s1[50] = {'\0'}, s2[50] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, s1);
  int16_t res2 = sscanf(str, format, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_spec_c_11) {
  char format[] = "%30c";
  char str[] = "\t\n\n  123 \n so much junk \t and some more";
  char s1[50] = {'\0'}, s2[50] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, s1);
  int16_t res2 = sscanf(str, format, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_spec_c_12) {
  char format[] = "%30c %c";
  char str[] = "\t\n\n  123 \n so much junk \t and some more";
  char s1[50] = {'\0'}, s2[50] = {'\0'};
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, s1, &c1);
  int16_t res2 = sscanf(str, format, s2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_13) {
  char format[] = "%*4c %c ";
  char str[] = "0123456789abc def g";
  char c1 = {'\0'}, c2 = {'\0'};

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_14) {
  char format[] = "%*4c %c %s";
  char str[] = "0123456789abc def g";
  char s1[50] = {'\0'}, s2[50] = {'\0'};

  char c1 = {'\0'}, c2 = {'\0'};

  int16_t res1 = s21_sscanf(str, format, &c1, s1);
  int16_t res2 = sscanf(str, format, &c2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

// START_TEST(sscanf_spec_c_15) {
//   char format[] = "%hc";
//   char str[] = "s";
//   char c1, c2;
//
//   int16_t res1 = s21_sscanf(str, format, &c1);
//   int16_t res2 = sscanf(str, format, &c2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(c1, c2);
// }
// END_TEST

START_TEST(sscanf_spec_c_16) {
  char format[] = "%lc";
  char str[] = "x";
  wchar_t c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

// START_TEST(sscanf_spec_c_17) {
//   char format[] = "%Lc";
//   char str[] = "s";
//   char c1, c2;
//
//   int16_t res1 = s21_sscanf(str, format, &c1);
//   int16_t res2 = sscanf(str, format, &c2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(c1, c2);
// }
// END_TEST

START_TEST(sscanf_spec_c_18) {
  char format[] = "%*4c";
  char str[] = "123";
  char s1[5] = {'\0'}, s2[5] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, s1);
  int16_t res2 = sscanf(str, format, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

Suite *suite_s21_sscanf_c(void) {
  Suite *s = suite_create("\033[42m-=s21_scanf_c=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_c_1);
  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_3);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);
  tcase_add_test(tc, sscanf_spec_c_6);
  tcase_add_test(tc, sscanf_spec_c_7);
  tcase_add_test(tc, sscanf_spec_c_8);
  tcase_add_test(tc, sscanf_spec_c_9);
  tcase_add_test(tc, sscanf_spec_c_10);
  tcase_add_test(tc, sscanf_spec_c_11);
  tcase_add_test(tc, sscanf_spec_c_12);
  tcase_add_test(tc, sscanf_spec_c_13);
  tcase_add_test(tc, sscanf_spec_c_14);
  //  tcase_add_test(tc, sscanf_spec_c_15);
  tcase_add_test(tc, sscanf_spec_c_16);
  //  tcase_add_test(tc, sscanf_spec_c_17);
  tcase_add_test(tc, sscanf_spec_c_18);
  suite_add_tcase(s, tc);
  return s;
}
