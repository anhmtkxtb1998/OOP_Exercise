#include "rhombus.h"
#include<math.h>
TRhombus::TRhombus(double a, double angle) : TParallelogram(a, 2 * a * cos(PI *angle/180), angle)
{
    className = "Rhombus";
}
TRhombus * TRhombus::create(double a, double angle)
{
    if( a <= 0|| angle <=0 || angle >= 90)
        return NULL;
    return (new TRhombus(a, angle));
}
