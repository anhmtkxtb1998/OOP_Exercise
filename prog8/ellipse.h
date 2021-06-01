#ifndef TELLIPSE_H
#define TELLIPSE_H
#define PI (double)3.14159

#include "figure.h"
#include <math.h>

class TEllipse : public TFigure
{
protected:
    double Ra, Rb;
    TEllipse(double, double);
public:
    static TEllipse * create(double, double);
    double Area();
    double Perimeter();

};

#endif // TELLIPSE_H
