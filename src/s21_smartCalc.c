#include "s21_smartCalc.h"

// #All:
// #

int s21_smartCalc_v1_0(char *expression, double *result) {
  int err = 0;
  double res;
  // 1 ошибка в препроцессе

  printf("INFIX = '%s'\n", expression);
  err = s21_preprocess(expression);

  printf("%ds21_preprocess = '%s'\n", err, expression);

  if (err != 0) {
    return err;
  }

  err = s21_infixToPolish(expression);
  printf("%ds21_infixToPolish = '%s'\n", err, expression);

  if (err != 0) {
    return err;
  }
  err = s21_evaluatePostfixExpression(expression, &res);
  printf("%ds21_evaluatePostfixExpression = '%lf'\n", err, res);

  *result = res;

  return err;
}

// int main() {

//   char infix[255] = "55 *              3";
//   double res;
//   int err = s21_smartCalc_v1_0(infix, &res);

//   printf("res = %lf\n", res);

// }
