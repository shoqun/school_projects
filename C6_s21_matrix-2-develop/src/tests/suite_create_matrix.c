#include "s21_test.h"

START_TEST(matrix_create_1) {
  matrix_t A;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 0);

  ck_assert_ptr_nonnull(&A.matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_ptr_nonnull(&A.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(matrix_create_2) {
  matrix_t A;
  int rows = -2;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 1);

  // s21_remove_matrix(&A);
}
END_TEST

Suite *test_matrix_create() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_CREATE==\033[0m");
  TCase *tc = tcase_create("matrix_eq_tc");

  tcase_add_test(tc, matrix_create_1);
  tcase_add_test(tc, matrix_create_2);

  suite_add_tcase(s, tc);
  return s;
}