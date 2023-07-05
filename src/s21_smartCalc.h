#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int stack_size;
  char value;

  struct Node *next;
} Node;

typedef struct Node2 {
  double value;

  struct Node2 *next;
} Node2;

// Функция для добавления нового узла в начало списка
void push(struct Node **headRef, char newData);
void append(struct Node **headRef, char newData);

char pop(struct Node **headRef);

// Функция для вычисления выражения в ОПН
int isOperator(char ch);
void push2(struct Node2 **headRef, double newValue);
double pop2(struct Node2 **headRef);
int isDigit(char ch);

int s21_preprocess(char *infix);
int s21_infixToPolish(char *postfix);
double s21_evaluatePostfixExpression(const char *expression, double *result);
int s21_smartCalc_v1_0(char *expression, double *result);

int s21_diffential(double pv, double r, double m, char *filename);
void clearLinkedList2(Node2 *list);  // delete

int s21_deposit(char *filename, double principal, double duration,
                double interestRate, double taxRate, double ks,
                int compoundingPeriods, int capital);
