#ifndef TGRAPH_H
#define TGRAPH_H

#include <QPainter>

class TGraph
{
    int count;
public:
    TGraph(int);
    void draw(QPainter*,QRect,QColor);
};

#endif // TGRAPH_H
