#include "controlwindow.h"
#include "ui_controlwindow.h"

quint32 TControlwindow::order = 1;

<<<<<<< HEAD
TControlwindow::TControlwindow(QMainWindow *parent): QMainWindow(parent), ui(new Ui::TControlwindow)
=======
TControlwindow::TControlwindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::TControlwindow)
>>>>>>> 031abc6e6d9c4206835005df99eea4dbd5c78f8f
{
    ui->setupUi(this);
    connect(ui->btn_request, SIGNAL(pressed()), this, SLOT(ControlEvents()));
    connect(ui->btn_reset, SIGNAL(pressed()), this, SLOT(ControlEvents()));
}

TControlwindow::~TControlwindow()
{
    delete ui;
}

void TControlwindow::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}

void TControlwindow::ControlEvents()
{
   QPushButton * btn = (QPushButton *)sender();
   if (btn == ui->btn_request)
   {
       TEvent msg(REQUEST_PROBLEM);
       msg.data.order_problem = order;

       QString m = "Отправил запрос № ";
       m.append(QString().setNum(order));
       QMessageBox::information(this,"Сообщение",m);
       emit sendControlEvent(msg);
       order++;
   }
   if (btn == ui->btn_reset)
   {
       TEvent msg(RESET);
       emit sendControlEvent(msg);
   }
}
