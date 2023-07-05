#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *r_ptr = S21_NULL;

  if (n != 0 && str != S21_NULL) {
    s21_size_t len = n / sizeof(char);
    for (s21_size_t i = 0; i < len; i++) {
      if (*((unsigned char *)str + i) == (unsigned char)c) {
        r_ptr = (unsigned char *)str + i;
        break;
      }
    }
  }
  return r_ptr;
}
