/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TInterface
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_param;
    QPushButton *btn_state;
    QPushButton *btn_control;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TInterface)
    {
        if (TInterface->objectName().isEmpty())
            TInterface->setObjectName(QString::fromUtf8("TInterface"));
        TInterface->resize(315, 175);
        centralwidget = new QWidget(TInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_param = new QPushButton(centralwidget);
        btn_param->setObjectName(QString::fromUtf8("btn_param"));

        verticalLayout->addWidget(btn_param);

        btn_state = new QPushButton(centralwidget);
        btn_state->setObjectName(QString::fromUtf8("btn_state"));

        verticalLayout->addWidget(btn_state);

        btn_control = new QPushButton(centralwidget);
        btn_control->setObjectName(QString::fromUtf8("btn_control"));

        verticalLayout->addWidget(btn_control);

        TInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 315, 20));
        TInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(TInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TInterface->setStatusBar(statusbar);

        retranslateUi(TInterface);

        QMetaObject::connectSlotsByName(TInterface);
    } // setupUi

    void retranslateUi(QMainWindow *TInterface)
    {
        TInterface->setWindowTitle(QApplication::translate("TInterface", "\320\230\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201", nullptr));
        btn_param->setText(QApplication::translate("TInterface", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        btn_state->setText(QApplication::translate("TInterface", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217", nullptr));
        btn_control->setText(QApplication::translate("TInterface", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TInterface: public Ui_TInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
