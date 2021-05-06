#ifndef TGRAPH_H
#define TGRAPH_H

#include "matrix.h"

class TGraph
{
    int count;
    TMatrix matrix;
public:
    TGraph(TMatrix);
    TGraph(TGraph&);
    ~TGraph();
    int getCount();
    void setCount(int);
    TMatrix getMatrix();
    void setMatrix(TMatrix);
};

#endif // TGRAPH_H
