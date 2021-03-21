#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QMainWindow>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QString>
#include "polinom.h"

class TInterface : public QMainWindow
{
    Q_OBJECT
    QLabel * name_a, * delimeter_a;
    QLineEdit * numerator_a, * denominator_a;

    QLabel * name_b, * delimeter_b;
    QLineEdit * numerator_b, * denominator_b;

    QLabel * name_c, * delimeter_c;
    QLineEdit * numerator_c, * denominator_c;

    QLabel * name_x, * delimeter_x;
    QLineEdit * numerator_x, * denominator_x;

    QLabel * output;
    QPushButton * value_btn;
    QPushButton* root_btn;
    QPushButton* print_classic_btn;
    QPushButton* print_canonic_btn;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
public slots:
    void Value();
    void Roots();
    void Print_classic();
    void Print_canonic();
};
#endif // TINTERFACE_H
