#include "rectangle.h"
#include <math.h>
TRectangle::TRectangle(double a, double b):TParallelogram(a,b, 180 / PI * acos(a/b)){
    className = "Rectangle";
}
TRectangle * TRectangle::create(double a, double b)
{
    if(a <= 0 || b <= 0 || a >= b)
        return NULL;
    return (new TRectangle(a, b));
}
