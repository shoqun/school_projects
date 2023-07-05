#include "s21_matrix.h"

/*
    0 - OK
    1 - Ошибка, некорректная матрица
    2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
    нельзя провести вычисления и т.д.)
  */

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL) {
    return 1;
  }

  result->matrix = NULL;
  if (A->rows <= 0 || A->columns <= 0) {
    return 1;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return 2;
  }

  if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    return 1;
  }

  int i, j;
  for (i = 0; i < result->rows; i++) {
    for (j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return 0;
}
