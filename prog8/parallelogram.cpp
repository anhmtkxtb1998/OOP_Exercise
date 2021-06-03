#include "parallelogram.h"
#include <math.h>
TParallelogram::TParallelogram(double a, double b, double angle): TQuadrangle(a, b, sqrt(a * a + b * b - 2 *a*b*cos(PI *angle/180)), angle, 180.0/PI * asin(a * sin(PI * angle/180)/sqrt(a * a + b * b -2 *a*b*cos(PI *angle/180))))
{
    className = "Parallelogram";
}
