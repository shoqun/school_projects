#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest_ptr = dest;

  // Находим конец строки dest
  while (*dest_ptr != '\0') {
    dest_ptr++;
  }

  // Копируем символы из src в конец dest
  while (*src != '\0' && n > 0) {
    *dest_ptr = *src;
    dest_ptr++;
    src++;
    n--;
  }

  // Добавляем символ нулевого байта в конец dest
  *dest_ptr = '\0';

  return dest;
}