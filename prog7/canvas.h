#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QCloseEvent>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include "stategraph.h"

class TCanvas : public QWidget
{
    Q_OBJECT
    QLabel *lb_state;
    QComboBox * cb_state;
    QPushButton * btn_choose;
    TStateGraph *g;
public:
    TCanvas(TStateGraph, QWidget *parent = 0);
    ~TCanvas();
    void AddStatesToChoose(int);
public slots:
    void ChangeGraph(TStateGraph);
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent*);
private slots:
    void ChangeState();
signals:
    void closing();
    void ChangeActiveVertex(int);
};

#endif // TCANVAS_H
