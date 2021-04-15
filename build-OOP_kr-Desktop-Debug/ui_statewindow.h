/********************************************************************************
** Form generated from reading UI file 'statewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEWINDOW_H
#define UI_STATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TStatewindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QSpinBox *s_order;
    QLabel *lbl_time_solve_remaining;
    QLabel *label_3;
    QLabel *lbl_time_failure_remaining;
    QLabel *lbl_status;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TStatewindow)
    {
        if (TStatewindow->objectName().isEmpty())
            TStatewindow->setObjectName(QString::fromUtf8("TStatewindow"));
        TStatewindow->resize(374, 305);
        centralwidget = new QWidget(TStatewindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        s_order = new QSpinBox(centralwidget);
        s_order->setObjectName(QString::fromUtf8("s_order"));
        s_order->setMinimum(1);
        s_order->setMaximum(5);

        gridLayout->addWidget(s_order, 0, 1, 1, 1);

        lbl_time_solve_remaining = new QLabel(centralwidget);
        lbl_time_solve_remaining->setObjectName(QString::fromUtf8("lbl_time_solve_remaining"));

        gridLayout->addWidget(lbl_time_solve_remaining, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lbl_time_failure_remaining = new QLabel(centralwidget);
        lbl_time_failure_remaining->setObjectName(QString::fromUtf8("lbl_time_failure_remaining"));

        gridLayout->addWidget(lbl_time_failure_remaining, 3, 1, 1, 1);

        lbl_status = new QLabel(centralwidget);
        lbl_status->setObjectName(QString::fromUtf8("lbl_status"));

        gridLayout->addWidget(lbl_status, 1, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        TStatewindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TStatewindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 374, 20));
        TStatewindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TStatewindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TStatewindow->setStatusBar(statusbar);

        retranslateUi(TStatewindow);

        QMetaObject::connectSlotsByName(TStatewindow);
    } // setupUi

    void retranslateUi(QMainWindow *TStatewindow)
    {
        TStatewindow->setWindowTitle(QApplication::translate("TStatewindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\276\320\262", nullptr));
        label_4->setText(QApplication::translate("TStatewindow", "\320\236\321\201\321\202\320\260\320\262\321\210\320\265\320\265\321\201\321\217 \320\264\320\276 \321\201\320\261\320\276\321\217 \320\262\321\200\320\265\320\274\321\217:", nullptr));
        label_2->setText(QApplication::translate("TStatewindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\272\320\276\320\277\321\214\321\216\321\202\320\265\321\200\320\260:", nullptr));
        lbl_time_solve_remaining->setText(QString());
        label_3->setText(QApplication::translate("TStatewindow", "\320\222\321\200\320\265\320\274\321\217 \320\264\320\276 \320\272\320\276\320\275\321\206\320\260 \321\200\320\265\321\210\320\265\320\275\320\270\321\217:", nullptr));
        lbl_time_failure_remaining->setText(QString());
        lbl_status->setText(QString());
        label->setText(QApplication::translate("TStatewindow", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\276\320\277\321\214\321\216\321\202\320\265\321\200\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TStatewindow: public Ui_TStatewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEWINDOW_H
