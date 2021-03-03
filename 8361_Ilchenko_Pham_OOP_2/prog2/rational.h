#ifndef TRATIONAL_H
#define TRATIONAL_H
#include <iostream>

class TRational
{
    int a;
    unsigned b;
public:
    TRational(int, unsigned);
    TRational(const int&);
    friend std::ostream& operator <<(std::ostream&, TRational&);
    friend std::istream& operator >>(std::istream&, TRational&);
    friend std::istream& operator >>(std::istream &, char const *);
};

#endif // TRATIONAL_H
