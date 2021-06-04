#ifndef TMODEL_H
#define TMODEL_H

#include<QObject>
#include<QTimer>
#include<QList>
#include<QRandomGenerator>
#include<QMessageBox>
#include "computer.h"
#include"eventypes.h"


class TModel: public QObject
{
    Q_OBJECT
    static quint32 time_solving;
    static quint32 time_failure;

    QList<TComputer*> lst_com;
    QTimer *p_timer;
public:
    TModel();
    ~TModel();
private slots:
    void init();
    void paramRequest(int);
    void stateRequest(int);
    void tact();
public slots:
    void recevieModelEvent(TEvent);

signals:
    void sendModelEvent(TEvent);

};

#endif // TMODEL_H
