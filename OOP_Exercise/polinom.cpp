#include "polinom.h"
#include<cmath>

Polinom::Polinom(number x,number y,number z)
{
    printmode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
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
        number * xroots = new number[2];
        xroots[0] = (-b - sqrt(delta))/(2 * a);
        xroots[1] = (-b + sqrt(delta))/(2 * a);
        if (-a*(xroots[0] + xroots[1]) == b && a*xroots[0]*xroots[1] == c)
        {
            return xroots;
        }
        if (value(xroots[0]) == 0)
        {
            xroots[1] = xroots[0];
            return xroots;
        }
        if (value(xroots[1]) == 0)
        {
            xroots[0] = xroots[1];
            return xroots;
        }
        delete [] xroots;
    }
    return NULL;
}

std::ostream& operator <<(std::ostream& os,Polinom& p)
{
    if (p.printmode == EPrintModeClassic)
        os << "p(x) = " << p.a <<"x^2 " << (p.b < 0 ? "" : "+") << p.b << "x " << (p.c < 0 ? "" : "+") << p.c <<std::endl;
    else
    {
        if (p.b % (2*p.a) == 0)
        {
            number x0 = -p.b/(2*p.a);
            number y0 = p.value(x0);

            os << p.a << "(x " << (x0 < 0 ? "+ " : "- ") << std::abs(x0) << ")^2 " << (y0 < 0 ? "" : "+") << y0 << std::endl;
        }
        else
        {
            os << "Cannot output canonical form because x0 = -b/(2*a) does not belong to type 'number'" << std::endl;
        }
    }
    return os;
}
