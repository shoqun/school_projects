#include "s21_smartCalc.h"

/*
  Вход: сумма вклада, срок размещения, процентная ставка, налоговая ставка,
  периодичность выплат, капитализация процентов,

  без вот этого: список пополнений, список частичных снятий

  Доп. вход: дд.мм.гггг начало пополнения, периодичность пополнений, сумма.

  Доп. вход: дд.мм.гггг начало частичных снятий, периодичность снятий, сумма.


  Выход: начисленные проценты, сумма налога, сумма на вкладе к концу срока

*/

// Функция для расчета суммы налога
double calculateTax(double ks, double interest, double taxRate) {
  /*
   Налог платится 1 раз в год за все вклады.
   ФНС рассчитывает сумму налога самостоятельно и направляет уведомление.
   Срок уплаты - 1 декабря года, следующего за расчетным.
 */
  double result = 0;
  double s0;
  s0 = ks * 1000000;

  if (interest > s0) {
    result = (result - s0) * taxRate;
  }
  return result;
}

// Функция для расчета начисленных процентов
// переводим всё в дни
double calculateAccruedInterest(double principal, double interestRate,
                                double duration, int compoundingPeriods) {
  // double rate = interestRate / 100.0; уже поделил

  if (compoundingPeriods == 365)
    compoundingPeriods = 1;
  else if (compoundingPeriods == 30)
    compoundingPeriods = 12;
  else if (compoundingPeriods == 1)
    compoundingPeriods = 365;

  double compoundedInterest =
      principal * (1 + (interestRate / compoundingPeriods));  // 365, 30, 1
  return compoundedInterest - principal;
}

int s21_deposit(char *filename, double principal, double duration,
                double interestRate, double taxRate, double ks,
                int compoundingPeriods, int capital) {
  FILE *file;

  file = fopen(filename, "a");

  if (file == NULL) {
    printf("Не удалось открыть файл.\n");
    return 17;
  }
  fprintf(file, "Сумма вклада %.2lf\n", principal);
  fprintf(file, "Срок размещения %.2lf месяцев\n",
          ((double)duration / 365 * 12));
  fprintf(file, "Процентная ставка %.2lf%% в год\n", interestRate);
  fprintf(file,
          "Периодичность выплат %lf в месяц(округлите до целого, если там "
          "чуть-чуть не хватает))\n",
          ((double)compoundingPeriods / 365 * 12));

  interestRate = interestRate / 100.0;  // Процентная ставка

  // principal = 10000.0; // Сумма вклада
  // duration = 365; // Срок размещения в днях

  // taxRate = 15.0; // Налоговая ставка
  // compoundingPeriods = 30; // Периодичность выплат и капитализации процентов
  //  double deposits[2] = {500.0, 1000.0}; // Список пополнений
  //  double withdrawals[2] = {300.0, 200.0}; // Список частичных снятий
  double accruedInterest = 0;
  int k = 0;
  for (int i = 1; i <= duration; i++) {
    // Расчет начисленных процентов

    if ((i - k) / compoundingPeriods >= 1) {
      double temp = accruedInterest;
      accruedInterest += calculateAccruedInterest(principal, interestRate,
                                                  duration, compoundingPeriods);
      k = i;
      fprintf(file,
              "Начисленные процеты %.2lf за %d расчетный период\n",
              accruedInterest - temp, i / compoundingPeriods);

      if (capital) {
        principal = principal + (accruedInterest - temp);
      }
    }
  }

  taxRate = taxRate / 100.0;
  double taxAmount = calculateTax(ks, accruedInterest, taxRate);

  fprintf(file, "Начисленные проценты за период = %.2lf\n", accruedInterest);
  fprintf(file,
          "Сумма налога, рассчитанная по формуле (1 000 000 * текущая ключевая "
          "ставка ЦБ), которая взимается свыше дохода %.2lf, равна %.2lf\n",
          ks * 1000000, taxAmount);
  fprintf(file, "Сумма на вкладе к концу срока равна %.2lf\n\n\n", principal);

  fclose(file);
  return 0;
}

// int main() {

//  char *filename =
//  "/Users/shogun/Desktop/cprojects/21school21/smartCalc/smartCalc_v1.0/C7_SmartCalc_v1.0-1/src/file.txt";

//  double ks = 9.5/100.0;
//  double principal = 100000;
//  int duration = 365;
//  double interestRate = 15;
//  int compoundingPeriods = 1; // 1 year = 365, 1 month  = 30, 1 day = 1;
//  double taxRate = 13;
//  int capital = 1;

//  s21_deposit(filename,principal,duration,interestRate, taxRate, ks,
//  compoundingPeriods, 1);

//  return 0;
//}
