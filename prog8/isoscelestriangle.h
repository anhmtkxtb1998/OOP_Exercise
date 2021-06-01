#ifndef TEQUILATERALTRIANGLE_H
#define TEQUILATERALTRIANGLE_H
#include "triangle.h"

class TIsoscelesTriangle: public TTriangle
{
protected:
    TIsoscelesTriangle(double, double);
public:
    static TIsoscelesTriangle * create(double, double);

};

#endif // TEQUILATERALTRIANGLE_H
