#include "s21_test.h"

START_TEST(test_sub_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t perfection;

  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(5, 5, &perfection);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j + 0.3232129923;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&B, &A, &result), 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      perfection.matrix[i][j] = 0.3232129923;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&result, &perfection), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&perfection);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_matrix_2) {
  matrix_t *A = NULL;
  matrix_t B;
  matrix_t *result = NULL;

  ck_assert_int_eq(s21_sub_matrix(A, &B, result), 1);
}
END_TEST

START_TEST(test_sub_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  B.matrix[2][0] = 5;
  B.matrix[2][1] = 6;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST
START_TEST(test_sub_matrix_4) {
  matrix_t A;
  matrix_t B;
  matrix_t *result = malloc(sizeof(matrix_t));
  result->matrix = NULL;
  matrix_t perfection;

  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &perfection);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j + 0.3232129923;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&B, &A, result), 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      perfection.matrix[i][j] = 0.3232129910;
      // printf("%lf == %lf\n", result->matrix[i][j], perfection.matrix[i][j]);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(result, &perfection), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&perfection);
  s21_remove_matrix(result);

  free(result);
}
END_TEST
START_TEST(test_sub_matrix_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(4, 2, &A);
  s21_create_matrix(4, 2, &B);
  s21_create_matrix(4, 2, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -6;
  A.matrix[3][0] = 5;
  A.matrix[3][1] = 6;

  B.matrix[0][0] = -1;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = -3;
  B.matrix[1][1] = -4;
  B.matrix[2][0] = -5;
  B.matrix[2][1] = 6;
  B.matrix[3][0] = -5;
  B.matrix[3][1] = 6;

  check.matrix[0][0] = 2;
  check.matrix[0][1] = 4;
  check.matrix[1][0] = 6;
  check.matrix[1][1] = 8;
  check.matrix[2][0] = 10;
  check.matrix[2][1] = -12;
  check.matrix[3][0] = 10;
  check.matrix[3][1] = 0;

  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_matrix_sub() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_SUBSTRACTION==\033[0m");
  TCase *tc = tcase_create("matrix_eq_tc");

  tcase_add_test(tc, test_sub_matrix_1);
  tcase_add_test(tc, test_sub_matrix_2);
  tcase_add_test(tc, test_sub_matrix_3);
  tcase_add_test(tc, test_sub_matrix_4);
  tcase_add_test(tc, test_sub_matrix_5);

  suite_add_tcase(s, tc);

  return s;
}
