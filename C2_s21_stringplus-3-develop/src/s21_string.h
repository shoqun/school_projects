#ifndef S21_STRING_H
#define S21_STRING_H
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define S21_NULL ((void *)0)
typedef unsigned long s21_size_t;
typedef struct flags {
  int minus;
  int plus;
  int sharp;
  int space;
  int zero;
  int width;
  int precision;
  int prec;
  int length;
  int specificator;
} flags;
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n);

// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n);

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strcat(char *dest, const char *src);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strchr(const char *str, int c);

// Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2);

// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.
char *s21_strerror(int errnum);

// Вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str);

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2);

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c);

// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle);

// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim);

// допы
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// основные функции и парсеры  для спринтф
int s21_sprintf(char *str, const char *format, ...);
const char *flag_width_precision_parser(const char *str, flags *data);
const char *specificator_parser(const char *str, flags *data);
char *call_specificator(va_list *ptr, flags data, char **str,
                        const char **format, unsigned int *count);
char *integers(char **str, flags a, va_list *ptr, unsigned int *count);
char *uintegers(char **str, flags a, va_list *ptr, unsigned int *count);
char *doubles(char **str, flags a, va_list *ptr, unsigned int *count);
char *chars(char **str, flags a, va_list *ptr, const char **format,
            unsigned int *count);
char *charPointers(char **str, flags a, va_list *ptr, const char **format,
                   unsigned int *count);
char *wCharPointers(char **str, flags data,  // для работы с символами,
                    va_list *ptr,  // которые выходят за рамки ASCII
                    const char **format, unsigned int *count);
char *pointers(char **str, flags a, va_list *ptr, unsigned int *count);
char *integerPointers(char **str, va_list *ptr, unsigned int count);

// вспомогательные функции (в libs.c)
char *reverse(char s[]);
char *ourItoa(long long int value, char *result, int base);
char *ourUItoa(long long unsigned value, char *result, int base);
// int stringToInteger(const char *str);
// double stringToDouble(const char *s);
void cleanFlags(flags *data);
void widthHelper(char *result, flags data, int *i, int strlength);

void process_g(int *specificator, int *precision, char *nu, int *og,
               long double x);
void cut_off_zeros(char *nu, flags data, int og);
void to_upper(char *x);
void rounding_double(int length, int precision, char *nu, flags data);
void work_with_e(long double x, flags data, int precision, char **nu1, int og);
int value_to_str(long double x, char *nu, long double x1, int *length);
void double_to_str(long double x, long double x1, char *nu, int *length);
void recursive_long_int(long double d_arg, int symbols, char **str);
void e_to_str(long double x, char *nu, char *nunu, flags a, int *i,
              int precision);
void print_base(flags data, unsigned long x, char *result, int *i,
                int *precision);
void negativeSign(char *str, int i);
void positiveSign(flags data, char *str, int i);

#define LLINT_DIG_MAX_OCT 21  // max amount of digits in LLINT value in OCT not
#define LLINT_DIG_MAX_DEC 19  // max amount of digits in LLINT value in DEC not
#define LLINT_DIG_MAX_HEX 16  // max amount of digits in LLINT value in HEX not
#define EXP_MAX_VALUE 4952    // max value of exp in scientific notation

enum num_system { OCT = 8, DEC = 10, HEX = 16, vNAN = 404, vINF = 999 };

enum scanf_err {
  ONLY_SIGN = 11,     //  char out of valid range after sign char
  NO_DIGITS = 12,     //  not valid digit in str and dig_cnt == 0
  NOT_NUMBER = 13,    //  char out of valid range in DEC notation
  NOT_PERC = 14,      //  current char is not % for '%' specifier
  UNDECL_SPEC = 15,   //  undeclared specificator
  EMPTY_STR = 16,     //  unexpected '\0' when read string with %s
  EMPTY_STR_CH = 17,  //  unexpected '\0' when read char with %c
  EMPTY_STR_N = 18,   //  unexpected '\0' when read numeric value
  UNM_STR_F = 19      //  unmutching characters in str and form,
};                    //  when there is char w/o % in format

