#ifndef STATEGRAPH_H
#define STATEGRAPH_H
#include "graph.h"

class TStateGraph : public TGraph
{
    int activeVertex;
public:
    TStateGraph(TMatrix, int);
    void setActiveVertex(int);
    int getActiveVertex();
    void newEvent(int);
};

#endif // STATEGRAPH_H
