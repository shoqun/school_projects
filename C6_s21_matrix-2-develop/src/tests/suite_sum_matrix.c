#include "s21_test.h"

START_TEST(test_sum_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t perfection;

  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows + 1, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(5, 5, &perfection);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j + 0.3232129923;
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&A, &B, result), 2);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      perfection.matrix[i][j] = 2 * (i + j) + 0.3232129910;
      // printf("%lf == %lf\n", result->matrix[i][j], perfection.matrix[i][j]);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(result, &perfection), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&perfection);
  s21_remove_matrix(result);

  free(result);
}
END_TEST

//Важно помнить, что если память была выделена в функции, то ответственность за
//ее освобождение обычно лежит на вызывающей стороне.
START_TEST(test_sum_matrix_1_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  result.matrix = NULL;
  matrix_t perfection;

  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  // s21_create_matrix(rows,columns, &result);
  s21_create_matrix(rows, columns, &perfection);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j + 0.3232129923;
    }
    // res = x+x+y = 2x+y
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      perfection.matrix[i][j] = 2 * (i + j) + 0.3232129910;
      // printf("%lf == %lf\n", result.matrix[i][j], perfection.matrix[i][j]);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&result, &perfection), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&perfection);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_matrix_1_2) {
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
  ck_assert_int_eq(s21_sum_matrix(&A, &B, result), 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      perfection.matrix[i][j] = 2 * (i + j) + 0.3232129910;
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

START_TEST(test_sum_matrix_2) {
  matrix_t *A = NULL;
  matrix_t B;
  matrix_t *result = NULL;

  ck_assert_int_eq(s21_sum_matrix(A, &B, result), 1);
}
END_TEST

START_TEST(test_sum_matrix_3) {
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
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_4) {
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

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 0;
  check.matrix[1][0] = 0;
  check.matrix[1][1] = 0;
  check.matrix[2][0] = 0;
  check.matrix[2][1] = 0;
  check.matrix[3][0] = 0;
  check.matrix[3][1] = 12;

  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// 1,2 && 2,1 error 2
// A == NULL error 1

Suite *test_matrix_sum() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_SUMMIRIZE==\033[0m");
  TCase *tc = tcase_create("matrix_eq_tc");

  tcase_add_test(tc, test_sum_matrix_1);
  tcase_add_test(tc, test_sum_matrix_1_1);
  tcase_add_test(tc, test_sum_matrix_1_2);
  tcase_add_test(tc, test_sum_matrix_2);
  tcase_add_test(tc, test_sum_matrix_3);
  tcase_add_test(tc, test_sum_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}
