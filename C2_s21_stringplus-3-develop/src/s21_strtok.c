#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *ptr = S21_NULL;
  int F_StrEnd = 0;
  if (str != S21_NULL) {
    ptr = str;
  }
  if (ptr) {
    // take off separator(s) and token, until found another separator
    str = ptr + s21_strspn(ptr, delim);
    ptr = str + s21_strcspn(str, delim);
    // if there is no tokens left, points static pointer to void(0)
    if (ptr == str) {
      ptr = S21_NULL;
      F_StrEnd = 1;
    } else if (*ptr) {
      *ptr = 0;
      ptr = ptr + 1;
    } else {
      ptr = 0;
    }
  }
  return F_StrEnd == 0 ? str : S21_NULL;
}
