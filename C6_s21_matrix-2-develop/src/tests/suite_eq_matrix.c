#include "s21_test.h"

START_TEST(matrix_eq_1) {
  matrix_t A;
  matrix_t B;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      double temp = rand() % 20;
      A.matrix[i][j] = temp + 0.1234567913;
      B.matrix[i][j] = temp + 0.12345676;
      // printf("%lf == %lf\n", A.matrix[i][j], B.matrix[i][j]);
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(matrix_eq_2) {
  matrix_t A;
  matrix_t B;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      A.matrix[i][j] = generate_random_double(-10, 10);
      B.matrix[i][j] = A.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(matrix_eq_3) {
  matrix_t A;
  matrix_t B;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      A.matrix[i][j] = generate_random_double(-10, 10);
      B.matrix[i][j] = generate_random_double(-10, 10);
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(matrix_eq_4) {
  matrix_t A;
  matrix_t B;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      A.matrix[i][j] = rand() % 20;
      B.matrix[i][j] = rand() % 30;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(matrix_eq_5) {
  matrix_t A;
  matrix_t B;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      A.matrix[i][j] = generate_random_double(-10 - j, 10 + j);
      B.matrix[i][j] = generate_random_double(-10 - j - i, 10 + i + j);
      // printf("%lf == %lf\n", A.matrix[i][j], B.matrix[i][j]);
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(matrix_eq_6) {
  matrix_t *A = NULL;
  matrix_t B;

  ck_assert_int_eq(s21_eq_matrix(A, &B), 0);
}
END_TEST

START_TEST(matrix_eq_7) {
  matrix_t A;
  matrix_t B;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  }
  A.rows = -2;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  A.rows = 5;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_matrix_eq(void) {
  Suite *s = suite_create("\033[44m==S21_MATRIX_EQUAL==\033[0m");
  TCase *tc = tcase_create("matrix_eq_tc");

  tcase_add_test(tc, matrix_eq_1);
  tcase_add_test(tc, matrix_eq_2);
  tcase_add_test(tc, matrix_eq_3);

  tcase_add_test(tc, matrix_eq_4);
  tcase_add_test(tc, matrix_eq_5);
  tcase_add_test(tc, matrix_eq_6);
  tcase_add_test(tc, matrix_eq_7);

  suite_add_tcase(s, tc);

  return s;
}