typedef struct {
  uint8_t sign;              //  sign of number 0 == '+', 1 == '-'
  enum num_system val_base;  //  base of number notation (HEX == 16, etc)
  uint64_t uval;
  int64_t val;
  uint8_t dig_cnt;          //  counter for digits in number
  uint8_t digits_overflow;  //  flag of overflowing amount of digits

  uint8_t dot_flag : 1;
  uint8_t exp_flag : 1;
  int16_t exponent;
  int8_t dot_position;
  long double float_val;
} numb_data;

typedef struct {
  // struct for format  %[*][width][length]specifier
  // width description
  uint64_t number_width;    // minimum number of characters to be stored
  uint8_t ss_suppress : 1;  // * sign : reads data , but suppresses assignment
  // length description
  uint8_t h_short_int_width_f : 1;  // only for i, d, o, u, x and X
  uint8_t hh_char_width_f : 1;      // only for i, d, o, u, x and X
  uint8_t l_long_int_width_f : 1;  // for i, d, o, u, x, X, and for c, s as wide
  uint8_t ll_ll_int_width_f : 1;   // for i, d, o, u, x, X, and for c, s as wide
  uint8_t L_long_double : 1;       // only for e, E, f, g and G
  // specifier
  uint8_t c_character : 1;      //  character
  uint8_t d_s_decimal_int : 1;  //  signed decimal integer
  uint8_t i_s_integer : 1;      //  signed integer (dec/oct/hex)
  uint8_t f_float : 1;          //  dec float or scientific not (e/ E/ f/ g/ G)
  uint8_t o_u_octal : 1;        //  unsigned octal
  uint8_t s_string : 1;         //  string of characters
  uint8_t u_u_int : 1;          //  unsigned integer
  uint8_t x_u_hex_int : 1;      //  unsigned hex integer (x/ X)
  uint8_t p_pointer_addr : 1;   //  pointer address
  uint8_t n_number_of_chr : 1;  //  number of characters until %n occurs
  uint8_t olo_chr : 1;          //  character %
  enum scanf_err e_error;       //  general error for any undeclared character

  const char *str_start;  // pointer to first bit in str
  int res_cnt;            // counter for successfully assigned args
} format_flags;

int s21_sscanf(const char *str, const char *format, ...);

const char *format_parser(const char *format_char, format_flags *flags);
const char *width_to_number(const char *format_char, format_flags *flags);
const char *set_specifier(const char *format_char, format_flags *flags);
const char *str_parser(const char *str, format_flags *flags, va_list last_arg);

const char *int_parser(const char *str, va_list last_arg, format_flags *flags);
const char *float_parser(const char *str, va_list last_arg,
                         format_flags *flags);

const char *c_parser(const char *str, va_list last_arg, format_flags *flags);
const char *n_parser(const char *str, va_list last_arg, format_flags *flags);
const char *s_parser(const char *str, va_list last_arg, format_flags *flags);
const char *olo_parser(const char *str, format_flags *flags);

const char *numb_prep_sign(const char *str, numb_data *numb,
                           format_flags *flags);
const char *numb_prep_base(const char *str, numb_data *numb,
                           format_flags *flags);
const char *numb_digits_cnt(const char *str, numb_data *numb,
                            format_flags *flags);
const char *numb_prep_uint(const char *str, numb_data *numb,
                           format_flags *flags);
const char *numb_uint_to_int(const char *str, numb_data *numb,
                             format_flags *flags);

const char *fnumb_prep_base(const char *str, numb_data *numb,
                            format_flags *flags);
const char *fnumb_digits_cnt(const char *str, numb_data *numb,
                             format_flags *flags);
const char *numb_val_to_float(const char *str, numb_data *numb);

const char *write_args(const char *str, va_list last_arg, numb_data *numb,
                       format_flags *flags);
uint8_t chr_to_int(const char *str, numb_data *numb);
const char *numb_exp_to_int(const char *str, numb_data *numb,
                            format_flags *flags);
uint8_t s21_isspace(const char *str);

#endif  // S21_STRING_H
