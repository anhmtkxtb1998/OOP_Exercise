#ifndef TAPPLICATION_H
#define TAPPLICATION_H
#include <QApplication>
#include "interface.h"
#include "model.h"

class TApplication: public QApplication
{
    Q_OBJECT
    TInterface * interface;
    TModel * model;

public:
    TApplication(int, char**);
    ~TApplication();
};

#endif // TAPPLICATION_H
