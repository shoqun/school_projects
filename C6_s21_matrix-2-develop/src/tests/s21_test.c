#include "s21_test.h"

int main() {
  int failed = 0;

  /*
  Реализовать основные действия с матрицами (частично описанные выше):
  create_matrix (создание), remove_matrix (очистка и уничтожение), eq_matrix
  (сравнение), sum_matrix (сложение), sub_matrix (вычитание), mult_matrix
  (умножение), mult_number (умножение на число), transpose (транспонирование),
  determinant (вычисление определителя), calc_complements (вычисление матрицы
  алгебраических дополнений), inverse_matrix (поиск обратной матрицы).
  */
  Suite *s21_matrix_test[] = {
      test_matrix_create(),     // ++
      test_matrix_remove(),     // ++
      test_matrix_eq(),         // +
      test_matrix_sum(),        // + - (неправильно создавал)
      test_matrix_sub(),        // + - (неправильно создавал)
      test_mult_matrix(),       // +
      test_mult_number(),       // +
      test_matrix_transpose(),  // +
      test_matrix_determinant(),       // + -
      test_matrix_calc_complements(),  // -
      test_inverse_matrix(),           // -

      // дома надо сделать тесты по determinant, test_matrix_calc_complements,
      // test_inverse_matrix пройтись еще по 1-2 базовым случаям и рассмотреть
      // краевые. я уже после 1 фэйла вроде все учел, но есть проблемы с памятью
      // в обратной матрице        // -
      NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 0 : 1;
}
