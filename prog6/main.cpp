#include<QApplication>
#include "interface.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TInterface interface;
    interface.show();
    return a.exec();
}
