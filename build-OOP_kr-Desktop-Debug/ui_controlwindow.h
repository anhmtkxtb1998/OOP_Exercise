/********************************************************************************
** Form generated from reading UI file 'controlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWINDOW_H
#define UI_CONTROLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TControlwindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btn_request;
    QPushButton *btn_reset;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TControlwindow)
    {
        if (TControlwindow->objectName().isEmpty())
            TControlwindow->setObjectName(QString::fromUtf8("TControlwindow"));
        TControlwindow->resize(293, 153);
        centralwidget = new QWidget(TControlwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_request = new QPushButton(centralwidget);
        btn_request->setObjectName(QString::fromUtf8("btn_request"));

        gridLayout->addWidget(btn_request, 0, 0, 1, 1);

        btn_reset = new QPushButton(centralwidget);
        btn_reset->setObjectName(QString::fromUtf8("btn_reset"));

        gridLayout->addWidget(btn_reset, 1, 0, 1, 1);

        TControlwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TControlwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 293, 20));
        TControlwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TControlwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TControlwindow->setStatusBar(statusbar);

        retranslateUi(TControlwindow);

        QMetaObject::connectSlotsByName(TControlwindow);
    } // setupUi

    void retranslateUi(QMainWindow *TControlwindow)
    {
        TControlwindow->setWindowTitle(QApplication::translate("TControlwindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        btn_request->setText(QApplication::translate("TControlwindow", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        btn_reset->setText(QApplication::translate("TControlwindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TControlwindow: public Ui_TControlwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
