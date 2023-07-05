#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QShortcut>

#ifdef __cplusplus
extern "C" {
#endif
#include "../s21_smartCalc.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
  Q_OBJECT

 public:
  Calculator(QWidget *parent = nullptr);
  ~Calculator();
  Ui::Calculator *ui;
  void replace_x_y();

 private slots:
  void digits_numbers();
  void handleEqualShortcut();

  void handleButtonClicked();
  void on_pushButton_equals_clicked();

  void on_pushButton_dot_clicked();

  void operations1();
  void operations2();

  void on_pushButton_div_clicked();

  void on_pushButton_log10_clicked();

  void on_pushButton_graph_clicked();

  void on_pushButton_del_clicked();

  void on_plainTextEdit_textChanged();

  void on_plainTextEdit_blockCountChanged(int newBlockCount);

  void on_pushButton_clicked();

  void on_pushButton_10_clicked();

 private:
};

#endif  // CALCULATOR_H
