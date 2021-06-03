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
    return 4 * (PI * Ra * Rb + (Ra - Rb) * (Ra - Rb))/(Ra + Rb);
}
