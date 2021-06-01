#ifndef TEQUILATERALTRIAGLE_H
#define TEQUILATERALTRIAGLE_H

#include "isoscelestriangle.h"

class TEquilateralTriagle : public TIsoscelesTriangle
{
    TEquilateralTriagle(double);
public:
    static TEquilateralTriagle * create(double);

};

#endif // TEQUILATERALTRIAGLE_H
