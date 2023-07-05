#include "s21_test.h"

START_TEST(test_matrix_determinant_1) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(3, 3, &A);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = i + j + 1;
    }
  }
  A.matrix[2][2] = 10;

  int res = s21_determinant(&A, &det);

  ck_assert_double_eq(det, -5);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_matrix_determinant_2) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(3, 3, &A);

  int k = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  A.matrix[2][2] = 10;
  int res = s21_determinant(&A, &det);

  ck_assert_double_eq(det, -3);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_matrix_determinant_3) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(3, 3, &A);

  int k = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }

  int res = s21_determinant(&A, &det);

  ck_assert_double_eq(det, 0);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_matrix_determinant_4) {
  matrix_t *A = NULL;
  double det = 0;
  int res = s21_determinant(A, &det);

  ck_assert_int_eq(res, 1);
}
END_TEST
START_TEST(test_matrix_determinant_5) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(4, 5, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_matrix_determinant_6) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 5;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 6;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 10;
  A.matrix[2][3] = 2;

  A.matrix[3][0] = 4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 11;

  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(det, -55);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_matrix_determinant_7) {
  matrix_t *A = (matrix_t *)malloc(sizeof(matrix_t) * 10);

  double det = 0.0;
  s21_create_matrix(6, 6, A);

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

  int res = s21_determinant(A, &det);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(A);
  free(A);
}
END_TEST
START_TEST(test_matrix_determinant_8) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(5, 3, &A);

  int k = 1;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }

  int res = s21_determinant(&A, &det);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST

// базовый случай
START_TEST(test_matrix_determinant_9) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(2, 2, &A);

  int k = 2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }

  int res = s21_determinant(&A, &det);

  ck_assert_double_eq(det, -2);

  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
}
END_TEST

// базовейший случай
START_TEST(test_matrix_determinant_10) {
  matrix_t A = {0};
  double det = 0;
  s21_create_matrix(1, 1, &A);

  int k = 12;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }

  int res = s21_determinant(&A, &det);

  ck_assert_double_eq(det, 12);

  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
}
END_TEST

Suite *test_matrix_determinant() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_DETERMINANT==\033[0m");

  TCase *tc = tcase_create("test_matrix_determinant");

  tcase_add_test(tc, test_matrix_determinant_1);
  tcase_add_test(tc, test_matrix_determinant_2);
  tcase_add_test(tc, test_matrix_determinant_3);
  tcase_add_test(tc, test_matrix_determinant_4);
  tcase_add_test(tc, test_matrix_determinant_5);

  tcase_add_test(tc, test_matrix_determinant_6);
  tcase_add_test(tc, test_matrix_determinant_7);
  tcase_add_test(tc, test_matrix_determinant_8);
  tcase_add_test(tc, test_matrix_determinant_9);
  tcase_add_test(tc, test_matrix_determinant_10);

  suite_add_tcase(s, tc);

  return s;
}
//  for(int i = 0; i < 3; i++) {
//   for (int j = 0; j < 3; j++) {
//     printf("%2lf ",A.matrix[i][j]);
//   }
//   printf("\n");
// }
