#include "s21_test.h"

START_TEST(matrix_mult_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t check;
  int m = 3;
  int n = 1;
  int k = 5;
  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);
  s21_create_matrix(m, n, &check);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      A.matrix[i][j] = i + j + 3.141592;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      B.matrix[i][j] = i + j + 3.141592;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  check.matrix[0][0] = 142.17984147232;
  check.matrix[1][0] = 167.88780147232;
  check.matrix[2][0] = 193.59576147232;
  for (int i = 0; i < 3; i++) {
    // printf("%lf == %lf\n", result.matrix[i][0], check.matrix[i][0]);
  }
  ck_assert_int_eq(s21_eq_matrix(&result, &check), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(matrix_mult_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t *result = NULL;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, result), 1);
}
END_TEST

START_TEST(matrix_mult_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(5, 6, &A);
  s21_create_matrix(5, 6, &B);
  // s21_create_matrix(5, 6, &result);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      B.matrix[i][j] = i + j + 3.141592;
      A.matrix[i][j] = i + j + 3.141592;
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_mult_matrix_4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t check;
  result.matrix = NULL;

  int m = 3;
  int n = 1;
  int k = 5;
  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);
  s21_create_matrix(m, n, &check);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      A.matrix[i][j] = i + j + 3.141592;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      B.matrix[i][j] = i + j + 3.141592;
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);

  check.matrix[0][0] = 142.17984147232;
  check.matrix[1][0] = 167.88780147232;
  check.matrix[2][0] = 193.59576147232;
  // for (int i = 0; i < 3; i++) {
  //   printf("%.7lf == %.7lf\n", result.matrix[i][0], check.matrix[i][0]);
  // }
  ck_assert_int_eq(s21_eq_matrix(&result, &check), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(matrix_mult_matrix_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(5, 7, &A);
  s21_create_matrix(6, 1, &B);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      A.matrix[i][j] = i + j + 3.141592;
      B.matrix[i][0] = i + j + 3.141592;
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&result);
}
END_TEST

Suite *test_mult_matrix() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_MULTIPLY==\033[0m");
  TCase *tc = tcase_create("matrix_mul_tc");

  tcase_add_test(tc, matrix_mult_matrix_1);
  tcase_add_test(tc, matrix_mult_matrix_2);
  tcase_add_test(tc, matrix_mult_matrix_3);
  tcase_add_test(tc, matrix_mult_matrix_4);
  tcase_add_test(tc, matrix_mult_matrix_5);

  suite_add_tcase(s, tc);

  return s;
}
