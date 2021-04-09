#include "statewindow.h"
#include "ui_statewindow.h"

TStatewindow::TStatewindow(QMainWindow *parent): QMainWindow(parent), ui(new Ui::TStatewindow)
{
    ui->setupUi(this);

    p_timer = new QTimer(this);
    connect(ui->s_order,SIGNAL(valueChanged(int)), this, SLOT(GetStateByOrder(int)));
    connect(p_timer,SIGNAL(timeout()), this, SLOT(ChangedState()));
    p_timer->start(1000);
}

TStatewindow::~TStatewindow()
{
    delete ui;
}

void TStatewindow::setCurrentState(TEvent msg)
{
    ui->s_order->setValue(msg.data.p.order);
    ui->lbl_status->setText(((msg.data.s.isbusy) ? "Занятое":"Свободное"));
    ui->lbl_time_solve_remaining->setText(QString().setNum(msg.data.s.time_remaning));

    if (msg.data.s.time_failure > 0)
    {
        ui->label_4->setText("Ост.время до сбоя");
        ui->lbl_time_failure_remaining->setText(QString().setNum(msg.data.s.time_failure));
    }
    else
    {
<<<<<<< HEAD
        ui->lbl_time_failure_remaining->setText(QString().setNum(0));
=======
        ui->label_4->setText("Время востановления");
        ui->lbl_time_failure_remaining->setText(QString().setNum(-msg.data.s.time_failure));
>>>>>>> 031abc6e6d9c4206835005df99eea4dbd5c78f8f
    }
}

void TStatewindow::closeEvent(QCloseEvent * event)
{
    emit closing();
    event->accept();
}

void TStatewindow::GetStateByOrder(int order)
{
    TEvent msg(STATEREQUEST);
    msg.data.p.order = order;
    emit sendStateEvents(msg);
}

void TStatewindow::ChangedState()
{
    TEvent msg(STATEREQUEST);
    msg.data.p.order = ui->s_order->value();
    emit sendStateEvents(msg);
}
