#include "s21_matrix.h"

/*
  0 - OK
  1 - Invalid
*/

// int is_valid_matrix(matrix_t *A) {
//   if (A == NULL || A->rows <= 0 || A->columns <= 0) {
//     return 1;
//   }
//   return 0;
// }

int compareDouble(double a, double b, double precision) {
  double precision1 = 1.0 / precision;                   // 1e7
  double roundedA = round(a * precision1) / precision1;  // 32.23455678
  double roundedB = round(b * precision1) / precision1;  // 32.23455678

  if (fabs(roundedA - roundedB) <= precision) {
    // Числа равны с точностью до 7-го знака после запятой
    return 0;
  } else {
    return 1;
  }
}
