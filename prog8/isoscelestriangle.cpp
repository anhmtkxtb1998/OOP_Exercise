#include "isoscelestriangle.h"

TIsoscelesTriangle::TIsoscelesTriangle(double a, double _angle): TTriangle(a , a, _angle)
{
     className = "Isosceles Triangle";
}
TIsoscelesTriangle * TIsoscelesTriangle::create(double a, double _angle)
{
    if( a <= 0 || _angle <= 0|| _angle >= 180)
        return NULL;
    return (new TIsoscelesTriangle(a, _angle));
}
