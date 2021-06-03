#ifndef TSQUARE_H
#define TSQUARE_H
#include "rhombus.h"
#include "rectangle.h"

class TSquare : public TRectangle, public TRhombus
{
    TSquare(double);
public:
    static TSquare * create(double);

};

#endif // TSQUARE_H
