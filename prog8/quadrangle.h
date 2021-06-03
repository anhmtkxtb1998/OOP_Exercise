#ifndef TQUADRANGLE_H
#define TQUADRANGLE_H
#define PI (double)3.14159
#include "figure.h"
#include "triangle.h"

class TQuadrangle : public TFigure
{
protected:
    double d;
    TTriangle * t1 = NULL;
    TTriangle * t2 = NULL;
public:
    TQuadrangle(double, double, double, double, double);
    ~TQuadrangle();
    double Area() ;
    double Perimeter();

};

#endif // TQUADRANGLE_H
