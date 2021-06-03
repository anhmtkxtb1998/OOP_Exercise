#include "square.h"
#include <math.h>
TSquare::TSquare(double a) :  TRectangle(a, a), TRhombus(a, 90)
{
    TRhombus::className = "Square";
    TRectangle::className = "Square";
}

