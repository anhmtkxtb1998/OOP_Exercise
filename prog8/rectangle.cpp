#include "rectangle.h"
#include <math.h>
TRectangle::TRectangle(double a, double b):TParallelogram(a,b, 180 / PI * acos(a/b))
{
    className = "Rectangle";
}
