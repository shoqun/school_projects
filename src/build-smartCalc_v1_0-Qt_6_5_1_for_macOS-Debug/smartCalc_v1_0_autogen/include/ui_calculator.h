/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Tab;
    QPushButton *pushButton_dot_3;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_7;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_4;
    QPushButton *pushButton_plus_minus_3;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_del;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_1;
    QPushButton *pushButton_div;
    QPushButton *pushButton_2;
    QPushButton *pushButton_dot_2;
    QPushButton *pushButton_0;
    QPushButton *pushButton_log10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_equals;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_graph;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_5;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_open_bracket;
    QPushButton *pushButton_6;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_power;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_8;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_close_bracket;
    QPlainTextEdit *plainTextEdit_ymax;
    QPlainTextEdit *plainTextEdit_xmin;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_ymin;
    QPlainTextEdit *plainTextEdit_x;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_xmax;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_5;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_annuit;
    QRadioButton *radioButton_different;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_overpayment;
    QLabel *label_16;
    QLabel *label_all_payment;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *pushButton;
    QLabel *label_15;
    QLineEdit *lineEdit_3;
    QLabel *label_22;
    QLabel *label_payment_month;
    QLabel *label_23;
    QWidget *tab;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *checkBox_capital;
    QListWidget *listWidget_compoundingPeriods;
    QPushButton *pushButton_10;
    QListWidget *listWidget_duration;
    QDoubleSpinBox *doubleSpinBox_taxRate;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_interestRate;
    QLabel *label_13;
    QLineEdit *lineEdit_principal;
    QLineEdit *lineEdit_duration;
    QLabel *label_10_error;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_ks;
    QLabel *label_24;
    QLabel *label_25;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName("Calculator");
        Calculator->resize(614, 416);
        Calculator->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 601, 401));
        Tab = new QWidget();
        Tab->setObjectName("Tab");
        pushButton_dot_3 = new QPushButton(Tab);
        pushButton_dot_3->setObjectName("pushButton_dot_3");
        pushButton_dot_3->setGeometry(QRect(229, 314, 61, 61));
        pushButton_dot_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_dot_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_dot_3->setCheckable(false);
        pushButton_sin = new QPushButton(Tab);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(229, 70, 61, 61));
        pushButton_sin->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_sin->setCheckable(false);
        pushButton_7 = new QPushButton(Tab);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(351, 131, 61, 61));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_7->setCheckable(false);
        pushButton_sqrt = new QPushButton(Tab);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(290, 131, 61, 61));
        pushButton_sqrt->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_sqrt->setCheckable(false);
        pushButton_4 = new QPushButton(Tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(351, 192, 61, 61));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4->setCheckable(false);
        pushButton_plus_minus_3 = new QPushButton(Tab);
        pushButton_plus_minus_3->setObjectName("pushButton_plus_minus_3");
        pushButton_plus_minus_3->setGeometry(QRect(169, 253, 61, 61));
        pushButton_plus_minus_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_plus_minus_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_plus_minus_3->setCheckable(false);
        pushButton_tan = new QPushButton(Tab);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(229, 192, 61, 61));
        pushButton_tan->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_tan->setCheckable(false);
        pushButton_del = new QPushButton(Tab);
        pushButton_del->setObjectName("pushButton_del");
        pushButton_del->setGeometry(QRect(534, 70, 61, 61));
        pushButton_del->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_del->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" background-color: rgb(255, 151, 57);\n"
