#include "s21_smartCalc.h"

//надо сделать новый пуш, новый поп новый ноде для этого файла.
// тригонометрические функции и унарный минус это как оператор-операнд. он
// является незаменимым вторым операндом и работает как операнд

void push2(struct Node2 **headRef, double newValue) {
  // Создание нового узла

  struct Node2 *newNode = (struct Node2 *)malloc(sizeof(struct Node2));

  newNode->value = newValue;

  newNode->next = *headRef;
  // Обновление указателя на голову списка
  *headRef = newNode;
}

double pop2(struct Node2 **headRef) {
  if (*headRef == NULL) {
    fprintf(stdout, "Список пуст\n");
    return 0;
  }

  struct Node2 *temp = *headRef;
  *headRef = (*headRef)->next;
  double value = temp->value;
  free(temp);
  return value;
}

int isDigit(char ch) {
  if ((ch >= '0' && ch <= '9') || ch == '.') {
    return 1;
  }
  return 0;
}

void clearLinkedList2(Node2 *list) {
  while (list != NULL) {
    struct Node2 *temp = list;
    list = temp->next;
    free(temp);
  }
  printf("Список пуст\n");
  return;
}

// Функция для вычисления выражения в ОПН

// return 2 - ("Некорректный оператор\n");
// return 1 - ("Ошибка преобразования строки в число");

// 0 - успех, 4 - Ошибка преобразования строки в число 5 - Деление на ноль
// 6 - Некорректный оператор
double s21_evaluatePostfixExpression(
    const char *expression, double *result) {  // expression from input box
  int i = -1;
  Node2 *list = (Node2 *)malloc(sizeof(Node2));  // надо выделять блять память
  // stack->stack_size = 0; // забыл для чего
  list->next = NULL;
  list->value = 0;
  int k = 0;
  int operandCount = 0;
  *result = 0;
  char number[30] = {0};  // ограничение числа 30 символами  restriction
  int flag = 0;
  while (expression[++i] != '\0' && !flag) {
    // если число, добавить в стек
    if (isDigit(expression[i])) {
      k = 0;
      while (isDigit(expression[i])) {
        number[k++] = expression[i++];
      }
      i = i - 1;

      number[k] = '\0';

      // convert char to number
      char *nstr = number;

      // Если преобразование не может быть выполнено, то возвращается 0, а по
      // адресу указанному в переменной endstr записывается указатель на начало
      // строки str.
      char *tstr = nstr;
      double a = strtod(nstr, &nstr);

      if (a == 0.0 && tstr[0] != '0') {  // надеюсь ошибок не будет
        printf("Ошибка преобразования строки в число");
        flag = 4;
      }

      push2(&list, a);
      operandCount++;

    } else if (isOperator(expression[i])) {
      if (isOperator(expression[i]) == 1) {
        // Если текущий символ - оператор (1), выньте два операнда из стека,
        // примените оператор и поместите результат обратно в стек

        if (operandCount - 2 < 0) {
          printf("Недостаточно операндов\n");
          flag = 10;
          break;
        }
        operandCount -= 2;
        double operand2 = pop2(&list);
        double operand1 = pop2(&list);

        switch (expression[i]) {
          case '+':
            *result = operand1 + operand2;
            break;
          case '-':
            *result = operand1 - operand2;
            break;
          case '*':
            *result = operand1 * operand2;
            break;
          case '/':
            if (operand2 == 0) {
              printf("Деление на ноль\n");
              flag = 5;
            } else {
              *result = operand1 / operand2;
            }
            break;
          case '^':
            *result = pow(operand1, operand2);
            break;
          case 'm':
            *result = fmod(operand1, operand2);
            break;
          default:
            printf("Некорректный оператор\n");
            flag = 6;
        }

      } else if (isOperator(expression[i]) == 2) {
        // Если текущий символ - функция (2), выньте 1(один) операнд из стека,
        // примените оператор и поместите результат обратно в стек
        if (operandCount - 1 < 0) {
          printf("1Недостаточно операндов\n");
          flag = 10;
          break;
        }
        operandCount -= 1;
        double operand1 = pop2(&list);
        switch (expression[i]) {
          case '~':
            *result = -operand1;
            break;
          case 'c':
            *result = cos(operand1);
            break;
          case 's':
            *result = sin(operand1);
            break;
          case 't':
            if (cos(operand1) >= 1e-07) {
              printf("Число в корне должно быть положительным\n");
              *result = tan(operand1);
            } else {
              *result = tan(operand1);
            }

            break;
          case 'a':
            *result = acos(operand1);
            break;
          case 'b':
            *result = asin(operand1);
            break;
          case 'd':
            *result = atan(operand1);
            break;
          case 'q':
            if (operand1 < 0) {
              printf("Число в корне должно быть положительным\n");
              flag = 12;
            } else {
              *result = sqrt(operand1);
            }
            break;
          case 'n':
            *result = log(operand1);
            break;
          case 'l':
            *result = log10(operand1);
            break;
          default:
            printf("Некорректный оператор\n");
            flag = 2;
        }
      }
      push2(&list, *result);
      operandCount++;
    }
  }

  *result = pop2(&list);
  clearLinkedList2(list);
  if (flag != 0) {
    *result = 0;
  }
  return flag;
}
