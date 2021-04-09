#include "controlwindow.h"
#include "ui_controlwindow.h"

quint32 TControlwindow::order = 1;

TControlwindow::TControlwindow(QMainWindow *parent): QMainWindow(parent), ui(new Ui::TControlwindow)
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

       QString m = "Поступила задача №";
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
