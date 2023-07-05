#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return 1;
  }

  matrix_t complements = {0};

  int flag[4] = {-1, -1, -1, -1};
  double det = 0.0;

  flag[0] = s21_determinant(A, &det);

  if (flag[0] != 0) {  // важно
    return flag[0];
  }

  if (det == 0) {
    return 2;
  }

  flag[1] = s21_calc_complements(A, &complements);

  if (flag[1] != 0) {
    return flag[1];
  }
  // если ошибка, матрица complements не создается
  matrix_t transpose = {0};
  if (flag[1] == 0) {
    flag[2] = s21_transpose(&complements, &transpose);
    // printf("flag[2] = %d\n", flag[2]);
    s21_remove_matrix(&complements);
  }
  if (flag[2] != 0) {
    return 1;
  }
  if (flag[2] == 0) {
    flag[3] = s21_mult_number(&transpose, 1.0 / det, result);
    s21_remove_matrix(&transpose);
  }
  return flag[3];
}
