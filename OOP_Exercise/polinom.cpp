#include "polinom.h"
#include<cmath>

Polinom::Polinom(number x,number y,number z)
{
    printmode = EPrintModeClassic;
    a = x;
    b = y;
    c =z;
}

void Polinom::SetPrintMode(EPrintMode mode)
{
    printmode = mode;
}

number Polinom::value(number x)
{
    return (a * x *x  + b * x + c);
}

number * Polinom::roots()
{
    number delta = b * b - 4 * a * c;
    if (delta >= 0)
    {
        number * roots = new number[2];
        roots[0] = (-b - sqrt(delta))/(2 * a);
        roots[1] = (-b + sqrt(delta))/(2 * a);
        if (-a*(roots[0] + roots[1]) == b && a*roots[0]*roots[1] == c)
        {
            return roots;
        }
    }
    return NULL;
}

std::ostream& operator <<(std::ostream& os,Polinom& p)
{
    if (p.printmode == EPrintModeClassic)
        os << "p(x) = " << p.a <<"x^2 " << (p.b < 0 ? "" : "+") << p.b << "x " << (p.c < 0 ? "" : "+") << p.c <<std::endl;
    else
    {
        number x0 = -p.b/2*p.a;
        number y0 = p.value(x0);
        number param = 1/std::abs(2*p.a);
        os << "(x " << (x0 < 0 ? "+ " : "- ") << std::abs(x0) << ")^2 = " << (param < 0 ? "-" : "") << "2 * " << param << " * (y " << (y0 < 0 ? "+ " : "- ") << std::abs(y0) << ")" << std::endl;

        os << "y = " << p.a << "(x " << (x0 < 0 ? "+ " : "- ") << std::abs(x0) << ")^2 " << (y0 < 0 ? "" : "+") << y0 << std::endl;
    }
    return os;
}
