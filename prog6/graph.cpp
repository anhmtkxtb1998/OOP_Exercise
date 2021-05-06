#include "graph.h"

TGraph::TGraph(TMatrix m)
{
    matrix = m;
    count = m.getX();
}

TGraph::TGraph(TGraph &t)
{
    matrix = t.getMatrix();
    count = t.getCount();
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
