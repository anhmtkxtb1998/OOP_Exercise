#ifndef TGRAPH_H
#define TGRAPH_H

#include <QPainter>
#include<QObject>
#include<QVector>
#include "matrix.h"

class TGraph
{
    int count;
    TMatrix matrix;
public:
    TGraph(int, TMatrix);
    ~TGraph();
    void draw(QPainter*,QRect,QColor);
    void setMatrix(TMatrix);
    void setCount(int);
};

#endif // TGRAPH_H
