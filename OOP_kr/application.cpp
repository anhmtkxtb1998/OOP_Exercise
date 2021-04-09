#include "application.h"

TApplication::TApplication(int argc, char **argv): QApplication(argc,argv)
{
    interface = new TInterface();
    interface->show();
    model =new TModel();
    connect(interface, SIGNAL(sendInterfaceEvent(TEvent)), model,SLOT(recevieModelEvent(TEvent)));
    connect(model,SIGNAL(sendModelEvent(TEvent)), interface,SLOT(recevieInterfaceEvent(TEvent)));
}

TApplication::~TApplication()
{
    delete interface;
    delete model;
}
