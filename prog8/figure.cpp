#include "figure.h"

TFigure::TFigure()
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
void TFigure::output(ostream &outDev)
{
 outDev << "\n" << className << ": ";
 outDev << " \tArea: " << Area();
 outDev <<"\tPerimeter: " << Perimeter() << endl;
}
