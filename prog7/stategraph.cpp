#include "stategraph.h"

TStateGraph::TStateGraph(TMatrix m,int a) : TGraph(m)
{
    activeVertex = a;
}
void TStateGraph::setActiveVertex(int a)
{
    activeVertex = a;
}
int TStateGraph::getActiveVertex()
{
    return activeVertex;
}
void TStateGraph::newEvent(int event)
{
    activeVertex = matrix.at(activeVertex, event) - 1;
}
