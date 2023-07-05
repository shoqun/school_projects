#include <check.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix.h"

double generate_random_double(double min, double max);
Suite *test_matrix_eq(void);
Suite *test_matrix_create(void);
Suite *test_matrix_remove();
Suite *test_matrix_sum();
Suite *test_matrix_sub();
Suite *test_mult_matrix();
Suite *test_mult_number();
Suite *test_matrix_transpose();
Suite *test_matrix_determinant();
Suite *test_matrix_calc_complements();
Suite *test_inverse_matrix();
