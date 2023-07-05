#include "s21_matrix.h"

/*
    0 - OK
    1 - Ошибка, некорректная матрица
    2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
    нельзя провести вычисления и т.д.)
  */

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (result == NULL || A == NULL || A->rows <= 0 || A->columns <= 0) {
    return 1;
  }
  // result->matrix == NULL;

  if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    return 1;
  }

  int i, j;
  for (i = 0; i < A->rows; i++) {
    for (j = 0; j < A->columns; j++) {
      result->matrix[i][j] = number * A->matrix[i][j];  //
    }
  }

  return 0;
}
