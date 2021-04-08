#include "rational.h"
#include "common.h"
#include <cmath>
QChar TRational::SEPARATOR = separator;

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

TRational::TRational(const QByteArray& arr)
{
    int p = arr.indexOf(SEPARATOR);
    a = arr.left(p).toInt();
    b = arr.right(arr.length()-p-1).toInt();
    this->compact();
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

int TRational::get_value_a()
{
    return this->a;
}

int TRational::get_value_b()
{
    return this->b;
}

void TRational::setSeparator(QChar ch)
{
    SEPARATOR = ch;
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

QString& operator <<(QString& s, TRational r)
{
    s += "(" + QString().setNum(r.a) + "/" + QString().setNum(r.b) +")";
    return s;
}

QByteArray& operator >>(QByteArray& arr, TRational& c)
{
    int p = arr.indexOf(TRational::SEPARATOR);
    p = arr.indexOf(TRational::SEPARATOR,p+1);
    if (p > 0)
    {
        c = TRational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

TRational::operator QString()
{
    QString s;
    s += "(" + QString().setNum(a) + "/" + QString().setNum(b) +")";
    return s;
}
