#ifndef TRHOMBUS_H
#define TRHOMBUS_H
#include "parallelogram.h"

class TRhombus : public TParallelogram
{
protected:
    TRhombus(double, double);
public:
    static TRhombus * create(double, double);

};

#endif // TRHOMBUS_H
