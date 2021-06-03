#include "square.h"
#include <math.h>
#include <iostream>
TSquare::TSquare(double a) :  TRectangle(a, a * sqrt(2)), TRhombus(a, 45)
{
    TRhombus::className = "Square";
    TRectangle::className = "Square";
    cout << "square init" << endl;
}
TSquare * TSquare::create(double a)
{
    if (a <= 0)
        return NULL;
    return(new TSquare(a));
}
