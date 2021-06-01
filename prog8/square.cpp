#include "square.h"
#include <math.h>
TSquare::TSquare(double a) :  TRectangle(a, a * sqrt(2))
{
     className = "Square";
}
TSquare * TSquare::create(double a)
{
    if (a <= 0)
        return NULL;
    return(new TSquare(a));
}
