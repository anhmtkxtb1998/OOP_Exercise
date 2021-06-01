#include "triangle.h"
#include<math.h>

TTriangle::TTriangle(double x, double y, double _angle)
{
    a = x; b = y;  angle = _angle; className = "Triangle";
}

TTriangle * TTriangle::create(double x, double y, double _angle)
{
    if (( x <=0)||(y<=0)||_angle <= 0 || _angle >= 180)
        return NULL;
     return (new TTriangle(x, y, _angle));
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
