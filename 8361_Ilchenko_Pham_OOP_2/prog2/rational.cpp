#include "rational.h"
#include <cmath>

TRational::TRational()
{

}

TRational::TRational(int a, int b = 1)
{
    this->a = a;
    this->b = b;
    this->compact();
}

TRational::TRational(const int& a)
{
    this->a = a;
    this->b = 1;
}

int TRational::gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void TRational::compact()
{
    int g = gcd(a,b);
    a = a/g;
    b = b/g;
    if (b < 0)
    {
        a *= -1;
        b *= -1;
    }
}

std::ostream& operator <<(std::ostream& os, TRational r)
{
    os << "(" << r.a << "/" << r.b << ")";
    return os;
}

std::istream& operator >>(std::istream& is, TRational& r)
{
    char div;
    is >> r.a >> div >> r.b;
    if (div != '/')
        std::cout << "Enter in format a/b: ";
    while (r.b == 0)
    {
        std::cout << "Denominator cant be 0. Reenter: ";
        is >> r.a >> div >> r.b;
        if (div != '/')
            std::cout << "Enter in format a/b: ";
    }
    r.compact();
    return is;
}

bool TRational::operator ==(const TRational & p) const
{
    if (this->a == p.a && this->b == p.b)
        return true;
    else
        return false;
}

bool TRational::operator >=(const TRational & p) const
{
    if (this->a * p.b >= p.a * this->b)
        return true;
    else
        return false;
}

bool TRational::operator <(const TRational & p) const
{
    if (this->a * p.b < p.a * this->b)
        return true;
    else
        return false;
}

TRational operator *(const TRational &r, const TRational & p)
{
    TRational res(r.a * p.a, r.b * p.b);
    return res;
}

TRational TRational::operator /(const TRational & p) const
{
    TRational res(this->a * p.b, this->b * p.a);
    return res;
}

TRational TRational::operator +(const TRational & p) const
{
    TRational res(this->a * p.b + p.a * this->b, this->b * p.b);
    return res;
}

TRational TRational::operator -(const TRational & p) const
{
    TRational res(this->a * p.b - p.a * this->b, this->b * p.b);
    return res;
}

TRational TRational::operator -() const
{
    TRational res(-this->a, this->b);
    return res;
}

TRational sqrt(TRational r)
{
    TRational res(sqrt(r.a), sqrt(r.b));
    return res;
}

TRational std::abs(TRational r)
{
    TRational res(std::abs(r.a), r.b);
    return res;
}
