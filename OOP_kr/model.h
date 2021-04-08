#ifndef TMODEL_H
#define TMODEL_H

#include<QObject>
#include<QTimer>
#include<QList>
#include<qrandom.h>
#include<QTime>
#include<QMessageBox>
#include "computer.h"
#include"eventypes.h"


class TModel: public QObject
{
    Q_OBJECT
    static quint32 time_sloving;
    static quint32 time_failure;

    QList<TComputer*> lst_com;
    QTimer *p_timer;
public:
    TModel();
    ~TModel();
    void Init();
    void Paramrequest(int);
    void Staterequest(int);
private slots:
    void Tact();
public slots:
    void recevieModelEvent(TEvent);

signals:
    void sendModelEvent(TEvent);

};

#endif // TMODEL_H
