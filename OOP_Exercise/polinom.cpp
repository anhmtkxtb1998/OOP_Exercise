#include "polinom.h"

Polinom::Polinom(number x,number y,number z)
{
printmode = EPrintModeClassic;
a = x; b = y;c =z;
}
void Polinom::SetPrintMode(EPrintMode mode){
    printmode = mode;
}
number Polinom::value(number x){
    return (a * x *x  + b * x + c);
}
number * Polinom::roots(){
    number delta = b * b - 4 * a *c;
    if(delta < 0)
        return NULL;
    else
    {
        number * roots = new number[2];
        roots[0]= (-b - sqrt(delta))/(2 * a);
        roots[1] =(-b + sqrt(delta))/(2 * a);
        return roots;
    }
}
ostream& operator <<(ostream& os,Polinom& p){
    if(p.printmode == EPrintModeClassic)
    os << "p(x) = " << p.a <<"x^2 + " << p.b <<"x + " << p.c <<endl;
    else
    {

    }
    return os;
}
