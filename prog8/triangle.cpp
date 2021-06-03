#include "triangle.h"
#include <math.h>

TTriangle::TTriangle(double x, double y, double _angle)
{
    a = x;
    b = y;
    angle = _angle;
    className = "Triangle";
}
double TTriangle::Perimeter()
{
    double c = sqrt(a * a + b * b - 2 * a * b * cos(PI *angle/180));
    return (a + b + c);
}
double TTriangle::Area()
{
    return (1.0/2 * a * b * sin(PI * angle/180));
}
