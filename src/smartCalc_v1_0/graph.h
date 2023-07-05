#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>

#include "calculator.h"
#include "qcustomplot.h"
//#include

namespace Ui {
class graph;
}

class graph : public QDialog {
  Q_OBJECT

 public:
  explicit graph(Calculator *calculator, QWidget *parent = nullptr);
  ~graph();

 private slots:

 private:
  Ui::graph *ui;
  Calculator *m_calculator;
  double xBegin, xEnd, h, X, result;
  int N;
  QVector<double> x, y;
  void func();
};

#endif  // GRAPH_H
