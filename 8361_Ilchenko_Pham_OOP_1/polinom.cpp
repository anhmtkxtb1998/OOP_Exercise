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

number * Polinom::roots()
{
    number discr = b * b - 4 * a * c;
    if (discr >= 0)
    {
        number * xroots = new number[2];
        xroots[0] = (-b - sqrt(discr))/(2 * a);
        xroots[1] = (-b + sqrt(discr))/(2 * a);
        if (-a * (xroots[0] + xroots[1]) == b && a * xroots[0] * xroots[1] == c)
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
        os << "p(x) = " << p.a << "x^2 " << (p.b < 0 ? "- " : "+ ") << std::abs(p.b) << "x " << (p.c < 0 ? "- " : "+ ") << std::abs(p.c) << std::endl;
    else
    {
        number x0 = -p.b/(2*p.a);
        if (x0 * 2 * p.a == -p.b)
        {
            number y0 = p.value(x0);
            os << p.a << "(x " << (x0 < 0 ? "+ " : "- ") << std::abs(x0) << ")^2 " << (y0 < 0 ? "- " : "+ ") << std::abs(y0) << std::endl;
        }
        else
        {
            os << "Cannot output canonic form because x0 = -b/(2*a) does not belong to type 'number'" << std::endl;
        }
    }
    return os;
}
