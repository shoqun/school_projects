#ifndef _S21_MATRIX_
#define _S21_MATRIX_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);  // valgrind

void s21_remove_matrix(matrix_t *A);  // valgrind wtf

// chec1 = 1 раз проверил
// checked, need tests
// NEED check
// -

#define SUCCESS 1
#define FAILURE 0
int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // chec1

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // NEED check

int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  // NEED check

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // NEED check

int s21_transpose(matrix_t *A, matrix_t *result);  // NEED check

int s21_determinant(matrix_t *A, double *result);  // -

int s21_create_minor_matrix(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);  // -

int s21_inverse_matrix(matrix_t *A, matrix_t *result);  // -

int compareDouble(double a, double b, double precision);

// int is_valid_matrix(matrix_t *A);

#endif  // _S21_MATRIX_
