#include "interface.h"
#include "ui_interface.h"

TInterface::TInterface(QMainWindow *parent): QMainWindow(parent), ui(new Ui::TInterface)
{
    paramwindow = nullptr;
    statewindow = nullptr;
    controlwindow = nullptr;
    ui->setupUi(this);
    connect(ui->btn_param, SIGNAL(pressed()), this, SLOT(openParamwindow()));
    connect(ui->btn_state, SIGNAL(pressed()), this, SLOT(openStatewindow()));
    connect(ui->btn_control, SIGNAL(pressed()), this, SLOT(openControlwindow()));
}

TInterface::~TInterface()
{
    delete ui;
}

void TInterface::openParamwindow()
{
    if (paramwindow == nullptr)
    {
        paramwindow = new TParamwindow();
        connect(paramwindow, SIGNAL(closing()), this, SLOT(closeParamwindow()));
        connect(paramwindow, SIGNAL(sendParamEvent(TEvent)), this, SIGNAL(sendInterfaceEvent(TEvent)));
        paramwindow->show();
        TEvent msg(PARAMREQUEST);
        msg.data.p.order = 1;
        emit sendInterfaceEvent(msg);
    }
}

void TInterface::openStatewindow()
{
    if (statewindow == nullptr)
    {
        statewindow = new TStatewindow();
        connect(statewindow,SIGNAL(closing()), this, SLOT(closeStatewindwow()));
        connect(statewindow,SIGNAL(sendStateEvents(TEvent)), this,SIGNAL(sendInterfaceEvent(TEvent)));
        statewindow->show();
        TEvent msg(STATEREQUEST);
        msg.data.p.order = 1;
        emit sendInterfaceEvent(msg);
    }
}

void TInterface::openControlwindow()
{
    if (controlwindow == nullptr)
    {
        controlwindow = new TControlwindow();
        connect(controlwindow,SIGNAL(closing()), this, SLOT(closeControlwindow()));
        connect(controlwindow,SIGNAL(sendControlEvent(TEvent)), this, SIGNAL(sendInterfaceEvent(TEvent)));
        controlwindow->show();
    }
}

void TInterface::closeParamwindow()
{
    disconnect(paramwindow, SIGNAL(closing()), this, SLOT(closeParamwindow()));
    disconnect(paramwindow, SIGNAL(sendParamEvent(TEvent)), this, SIGNAL(sendInterfaceEvent(TEvent)));
    paramwindow = nullptr;
}

void TInterface::closeStatewindwow()
{
    disconnect(statewindow,SIGNAL(closing()), this, SLOT(closeStatewindwow()));
    disconnect(statewindow,SIGNAL(sendStateEvents(TEvent)), this,SIGNAL(sendInterfaceEvent(TEvent)));
    statewindow = nullptr;
}

void TInterface::closeControlwindow()
{
    disconnect(controlwindow,SIGNAL(closing()), this, SLOT(closeControlwindow()));
    disconnect(controlwindow,SIGNAL(sendControlEvent(TEvent)), this, SIGNAL(sendInterfaceEvent(TEvent)));
    controlwindow = nullptr;
}

void TInterface::closeEvent(QCloseEvent * event)
{
    if (paramwindow != nullptr)
    {
         disconnect(paramwindow, SIGNAL(closing()), this, SLOT(closeParamwindow()));
         paramwindow->close();
    }
    if (statewindow != nullptr)
    {
        disconnect(statewindow,SIGNAL(closing()), this, SLOT(closeStatewindwow()));
        statewindow->close();
    }
    if (controlwindow != nullptr)
    {
        disconnect(controlwindow,SIGNAL(closing()), this, SLOT(closeControlwindow()));
        controlwindow ->close();
    }
    event->accept();
}

void TInterface::recevieInterfaceEvent(TEvent msg){
    switch(msg.type)
    {
    case PARAMREQUEST:
        if (paramwindow != nullptr)
            paramwindow->setCurrentParamdata(msg);
        break;
     case STATEREQUEST:
        if (statewindow != nullptr)
            statewindow->setCurrentState(msg);
        break;
    default: break;
    }
}
