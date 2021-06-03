#include "rectangle.h"
#include <math.h>
TRectangle::TRectangle(double a, double b):TParallelogram(a, sqrt(a*a + b*b), 180 / PI * atan(b/a))
{
    className = "Rectangle";
}
