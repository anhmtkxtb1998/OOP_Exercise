#ifndef TFIGURE_H
#define TFIGURE_H
#include<iostream>
using namespace std;
class TFigure
{
protected:
    string className;
public:
    TFigure();
    virtual double Area() ;
    virtual double Perimeter();
    void output(ostream&);
};

#endif // TFIGURE_H
