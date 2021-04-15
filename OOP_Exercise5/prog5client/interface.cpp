#include "interface.h"
#include "common.h"
TInterface::TInterface(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Работа №3");
    setFixedSize(400,300);

    name_a = new QLabel("a =",this);
    name_a->setGeometry(50,20,30,20);
    numerator_a = new QLineEdit("1",this);
    numerator_a->setGeometry( 110,20,50,20);
    numerator_a->setValidator(new QIntValidator());
    delimeter_a = new QLabel(" / ",this);
    delimeter_a->setGeometry(180,20,30,20);
    denominator_a = new QLineEdit("1", this);
    denominator_a->setGeometry(230,20,50,20);
    denominator_a->setValidator(new QIntValidator());

    name_b = new QLabel("b =",this);
    name_b->setGeometry(50,60,30,20);
    numerator_b = new QLineEdit("2",this);
    numerator_b->setGeometry(110,60,50,20);
    numerator_b->setValidator(new QIntValidator());
    delimeter_b = new QLabel(" / ",this);
    delimeter_b->setGeometry(180,60,30,20);
    denominator_b = new QLineEdit("1",this);
    denominator_b->setGeometry(230,60,50,20);
    denominator_b->setValidator(new QIntValidator());

    name_c = new QLabel("c =",this);
    name_c->setGeometry(50,100,30,20);
    numerator_c = new QLineEdit("1",this);
    numerator_c ->setGeometry(110,100,50,20);
    numerator_c->setValidator(new QIntValidator());
    delimeter_c = new QLabel(" / ",this);
    delimeter_c->setGeometry(180,100,30,20);
    denominator_c = new QLineEdit("1",this);
    denominator_c->setGeometry(230,100,50,20);
    denominator_c->setValidator(new QIntValidator());

    name_x = new QLabel("x =",this);
    name_x->setGeometry(50,140,30,20);
    numerator_x = new QLineEdit("1",this);
    numerator_x ->setGeometry(110,140,50,20);
    numerator_x->setValidator(new QIntValidator());
    delimeter_x = new QLabel(" / ",this);
    delimeter_x->setGeometry(180,140,30,20);
    denominator_x = new QLineEdit("1",this);
    denominator_x->setGeometry(230,140,50,20);
    denominator_x->setValidator(new QIntValidator());

    value_btn = new QPushButton("Value", this);
    value_btn->setGeometry(10,180,60,30);
    root_btn = new QPushButton("Roots", this);
    root_btn->setGeometry( 100,180,60,30);
    print_classic_btn = new QPushButton("Classic", this);
    print_classic_btn->setGeometry(190,180,60,30);
    print_canonic_btn = new QPushButton("Canonic", this);
    print_canonic_btn->setGeometry(280,180,60,30);

    i_button = new QRadioButton("Interger", this);
    i_button->setGeometry(10,230,120, 30);
    r_button = new QRadioButton("Rational", this);
    r_button->setGeometry(250,230,130,30);
    i_button->setChecked(true);
    output = new QLabel(this);
    output->setGeometry(10,270,380,30);

    connect(value_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(root_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(print_classic_btn,SIGNAL(pressed()),this, SLOT(formRequest()));
    connect(print_canonic_btn,SIGNAL(pressed()),this, SLOT(formRequest()));
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

    delete output;
    delete value_btn;
    delete root_btn;
    delete print_classic_btn;
    delete print_canonic_btn;

    delete i_button;
    delete r_button;
}
void TInterface::formRequest(){
    QString msg;
    if(i_button->isChecked())
    {
        msg << QString().setNum(I_MODE);
        msg << numerator_a->text();
        msg << numerator_b->text();
        msg << numerator_c->text();

    }
    else
    {
    msg <<QString().setNum(R_MODE);
    msg << numerator_a->text() << denominator_a->text();
    msg << numerator_b->text() << denominator_b->text();
    msg << numerator_c->text() << denominator_c->text();
    }
    QPushButton * btn = (QPushButton *) sender();
    if(btn == value_btn){
       msg << QString().setNum(VALUE_REQUEST);
       if(i_button->isChecked())
           msg <<numerator_x->text();
       else
       msg <<numerator_x->text() << denominator_x->text();
    }
    else if(btn == root_btn)
        msg << QString().setNum(ROOT_ANSWER);
    else if(btn == print_classic_btn)
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    else if(btn == print_canonic_btn)
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
   emit request(msg);
}
void TInterface::answer(QString msg){
     QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p + 1, msg.length() - p - 2);
    if(t == VALUE_ANSWER){
        text = "p";
        p = msg.indexOf(separator);
        text+= msg.left(p);
        text+= "=";
        text += msg.mid(p + 1, msg.length()- p -1);
        output->setText(text);
    }
    else if(t == PRINT_ANSWER){
        text = "p(x) = ";
        text+= msg;
        output->setText(text);
    }
    else if(t == ROOT_ANSWER){
        text += msg;
        output->setText(text);
    }
    else if(t == ERROR)
        output->setText(msg);

}
