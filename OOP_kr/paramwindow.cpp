#include "paramwindow.h"
#include "ui_paramwindow.h"

TParamwindow::TParamwindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui:: TParamwindow)
{
    ui->setupUi(this);
    connect(ui->btn1,SIGNAL(pressed()), this, SLOT(ControlEvents()));
    connect(ui->btn2, SIGNAL(pressed()), this, SLOT(ControlEvents()));
    connect(ui->s_order, SIGNAL(valueChanged(int)),this, SLOT(Getinformation(int)));
}

TParamwindow::~TParamwindow()
{
    delete ui;
}
void TParamwindow::setCurrentParamdata(TEvent msg){
    ui->s_order->setValue(msg.data.p.order);
    ui->s_time_solving->setValue(msg.data.p.time_sloving);
    ui->s_failure_time->setValue(msg.data.p.time_failure);
}
void TParamwindow::closeEvent(QCloseEvent * event){
    emit closing();
    event->accept();
}
void TParamwindow::ControlEvents(){
    QPushButton * btn = (QPushButton * ) sender();
    if(btn == ui->btn1){
        TEvent msg(PARAMMESSAGE);
        msg.data.p.order = ui->s_order->value();
        msg.data.p.time_sloving = ui->s_time_solving->value();
        msg.data.p.time_failure = ui->s_failure_time->value();
        emit sendParamEvent(msg);
    }
    if(btn == ui->btn2){
        TEvent msg(PARAMREQUEST);
        msg.data.p.order = ui->s_order->value();
        emit sendParamEvent(msg);
    }
}

void TParamwindow::Getinformation(int order){
    TEvent msg(PARAMREQUEST);
    msg.data.p.order = order;
    emit sendParamEvent(msg);
}
