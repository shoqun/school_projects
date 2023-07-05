#include "s21_matrix.h"

/*
короче, конкретный вопрос:

В  функции не нужно выделять память на структуру, но нужно выделять память на
матрицу, если ее нет?
```
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

    0 - OK
    1 - Ошибка, некорректная матрица
    2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
   нельзя провести вычисления и т.д.)

*/

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return 1;
  }
  result->matrix == NULL;
  if (A->columns != B->rows) {
    return 2;  // матрицы нельзя перемножить
  }

  if (s21_create_matrix(A->rows, B->columns, result) != 0) {
    return 1;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0.0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return 0;
}
