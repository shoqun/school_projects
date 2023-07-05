#include "s21_test.h"

START_TEST(test_matrix_calc_complements_1) {
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

  int res = s21_calc_complements(&A, &result);
  check.matrix[0][0] = 19;
  check.matrix[0][1] = 6;
  check.matrix[0][2] = -21;

  check.matrix[1][0] = 6;
  check.matrix[1][1] = -12;
  check.matrix[1][2] = 6;

  check.matrix[2][0] = -13;
  check.matrix[2][1] = 6;
  check.matrix[2][2] = 3;

  ck_assert_int_eq(res, 0);

  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(test_matrix_calc_complements_2) {
  matrix_t *A = (matrix_t *)malloc(sizeof(matrix_t) * 10);
  matrix_t *result = (matrix_t *)malloc(sizeof(matrix_t) * 10);
  matrix_t check = {0};

  double det = 0.0;
  // 6x6
  s21_create_matrix(6, 6, A);
  s21_create_matrix(6, 6, &check);

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
  check.matrix[0][1] = 101200;
  check.matrix[0][2] = -78375;
  check.matrix[0][3] = -35750;
  check.matrix[0][4] = 335225;
  check.matrix[0][5] = -12650;

  check.matrix[1][0] = -169620;
  check.matrix[1][1] = -52965;
  check.matrix[1][2] = 111705;
  check.matrix[1][3] = 112255;
  check.matrix[1][4] = 75295;
  check.matrix[1][5] = -41910;

  check.matrix[2][0] = 51865;
  check.matrix[2][1] = -63745;
  check.matrix[2][2] = 96140;
  check.matrix[2][3] = 715;
  check.matrix[2][4] = -186890;
  check.matrix[2][5] = 24145;

  check.matrix[3][0] = 174790;
  check.matrix[3][1] = -54945;
  check.matrix[3][2] = -23210;
  check.matrix[3][3] = 25740;
  check.matrix[3][4] = -157740;
  check.matrix[3][5] = 23045;

  check.matrix[4][0] = -32406;
  check.matrix[4][1] = 12793;
  check.matrix[4][2] = 12529;
  check.matrix[4][3] = 16159;
  check.matrix[4][4] = -72479;
  check.matrix[4][5] = 8107;

  check.matrix[5][0] = 7890;
  check.matrix[5][1] = 21805;
  check.matrix[5][2] = -12635;
  check.matrix[5][3] = -9685;
  check.matrix[5][4] = 15610;
  check.matrix[5][5] = -1255;

  int res = s21_calc_complements(A, result);

  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(result, &check);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(A);
  s21_remove_matrix(&check);
  s21_remove_matrix(result);
  free(A);
  free(result);
}
END_TEST
START_TEST(test_matrix_calc_complements_3) {
  matrix_t *A = NULL;
  matrix_t result;
  int res = s21_calc_complements(A, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST
START_TEST(test_matrix_calc_complements_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &A);
  A.rows = 1;
  A.columns = 0;
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, 1);
  A.rows = 3;
  A.columns = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST
START_TEST(test_matrix_calc_complements_5) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 4, &A);

  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

// базовейший случай
START_TEST(test_matrix_calc_complements_6) {
  matrix_t result = {0};
  matrix_t A = {0};
  matrix_t check = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);

  int k = 12;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }

  check.matrix[0][0] = 12;

  int res = s21_calc_complements(&A, &result);

  ck_assert_int_eq(res, 0);

  res = s21_eq_matrix(&result, &check);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// базовый случай
START_TEST(test_matrix_calc_complements_7) {
  matrix_t result = {0};
  matrix_t A = {0};
  matrix_t check = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);

  int k = 2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  check.matrix[0][0] = 5;
  check.matrix[0][1] = -4;
  check.matrix[1][0] = -3;
  check.matrix[1][1] = 2;
  int res = s21_calc_complements(&A, &result);

  ck_assert_int_eq(res, 0);

  res = s21_eq_matrix(&result, &check);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// matrix is not square
START_TEST(test_matrix_calc_complements_8) {
  matrix_t A = {0};
  matrix_t result;
  s21_create_matrix(2, 3, &A);

  int k = 2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  A.matrix[0][2] = 2;
  A.matrix[1][2] = 3;

  int res = s21_calc_complements(&A, &result);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST

Suite *test_matrix_calc_complements() {
  Suite *s = suite_create("\033[44m==S21_CALC_COMPLEMENTS==\033[0m");

  TCase *tc = tcase_create("test_matrix_determinant");

  tcase_add_test(tc, test_matrix_calc_complements_1);
  tcase_add_test(tc, test_matrix_calc_complements_2);
  tcase_add_test(tc, test_matrix_calc_complements_3);
  tcase_add_test(tc, test_matrix_calc_complements_4);
  tcase_add_test(tc, test_matrix_calc_complements_5);
  tcase_add_test(tc, test_matrix_calc_complements_6);
  tcase_add_test(tc, test_matrix_calc_complements_7);
  tcase_add_test(tc, test_matrix_calc_complements_8);

  suite_add_tcase(s, tc);

  return s;
}
