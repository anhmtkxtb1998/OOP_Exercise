#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QCloseEvent>
#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include "derivegraph.h"

class TCanvas : public QWidget
{
    Q_OBJECT
    QLabel *lb_state;
    QComboBox * cb_state;
    QPushButton * btn_choose;
    TDerivesample *g;
public:
    TCanvas(TDerivesample, QWidget *parent = 0);
    ~TCanvas();
    void AddItemComboBox(int);
public slots:
    void ChangeGraph(TDerivesample);
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent*);
private slots:
    void ChangeState();
signals:
    void closing();
    void ChangeActivateEdge(int);
};

#endif // TCANVAS_H
