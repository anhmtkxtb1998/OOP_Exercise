#include "statewindow.h"
#include "ui_statewindow.h"

TStatewindow::TStatewindow(QWidget *parent): QMainWindow(parent), ui(new Ui::TStatewindow)
{
    ui->setupUi(this);
    ui->tableWidget->setVerticalHeaderItem(0, new QTableWidgetItem("Состояние компьютера"));
    ui->tableWidget->setVerticalHeaderItem(1, new QTableWidgetItem("Оставшееся время решения"));
    ui->tableWidget->setVerticalHeaderItem(2, new QTableWidgetItem("Оставшееся время до сбоя"));

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
//    ui->s_order->setValue(msg.data.p.order);
//    ui->lbl_status->setText(((msg.data.s.isbusy) ? "Занятое":"Свободное"));
    QTableWidgetItem *item = new QTableWidgetItem(((msg.data.s.isbusy) ? "Занятое":"Свободное"));
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);

    ui->tableWidget->setItem(0, 0, item);

//    ui->lbl_time_solve_remaining->setText(QString().setNum(msg.data.s.time_remaning));
    item = new QTableWidgetItem(QString().setNum(msg.data.s.time_remaning));
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);

    ui->tableWidget->setItem(1, 0, item);


    if (msg.data.s.time_failure > 0)
    {
//        ui->label_4->setText("Ост.время до сбоя");
//        ui->lbl_time_failure_remaining->setText(QString().setNum(msg.data.s.time_failure));
        item = new QTableWidgetItem(QString().setNum(msg.data.s.time_failure));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
//        item->setData(Qt::DisplayRole, msg.data.s.time_failure);
        ui->tableWidget->setItem(2, 0, item);
    }
    else
    {
//        ui->label_4->setText("Время востановления");
//        ui->lbl_time_failure_remaining->setText(QString().setNum(-msg.data.s.time_failure));
        item = new QTableWidgetItem(QString().setNum(-msg.data.s.time_failure));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(2, 0, item);
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
