#include "calculator.h"

#include "./ui_calculator.h"
#include "graph.h"
#include "ui_graph.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);

  connect(ui->pushButton_0, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_1, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_2, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_3, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_4, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_5, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_6, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_7, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_8, &QPushButton::clicked, this,
          &Calculator::digits_numbers);
  connect(ui->pushButton_9, &QPushButton::clicked, this,
          &Calculator::digits_numbers);

  connect(ui->pushButton_open_bracket, &QPushButton::clicked, this,
          &Calculator::operations1);
  connect(ui->pushButton_close_bracket, &QPushButton::clicked, this,
          &Calculator::operations1);

  connect(ui->pushButton_plus, &QPushButton::clicked, this,
          &Calculator::operations1);
  connect(ui->pushButton_minus, &QPushButton::clicked, this,
          &Calculator::operations1);
  connect(ui->pushButton_mul, &QPushButton::clicked, this,
          &Calculator::operations1);
  connect(ui->pushButton_power, &QPushButton::clicked, this,
          &Calculator::operations1);
  connect(ui->pushButton_mod, &QPushButton::clicked, this,
          &Calculator::operations1);

  connect(ui->pushButton_sin, &QPushButton::clicked, this,
          &Calculator::operations2);
  connect(ui->pushButton_cos, &QPushButton::clicked, this,
          &Calculator::operations2);
  connect(ui->pushButton_tan, &QPushButton::clicked, this,
          &Calculator::operations2);
  connect(ui->pushButton_sqrt, &QPushButton::clicked, this,
          &Calculator::operations2);
  connect(ui->pushButton_ln, &QPushButton::clicked, this,
          &Calculator::operations2);
  connect(ui->pushButton_asin, &QPushButton::clicked, this,
          &Calculator::operations2);
  connect(ui->pushButton_acos, &QPushButton::clicked, this,
          &Calculator::operations2);
  connect(ui->pushButton_atan, &QPushButton::clicked, this,
          &Calculator::operations2);

  ui->radioButton_annuit->setChecked(true);
  // когда пользователь нажимает клавишу "Enter" на клавиатуре,
  // будет вызываться слот on_pushButton_equals_clicked()
  // кнопки "=" в вашем классе Calculator.Ω
}

Calculator::~Calculator() { delete ui; }

void Calculator::handleButtonClicked() {
  QTextCursor cursor = ui->plainTextEdit->textCursor();
  cursor.movePosition(QTextCursor::End);
  ui->plainTextEdit->setTextCursor(cursor);
  ui->plainTextEdit->ensureCursorVisible();
}

void Calculator::replace_x_y() {
  QString replacedText1 = ui->plainTextEdit_x->toPlainText();
  QString replacedText2 = ui->plainTextEdit_xmin->toPlainText();
  QString replacedText3 = ui->plainTextEdit_xmax->toPlainText();
  QString replacedText4 = ui->plainTextEdit_ymin->toPlainText();
  QString replacedText5 = ui->plainTextEdit_ymax->toPlainText();

  if (replacedText1.isEmpty()) {
    ui->plainTextEdit_x->setPlainText("0");
    replacedText1 = ui->plainTextEdit_x->toPlainText();
  }
  if (ui->plainTextEdit_xmin->toPlainText().isEmpty()) {
    ui->plainTextEdit_xmin->setPlainText("-10");
  }
  if (ui->plainTextEdit_xmax->toPlainText().isEmpty()) {
    ui->plainTextEdit_xmax->setPlainText("10");
  }
  if (ui->plainTextEdit_ymin->toPlainText().isEmpty()) {
    ui->plainTextEdit_ymin->setPlainText("-10");
  }
  if (ui->plainTextEdit_ymax->toPlainText().isEmpty()) {
    ui->plainTextEdit_ymax->setPlainText("10");
  }

  bool containsOnlyDigits = true;
  for (const QChar &ch : replacedText1) {
    if (!ch.isDigit()) {
      containsOnlyDigits = false;
      break;
    }
  }
  if (!containsOnlyDigits) {
    ui->plainTextEdit_x->setPlainText("0");
    replacedText1 = ui->plainTextEdit_x->toPlainText();
  }

  containsOnlyDigits = true;
  for (const QChar &ch : replacedText2) {
    if (!ch.isDigit()) {
      containsOnlyDigits = false;
      break;
    }
  }
  if (!containsOnlyDigits) {
    ui->plainTextEdit_xmin->setPlainText("-10");
    replacedText2 = ui->plainTextEdit_xmin->toPlainText();
  }

  containsOnlyDigits = true;
  for (const QChar &ch : replacedText3) {
    if (!ch.isDigit()) {
      containsOnlyDigits = false;
      break;
    }
  }
  if (!containsOnlyDigits) {
    ui->plainTextEdit_xmax->setPlainText("10");
    replacedText2 = ui->plainTextEdit_xmax->toPlainText();
  }

  containsOnlyDigits = true;
  for (const QChar &ch : replacedText4) {
    if (!ch.isDigit()) {
      containsOnlyDigits = false;
      break;
    }
  }
  if (!containsOnlyDigits) {
    ui->plainTextEdit_ymin->setPlainText("-10");
    replacedText2 = ui->plainTextEdit_ymin->toPlainText();
  }

  containsOnlyDigits = true;
  for (const QChar &ch : replacedText5) {
    if (!ch.isDigit()) {
      containsOnlyDigits = false;
      break;
    }
  }
  if (!containsOnlyDigits) {
    ui->plainTextEdit_ymax->setPlainText("10");
    replacedText2 = ui->plainTextEdit_ymax->toPlainText();
  }
}

