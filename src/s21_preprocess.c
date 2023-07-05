#include "s21_smartCalc.h"

#define MAX_SIZE 255

/*
  Вечером тяжело кодить, поэтому буду кодить завтра со свежей головой.

  Сейчас 17.06 в 23:19 находясь в электричке я могу лишь подытожить написанное и
  обозначить направление, как и что стоит написать.

  Сегодня я сделал неполностью preprocessing, который должен включать в себя
  предобработку введенной строки в input box в QT интерфейсе. Я немного
  запутался в процессе работы, но сейчас я в целом понимаю что нужно делать.

  Мне не нужно обрабатывать все ошибки, нужно учитывать возможности интерфейса в
  будущем для обработки некорректного ввода со стороны юзера. На самом деле я
  хочу сделать калькулятор максимально удобным для юзера, а код должен быть
  лаконичен и понятен.

  Надо поковыряться в калькуляторе в браузере и посмотреть что и как можно
  написать

  Решить проблему с точками, чтобы нельзя было спамить. Можно решить в
  графическом интерфейсе. √ Решить проблему с дублированием базовых операторов,
  один оператор должен меняться на другой как в гугле. √ Решается в интерфейсе ∆



*/

// на вход подается строка без дублирования операторов типа 8+3 +-2 *3*+4
// однако вот так можно: 8*-2, и описать еще случаи как можно
// вот так не будет: '32.22.33', '.'
// 8 *ªº–≠¡™£¢∞∞§¶¶•ª§§œ∑´®´∑œ†¥¨¨ˆˆøπππˆˆøπˆøπ“‘«æ…¬˚∆˙©ƒ∂ßå≈ç√√∫˜√
// 8 * 0 - 2

/*
  18.06 13:27 я снова живу


*/

