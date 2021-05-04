#include "canvas.h"

TCanvas::TCanvas(TGraph *f, QWidget *parent) : QWidget(parent)
{
    g = f;
    setFixedSize(400,400);
}

TCanvas::~TCanvas()
{

}

void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    g->draw(&p, rect(), Qt::green);
    p.end();
}