void Calculator::digits_numbers() {
  // ui->plainTextEdit->textCursor().movePosition(QtextCursor::End);

  ui->plainTextEdit->canPaste();

  QPushButton *button = (QPushButton *)sender();
  QString text = ui->plainTextEdit->toPlainText();  // get text from input field
  QString number = button->text();
  QString result = text + number;
  ui->plainTextEdit->setPlainText(result);

  handleButtonClicked();
}

void Calculator::operations1() {
  QPushButton *button = (QPushButton *)sender();

  QString text = ui->plainTextEdit->toPlainText();  // get text from input field
  QString operation = button->text();
  QString result = text + operation;
  ui->plainTextEdit->setPlainText(result);

  handleButtonClicked();
}

void Calculator::operations2() {
  QPushButton *button = (QPushButton *)sender();

  QString text = ui->plainTextEdit->toPlainText();  // get text from input field
  QString operation = button->text();
  QString result = text + operation + "(";
  ui->plainTextEdit->setPlainText(result);

  handleButtonClicked();
}

void Calculator::handleEqualShortcut() {
  // QPushButton *button = (QPushButton *)sender();

  on_pushButton_equals_clicked();
}

void Calculator::on_pushButton_equals_clicked() {
  int err = 0;
  replace_x_y();

  QString originalText = ui->plainTextEdit->toPlainText();
  QString modifiedText = originalText;
  QString plainText_x = ui->plainTextEdit_x->toPlainText();
  modifiedText.replace("x", "(" + plainText_x + ")");

  ui->plainTextEdit->setPlainText(modifiedText);

  QString text = ui->plainTextEdit->toPlainText();
  QByteArray byteArray = text.toUtf8();
  char *data = byteArray.data();
  if (byteArray.length() > 255) {
    ui->plainTextEdit->setPlainText("Error, length is more than 255");
  } else {
    char expression[256];
    strncpy(expression, data, 255);
    double res = 0;
    err = s21_smartCalc_v1_0(expression, &res);
    if (err == 0) {
      QString text = QString::number(res, 'f', 7);
      ui->plainTextEdit->setPlainText(text);
    } else if (err == 10) {
      ui->plainTextEdit->setPlainText("Error. Недостаточно операндов");
    } else if (err == 11) {
      ui->plainTextEdit->setPlainText("Error. Некорректно написан оператор");
    } else if (err == 12) {
      ui->plainTextEdit->setPlainText(
          "Error. Число в корне должно быть положительным");
    } else if (err == 1) {
      ui->plainTextEdit->setPlainText("Error. Некорректные символы");
    } else if (err == 2) {
      ui->plainTextEdit->setPlainText("Error. Ошибка со скобками");
    } else if (err == 3) {
      ui->plainTextEdit->setPlainText("Error. Ошибка с точкой");
    } else if (err == 4) {
      ui->plainTextEdit->setPlainText(
          "Error. Ошибка преобразования строки в число");
    } else if (err == 5) {
      ui->plainTextEdit->setPlainText("Error. Деление на ноль");
    } else if (err == 6) {
      ui->plainTextEdit->setPlainText("Error. Некорректный оператор");
    }
  }

  handleButtonClicked();
}

void Calculator::on_pushButton_dot_clicked() {
  ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + ".");
  handleButtonClicked();
}

void Calculator::on_pushButton_div_clicked() {
  // if (!ui->plainTextEdit->toPlainText().contains('/'))

  ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "/");
  handleButtonClicked();
}

void Calculator::on_pushButton_log10_clicked() {
  ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "log(");
  handleButtonClicked();
}

void Calculator::on_pushButton_graph_clicked() {
  // replace_x_y();
  QString temp = ui->plainTextEdit->toPlainText();

  on_pushButton_equals_clicked();

  if (ui->plainTextEdit->toPlainText().contains("Error")) {
  } else {
    ui->plainTextEdit->setPlainText(temp);
    graph *w2 = new graph(this);
    w2->show();
  }

  // w2.exec();
}

void Calculator::on_pushButton_del_clicked() {
  ui->plainTextEdit->setPlainText("");
}

