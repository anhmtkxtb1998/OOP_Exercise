#include "interface.h"

TInterface::TInterface(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Работа №3");
    setFixedSize(300,250);
    //create label, lineedit for coeff_ a
    name_a = new QLabel("a =",this);
    name_a->setGeometry(50,20,30,20);
    numerator_a = new QLineEdit(this);
    numerator_a->setGeometry(90,20,50,20);
    delimeter_a = new QLabel(" / ",this);
    delimeter_a->setGeometry(150,20,30,20);
    denominator_a = new QLineEdit(this);
    denominator_a->setGeometry(190,20,50,20);
    //create label, lineedit for coeff_ b
    name_b = new QLabel("b =",this);
    name_b->setGeometry(50,60,30,20);
    numerator_b = new QLineEdit(this);
    numerator_b->setGeometry(90,60,50,20);
    delimeter_b = new QLabel(" / ",this);
    delimeter_b->setGeometry(150,60,30,20);
    denominator_b = new QLineEdit(this);
    denominator_b->setGeometry(190,60,50,20);
    //create label, lineedit for coeff_ c
    name_c = new QLabel("c =",this);
    name_c->setGeometry(50,100,30,20);
    numerator_c = new QLineEdit(this);
    numerator_c ->setGeometry(90,100,50,20);
    delimeter_c = new QLabel(" / ",this);
    delimeter_c->setGeometry(150,100,30,20);
    denominator_c = new QLineEdit(this);
    denominator_c->setGeometry(190,100,50,20);
    //create label, lineedit for value x
    name_x = new QLabel("x =",this);
    name_x->setGeometry(50,140,30,20);
    numerator_x = new QLineEdit(this);
    numerator_x ->setGeometry(90,140,50,20);
    delimeter_x = new QLabel(" / ",this);
    delimeter_x->setGeometry(150,140,30,20);
    denominator_x = new QLineEdit(this);
    denominator_x->setGeometry(190,140,50,20);
    //create butons
    value_btn = new QPushButton("Value", this);
    value_btn->setGeometry(10,180,60,30);
    root_btn = new QPushButton("Roots", this);
    root_btn->setGeometry(80,180,60,30);
    print_classic_btn = new QPushButton("Classic", this);
    print_classic_btn->setGeometry(150,180,60,30);
    print_canonic_btn = new QPushButton("Canonic", this);
    print_canonic_btn->setGeometry(220,180,60,30);
    output = new QLabel(this);
    output-> setGeometry(10,220,280,25);

    //signals-slots
    connect(value_btn,SIGNAL(pressed()),this,SLOT(Value()));
    connect(root_btn,SIGNAL(pressed()),this,SLOT(Roots()));
    connect(print_classic_btn,SIGNAL(pressed()),this, SLOT(Print_classic()));
    connect(print_canonic_btn,SIGNAL(pressed()),this, SLOT(Print_canonic()));
}

TInterface::~TInterface()
{
    delete name_a;
    delete numerator_a;
    delete delimeter_a;
    delete denominator_a;
    delete name_b;
    delete numerator_b;
    delete delimeter_b;
    delete denominator_b;
    delete name_c;
    delete numerator_c;
    delete delimeter_c;
    delete denominator_c;
}

void TInterface::Value(){
    QString s;
    if(denominator_a->text().toInt() == 0 || denominator_b->text().toInt() == 0 || denominator_c->text().toInt() == 0|| denominator_x->text().toInt() == 0){
        s += "denominator must be different 0";
    }
    else
    {number a(numerator_a->text().toInt(), denominator_a->text().toInt()), b(numerator_b->text().toInt(), denominator_b->text().toInt()), c(numerator_c->text().toInt(), denominator_c->text().toInt());
    number x(numerator_x->text().toInt(), denominator_x->text().toInt());
    Polinom p(a,b,c);
    s += "p(";
    s << x;
    s += ") = ";
    s << p.value(x);
    }
    output->setText(s);
}
void TInterface::Roots(){
    QString s;
    if(denominator_a->text().toInt() == 0 || denominator_b->text().toInt() == 0 || denominator_c->text().toInt() == 0|| denominator_x->text().toInt() == 0){
        s += "denominator must be different 0";
    }
    else
    {
     number a(numerator_a->text().toInt(), denominator_a->text().toInt()), b(numerator_b->text().toInt(), denominator_b->text().toInt()), c(numerator_c->text().toInt(), denominator_c->text().toInt());
     Polinom p(a,b,c);
     number roots[2];
     int result = p.roots(roots);
     if (result == 0)
         s += "No solutions!\n";
     else
     {
         if (result == 1){
             s += "One solution: x1 = ";
             s << roots[0];
             s+="\n";
         }
         else{
             s += "Two solutions: x1 = ";
             s << roots[0];s += ", x2 = " ;
             s << roots[1];
             s += "\n";
         }

     }

    }
     output->setText(s);

}
void TInterface::Print_classic(){
    QString s;
    if(denominator_a->text().toInt() == 0 || denominator_b->text().toInt() == 0 || denominator_c->text().toInt() == 0|| denominator_x->text().toInt() == 0){
        s += "denominator must be different 0";
    }
    else
    {
    number a(numerator_a->text().toInt(), denominator_a->text().toInt()), b(numerator_b->text().toInt(), denominator_b->text().toInt()), c(numerator_c->text().toInt(), denominator_c->text().toInt());
    Polinom p(a,b,c);
    p.setPrintMode(EPrintModeClassic);
    s << p;
    }
    output-> setText(s);
}
void TInterface::Print_canonic(){
    QString s;
    if(denominator_a->text().toInt() == 0 || denominator_b->text().toInt() == 0 || denominator_c->text().toInt() == 0|| denominator_x->text().toInt() == 0){
        s += "denominator must be different 0";
    }
    else
    {
    number a(numerator_a->text().toInt(), denominator_a->text().toInt()), b(numerator_b->text().toInt(), denominator_b->text().toInt()), c(numerator_c->text().toInt(), denominator_c->text().toInt());
    Polinom p(a,b,c);
    p.setPrintMode(EPrintModeCanonic);
    s << p;
    }
    output-> setText(s);
}















