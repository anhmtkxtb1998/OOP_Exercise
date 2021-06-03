#include "rhombus.h"
#include<math.h>
TRhombus::TRhombus(double a, double angle) : TParallelogram(a, 2 * a * cos(PI *angle/(2*180)), angle/2)
{
    className = "Rhombus";
}
