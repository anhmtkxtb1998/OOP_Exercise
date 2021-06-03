#include "quadrangle.h"
#include <math.h>
#include <iostream>
TQuadrangle::TQuadrangle(double _a, double _b, double _c, double _angle1, double _angle2)
{
    d = _b;
    delete t1;
    delete t2;
    t1 = new TTriangle(_a, _b, _angle1);
    t2 = new TTriangle(_b, _c, _angle2);
    className = "Quadrangle";
}
TQuadrangle::~TQuadrangle()
{
    delete t1;
    delete t2;
}
double TQuadrangle::Area()
{
    return (t1->Area() + t2->Area());
}
double TQuadrangle::Perimeter()
{
    return (t1->Perimeter() + t2->Perimeter() - 2 * d);
}
