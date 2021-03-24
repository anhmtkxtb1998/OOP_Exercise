#ifndef TRATIONAL_H
#define TRATIONAL_H
#include <QString>
class TRational;

namespace std
{
    TRational abs(TRational);
}

class TRational
{
    int a, b;
    int gcd(int, int);
    void compact();
public:
    TRational();
    TRational(int, int);
    TRational(const int&);
    bool operator ==(const TRational &) const;
    bool operator >=(const TRational &) const;
    bool operator <(const TRational &) const;
    friend TRational operator *(const TRational &, const TRational &);
    TRational operator /(const TRational &) const;
    TRational operator +(const TRational &) const;
    TRational operator -(const TRational &) const;
    TRational operator -() const;
    friend TRational sqrt(TRational);
    friend TRational std::abs(TRational);
    friend QString& operator <<(QString&, TRational);
};



#endif // TRATIONAL_H
