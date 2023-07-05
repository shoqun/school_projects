#include "s21_matrix.h"
/*
    0 - OK
    1 - Ошибка выделения памяти
  */

// память уже должна быть выделена на result

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows <= 0 || columns <= 0) {
    return 1;
  }

  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (result->matrix == NULL) {  // проверка на успешное выделение памяти
    return 1;
  }

  for (int i = 0; i < rows; i++) {
    // выделение памяти для столбцов матрицы
    result->matrix[i] = calloc(columns, sizeof(double));
    result->rows = i + 1;  // приемлемо.
    // проверка на успешное выделение памяти
    if (result->matrix[i] == NULL) {
      // освобождение ранее выделенной памяти
      s21_remove_matrix(result);
      return 1;
    }
  }
  return 0;
}
