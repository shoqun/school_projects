#include "s21_test.h"

START_TEST(test_inverse_matrix_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  // 3x3
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 5;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 9;
  A.matrix[1][2] = 8;

  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 11;

  int res = s21_inverse_matrix(&A, &result);
  check.matrix[0][0] = -19. / 24;
  check.matrix[0][1] = -0.25;
  check.matrix[0][2] = 13. / 24;

  check.matrix[1][0] = -0.25;
  check.matrix[1][1] = 0.5;
  check.matrix[1][2] = -0.25;

  check.matrix[2][0] = 0.875;
  check.matrix[2][1] = -0.25;
  check.matrix[2][2] = -0.125;

  ck_assert_int_eq(res, 0);

  // for(int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     printf("%9.6lf ", result.matrix[i][j]);
  //   }
  //   printf("\n");
  // }
  //   printf("\n\n\n");

  // for(int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     if (result.matrix[i][j]==check.matrix[i][j])
  //     printf("1 ");
  //     else
  //     printf("0 ");
  //   }
  //   printf("\n");
  // }
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(test_inverse_matrix_2) {
  matrix_t *A = (matrix_t *)malloc(sizeof(matrix_t) * 10);

  matrix_t check = {0};
  matrix_t *result = (matrix_t *)malloc(sizeof(matrix_t) * 10);
  // if (A == NULL) {
  //   return 1;
  // }
  double det = 0.0;
  // 6x6
  s21_create_matrix(6, 6, A);
  s21_create_matrix(6, 6, &check);
  // s21_create_matrix(6, 6, result);

  A->matrix[0][0] = 1;
  A->matrix[0][1] = 2;
  A->matrix[0][2] = 3;
  A->matrix[0][3] = 5;
  A->matrix[0][4] = 4;
  A->matrix[0][5] = 22;

  A->matrix[1][0] = 2;
  A->matrix[1][1] = 3;
  A->matrix[1][2] = 4;
  A->matrix[1][3] = 6;
  A->matrix[1][4] = 2;
  A->matrix[1][5] = 3;

  A->matrix[2][0] = 3;
  A->matrix[2][1] = 4;
  A->matrix[2][2] = 10;
  A->matrix[2][3] = 2;
  A->matrix[2][4] = 4;
  A->matrix[2][5] = 22;

  A->matrix[3][0] = 4;
  A->matrix[3][1] = 3;
  A->matrix[3][2] = 2;
  A->matrix[3][3] = 11;
  A->matrix[3][4] = 4;
  A->matrix[3][5] = 22;

  A->matrix[4][0] = -5;
  A->matrix[4][1] = 5;
  A->matrix[4][2] = -5;
  A->matrix[4][3] = 5;
  A->matrix[4][4] = -5;
  A->matrix[4][5] = 5;

  A->matrix[5][0] = 22;
  A->matrix[5][1] = 44;
  A->matrix[5][2] = 33;
  A->matrix[5][3] = 22;
  A->matrix[5][4] = 11;
  A->matrix[5][5] = 22;

  check.matrix[0][0] = -204050;
  check.matrix[0][1] = -169620;
  check.matrix[0][2] = 51865;
  check.matrix[0][3] = 174790;
  check.matrix[0][4] = -32406;
  check.matrix[0][5] = 7890;

  check.matrix[1][0] = 101200;
  check.matrix[1][1] = -52965;
  check.matrix[1][2] = -63745;
  check.matrix[1][3] = -54945;
  check.matrix[1][4] = 12793;
  check.matrix[1][5] = 21805;

  check.matrix[2][0] = -78375;
  check.matrix[2][1] = 111705;
  check.matrix[2][2] = 96140;
  check.matrix[2][3] = -23210;
  check.matrix[2][4] = 12529;
  check.matrix[2][5] = -12635;

  check.matrix[3][0] = -35750;
  check.matrix[3][1] = 112255;
  check.matrix[3][2] = 715;
  check.matrix[3][3] = 25740;
  check.matrix[3][4] = 16159;
  check.matrix[3][5] = -9685;

  check.matrix[4][0] = 335225;
  check.matrix[4][1] = 75295;
  check.matrix[4][2] = -186890;
  check.matrix[4][3] = -157740;
  check.matrix[4][4] = -72479;
  check.matrix[4][5] = 15610;

  check.matrix[5][0] = -12650;
  check.matrix[5][1] = -41910;
  check.matrix[5][2] = 24145;
  check.matrix[5][3] = 23045;
  check.matrix[5][4] = 8107;
  check.matrix[5][5] = -1255;

  int res = s21_calc_complements(A, result);

  // printf("res = %d, %d, %d\n", res, result->rows, result->columns);
  // printf("A->rows = %d, %d\n",  A->rows, A->columns);
  matrix_t result1 = {0};
  ck_assert_int_eq(res, 0);

  res = s21_transpose(result, &result1);

  ck_assert_int_eq(res, 0);

  res = s21_eq_matrix(&result1, &check);

  ck_assert_int_eq(res, SUCCESS);

  s21_remove_matrix(A);
  s21_remove_matrix(&result1);
  s21_remove_matrix(result);
  s21_remove_matrix(&check);

  free(A);
  free(result);
}
START_TEST(test_inverse_matrix_3) {
  matrix_t A;

  s21_create_matrix(3, 3, &A);
  int k = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  matrix_t result;
  int res = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&result);
}
END_TEST
START_TEST(test_inverse_matrix_4) {
  matrix_t A;

  s21_create_matrix(3, 3, &A);
  int k = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  A.matrix[0][1] = 3;
  matrix_t result;
  matrix_t check;
  int res = s21_inverse_matrix(&A, &result);
  s21_create_matrix(3, 3, &check);
  ck_assert_int_eq(res, 0);

  check.matrix[0][0] = -0.5;
  check.matrix[0][1] = -0.5;
  check.matrix[0][2] = 0.5;

  check.matrix[1][0] = 1;
  check.matrix[1][1] = -2;
  check.matrix[1][2] = 1;

  check.matrix[2][0] = -0.5;
  check.matrix[2][1] = 13. / 6;
  check.matrix[2][2] = -7. / 6;

  res = s21_eq_matrix(&result, &check);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(test_inverse_matrix_5) {
  matrix_t A = {0};
  matrix_t *result = NULL;

  s21_create_matrix(3, 3, &A);

  int res = s21_inverse_matrix(&A, result);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_inverse_matrix_6) {
  matrix_t *A = NULL;
  matrix_t result = {0};

  s21_create_matrix(3, 3, &result);

  int res = s21_inverse_matrix(A, &result);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&result);
}
END_TEST
Suite *test_inverse_matrix() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_INVERSE==\033[0m");

  TCase *tc = tcase_create("test_inverse_matrix");

  tcase_add_test(tc, test_inverse_matrix_1);
  tcase_add_test(tc, test_inverse_matrix_2);
  tcase_add_test(tc, test_inverse_matrix_3);
  tcase_add_test(tc, test_inverse_matrix_4);
  tcase_add_test(tc, test_inverse_matrix_5);
  tcase_add_test(tc, test_inverse_matrix_6);

  suite_add_tcase(s, tc);

  return s;
}
