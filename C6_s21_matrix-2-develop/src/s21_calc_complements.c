#include "s21_matrix.h"

/*
   0 - OK
   1 - Ошибка, некорректная матрица
   2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
  нельзя провести вычисления и т.д.)
*/

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return 1;
  }
  if (A->rows <= 0 || A->columns <= 0) {
    return 1;  // Ошибка размеров матрицы A
  }

  if (A->rows != A->columns) {
    return 2;  // Ошибка: матрица A не квадратная
  }

  int flag = s21_create_matrix(A->rows, A->columns, result);
  if (flag == 1) {
    return 1;
  }

  // база
  if (A->rows == 1 && A->columns == 1) {
    result->matrix[0][0] = A->matrix[0][0];
    return 0;
  }

  matrix_t minor = {0};
  if (s21_create_minor_matrix(A, &minor) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = minor.matrix[i][j] * pow(-1, i + j);
      }
    }
    s21_remove_matrix(&minor);
  } else {
    s21_remove_matrix(result);
    return 1;
  }
  return 0;
}

/*

  Эта функция создает матрицу миноров для заданной матрицы `A`. Каждый элемент
  матрицы миноров представляет собой определитель подматрицы, полученной из
  матрицы `A` путем удаления одной строки и одного столбца. Результат
  сохраняется в матрице `result`.

*/
int s21_create_minor_matrix(matrix_t *A, matrix_t *result) {
  // Выделение памяти для матрицы миноров
  int flag = s21_create_matrix(A->rows, A->columns, result);
  if (flag) {
    return 1;  // Ошибка выделения памяти
  }
  // Вычисление миноров для каждого элемента матрицы A
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      // Вычисление минора элемента A[i][j]
      matrix_t minor;
      if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor) == 0) {
        // Копирование подматрицы без i-й строки и j-го столбца в minor
        int row_offset = 0;
        for (int row = 0; row < A->rows; row++) {
          if (row == i) {
            row_offset = -1;
            continue;
          }
          int col_offset = 0;
          for (int col = 0; col < A->columns; col++) {
            if (col == j) {
              col_offset = -1;
              continue;
            }
            minor.matrix[row + row_offset][col + col_offset] =
                A->matrix[row][col];
          }
        }
        // Вычисление определителя подматрицы
        double minor_det;
        int err = 0;
        if ((err = s21_determinant(&minor, &minor_det)) == 0) {
          result->matrix[i][j] = minor_det;
        } else {
          // Ошибка вычисления определителя
          // Нужно освободить ранее выделенную память
          s21_remove_matrix(&minor);
          s21_remove_matrix(result);
          return err;
        }
        // Освобождение памяти подматрицы
        s21_remove_matrix(&minor);
      } else {
        // Ошибка создания подматрицы
        // Нужно освободить ранее выделенную память
        s21_remove_matrix(result);
        return 1;
      }
    }
  }
  return 0;  // Успешное выполнение функции
}
