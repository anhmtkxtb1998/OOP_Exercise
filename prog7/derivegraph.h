#ifndef TDERIVESAMPLE_H
#define TDERIVESAMPLE_H
#include "graph.h"
#include <random>

class TDerivesample : public TGraph
{
int activate;
public:
    TDerivesample(TMatrix, int);
    void SetActivate(int);
    int GetActivate();
    void newEvents(int);
};

#endif // TDERIVESAMPLE_H
