#include "s21_string.h"

/*
  For detailed description :
  https://pubs.opengroup.org/onlinepubs/7908799/xsh/fscanf.html
  https://www.ibm.com/docs/en/zos/2.4.0?topic=programs-sscanf-read-format-data

    GENERAL DESCRIPTION
  The sscanf() function reads from the string s. This function reads bytes,
  interprets them according to a format, and stores the results in its
  arguments. Each expects, as arguments, a control string format described
  below, and a set of pointer arguments indicating where the converted input
  should be stored. The result is undefined if there are insufficient arguments
  for the format. If the format is exhausted while arguments remain, the excess
  arguments are evaluated but are otherwise ignored.

    RETURN VALUE
  Upon successful completion, this function return the number of successfully
  matched and assigned input items; this number can be 0 in the event of an
  early matching failure. If the input ends before the first matching failure
  or conversion, EOF is returned. If a read error occurs the error indicator for
  the stream is set, EOF is returned, and errno is set to indicate the error.

    ERRORS
  No errors are defined.
 */

int s21_sscanf(const char *str, const char *format, ...) {
  format_flags flags_val;
  s21_memset(&flags_val, 0, sizeof(flags_val));
  format_flags *flags = &flags_val;

  flags->str_start = str;
  va_list curr_arg;
  va_start(curr_arg, format);
  while (*format != '\0' && !flags->e_error) {
    if (*format == '%') {
      format = format_parser(format, flags);
      if (!flags->e_error || flags->e_error == UNDECL_SPEC) {
        str = str_parser(str, flags, curr_arg);
        if (!flags->ss_suppress && !flags->e_error && !flags->n_number_of_chr &&
            !flags->olo_chr) {
          flags->res_cnt++;
        } else if (flags->res_cnt == 0 && (flags->e_error == EMPTY_STR_N ||
                                           flags->e_error == EMPTY_STR_CH ||
                                           flags->e_error == UNDECL_SPEC)) {
          flags->res_cnt = -1;
        }
        // clearing formating struct w/o editing last 3 persistant values
        // uint16_t persist_size = sizeof(flags->res_cnt) +
        //                    sizeof(flags->e_error) + sizeof(flags->str_start);
        s21_memset(flags, 0, 11);
      }
    } else if (*format == *str) {
      format++;
      str++;
    } else if (s21_isspace(format)) {
      while (s21_isspace(str)) {
        str++;
      }
      format++;
    } else {
      flags->e_error = UNM_STR_F;
    }
  }
  va_end(curr_arg);
  return flags->res_cnt;
}

//  parsing current part of format string
//  sets flags for current specifier
//  sets pointer to next format string element
const char *format_parser(const char *format_char, format_flags *flags) {
  if (*(++format_char) == '*') {
    flags->ss_suppress = 1;
    format_char++;
  }
  if (*format_char >= '0' && *format_char <= '9') {
    format_char = width_to_number(format_char, flags);
  }
  if (*format_char == 'h' || *format_char == 'l' || *format_char == 'L') {
    if (*format_char == 'h') {
      if (*(format_char + 1) == 'h') {
        flags->hh_char_width_f = 1;
        format_char++;
      } else {
        flags->h_short_int_width_f = 1;
      }
    } else if (*format_char == 'l') {
      if (*(format_char + 1) == 'l') {
        flags->ll_ll_int_width_f = 1;
        format_char++;
      } else {
        flags->l_long_int_width_f = 1;
      }
    } else if (*format_char == 'L') {
      flags->L_long_double = 1;
    }
    format_char++;
  }
  format_char = set_specifier(format_char, flags);
  return (format_char);
}

//  parsing width value from format string to numeric integer value
//  sets pointer to next format string element (length or specifier itself)
const char *width_to_number(const char *format_char, format_flags *flags) {
  int64_t r_number = 0, cnt = 0;
  while (*(format_char + cnt) >= '0' && *(format_char + cnt) <= '9') {
    cnt++;
  }
  for (int64_t i = 0; cnt > 0; cnt--, i++) {
    r_number += (*(format_char++) - '0') * (int64_t)pow(10, cnt - 1);
  }
  flags->number_width = r_number;
  return (format_char);
}

