#include "rhombus.h"
#include<math.h>
TRhombus::TRhombus(double a, double angle) : TParallelogram(a, 2 * a * cos(PI *angle/180), angle)
{
    className = "Rhombus";
}
