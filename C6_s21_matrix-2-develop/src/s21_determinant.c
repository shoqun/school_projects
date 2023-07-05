#include "s21_matrix.h"

/*

    0 - OK
    1 - Ошибка, некорректная матрица
    2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
   нельзя провести вычисления и т.д.)

*/

int s21_determinant(matrix_t *A, double *result) {
  // Проверка на корректные аргументы
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return 1;  // Возвращаем код ошибки
  }
  // Проверка на квадратную матрицу и размерность
  if (A->rows != A->columns || A->rows <= 0 || A->columns <= 0) {
    return 2;  // Возвращаем код ошибки
  }

  *result = 0.0;

  // Базовый случай - матрица 2x2
  if (A->rows == 2 && A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return 0;  // Возвращаем успешный результат
  }
  // Базовейший случай - матрица 1x1
  if (A->rows == 1 && A->columns == 1) {
    *result = A->matrix[0][0];
    return 0;
  }

  // Иначе, рекурсивно вычисляем определитель через разложение по первому
  // столбцу
  // *result = 0.0;
  double sign = 1.0;
  for (int i = 0; i < A->rows; i++) {
    // Создание временной матрицы без первого столбца
    matrix_t temp = {0};
    int is_created = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
    if (is_created == 1) {
      return 1;
    }
    // Заполнение временной матрицы значениями из матрицы A без первого столбца
    int temp_i = 0;
    for (int a = 0; a < A->rows; a++) {
      if (a == i) {
        continue;  // Пропускаем текущую строку
      }
      for (int b = 1; b < A->columns; b++) {
        temp.matrix[temp_i][b - 1] = A->matrix[a][b];
      }
      temp_i++;
    }

    // Рекурсивно вычисляем определитель временной матрицы
    double sub_det = 0.0;
    // Рекурсивный вызов функции для вычисления определителя
    s21_determinant(&temp, &sub_det);

    // Обновляем результат с учетом знака и подматрицы
    *result += sign * A->matrix[i][0] * sub_det;
    sign *= -1.0;

    // Освобождение памяти, выделенной для временной матрицы
    s21_remove_matrix(&temp);
  }

  return 0;  // Возвращаем успешный результат
}
