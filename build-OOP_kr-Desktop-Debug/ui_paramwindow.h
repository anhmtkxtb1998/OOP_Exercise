/********************************************************************************
** Form generated from reading UI file 'paramwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWINDOW_H
#define UI_PARAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TParamwindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *s_order;
    QLabel *label_2;
    QSpinBox *s_time_solving;
    QLabel *label_3;
    QSpinBox *s_failure_time;
    QPushButton *btn1;
    QPushButton *btn2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TParamwindow)
    {
        if (TParamwindow->objectName().isEmpty())
            TParamwindow->setObjectName(QString::fromUtf8("TParamwindow"));
        TParamwindow->resize(336, 262);
        centralwidget = new QWidget(TParamwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        s_order = new QSpinBox(centralwidget);
        s_order->setObjectName(QString::fromUtf8("s_order"));
        s_order->setMinimum(1);
        s_order->setMaximum(5);

        gridLayout->addWidget(s_order, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        s_time_solving = new QSpinBox(centralwidget);
        s_time_solving->setObjectName(QString::fromUtf8("s_time_solving"));
        s_time_solving->setMinimum(2);
        s_time_solving->setMaximum(100);

        gridLayout->addWidget(s_time_solving, 1, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        s_failure_time = new QSpinBox(centralwidget);
        s_failure_time->setObjectName(QString::fromUtf8("s_failure_time"));
        s_failure_time->setMinimum(10);
        s_failure_time->setMaximum(100);

        gridLayout->addWidget(s_failure_time, 2, 1, 1, 1);

        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));

        gridLayout->addWidget(btn1, 3, 0, 1, 1);

        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));

        gridLayout->addWidget(btn2, 3, 1, 1, 1);

        TParamwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TParamwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 336, 22));
        TParamwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TParamwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TParamwindow->setStatusBar(statusbar);

        retranslateUi(TParamwindow);

        QMetaObject::connectSlotsByName(TParamwindow);
    } // setupUi

    void retranslateUi(QMainWindow *TParamwindow)
    {
        TParamwindow->setWindowTitle(QApplication::translate("TParamwindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        label->setText(QApplication::translate("TParamwindow", "\342\204\226 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\260", nullptr));
        label_2->setText(QApplication::translate("TParamwindow", "\320\222\321\200\320\265\320\274\321\217 \320\275\320\260 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 (\321\201\320\265\320\272\321\203\320\275\320\264\321\213)", nullptr));
        label_3->setText(QApplication::translate("TParamwindow", "\320\222\321\200\320\265\320\274\321\217 \320\264\320\276 \321\201\320\261\320\276\321\217 (\321\201\320\265\320\272\321\203\320\275\320\264\321\213)", nullptr));
        btn1->setText(QApplication::translate("TParamwindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btn2->setText(QApplication::translate("TParamwindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TParamwindow: public Ui_TParamwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWINDOW_H