void Calculator::on_plainTextEdit_textChanged() {
  static bool isProcessingText = false;  // Flag to prevent recursive call

  if (!isProcessingText && ui->plainTextEdit->toPlainText().contains("\n")) {
    isProcessingText = true;
    on_pushButton_equals_clicked();
    isProcessingText = false;
  }
}

void Calculator::on_plainTextEdit_blockCountChanged(int newBlockCount) {}

void Calculator::on_pushButton_clicked() {
  QString Present_Value = ui->lineEdit->text();

  double pv = Present_Value.toDouble();

  QString percent = ui->lineEdit_2->text();

  percent.replace("%", "");

  double r = percent.toDouble() / 100.0;
  double n = ui->lineEdit_3->text().toDouble();
  double payment_per_month = 0;
  double overpayment = 0;
  double all_payment = 0;
  if (ui->radioButton_annuit->isChecked()) {
    r = r / 12;
    payment_per_month = pv * (r * pow((1 + r), n)) / (pow((1 + r), n) - 1);
    ui->label_payment_month->setText(
        QString::number(payment_per_month, 'f', 2));

    overpayment = payment_per_month * n - pv;
    all_payment = payment_per_month * n;

    ui->label_overpayment->setText(QString::number(overpayment, 'f', 2));
    ui->label_all_payment->setText(QString::number(all_payment, '7', 2));

  } else if (ui->radioButton_different->isChecked()) {
    QString selectedPath = QFileDialog::getExistingDirectory(
        nullptr, "Выберите директорию", QDir::homePath());

    if (!selectedPath.isEmpty()) {
      qDebug() << "Выбранная директория: " << selectedPath;
      // Используйте выбранный путь для сохранения файла
    }
    QString file = selectedPath + "/diffential_payments.txt";
    QByteArray byteArray = file.toUtf8();
    char* filename = new char[byteArray.size() + 1];
    strcpy(filename, byteArray.data());

    int flag = s21_diffential(pv, r, n, filename);
    delete[] filename;
    if (flag == 0) {
      ui->label_payment_month->setText(
          "Вывод в текстовом файле differential_payments_di.txt");

    } else if (flag == 15) {
      ui->label_payment_month->setText(
          "Не удалось выделить память diff payment1");
    } else if (flag == 16) {
      ui->label_payment_month->setText(
          "Не удалось перевыделить память diff payment2");
    } else if (flag == 17) {
      ui->label_payment_month->setText(
          "Не удалось открыть файл differential_payments_di.txt");
    }
  }
}

void Calculator::on_pushButton_10_clicked() {
  bool ok;
  double principal = ui->lineEdit_principal->text().toDouble(&ok);
  double duration = ui->lineEdit_duration->text().toDouble(&ok);
  double interestRate = ui->doubleSpinBox_interestRate->value();
  double taxRate = ui->doubleSpinBox_taxRate->value();
  double ks = ui->doubleSpinBox_ks->value();
  ;
  int capital = 0;
  if (ui->checkBox_capital->isChecked()) {
    capital = 1;
  }

  double compoundingPeriods = 0;

  if (ui->listWidget_compoundingPeriods->item(0)->isSelected()) {
    compoundingPeriods = 1;
  } else if (ui->listWidget_compoundingPeriods->item(1)->isSelected()) {
    compoundingPeriods = 7;
  } else if (ui->listWidget_compoundingPeriods->item(2)->isSelected()) {
    compoundingPeriods = 30.4;
  } else if (ui->listWidget_compoundingPeriods->item(3)->isSelected()) {
    compoundingPeriods = 90.5;
  } else if (ui->listWidget_compoundingPeriods->item(4)->isSelected()) {
    compoundingPeriods = 182.5;
  } else if (ui->listWidget_compoundingPeriods->item(5)->isSelected()) {
    compoundingPeriods = 365.25;
  } else if (ui->listWidget_compoundingPeriods->item(6)->isSelected()) {
    compoundingPeriods = duration;
  }

  if (ui->listWidget_duration->item(0)->isSelected()) {
    // ok
  } else if (ui->listWidget_duration->item(1)->isSelected()) {
    duration = duration * 30.4;
  } else if (ui->listWidget_duration->item(2)->isSelected()) {
    duration = duration * 365.25;
  }

  if (!ok) {
    ui->label_10_error->setText("Ошибка, введите корректные значения");
  } else {
    QString selectedPath = QFileDialog::getExistingDirectory(
        nullptr, "Выберите директорию", QDir::homePath());


    if (!selectedPath.isEmpty()) {
      qDebug() << "Выбранная директория: " << selectedPath;
      // Используйте выбранный путь для сохранения файла
    }
    QString file = selectedPath + "/deposit_payment.txt";
    QByteArray byteArray = file.toUtf8();
    char* filename = new char[byteArray.size() + 1];
    strcpy(filename, byteArray.data());


    s21_deposit(filename, principal, duration, interestRate, taxRate, ks,
                compoundingPeriods, capital);

    delete[] filename;
  }
}
