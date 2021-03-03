#include "rational.h"

TRational::TRational(int a, unsigned b = 1)
{
    this->a = a;
    this->b = b;
}

TRational::TRational(const int& a)
{
    this->a = a;
    this->b = 1;
}

std::ostream& operator <<(std::ostream& os, TRational& r)
{
    os << "(" << r.a << "/" << r.b << ")";
    return os;
}

std::istream &operator>>(std::istream &is, char const *pat)
{
    char ch;
    while (isspace(static_cast<unsigned char>(is.peek())))
        is.get(ch);

    while (*pat && is && *pat == is.peek() && is.get(ch)) {
        ++pat;
    }

    // if we didn't reach the end of the pattern, matching failed (mismatch, premature EOF, etc.)
    if (*pat) {
        is.setstate(std::ios::failbit);
    }

    return is;
}

std::istream& operator >>(std::istream& is, TRational& r)
{
    is >> r.a >> "/" >> r.b;
    return is;
}


