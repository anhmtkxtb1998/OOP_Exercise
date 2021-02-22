#ifndef POLINOM_H
#define POLINOM_H
#include<iostream>
#include"Number.h"

enum EPrintMode{
    EPrintModeClassic,
    EPrintModeCanonic,
};
class Polinom
{
    EPrintMode printmode;
    number a,b,c;
public:
    Polinom(number,number,number);
    void SetPrintMode(EPrintMode);
    number value(number);
    number * roots();
    friend std::ostream& operator <<(std::ostream&,Polinom&);
};

#endif // POLINOM_H
