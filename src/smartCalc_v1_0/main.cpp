#include <QApplication>

#include "calculator.h"
#include "graph.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Calculator w1;
  w1.show();

  return a.exec();
}
