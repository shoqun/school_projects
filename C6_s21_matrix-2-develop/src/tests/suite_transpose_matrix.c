#include "s21_test.h"

START_TEST(test_matrix_transpose_1) {
  int res = 0;
  matrix_t A = {0};

  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_matrix_transpose_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      A.matrix[i][j] = i + j;
    }
  }
  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_matrix_transpose_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t *B = NULL;

  res = s21_transpose(&A, B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

// вопросики надо сюда выкатить, а завтра Сереже написать и/или в рокетчате
/*
  вопросы которые не разрешаются никак.
  Как должен подаваться массив result: уже инициализированным или я
  инициализирую в функции. А если пользователь уже положит в функцию матрицу с
  выделенной памятью, а у меня она перевыделит, такое надо как-то рассматривать.

  например в s21_transpose(&A, &B); массив B вне функции выделен динамически:
  B.matrix = malloc(rows,sizeof(double*)) и так далее. или так не будет в
  проверке?

*/
START_TEST(test_matrix_transpose_4_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_matrix_transpose_4_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_matrix_transpose_5) {
  int res = 0;
  matrix_t A = {0};
  matrix_t T = {0};
  matrix_t B = {0};

  s21_create_matrix(2, 3, &A);
  double num = 1.0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; num += 1.0, j++) {
      A.matrix[i][j] = num;
    }
  }
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;

  res = s21_transpose(&A, &T);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_matrix_transpose() {
  Suite *s = suite_create("\033[44m==S21_MATRIX_TRANSPOSE==\033[0m");
  TCase *tc = tcase_create("matrix_eq_tc");

  tcase_add_test(tc, test_matrix_transpose_1);
  tcase_add_test(tc, test_matrix_transpose_2);
  tcase_add_test(tc, test_matrix_transpose_3);
  tcase_add_test(tc, test_matrix_transpose_4_1);
  tcase_add_test(tc, test_matrix_transpose_4_2);
  tcase_add_test(tc, test_matrix_transpose_5);

  suite_add_tcase(s, tc);

  return s;
}
