#include "s21_test.h"

double generate_random_double(double min, double max) {
  // Инициализируем генератор случайных чисел
  srand(time(NULL));

  // Генерируем случайное целое число в диапазоне [0, RAND_MAX]
  int random_int = rand();

  // Приводим целое число к типу double
  double random_double = (double)random_int;

  // Нормализуем число в диапазоне [0, 1)
  random_double /= RAND_MAX;

  // Масштабируем число в заданный диапазон [min, max)
  random_double = min + (random_double * (max - min));

  return random_double;
}
