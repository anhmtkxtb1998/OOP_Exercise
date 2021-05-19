#include "derivegraph.h"

TDerivesample::TDerivesample(TMatrix m,int a) : TGraph(m)
{
    activate = a;
    srand(time(NULL));
}
void TDerivesample::SetActivate(int a)
{
    activate = a;
}
int TDerivesample::GetActivate()
{
    return activate;
}
void TDerivesample::newEvents(int event)
{

    activate = matrix.at(activate, event) -1;
}
