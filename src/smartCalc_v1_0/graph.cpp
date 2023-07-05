#include "graph.h"

#include <QtMath>

#include "./ui_calculator.h"
#include "calculator.h"
#include "ui_graph.h"

graph::graph(Calculator *calculator, QWidget *parent)
    : QDialog(parent), m_calculator(calculator), ui(new Ui::graph) {
  ui->setupUi(this);

  //    x.clear();
  //    y.clear();

  result = 0;
  h = 0.001;  // шаг
  xBegin = m_calculator->ui->plainTextEdit_xmin->toPlainText().toDouble();
  xEnd = m_calculator->ui->plainTextEdit_xmax->toPlainText().toDouble();

  ui->widget->xAxis->setRange(
      m_calculator->ui->plainTextEdit_xmin->toPlainText().toDouble(),
      m_calculator->ui->plainTextEdit_xmax->toPlainText().toDouble());  //
  ui->widget->yAxis->setRange(
      m_calculator->ui->plainTextEdit_ymin->toPlainText().toDouble(),
      m_calculator->ui->plainTextEdit_ymax->toPlainText().toDouble());

  QString text = m_calculator->ui->plainTextEdit->toPlainText();
  QString modifiedText = text;

  char expression[256] = {0};
  for (X = xBegin; X <= xEnd; X += h) {
    modifiedText.replace("x", "(" + QString::number(X, 'f', 8) + ")");

    QByteArray byteArray = modifiedText.toUtf8();
    char *data = byteArray.data();

    strncpy(expression, data, 255);

    int flag = 0;
    flag = s21_smartCalc_v1_0(data, &result);
    printf("result of surce = %lf \n", result);
    if (flag == 0 && result == result) {
      x.push_back(X);
      y.push_back(result);
    }

    modifiedText = text;
  }

  ui->widget->addGraph();

  ui->widget->graph(0)->addData(x, y);
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  // ui->widget->setNotAntialiasedElements(QCP::aeAll);
  // ui->widget->graph()->setAdaptiveSampling(false);
  ui->widget->replot();
}

graph::~graph() { delete ui; }