//  parsing format string to set specifier
//  sets pointer to next format string element
const char *set_specifier(const char *format_char, format_flags *flags) {
  if (*format_char == 'c') {
    flags->c_character = 1;
  } else if (*format_char == 'd') {
    flags->d_s_decimal_int = 1;
  } else if (*format_char == 'i') {
    flags->i_s_integer = 1;
  } else if (*format_char == 'e' || *format_char == 'E' ||
             *format_char == 'f' || *format_char == 'g' ||
             *format_char == 'G') {
    flags->f_float = 1;
  } else if (*format_char == 'o') {
    flags->o_u_octal = 1;
  } else if (*format_char == 's') {
    flags->s_string = 1;
  } else if (*format_char == 'u') {
    flags->u_u_int = 1;
  } else if (*format_char == 'x' || *format_char == 'X') {
    flags->x_u_hex_int = 1;
  } else if (*format_char == 'p') {
    flags->p_pointer_addr = 1;
  } else if (*format_char == 'n') {
    flags->n_number_of_chr = 1;
  } else if (*format_char == '%') {
    flags->olo_chr = 1;
  } else {
    flags->e_error = UNDECL_SPEC;
  }
  format_char++;
  return (format_char);
}

//  selecting funtion based on format
//  parsing string str to args
//  sets pointer to next string element
const char *str_parser(const char *str, format_flags *flags, va_list last_arg) {
  if (flags->c_character) {
    str = c_parser(str, last_arg, flags);
  } else if (flags->n_number_of_chr) {
    str = n_parser(str, last_arg, flags);
  } else {
    // skip blank characters in read string (space, newline, tabulation, etc)
    while (s21_isspace(str)) {
      str++;
    }

    if (flags->res_cnt == 0 && *str == '\0') {
      flags->e_error = EMPTY_STR_N;
    }

    if (!flags->e_error) {
      if (flags->s_string) {
        str = s_parser(str, last_arg, flags);
      } else if (flags->d_s_decimal_int || flags->i_s_integer ||
                 flags->o_u_octal || flags->u_u_int || flags->x_u_hex_int ||
                 flags->p_pointer_addr) {
        str = int_parser(str, last_arg, flags);
      } else if (flags->f_float) {
        str = float_parser(str, last_arg, flags);
      } else if (flags->olo_chr) {
        str = olo_parser(str, flags);
      }
    }
  }
  return (str);
}

