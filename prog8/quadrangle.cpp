#include "quadrangle.h"
#include <math.h>
TQuadrangle::TQuadrangle()
{
}
TQuadrangle::TQuadrangle(double _a, double _b, double _c, double _angle1, double _angle2)
{
    a = _a; b = _b; c = _c; angle1 = _angle1; angle2 = _angle2;
    className = "Quadrangle";
}
TQuadrangle *TQuadrangle::create(double _a, double _b, double _c, double _angle1, double _angle2)
{
   if(_a <= 0|| _b <= 0|| _c <=0 || _angle1 <= 0 || _angle1 >= 180 || _angle2 <= 0 || _angle2 >= 180)
       return NULL;
   return (new TQuadrangle(_a, _b, _c, _angle1, _angle2));
}
double TQuadrangle::Area()
{

  return 1.0/2*(a * b *sin(PI * angle1/180) + b * c * sin(PI * angle2/180));
}
double TQuadrangle::Perimeter()
{
    return (a + c + sqrt(a * a + b * b - 2 *a*b*cos(PI *angle1/180)) +  sqrt(b * b + c * c - 2 *b*c*cos(PI * angle2/180)));
}
