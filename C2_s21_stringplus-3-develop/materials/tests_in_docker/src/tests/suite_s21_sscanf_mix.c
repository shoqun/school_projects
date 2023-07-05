#include "s21_test.h"

START_TEST(sscanf_empty_1) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_2) {
  char format[] = "%d";
  char str[] = "     ";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_3) {
  char format[] = "%d";
  char str[] = "\n";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_4) {
  char format[] = "%d";
  char str[] = "\t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_5) {
  char format[] = "%d";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_6) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_7) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_8) {
  char format[] = "%d%d";
  char str[] = "4";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_9) {
  char format[] = "%s";
  char str[] = "";
  char s1[30] = {""}, s2[30] = {""};

  int16_t res1 = s21_sscanf(str, format, &s1);
  int16_t res2 = sscanf(str, format, &s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_empty_10) {
  char format[] = "%c";
  char str[] = "";
  char c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_empty_11) {
  char format[] = "%3c";
  char str[] = "123";
  char s1[50] = {'\0'}, s2[50] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, s1);
  int16_t res2 = sscanf(str, format, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_empty_12) {
  char format[] = "%3c";
  char str[] = "";
  char s1[50] = {'\0'}, s2[50] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, s1);
  int16_t res2 = sscanf(str, format, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_empty_13) {
  char format[] = "%*3c";
  char str[] = "";
  char s1[50] = {'\0'}, s2[50] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, s1);
  int16_t res2 = sscanf(str, format, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_empty_14) {
  char format[] = "%lc";
  char str[] = "";
  wchar_t c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_empty_15) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(sscanf_junk_1) {
//   char format[] = "%3j";
//   char str[] = "1";
//   char s1[50] = {'\0'}, s2[50] = {'\0'};
//
//   int16_t res1 = s21_sscanf(str, format, s1);
//   int16_t res2 = sscanf(str, format, s2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_pstr_eq(s1, s2);
// }
// END_TEST

START_TEST(sscanf_junk_2) {
  char format[] = "%%%c";
  char str[] = "x";
  char c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

Suite *suite_s21_sscanf_mix(void) {
  Suite *s = suite_create("\033[42m-=s21_scanf_mix=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_empty_1);
  tcase_add_test(tc, sscanf_empty_2);
  tcase_add_test(tc, sscanf_empty_3);
  tcase_add_test(tc, sscanf_empty_4);
  tcase_add_test(tc, sscanf_empty_5);
  tcase_add_test(tc, sscanf_empty_6);
  tcase_add_test(tc, sscanf_empty_7);
  tcase_add_test(tc, sscanf_empty_8);
  tcase_add_test(tc, sscanf_empty_9);
  tcase_add_test(tc, sscanf_empty_10);
  tcase_add_test(tc, sscanf_empty_11);
  tcase_add_test(tc, sscanf_empty_12);
  tcase_add_test(tc, sscanf_empty_13);
  tcase_add_test(tc, sscanf_empty_14);
  tcase_add_test(tc, sscanf_empty_15);
  //  tcase_add_test(tc, sscanf_junk_1);
  tcase_add_test(tc, sscanf_junk_2);
  suite_add_tcase(s, tc);
  return s;
}