//  parsing string str to args for integer formatted values
//  sets pointer to next string element  as result
const char *int_parser(const char *str, va_list last_arg, format_flags *flags) {
  numb_data numb = {0, DEC, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // checks str for sign, sets flag
  str = numb_prep_sign(str, &numb, flags);
  // reads number notation && set flag
  str = (!flags->e_error) ? numb_prep_base(str, &numb, flags) : str;
  // validates and counts digits amount
  str = (!flags->e_error) ? numb_digits_cnt(str, &numb, flags) : str;
  // calculates uint value from digits
  str = (!flags->e_error) ? numb_prep_uint(str, &numb, flags) : str;
  // calculates int from uint based on risen flags
  str = (!flags->e_error) ? numb_uint_to_int(str, &numb, flags) : str;
  // writes calculated value to arg
  str = write_args(str, last_arg, &numb, flags);
  return (str);
}

//  parsing string str to args for float formatted values
//  sets pointer to next string element  as result
const char *float_parser(const char *str, va_list last_arg,
                         format_flags *flags) {
  numb_data numb = {0, DEC, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // checks str for sign, sets flag
  str = numb_prep_sign(str, &numb, flags);
  // reads number notation && set flag
  str = (!flags->e_error) ? fnumb_prep_base(str, &numb, flags) : str;
  if (numb.val_base != vNAN && numb.val_base != vINF) {
    // validates and counts digits amount
    str = (!flags->e_error) ? fnumb_digits_cnt(str, &numb, flags) : str;
    // calculates uint value from digits
    str = (!flags->e_error) ? numb_prep_uint(str, &numb, flags) : str;
    if (numb.exp_flag) {
      str = numb_exp_to_int(str, &numb, flags);
    }
  }
  // calculates int from uint based on risen flags
  str = (!flags->e_error) ? numb_val_to_float(str, &numb) : str;
  // writes calculated value to arg
  str = write_args(str, last_arg, &numb, flags);
  return (str);
}

//  parsing string str to args for char values
//  arg can be array of chars == string (for cases with declared width value)
const char *c_parser(const char *str, va_list last_arg, format_flags *flags) {
  if (!flags->number_width) {
    flags->number_width = 1;
  }
  uint64_t cnt = 0;
  if (!flags->ss_suppress) {
    if (flags->l_long_int_width_f) {
      short *ptr_c = va_arg(last_arg, short *);
      while (cnt < flags->number_width) {
        if (*str != '\0') {
          *(ptr_c + cnt) = (short)*(str);
          str++;
          cnt++;
        } else {
          if (cnt == 0) {
            flags->e_error = EMPTY_STR_CH;
          }
          cnt++;
        }
      }
    } else {
      char *ptr_c = va_arg(last_arg, char *);
      while (cnt < flags->number_width) {
        if (*str != '\0') {
          *(ptr_c + cnt) = *(str);
          str++;
          cnt++;
        } else {
          if (cnt == 0) {
            flags->e_error = EMPTY_STR_CH;
          }
          cnt++;
        }
      }
    }
  } else {
    while (cnt < flags->number_width) {
      if (*str != '\0') {
        str++;
        cnt++;
      } else {
        if (cnt == 0) {
          flags->e_error = EMPTY_STR_CH;
        }
        cnt++;
      }
    }
  }
  return (str);
}

//  parsing string str in case of specifier == %%
//  expecting '%' char in std, sets pointer to next string element as result
const char *olo_parser(const char *str, format_flags *flags) {
  if (*str == '%') {
    str++;
  } else {
    flags->e_error = NOT_PERC;
  }
  return (str);
}

//  calculates number of characters read from str so far
//  writes this value to arg and return current pointer to str as result
const char *n_parser(const char *str, va_list last_arg, format_flags *flags) {
  // struct for writing functions unification, using only 'val' field
  numb_data numb = {0, DEC, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  numb.val = str - flags->str_start;
  str = write_args(str, last_arg, &numb, flags);
  return (str);
}

//  parsing string str to args for string values (array of chars)
//  args is a char arrays terminated with \0 == strings
const char *s_parser(const char *str, va_list last_arg, format_flags *flags) {
  if (*str == '\0') {
    flags->e_error = EMPTY_STR;
  }

  if (!flags->number_width) {
    flags->number_width = UINT64_MAX;
  }

  if (!flags->e_error) {
    uint64_t cnt = 0;
    if (!flags->ss_suppress) {
      if (flags->l_long_int_width_f) {
        short *ptr_c = va_arg(last_arg, short *);
        while (cnt < flags->number_width && !s21_isspace(str) && *str != '\0') {
          *(ptr_c + cnt) = (short)*(str);
          str++;
          cnt++;
        }
        *(ptr_c + cnt) = '\0';
      } else {
        char *ptr_c = va_arg(last_arg, char *);
        while (cnt < flags->number_width && !s21_isspace(str) && *str != '\0') {
          *(ptr_c + cnt) = *(str);
          str++;
          cnt++;
        }
        *(ptr_c + cnt) = '\0';
      }
    } else {
      if (flags->number_width == UINT64_MAX) {
        while (!s21_isspace(str) && *str != '\0') {
          str++;
        }
      } else {
        while (cnt < flags->number_width && !s21_isspace(str)) {
          str++;
          cnt++;
        }
      }
    }
  }
  return (str);
}

//  checks str for sign '+', '-';
//  calculating width counter if its specified;
//  sets pointer to next char in str as result
const char *numb_prep_sign(const char *str, numb_data *numb,
                           format_flags *flags) {
  if (!flags->number_width) {
    flags->number_width = UINT64_MAX;
  }

  if (*str == '-') {
    numb->sign = 1;
    str++;
    if (flags->number_width != UINT64_MAX && flags->number_width > 0) {
      (flags->number_width--);
    }
  } else if (*str == '+') {
    str++;
    if (flags->number_width != UINT64_MAX && flags->number_width > 0) {
      (flags->number_width--);
    }
  }

  if (flags->number_width == 0) {
    flags->e_error = ONLY_SIGN;
  }
  return (str);
}

//  checks str for number notation: 'OCT', 'DEC' or 'HEX', sets flag;
//  sets pointer to next char in str as result
const char *numb_prep_base(const char *str, numb_data *numb,
                           format_flags *flags) {
  if (*str == '0' && flags->i_s_integer) {
    if ((*(str + 1) == 'x' || *(str + 1) == 'X') && flags->number_width > 1) {
      numb->val_base = HEX;
      str = str + 2;
      if (flags->number_width != UINT64_MAX) {
        (flags->number_width = flags->number_width - 2);
      }
    } else if (flags->number_width > 1) {
      numb->val_base = OCT;
      str++;
      if (flags->number_width != UINT64_MAX) {
        (flags->number_width--);
      }
    }
  } else if (flags->o_u_octal) {
    numb->val_base = OCT;
  } else if (flags->x_u_hex_int || flags->p_pointer_addr) {
    numb->val_base = HEX;
    if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X') &&
        flags->number_width > 1) {
      str = str + 2;
      if (flags->number_width != UINT64_MAX) {
        (flags->number_width = flags->number_width - 2);
      }
    }
  }  // value_type = DEC; by default

  if (flags->number_width == 0 && !flags->i_s_integer && !flags->x_u_hex_int) {
    flags->e_error = NO_DIGITS;
  }
  return (str);
}

// calculating amount of digits to read, based on current format of number
// sets pointer to first char of number in str as result
const char *numb_digits_cnt(const char *str, numb_data *numb,
                            format_flags *flags) {
  char end_str = 0;
  while (((flags->number_width > 0 && numb->dig_cnt < flags->number_width) ||
          flags->number_width == UINT64_MAX) &&
         !end_str) {
    if (numb->val_base == OCT) {
      if (*(str + numb->dig_cnt) >= '0' && *(str + numb->dig_cnt) <= '7') {
        (numb->dig_cnt)++;
      } else {
        end_str++;
      }
    } else if (numb->val_base == DEC) {
      if (*(str + numb->dig_cnt) >= '0' && *(str + numb->dig_cnt) <= '9') {
        (numb->dig_cnt)++;
      } else {
        end_str++;
      }
    } else if (numb->val_base == HEX) {
      if ((*(str + numb->dig_cnt) >= '0' && *(str + numb->dig_cnt) <= '9') ||
          (*(str + numb->dig_cnt) >= 'a' && *(str + numb->dig_cnt) <= 'f') ||
          (*(str + numb->dig_cnt) >= 'A' && *(str + numb->dig_cnt) <= 'F')) {
        (numb->dig_cnt)++;
      } else {
        end_str++;
      }
    }
  }
  if (numb->dig_cnt == 0 && (numb->val_base == DEC || flags->o_u_octal)) {
    flags->e_error = NOT_NUMBER;
  }
  return (str);
}

// preparing uint value from read digits
// checks value for overflow (digits amounts and value <= INT64_MAX)
// sets pointer to next element in str as result
const char *numb_prep_uint(const char *str, numb_data *numb,
                           format_flags *flags) {
  for (uint8_t d_cnt = numb->dig_cnt; (d_cnt > 0); d_cnt--) {
    if (flags->f_float && *str == '.') {
      str++;
      d_cnt++;
    } else if ((numb->dig_cnt <= LLINT_DIG_MAX_OCT && numb->val_base == OCT) ||
               (numb->dig_cnt <= LLINT_DIG_MAX_DEC && numb->val_base == DEC) ||
               (numb->dig_cnt <= LLINT_DIG_MAX_HEX && numb->val_base == HEX)) {
      if (!numb->digits_overflow) {
        uint64_t add =
            (chr_to_int(str, numb)) * (uint64_t)pow(numb->val_base, d_cnt - 1);
        // check for value overflow and calculating current digit value
        // INT64_MAX increased to 1 bit when u_int flag rased to carry sign bit
        if ((add >= (INT64_MAX + numb->sign - numb->uval + flags->u_u_int))) {
          numb->uval = INT64_MAX + (numb->sign) + (flags->u_u_int);
        } else {
          numb->uval += add;
        }
      }
      str++;
      if (flags->f_float && *str == '.' && numb->dot_flag) {
        str++;
      }
    } else {
      numb->digits_overflow++;
    }
  }

  if (numb->exp_flag) {
    if (flags->number_width != UINT64_MAX &&
        (flags->number_width > numb->dig_cnt)) {
      flags->number_width =
          flags->number_width - numb->dig_cnt - numb->dot_flag - numb->exp_flag;
    }
  }
  return (str);
}

// calculating int value based on uint value and risen flags
// when value is overflow, sets it to INT64_MAX
// for u_int overflow discard flag
const char *numb_uint_to_int(const char *str, numb_data *numb,
                             format_flags *flags) {
  if (flags->u_u_int && numb->digits_overflow) {
    if (flags->l_long_int_width_f || flags->ll_ll_int_width_f) {
      numb->val = -1;  // specific case for long overflow
    } else {
      numb->val = INT64_MAX;  // for any sign overflow with u_int flag
    }
  } else if (numb->digits_overflow) {
    numb->val = (numb->sign) ? INT64_MIN : INT64_MAX;
  } else {
    numb->val = (numb->sign) ? -numb->uval : numb->uval;
  }

  // skipping extra digits when value if overflow INT64_MAX
  for (; numb->digits_overflow > 0; numb->digits_overflow--) {
    str++;
  }
  return (str);
}

//  variation of numb_prep_base for float values
//  checks str for number notation: 'DEC' or 'HEX', sets flag;
//  checks string for NAN and INF values
//  sets pointer to next char in str as result
const char *fnumb_prep_base(const char *str, numb_data *numb,
                            format_flags *flags) {
  if (*str == '0') {
    if ((*(str + 1) == 'x' || *(str + 1) == 'X') && flags->number_width > 1) {
      numb->val_base = HEX;
      str = str + 2;
      if (flags->number_width != UINT64_MAX) {
        (flags->number_width = flags->number_width - 2);
      }
    } else if (flags->number_width >= 1) {
      numb->val_base = DEC;
      // str++;
      if (flags->number_width != UINT64_MAX) {
        (flags->number_width--);
      }
    }
  } else if (*str == 'i' || *str == 'I') {
    if ((*(str + 1) == 'n' || *(str + 1) == 'N') && flags->number_width > 1) {
      if ((*(str + 2) == 'f' || *(str + 2) == 'F') && flags->number_width > 2) {
        numb->val_base = vINF;
        str = str + 3;
        if (flags->number_width != UINT64_MAX) {
          (flags->number_width = flags->number_width - 3);
        }
      }
    }
  } else if (*str == 'n' || *str == 'N') {
    if ((*(str + 1) == 'a' || *(str + 1) == 'A') && flags->number_width > 1) {
      if ((*(str + 2) == 'n' || *(str + 2) == 'N') && flags->number_width > 2) {
        numb->val_base = vNAN;
        str = str + 3;
        if (flags->number_width != UINT64_MAX) {
          (flags->number_width = flags->number_width - 3);
        }
      }
    }
  }  // value_type = DEC; by default

  if (flags->number_width == 0 && numb->val_base != vINF &&
      numb->val_base != vNAN && numb->val_base != HEX) {
    flags->e_error = NO_DIGITS;
  }
  return (str);
}

// variation of numb_digits_cnt for float values
// calculating amount of digits to read, based on current format of number
// sets pointer to first char of number in str as result
const char *fnumb_digits_cnt(const char *str, numb_data *numb,
                             format_flags *flags) {
  char end_str = 0;
  while (!end_str &&
         ((flags->number_width > 0 &&
           (uint64_t)(numb->dig_cnt + numb->dot_flag) < flags->number_width) ||
          flags->number_width == UINT64_MAX)) {
    if (numb->val_base == DEC) {
      if (*(str + numb->dig_cnt + numb->dot_flag) >= '0' &&
          *(str + numb->dig_cnt + numb->dot_flag) <= '9') {
        (numb->dig_cnt)++;
        if (numb->dot_flag) {
          numb->dot_position--;
        }
      } else if (*(str + numb->dig_cnt) == '.' && !(numb->dot_flag)) {
        numb->dot_flag = 1;
      } else if (*(str + numb->dig_cnt + numb->dot_flag) == 'e' ||
                 *(str + numb->dig_cnt + numb->dot_flag) == 'E') {
        numb->exp_flag = 1;
        end_str++;
      } else {
        end_str++;
      }
    } else if (numb->val_base == HEX) {
      if ((*(str + numb->dig_cnt + numb->dot_flag) >= '0' &&
           *(str + numb->dig_cnt + numb->dot_flag) <= '9') ||
          (*(str + numb->dig_cnt + numb->dot_flag) >= 'a' &&
           *(str + numb->dig_cnt + numb->dot_flag) <= 'f') ||
          (*(str + numb->dig_cnt + numb->dot_flag) >= 'A' &&
           *(str + numb->dig_cnt + numb->dot_flag) <= 'F')) {
        (numb->dig_cnt)++;
        if (numb->dot_flag) {
          numb->dot_position--;
        }
      } else if (*(str + numb->dig_cnt) == '.' && !(numb->dot_flag)) {
        numb->dot_flag = 1;
      } else {
        end_str++;
      }
    }
  }

  if (numb->dig_cnt == 0 && (numb->val_base == DEC || flags->o_u_octal)) {
    flags->e_error = NOT_NUMBER;
  }
  return (str);
}

// calculating float value based on uint value of mantisa, exp and risen flags
const char *numb_val_to_float(const char *str, numb_data *numb) {
  if (numb->val_base == vNAN) {
    numb->float_val = (numb->sign) ? -NAN : NAN;
  } else if (numb->val_base == vINF) {
    numb->float_val = (numb->sign) ? -INFINITY : INFINITY;
  } else {
    numb->exponent += numb->dot_position;
    numb->float_val = numb->uval * powl(numb->val_base, numb->exponent);
    numb->float_val = (numb->sign) ? -numb->float_val : numb->float_val;
  }
  return (str);
}

// writes values to agrs, based on specifier, length modifier and risen flags
const char *write_args(const char *str, va_list last_arg, numb_data *numb,
                       format_flags *flags) {
  if (!flags->ss_suppress && !flags->e_error) {
    // to write pointer adress
    if (flags->p_pointer_addr) {
      void **ptr_c = va_arg(last_arg, void **);
      *ptr_c = (void *)numb->val;
      // to write floating point  values
    } else if (flags->f_float) {
      if (flags->L_long_double) {
        long double *ptr_c = va_arg(last_arg, long double *);
        *ptr_c = (long double)numb->float_val;
      } else if (flags->l_long_int_width_f) {
        double *ptr_c = va_arg(last_arg, double *);
        *ptr_c = (double)numb->float_val;
      } else {
        float *ptr_c = va_arg(last_arg, float *);
        *ptr_c = (float)numb->float_val;
      }
      // to write integer values
    } else {
      if (flags->h_short_int_width_f) {
        short *ptr_c = va_arg(last_arg, short *);
        *ptr_c = (short)numb->val;
      } else if (flags->hh_char_width_f) {
        char *ptr_c = va_arg(last_arg, char *);
        *ptr_c = (char)numb->val;
      } else if (flags->l_long_int_width_f) {
        long int *ptr_c = va_arg(last_arg, long *);
        *ptr_c = (long int)numb->val;
      } else if (flags->ll_ll_int_width_f) {
        long long int *ptr_c = va_arg(last_arg, long long *);
        *ptr_c = (long long int)numb->val;
      } else {
        int *ptr_c = va_arg(last_arg, int *);
        *ptr_c = (int)numb->val;
      }
    }
  }
  return (str);
}

//  converting char to its numeric integer value based on its notation
//  examples: char = 'B' (int = 66) HEX to its value int = 11
uint8_t chr_to_int(const char *str, numb_data *numb) {
  uint8_t res_int = 0;
  if (numb->val_base == OCT || numb->val_base == DEC) {
    res_int = *str - '0';
  } else if (numb->val_base == HEX) {
    if (*str >= 'a' && *str <= 'f') {
      res_int = *str - 'a' + 10;
    } else if (*str >= 'A' && *str <= 'F') {
      res_int = *str - 'A' + 10;
    } else {
      res_int = *str - '0';
    }
  }
  return (res_int);
}

//  parsing exp value of scientific notation from str
//  sets pointer to next char in str as result
const char *numb_exp_to_int(const char *str, numb_data *numb,
                            format_flags *flags) {
  str++;
  int exp_sign = 1;
  if (flags->number_width > 0) {
    if (*str == '-') {
      exp_sign = -1;
      str++;
      if (flags->number_width != UINT64_MAX) {
        (flags->number_width--);
      }
    } else if (*str == '+') {
      str++;
      if (flags->number_width != UINT64_MAX) {
        (flags->number_width--);
      }
    }
  }

  uint64_t exp_digits = 0;
  while (*(str + exp_digits) >= '0' && *(str + exp_digits) <= '9' &&
         exp_digits <= flags->number_width) {
    exp_digits++;
    flags->number_width--;
  }

  while (exp_digits > 0 && numb->exponent < EXP_MAX_VALUE) {
    int64_t add = (*str - '0') * pow(10, exp_digits - 1);
    if (add >= (EXP_MAX_VALUE - numb->exponent)) {
      numb->exponent = EXP_MAX_VALUE;
    } else {
      numb->exponent += add;
    }
    str++;
    exp_digits--;
  }
  numb->exponent *= exp_sign;
  while ((*str >= '0' && *str <= '9') && flags->number_width == UINT64_MAX) {
    str++;
  }
  return (str);
}

//  checks char in str for specific values (like space, tabulation)
uint8_t s21_isspace(const char *str) {
  uint8_t value = 0;
  if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
      *str == '\f' || *str == '\r') {
    value = 1;
  }
  return (value);
}
