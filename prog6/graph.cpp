#include "graph.h"

TGraph::TGraph(TMatrix m)
{
    matrix = m;
    count = m.getX();
}

TGraph::~TGraph()
{

}

void TGraph::setCount(int c)
{
    count = c;
}

void TGraph::setMatrix(TMatrix m)
{
    matrix = m;
}

int TGraph::getCount()
{
    return count;
}

TMatrix TGraph::getMatrix()
{
    return matrix;
}
