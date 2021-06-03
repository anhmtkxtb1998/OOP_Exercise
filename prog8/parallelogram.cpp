#include "parallelogram.h"
#include <math.h>
TParallelogram::TParallelogram(double a, double b, double angle): TQuadrangle(a, b, sqrt(a * a + b * b - 2 *a*b*cos(PI *angle/180)), angle, 180.0/PI * asin(a * sin(PI * angle/180)/sqrt(a * a + b * b -2 *a*b*cos(PI *angle/180))))
{
    className = "Parallelogram";
}
TParallelogram* TParallelogram::create(double a, double b, double angle)
{
    if( a<= 0 || b <= 0 || angle <= 0 || angle >= 180)
        return NULL;
    return(new TParallelogram(a, b, angle));
}
