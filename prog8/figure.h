#ifndef TFIGURE_H
#define TFIGURE_H
#include <iostream>
#include <string>

class TFigure
{
protected:
    std::string className;
public:
    TFigure();
    virtual ~TFigure();
    virtual double Area() ;
    virtual double Perimeter();
    void output(std::ostream&);
};

#endif // TFIGURE_H
