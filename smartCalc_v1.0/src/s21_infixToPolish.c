#include "s21_smartCalc.h"

//унарные операции и функции должны выкидываться сразу же после другого
//оператора, если нет скобки
// Функция для добавления элемента в начало стека
// тригонометрические функции и унарный минус это как оператор-операнд. он
// является незаменимым вторым операндом и работает как операнд

void push(struct Node **headRef, char newValue) {
  // Создание нового узла
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  newNode->value = newValue;

  newNode->next = *headRef;
  // Обновление указателя на голову списка
  *headRef = newNode;
}

// Функция для удаления и возврата верхнего элемента стека
char pop(struct Node **headRef) {  // ?? надо ли двойной указатель?
  if (*headRef == NULL) {
    fprintf(stdout, "Список пуст\n");
    return 0;
  }

  struct Node *temp = *headRef;
  char value = temp->value;
  *headRef = temp->next;

  free(temp);

  return value;
}

int isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
      ch == 'm') {  // ch == '~'
    return 1;       // oper
  }
  if (ch == 'c' || ch == 's' || ch == 't' || ch == 'a' || ch == 'b' ||
      ch == 'd' || ch == '~' || ch == 'q' || ch == 'n' || ch == 'l') {
    return 2;
  }
  return 0;
}
// Функция для возврата верхнего элемента стека без удаления
char peek(struct Node **headRef) {
  if ((*headRef) == NULL) {
    printf("Ошибка: стек пуст\n");
    return '\0';
  }
  return (*headRef)->value;
}
int getOperatorPriority(char ch) {  // supremacy precedenceOperator
  switch (ch) {
    case '+':
    case '-':
      return 1;
    case 'm':
      return 2;
    case '*':
    case '/':
      return 3;
    case '^':
      return 4;

    case '~':
      return 5;
    case 'c':
    case 's':
    case 't':
    case 'a':
    case 'b':
    case 'd':
    case 'q':
    case 'n':
    case 'l':
      return 6;

    default:
      return 0;
  }
}

// возвращает 0 - успех, а не успеха нет) Успешный успех!

int s21_infixToPolish(char *infix) {
  char output[256] = {0};
  Node *stack = malloc(sizeof(Node));  // надо выделять блять память
  stack->next = NULL;
  stack->value = 0;
  int i = -1;
  int k = 0;

  while (infix[++i]) {
    if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
      output[k++] = infix[i];
    } else if (infix[i] == '(') {
      push(&stack, infix[i]);

    } else if (isOperator(infix[i])) {
      if (stack->value == '(') {
        if (isOperator(infix[i]) != 2 || infix[i] == '~') {
          output[k++] = ' ';
        }
        push(&stack, infix[i]);
      } else if (getOperatorPriority(infix[i]) >
                 getOperatorPriority(stack->value)) {
        if (isOperator(infix[i]) != 2) {
          output[k++] = ' ';
        }
        push(&stack, infix[i]);
      } else if (getOperatorPriority(infix[i]) <=
                 getOperatorPriority(stack->value)) {
        while (stack &&
               getOperatorPriority(infix[i]) <=
                   getOperatorPriority(stack->value) &&
               stack->value != '(') {  //
          output[k++] = ' ';
          output[k++] = pop(&stack);
          output[k++] = ' ';
        }
        push(&stack, infix[i]);
      }
    } else if (infix[i] == ')') {
      while (stack != NULL && stack->value != '(') {
        output[k++] = ' ';
        output[k++] = pop(&stack);
      }
      if (stack && stack->value == '(') {
        pop(&stack);
      }
    }
  }
  while (stack != NULL) {
    if (stack->value != '(') {
      output[k++] = ' ';
      output[k++] = pop(&stack);
    } else {
      pop(&stack);
    }
  }

  output[k - 2] = '\0';

  free(stack);

  strcpy(infix, output);

  return 0;
}
