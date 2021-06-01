#ifndef TRECTANGLE_H
#define TRECTANGLE_H
#include "parallelogram.h"

class TRectangle : public TParallelogram
{
protected:
    TRectangle(double, double);
public:
    static TRectangle * create(double, double);

};

#endif // TRECTANGLE_H
