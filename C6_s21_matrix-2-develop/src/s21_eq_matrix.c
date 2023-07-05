#include "s21_matrix.h"

// Сравнение должно происходить вплоть до 7 знака после запятой включительно.

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    return FAILURE;
  }

  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }

  int i, j;
  for (i = 0; i < A->rows; i++) {
    for (j = 0; j < A->columns; j++) {
      if (compareDouble(A->matrix[i][j], B->matrix[i][j], 1e-7)) {  // fix it
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}