"color: white;\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_del->setCheckable(false);
        pushButton_acos = new QPushButton(Tab);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(169, 131, 61, 61));
        pushButton_acos->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_acos->setCheckable(false);
        pushButton_1 = new QPushButton(Tab);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(351, 253, 61, 61));
        pushButton_1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_1->setCheckable(false);
        pushButton_div = new QPushButton(Tab);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setGeometry(QRect(534, 131, 61, 61));
        pushButton_div->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_div->setCheckable(false);
        pushButton_2 = new QPushButton(Tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(412, 253, 61, 61));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_2->setCheckable(false);
        pushButton_dot_2 = new QPushButton(Tab);
        pushButton_dot_2->setObjectName("pushButton_dot_2");
        pushButton_dot_2->setGeometry(QRect(169, 314, 61, 61));
        pushButton_dot_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_dot_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_dot_2->setCheckable(false);
        pushButton_0 = new QPushButton(Tab);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(351, 314, 61, 61));
        pushButton_0->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_0->setCheckable(false);
        pushButton_log10 = new QPushButton(Tab);
        pushButton_log10->setObjectName("pushButton_log10");
        pushButton_log10->setGeometry(QRect(290, 314, 61, 61));
        pushButton_log10->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_log10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_log10->setCheckable(false);
        pushButton_9 = new QPushButton(Tab);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(473, 131, 61, 61));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_9->setCheckable(false);
        pushButton_percent = new QPushButton(Tab);
        pushButton_percent->setObjectName("pushButton_percent");
        pushButton_percent->setGeometry(QRect(473, 70, 61, 61));
        pushButton_percent->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_percent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_percent->setCheckable(false);
        pushButton_equals = new QPushButton(Tab);
        pushButton_equals->setObjectName("pushButton_equals");
        pushButton_equals->setGeometry(QRect(473, 314, 61, 61));
        pushButton_equals->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_equals->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(0, 128, 255);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_equals->setCheckable(false);
        pushButton_dot = new QPushButton(Tab);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(412, 314, 61, 61));
        pushButton_dot->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_dot->setCheckable(false);
        pushButton_graph = new QPushButton(Tab);
        pushButton_graph->setObjectName("pushButton_graph");
        pushButton_graph->setGeometry(QRect(169, 253, 121, 61));
        QFont font;
        font.setPointSize(13);
        pushButton_graph->setFont(font);
        pushButton_graph->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_graph->setCheckable(false);
        pushButton_ln = new QPushButton(Tab);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(290, 253, 61, 61));
        pushButton_ln->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_ln->setCheckable(false);
        pushButton_mul = new QPushButton(Tab);
        pushButton_mul->setObjectName("pushButton_mul");
        pushButton_mul->setGeometry(QRect(534, 253, 61, 61));
        pushButton_mul->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_mul->setCheckable(false);
        pushButton_mod = new QPushButton(Tab);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(290, 70, 61, 61));
        pushButton_mod->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_mod->setCheckable(false);
        pushButton_cos = new QPushButton(Tab);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(229, 131, 61, 61));
        pushButton_cos->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_cos->setCheckable(false);
        pushButton_5 = new QPushButton(Tab);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(412, 192, 61, 61));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_5->setCheckable(false);
        pushButton_asin = new QPushButton(Tab);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(169, 70, 61, 61));
        pushButton_asin->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_asin->setCheckable(false);
        pushButton_open_bracket = new QPushButton(Tab);
        pushButton_open_bracket->setObjectName("pushButton_open_bracket");
        pushButton_open_bracket->setGeometry(QRect(351, 70, 61, 61));
        pushButton_open_bracket->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_open_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_open_bracket->setCheckable(false);
        pushButton_6 = new QPushButton(Tab);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(473, 192, 61, 61));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_6->setCheckable(false);
        pushButton_minus = new QPushButton(Tab);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(534, 192, 61, 61));
        pushButton_minus->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_minus->setCheckable(false);
        pushButton_power = new QPushButton(Tab);
        pushButton_power->setObjectName("pushButton_power");
        pushButton_power->setGeometry(QRect(290, 192, 61, 61));
        pushButton_power->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_power->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_power->setCheckable(false);
        pushButton_plus = new QPushButton(Tab);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(534, 314, 61, 61));
        pushButton_plus->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_plus->setCheckable(false);
        pushButton_3 = new QPushButton(Tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(473, 253, 61, 61));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_3->setCheckable(false);
        plainTextEdit = new QPlainTextEdit(Tab);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(169, 0, 426, 71));
        QFont font1;
        font1.setPointSize(20);
        plainTextEdit->setFont(font1);
        pushButton_8 = new QPushButton(Tab);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(412, 131, 61, 61));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_8->setCheckable(false);
        pushButton_atan = new QPushButton(Tab);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(169, 192, 61, 61));
        pushButton_atan->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_atan->setCheckable(false);
        pushButton_close_bracket = new QPushButton(Tab);
        pushButton_close_bracket->setObjectName("pushButton_close_bracket");
        pushButton_close_bracket->setGeometry(QRect(412, 70, 61, 61));
        pushButton_close_bracket->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_close_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_close_bracket->setCheckable(false);
        plainTextEdit_ymax = new QPlainTextEdit(Tab);
        plainTextEdit_ymax->setObjectName("plainTextEdit_ymax");
        plainTextEdit_ymax->setGeometry(QRect(60, 340, 104, 31));
        QFont font2;
        font2.setPointSize(17);
        plainTextEdit_ymax->setFont(font2);
        plainTextEdit_xmin = new QPlainTextEdit(Tab);
        plainTextEdit_xmin->setObjectName("plainTextEdit_xmin");
        plainTextEdit_xmin->setGeometry(QRect(60, 250, 104, 31));
        plainTextEdit_xmin->setFont(font2);
        plainTextEdit_xmin->setStyleSheet(QString::fromUtf8("text-align: center;"));
        label_2 = new QLabel(Tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 250, 51, 31));
        label_2->setFont(font2);
        plainTextEdit_ymin = new QPlainTextEdit(Tab);
        plainTextEdit_ymin->setObjectName("plainTextEdit_ymin");
        plainTextEdit_ymin->setGeometry(QRect(60, 310, 104, 31));
        plainTextEdit_ymin->setFont(font2);
        plainTextEdit_x = new QPlainTextEdit(Tab);
        plainTextEdit_x->setObjectName("plainTextEdit_x");
        plainTextEdit_x->setGeometry(QRect(60, 220, 104, 31));
        plainTextEdit_x->setFont(font2);
        label_4 = new QLabel(Tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 280, 51, 31));
        label_4->setFont(font2);
        plainTextEdit_xmax = new QPlainTextEdit(Tab);
        plainTextEdit_xmax->setObjectName("plainTextEdit_xmax");
        plainTextEdit_xmax->setGeometry(QRect(60, 280, 104, 31));
        plainTextEdit_xmax->setFont(font2);
        plainTextEdit_xmax->setStyleSheet(QString::fromUtf8("text-align: center;"));
        label_3 = new QLabel(Tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(7, 310, 51, 31));
        label_3->setFont(font2);
        label = new QLabel(Tab);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 220, 51, 31));
        label->setFont(font2);
        label_5 = new QLabel(Tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(7, 330, 51, 41));
        label_5->setFont(font2);
        tabWidget->addTab(Tab, QString());
        plainTextEdit->raise();
        pushButton_dot_3->raise();
        pushButton_sin->raise();
        pushButton_7->raise();
        pushButton_sqrt->raise();
        pushButton_4->raise();
        pushButton_plus_minus_3->raise();
        pushButton_tan->raise();
        pushButton_del->raise();
        pushButton_acos->raise();
        pushButton_1->raise();
        pushButton_div->raise();
        pushButton_2->raise();
        pushButton_dot_2->raise();
        pushButton_0->raise();
        pushButton_log10->raise();
        pushButton_9->raise();
        pushButton_percent->raise();
        pushButton_equals->raise();
        pushButton_dot->raise();
        pushButton_graph->raise();
        pushButton_ln->raise();
        pushButton_mul->raise();
        pushButton_mod->raise();
        pushButton_cos->raise();
        pushButton_5->raise();
        pushButton_asin->raise();
        pushButton_open_bracket->raise();
        pushButton_6->raise();
        pushButton_minus->raise();
        pushButton_power->raise();
        pushButton_plus->raise();
        pushButton_3->raise();
        pushButton_8->raise();
        pushButton_atan->raise();
        pushButton_close_bracket->raise();
        plainTextEdit_ymax->raise();
        plainTextEdit_xmin->raise();
        label_2->raise();
        plainTextEdit_ymin->raise();
        plainTextEdit_x->raise();
        label_4->raise();
        plainTextEdit_xmax->raise();
        label_3->raise();
        label->raise();
        label_5->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(130, 20, 113, 21));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 60, 113, 21));
        radioButton_annuit = new QRadioButton(tab_2);
        radioButton_annuit->setObjectName("radioButton_annuit");
        radioButton_annuit->setGeometry(QRect(30, 120, 121, 20));
        radioButton_different = new QRadioButton(tab_2);
        radioButton_different->setObjectName("radioButton_different");
        radioButton_different->setGeometry(QRect(170, 120, 171, 20));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 170, 91, 31));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(280, 170, 71, 31));
        label_overpayment = new QLabel(tab_2);
        label_overpayment->setObjectName("label_overpayment");
        label_overpayment->setGeometry(QRect(280, 210, 261, 20));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(280, 250, 91, 41));
        label_all_payment = new QLabel(tab_2);
        label_all_payment->setObjectName("label_all_payment");
        label_all_payment->setGeometry(QRect(280, 300, 271, 31));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 20, 101, 16));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 60, 101, 31));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(30, 100, 201, 20));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 150, 58, 16));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 50, 100, 32));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(250, 60, 41, 20));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(350, 20, 113, 21));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(260, 20, 101, 21));
        label_payment_month = new QLabel(tab_2);
        label_payment_month->setObjectName("label_payment_month");
        label_payment_month->setGeometry(QRect(30, 210, 181, 161));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(470, 20, 101, 21));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 20, 111, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 60, 121, 21));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(430, 20, 161, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 120, 131, 16));
        checkBox_capital = new QCheckBox(tab);
        checkBox_capital->setObjectName("checkBox_capital");
        checkBox_capital->setGeometry(QRect(10, 180, 191, 20));
        listWidget_compoundingPeriods = new QListWidget(tab);
        new QListWidgetItem(listWidget_compoundingPeriods);
        new QListWidgetItem(listWidget_compoundingPeriods);
        new QListWidgetItem(listWidget_compoundingPeriods);
        new QListWidgetItem(listWidget_compoundingPeriods);
        new QListWidgetItem(listWidget_compoundingPeriods);
        new QListWidgetItem(listWidget_compoundingPeriods);
        new QListWidgetItem(listWidget_compoundingPeriods);
        listWidget_compoundingPeriods->setObjectName("listWidget_compoundingPeriods");
        listWidget_compoundingPeriods->setGeometry(QRect(430, 50, 151, 131));
        pushButton_10 = new QPushButton(tab);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(50, 260, 501, 71));
        pushButton_10->setFont(font1);
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(0, 183, 255);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        listWidget_duration = new QListWidget(tab);
        new QListWidgetItem(listWidget_duration);
        new QListWidgetItem(listWidget_duration);
        new QListWidgetItem(listWidget_duration);
        listWidget_duration->setObjectName("listWidget_duration");
        listWidget_duration->setGeometry(QRect(240, 50, 151, 61));
        doubleSpinBox_taxRate = new QDoubleSpinBox(tab);
        doubleSpinBox_taxRate->setObjectName("doubleSpinBox_taxRate");
        doubleSpinBox_taxRate->setGeometry(QRect(150, 150, 62, 22));
        doubleSpinBox_taxRate->setValue(13.000000000000000);
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 150, 131, 16));
        doubleSpinBox_interestRate = new QDoubleSpinBox(tab);
        doubleSpinBox_interestRate->setObjectName("doubleSpinBox_interestRate");
        doubleSpinBox_interestRate->setGeometry(QRect(150, 120, 62, 22));
        doubleSpinBox_interestRate->setValue(15.000000000000000);
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(220, 120, 131, 21));
        lineEdit_principal = new QLineEdit(tab);
        lineEdit_principal->setObjectName("lineEdit_principal");
        lineEdit_principal->setGeometry(QRect(130, 20, 101, 21));
        lineEdit_duration = new QLineEdit(tab);
        lineEdit_duration->setObjectName("lineEdit_duration");
        lineEdit_duration->setGeometry(QRect(130, 60, 101, 21));
        label_10_error = new QLabel(tab);
        label_10_error->setObjectName("label_10_error");
        label_10_error->setGeometry(QRect(130, 210, 331, 51));
        label_10_error->setFont(font1);
        label_17 = new QLabel(tab);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(240, 190, 131, 16));
        doubleSpinBox_ks = new QDoubleSpinBox(tab);
        doubleSpinBox_ks->setObjectName("doubleSpinBox_ks");
        doubleSpinBox_ks->setGeometry(QRect(370, 190, 62, 22));
        doubleSpinBox_ks->setValue(9.500000000000000);
        label_24 = new QLabel(tab);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(440, 190, 51, 21));
        label_25 = new QLabel(tab);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(220, 150, 131, 21));
        tabWidget->addTab(tab, QString());
        Calculator->setCentralWidget(centralwidget);

        retranslateUi(Calculator);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        pushButton_dot_3->setText(QCoreApplication::translate("Calculator", "deposit", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("Calculator", "sin", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("Calculator", "sqrt", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        pushButton_plus_minus_3->setText(QCoreApplication::translate("Calculator", "x", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("Calculator", "tan", nullptr));
        pushButton_del->setText(QCoreApplication::translate("Calculator", "\320\241", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("Calculator", "acos", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        pushButton_div->setText(QCoreApplication::translate("Calculator", "\303\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        pushButton_dot_2->setText(QCoreApplication::translate("Calculator", "credit", nullptr));
        pushButton_0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        pushButton_log10->setText(QCoreApplication::translate("Calculator", "log10", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        pushButton_percent->setText(QCoreApplication::translate("Calculator", "%", nullptr));
        pushButton_equals->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("Calculator", "create graph", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("Calculator", "ln", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("Calculator", "mod", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("Calculator", "cos", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("Calculator", "asin", nullptr));
        pushButton_open_bracket->setText(QCoreApplication::translate("Calculator", "(", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        pushButton_power->setText(QCoreApplication::translate("Calculator", "^", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("Calculator", "atan", nullptr));
        pushButton_close_bracket->setText(QCoreApplication::translate("Calculator", ")", nullptr));
        plainTextEdit_ymax->setPlainText(QCoreApplication::translate("Calculator", "10", nullptr));
        plainTextEdit_xmin->setPlainText(QCoreApplication::translate("Calculator", "-10", nullptr));
        label_2->setText(QCoreApplication::translate("Calculator", "Xmin", nullptr));
        plainTextEdit_ymin->setPlainText(QCoreApplication::translate("Calculator", "-10", nullptr));
        plainTextEdit_x->setPlainText(QCoreApplication::translate("Calculator", "1", nullptr));
        label_4->setText(QCoreApplication::translate("Calculator", "Xmax", nullptr));
        plainTextEdit_xmax->setPlainText(QCoreApplication::translate("Calculator", "10", nullptr));
        label_3->setText(QCoreApplication::translate("Calculator", "Ymin ", nullptr));
        label->setText(QCoreApplication::translate("Calculator", "X", nullptr));
        label_5->setText(QCoreApplication::translate("Calculator", "Ymax ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab), QCoreApplication::translate("Calculator", "Calc", nullptr));
        radioButton_annuit->setText(QCoreApplication::translate("Calculator", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\320\275\321\202\320\275\321\213\320\271", nullptr));
        radioButton_different->setText(QCoreApplication::translate("Calculator", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        label_12->setText(QCoreApplication::translate("Calculator", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271\n"
"\320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        label_14->setText(QCoreApplication::translate("Calculator", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_overpayment->setText(QCoreApplication::translate("Calculator", "TextLabel", nullptr));
        label_16->setText(QCoreApplication::translate("Calculator", "\320\241\321\203\320\274\320\274\320\260\321\200\320\275\320\260\321\217\n"
"\320\262\321\213\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_all_payment->setText(QCoreApplication::translate("Calculator", "TextLabel", nullptr));
        label_18->setText(QCoreApplication::translate("Calculator", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_19->setText(QCoreApplication::translate("Calculator", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217\n"
"\321\201\321\202\320\260\320\262\320\272\320\260 \320\262 \320\263\320\276\320\264", nullptr));
        label_20->setText(QCoreApplication::translate("Calculator", "                 \320\242\320\270\320\277 \320\277\320\273\320\260\321\202\320\265\320\266\320\260", nullptr));
        label_21->setText(QCoreApplication::translate("Calculator", "\320\222\321\213\320\262\320\276\320\264", nullptr));
        pushButton->setText(QCoreApplication::translate("Calculator", "\321\200\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_15->setText(QCoreApplication::translate("Calculator", "%", nullptr));
        label_22->setText(QCoreApplication::translate("Calculator", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_payment_month->setText(QCoreApplication::translate("Calculator", "TextLabel", nullptr));
        label_23->setText(QCoreApplication::translate("Calculator", "\320\274\320\265\321\201.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Calculator", "Credit", nullptr));
        label_6->setText(QCoreApplication::translate("Calculator", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("Calculator", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_8->setText(QCoreApplication::translate("Calculator", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        label_9->setText(QCoreApplication::translate("Calculator", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        checkBox_capital->setText(QCoreApplication::translate("Calculator", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));

        const bool __sortingEnabled = listWidget_compoundingPeriods->isSortingEnabled();
        listWidget_compoundingPeriods->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_compoundingPeriods->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Calculator", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_compoundingPeriods->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Calculator", "\320\232\320\260\320\266\320\264\321\203\321\216 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_compoundingPeriods->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Calculator", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_compoundingPeriods->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Calculator", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_compoundingPeriods->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Calculator", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_compoundingPeriods->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("Calculator", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_compoundingPeriods->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("Calculator", "\320\222 \320\272\320\276\320\275\321\206\320\265 \321\201\321\200\320\276\320\272\320\260", nullptr));
        listWidget_compoundingPeriods->setSortingEnabled(__sortingEnabled);

        pushButton_10->setText(QCoreApplication::translate("Calculator", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));

        const bool __sortingEnabled1 = listWidget_duration->isSortingEnabled();
        listWidget_duration->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem7 = listWidget_duration->item(0);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("Calculator", "day(s)", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_duration->item(1);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("Calculator", "month(s)", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_duration->item(2);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("Calculator", "year(s)", nullptr));
        listWidget_duration->setSortingEnabled(__sortingEnabled1);

        label_11->setText(QCoreApplication::translate("Calculator", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("Calculator", "% \320\262 \320\263\320\276\320\264", nullptr));
        label_10_error->setText(QString());
        label_17->setText(QCoreApplication::translate("Calculator", "\320\232\320\273\321\216\321\207\320\265\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260 \320\246\320\221", nullptr));
        label_24->setText(QCoreApplication::translate("Calculator", "%", nullptr));
        label_25->setText(QCoreApplication::translate("Calculator", "% \320\262 \320\263\320\276\320\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Calculator", "Deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
