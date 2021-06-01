#ifndef TPARALLELOGRAM_H
#define TPARALLELOGRAM_H
#include "quadrangle.h"

class TParallelogram : public TQuadrangle
{
protected:
    TParallelogram( double, double, double);
public:
    static TParallelogram * create(double, double, double);

};

#endif // TPARALLELOGRAM_H
