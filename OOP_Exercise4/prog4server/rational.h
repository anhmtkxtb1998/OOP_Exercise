#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
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
    static QChar SEPARATOR;
    void compact();

public:
    TRational();
    TRational(int, int);
    TRational(const int&);
    TRational(const QByteArray&);
    int get_value_a();
    int get_value_b();
    static void setSeparator(QChar);
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
    friend QByteArray& operator >>(QByteArray&, TRational&);
    operator QString();
};


#endif // RATIONAL_H
