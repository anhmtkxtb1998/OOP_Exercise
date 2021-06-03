#include "ellipse.h"


TEllipse::TEllipse(double a, double b)
{
    Ra = a;
    Rb = b;
    className = "Ellipse";
}

double TEllipse::Area()
{
    return PI * Ra * Rb;
}
double TEllipse::Perimeter()
{
    return PI *(3*(Ra+Rb)- sqrt((3 * Ra + Rb) * (Ra + 3 * Rb)));
}
