#include "s21_test.h"

START_TEST(matrix_remove_1) {
  matrix_t *A = malloc(sizeof(matrix_t));
  // matrix_t A;
  int rows = 10;
  int columns = 10;

  s21_create_matrix(rows, columns, A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A->matrix[i][j] = i + j;
    }
  }
  // заглушка нужна почему-то
  s21_remove_matrix(A);
  // free(A);
  ck_assert_ptr_null(A->matrix);
  free(A);
}
END_TEST

START_TEST(matrix_remove_2) {
  matrix_t *A = NULL;

  s21_remove_matrix(A);
  ck_assert_ptr_null(A);
}
END_TEST

Suite *test_matrix_remove() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_REMOVE==\033[0m");
  TCase *tc = tcase_create("matrix_eq_tc");

  tcase_add_test(tc, matrix_remove_1);
  tcase_add_test(tc, matrix_remove_2);

  suite_add_tcase(s, tc);
  return s;
}
