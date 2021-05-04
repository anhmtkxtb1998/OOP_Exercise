#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include "graph.h"

class TCanvas : public QWidget
{
    Q_OBJECT

    TGraph *g;
public:
    TCanvas(TGraph *, QWidget *parent = 0);
    ~TCanvas();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // TCANVAS_H
