#ifndef POLINOM_H
#define POLINOM_H
#include<iostream>
#include<cmath>
#include"Number.h"
using namespace std;
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
    friend ostream& operator <<(ostream&,Polinom&);
};

#endif // POLINOM_H
