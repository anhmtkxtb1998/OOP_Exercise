#include "figure.h"

TFigure::TFigure()
{

}
TFigure::~TFigure()
{

}
double TFigure::Area()
{
    return 0;
}
double TFigure::Perimeter()
{
    return 0;
}
void TFigure::output(std::ostream &outDev)
{
    outDev << "\n" << className << ": ";
    outDev << " \tArea: " << Area();
    outDev <<"\tPerimeter: " << Perimeter() << std::endl;
}
