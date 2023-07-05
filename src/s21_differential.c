#include "s21_smartCalc.h"

int s21_diffential(double pv, double r, double m, char *filename) {
  double *payment = (double *)malloc(sizeof(double) * 144);

  if (payment == NULL) {
    printf("Не удалось выделить память diff payment1\n");
    return 15;
  }

  int i = 0;
  double overpayment = pv;
  double default_day = 30.436875;
  double default_year = 365.2425;
  double pv_body = pv / m;
  double procent_body = (pv * r * default_day) / default_year;

  double all_payments = 0;

  FILE *file;  // Указатель на файл

  // Открытие файла в режиме записи ("w")
  file = fopen(filename, "a");

  if (file == NULL) {
    printf("Не удалось открыть файл.\n");
    return 17;
  }

  fprintf(file, "Выплата[Номер_Выплаты] = Сумма_Выплаты\n");
  fprintf(file, "Сумма кредита = %lf\n", pv);
  while (i < m) {
    if (i == 144) {
      payment = realloc(payment, i + 144);
      if (payment == NULL) {
        printf("Не удалось перевыделить память diff payment2\n");
        return 16;
      }
    }
    payment[i] = pv_body + procent_body;

    pv = pv - pv_body;

    procent_body = (pv * r * default_day) / default_year;

    all_payments += payment[i];

    fprintf(file, "payment[%d] %*s %6.2lf\n", i + 1, 2 - ((i + 1) / 10), "=",
            payment[i]);
    i++;
  }

  overpayment = (overpayment - all_payments) * (-1);

  fprintf(file, "\n\nThe full payout is = %.2lf\n", all_payments);

  fprintf(file, "Overpayment is = %.2lf\n\n", overpayment);
  // Закрытие файла
  fclose(file);

  return 0;
}

// int main() {
//   double pv = 120000;
//   double r = 0.15;
//   double m = 12;

//   s21_diffential(pv, r, m);
// }