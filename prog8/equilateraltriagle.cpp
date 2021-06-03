#include "equilateraltriagle.h"

TEquilateralTriagle::TEquilateralTriagle(double a): TIsoscelesTriangle(a, 60)
{
    className = "Equilateral Triagle";
}
TEquilateralTriagle * TEquilateralTriagle::create(double a)
{
    if(a <= 0)
        return NULL;
    return (new TEquilateralTriagle(a));
}
