#include "ellipse.h"


TEllipse::TEllipse(double a, double b)
{
    Ra = a;
    Rb = b;
    className = "Ellipse";
}
TEllipse * TEllipse::create(double a, double b)
{
    if( a <= 0 || b <= 0)
        return NULL;
    return(new TEllipse(a, b));
}
double TEllipse::Area()
{
    return PI * Ra * Rb;
}
double TEllipse::Perimeter()
{
    return PI *(3*(Ra+Rb)- sqrt((3 * Ra + Rb) * (Ra + 3 * Rb)));
}