// решается проблема с точками, например: '32.' или '.43' или 'sin.2' или '.' -
// ошибка
int dotProcessing(char *infix, int i, char *output, int *knd) {
  int k = *knd;

  if (i == 0 && !(infix[i + 1] >= '0' && infix[i + 1] <= '9')) {
    return 3;  // error
  }
  if (i != 0 && (!(infix[i - 1] >= '0' && infix[i - 1] <= '9') &&
                 !(infix[i + 1] >= '0' && infix[i + 1] <= '9'))) {  // .
    return 3;                                                       // error
  }
  if (i == 0) {
    output[k++] = '0';
    output[k++] = '.';
  } else if (i != 0 && infix[i] == '.' && infix[i + 1] >= '0' &&
             infix[i + 1] <= '9' &&
             !(infix[i - 1] >= '0' &&
               infix[i - 1] <=
                   '9')) {  // output[k-1] >= '0' && output[k-1] <= '9'
    output[k++] = '0';
    output[k++] = '.';

  } else if (i != 0 && infix[i] == '.' && infix[i - 1] >= '0' &&
             infix[i - 1] <= '9' &&
             !(infix[i - 1] >= '0' && infix[i - 1] <= '9')) {
    output[k++] = '.';
    output[k++] = '0';
  } else {
    output[k++] = '.';
  }

  *knd = k;
  return 0;  // success;
}
// возвращает 0 - ок, 1 - trigonomet, 2 - скобки, 3 - точки
int s21_preprocess(char *infix) {  // preprocess error if some invalid symbol
  char output[256] = {0};
  // memset(output, 0, sizeof(output)); можно так
  int i = -1;
  int k = 0;
  int dotCounter = 0;
  int flag = 0;
  int bracketCounter1 = 0;
  int bracketCounter2 = 0;
  int isTrigonometry = 0;
  while (infix[++i] != '\0' &&
         !flag) {  // ошибок не будет с внезапным концом файла или переполнением

    isTrigonometry = i;
    if (infix[i] >= '0' && infix[i] <= '9') {
      if (infix[i + 1] == '(') {
        output[k++] = infix[i];
        output[k++] = '*';
      } else if (i != 0 && infix[i - 1] == ')') {
        output[k++] = '*';
        output[k++] = infix[i];
      } else {
        output[k++] = infix[i];
      }
    } else if (infix[i] == '.' && dotCounter == 0) {
      flag = dotProcessing(infix, i, output, &k);
      dotCounter = 1;
    } else if (i == 0 && infix[i] == '+') {
      // continue;
    } else if (i == 0 && infix[i] == '-') {
      output[k++] = '~';
    } else if (infix[i] == ' ' || infix[i] == '\n') {
    } else if (infix[i] == '+' && output[k - 1] == '(') {  // унарный плюс
      dotCounter = 0;
    } else if (infix[i] == '-' && output[k - 1] == '(') {  // унарный минус
      output[k++] = '~';

      dotCounter = 0;
    } else if ((infix[i] == '+' || infix[i] == '-' || infix[i] == '*' ||
                infix[i] == '/' || infix[i] == '^')) {
      if (infix[i - 1] == '(' && i != 0) {
        flag = 11;
      }
      output[k++] = infix[i];
      dotCounter = 0;

    } else if (infix[i] == '(') {  // )5+7(
      bracketCounter1++;
      output[k++] = infix[i];
    } else if (infix[i] == ')') {
      bracketCounter2++;
      if (output[k - 1] == '(' && i != 0) {
        bracketCounter2++;
        // break;
      }

      if (bracketCounter2 - bracketCounter1 > 0) {  // (((1231-2)*3)-3232
        bracketCounter2 = 10;
        // break;
      }

      output[k++] = infix[i];
      if (infix[i + 1] == '(') {
        output[k++] = '*';
      }
    } else if (infix[i] == 'c' && infix[i + 1] == 'o' &&
               infix[i + 2] ==
                   's') {  // если infix[i+1] == '\0' то просто не идет проверка
                           // дальше и никакого сегментала
      output[k++] = 'c';
      i = i + 2;
    } else if (infix[i] == 's' && infix[i + 1] == 'i' && infix[i + 2] == 'n') {
      output[k++] = 's';
      i = i + 2;
    } else if (infix[i] == 't' && infix[i + 1] == 'a' && infix[i + 2] == 'n') {
      output[k++] = 't';
      i = i + 2;
    } else if (infix[i] == 'a' && infix[i + 1] == 'c' && infix[i + 2] == 'o' &&
               infix[i + 3] == 's') {
      output[k++] = 'a';
      i = i + 3;
    } else if (infix[i] == 'a' && infix[i + 1] == 's' && infix[i + 2] == 'i' &&
               infix[i + 3] == 'n') {
      output[k++] = 'b';
      i = i + 3;
    } else if (infix[i] == 'a' && infix[i + 1] == 't' && infix[i + 2] == 'a' &&
               infix[i + 3] == 'n') {
      output[k++] = 'd';
      i = i + 3;
    } else if (infix[i] == 's' && infix[i + 1] == 'q' && infix[i + 2] == 'r' &&
               infix[i + 3] == 't') {
      output[k++] = 'q';
      i = i + 3;
    } else if (infix[i] == 'l' && infix[i + 1] == 'n') {
      output[k++] = 'n';
      i = i + 1;
    } else if (infix[i] == 'l' && infix[i + 1] == 'o' && infix[i + 2] == 'g') {
      output[k++] = 'l';
      i = i + 2;
    } else if (infix[i] == 'm' && infix[i + 1] == 'o' && infix[i + 2] == 'd') {
      output[k++] = 'm';
      i = i + 2;
    } else {
      flag = 1;
    }

    if (isTrigonometry != i && output[k - 1] != 'm') {
      dotCounter = 0;  // в общем при тригонметрических функциях i прибавляется
                       // на 2 поэтому
      char tmp;
      char tmp2;
      if (k - 1 != 0 && output[k - 2] >= '0' && output[k - 2] <= '9' &&
          infix[isTrigonometry - 1] != '(') {
        tmp = output[k - 1];
        output[k - 1] = '*';
        output[k++] = tmp;
      } else if (k - 1 != 0 && (output[k - 2] == '(' || output[k - 2] == ')') &&
                 infix[isTrigonometry - 1] != '(') {
        tmp = output[k - 1];
        output[k - 1] = '*';
        output[k++] = tmp;
      }
    }
  }
  output[k] = '\0';

  if (bracketCounter1 != bracketCounter2 && flag == 0) {
    flag = 2;
  } else {
    strncpy(infix, output, k);
    infix[k] = '\0';
  }
  return flag;
}
