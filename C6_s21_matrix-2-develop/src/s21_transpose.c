#include "s21_matrix.h"

/*
    0 - OK
    1 - Ошибка, некорректная матрица
    2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
   нельзя провести вычисления и т.д.)

   если A->matrix == NULL, то тут надо вернуть ошибку, но если нулл в
   create_matrix? память выделить для A, я не смогу, но выделить память для
   матрицы, можно. Здесь это бесполезно но в других ф-циях...
*/

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return 1;
  }

  if (s21_create_matrix(A->columns, A->rows, result) != 0) {
    return 1;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] =
          A->matrix[i][j];  // Записываем элементы в транспонированную матрицу
    }
  }
  return 0;
}
