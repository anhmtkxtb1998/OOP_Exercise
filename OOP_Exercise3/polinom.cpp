#include "polinom.h"
#include <cmath>

Polinom::Polinom(number a, number b, number c)
{
    printmode = EPrintModeClassic;
    this->a = a;
    this->b = b;
    this->c = c;
}

void Polinom::setPrintMode(EPrintMode mode)
{
    printmode = mode;
}

number Polinom::value(number x)
{
    return (a * x * x + b * x + c);
}

int Polinom::roots(number xroots[])
{
    number discr = b * b - 4 * a * c;
    if (discr >= 0)
    {
        xroots[0] = (-b - sqrt(discr))/(2 * a);
        xroots[1] = (-b + sqrt(discr))/(2 * a);
        if (-a * (xroots[0] + xroots[1]) == b && a * xroots[0] * xroots[1] == c)
        {
            return 2;
        }
        if (value(xroots[0]) == 0)
        {
            xroots[1] = xroots[0];
            return 1;
        }
        if (value(xroots[1]) == 0)
        {
            xroots[0] = xroots[1];
            return 1;
        }

    }
    return 0;
}

QString& operator <<(QString& os,Polinom& p)
{
    if (p.printmode == EPrintModeClassic){
        os << p.a; os += "x^2 " + QString(p.b < 0 ? "- " : "+ ") ;os << std::abs(p.b) ;os += "x " + QString(p.c < 0 ? "- " : "+ "); os << std::abs(p.c); os += "\n";
    }
    else
    {
        number x0 = -p.b/(2*p.a);
        if (x0 * 2 * p.a == -p.b)
        {
            number y0 = p.value(x0);
            os  << p.a; os += "(x " + QString(x0 < 0 ? "+ " : "- "); os << std::abs(x0); os += ")^2 " + QString(y0 < 0 ? "- " : "+ "); os << std::abs(y0) ; os +=  "\n";
        }
        else
        {
            os += "Cannot output canonic form because x0 = -b/(2*a) does not belong to type 'number'\n";
        }
    }
    return os;
}
