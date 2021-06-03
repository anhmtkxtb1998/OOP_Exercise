#ifndef TQUADRANGLE_H
#define TQUADRANGLE_H
#define PI (double)3.14159
#include "figure.h"
#include "triangle.h"

class TQuadrangle : public TFigure
{
protected:
//    double a, b, c, angle1, angle2;
    double b;
    TTriangle * t1 = NULL;
    TTriangle * t2 = NULL;
    TQuadrangle(double, double, double, double, double);
public:
    static TQuadrangle * create(double, double, double, double, double);
    double Area() ;
    double Perimeter();

};

#endif // TQUADRANGLE_H
