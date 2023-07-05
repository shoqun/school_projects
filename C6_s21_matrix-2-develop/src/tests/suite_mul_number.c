#include "s21_test.h"

START_TEST(matrix_mult_number_1) {
  matrix_t A;
  matrix_t result;
  matrix_t check;
  int m = 3;
  int k = 5;
  s21_create_matrix(m, k, &A);
  s21_create_matrix(m, k, &check);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      A.matrix[i][j] = i + j + 3.141592;
    }
  }
  double pi = 3.141592;
  ck_assert_int_eq(s21_mult_number(&A, pi, &result), 0);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      check.matrix[i][j] = (i + j + 3.141592) * pi;
    }
  }
  for (int i = 0; i < 3; i++) {
    // printf("%lf == %lf\n", result.matrix[i][0], check.matrix[i][0]);
  }
  ck_assert_int_eq(s21_eq_matrix(&result, &check), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(matrix_mult_number_2) {
  matrix_t A;
  matrix_t *result = NULL;
  ck_assert_int_eq(s21_mult_number(&A, 3.141414, result), 1);
}
END_TEST

START_TEST(matrix_mult_number_3) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(5, 6, &A);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      A.matrix[i][j] = i + j + 3.141592;
    }
  }

  ck_assert_int_eq(s21_mult_number(&A, 3.141414, &result), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_mult_number_4) {
  matrix_t A;
  matrix_t result;
  matrix_t check;
  result.matrix = NULL;

  int m = 3;
  int n = 1;
  int k = 5;
  s21_create_matrix(k, n, &A);

  s21_create_matrix(k, n, &check);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      A.matrix[i][j] = i + j + 3.141592;
    }
  }

  ck_assert_int_eq(s21_mult_number(&A, 3.141592, &result), 0);

  check.matrix[0][0] = 9.869600294464;
  check.matrix[1][0] = 13.011192294464;
  check.matrix[2][0] = 16.152784294464;
  check.matrix[3][0] = 19.294376294464;
  check.matrix[4][0] = 22.435968294464;
  // for (int i = 0; i < 3; i++) {
  //   printf("%.7lf == %.7lf\n", result.matrix[i][0], check.matrix[i][0]);
  // }
  ck_assert_int_eq(s21_eq_matrix(&result, &check), 1);

  s21_remove_matrix(&A);

  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(matrix_mult_number_5) {
  matrix_t A;

  matrix_t result;

  s21_create_matrix(5, 7, &A);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      A.matrix[i][j] = i + j + 3.141592;
    }
  }
  A.rows = 0;
  ck_assert_int_eq(s21_mult_number(&A, 3.1412, &result), 1);
  A.rows = 5;
  s21_remove_matrix(&A);

  // s21_remove_matrix(&result);
}
END_TEST

Suite *test_mult_number() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_MULT_NUMBER==\033[0m");
  TCase *tc = tcase_create("matrix_mul_tc");

  tcase_add_test(tc, matrix_mult_number_1);
  tcase_add_test(tc, matrix_mult_number_2);
  tcase_add_test(tc, matrix_mult_number_3);
  tcase_add_test(tc, matrix_mult_number_4);
  tcase_add_test(tc, matrix_mult_number_5);

  suite_add_tcase(s, tc);

  return s;
}
