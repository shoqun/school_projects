#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL) {
    return;  // Защита от передачи нулевого указателя
  }

  // ура, ремувать структуру не надо, так как непонятно, статическая она или
  // динамическая
  int i;
  // Освобождение памяти для каждой строки матрицы
  for (i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
    // A->matrix[i] = NULL;
  }
  free(A->matrix);

  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
  return;
}
