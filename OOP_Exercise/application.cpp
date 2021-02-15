#include "application.h"
#include<iostream>
#include "polinom.h"
using namespace std;
TApplication::TApplication()
{

}
int TApplication::exec()
{
    int ch;
    number a = 0,b =1,c=1;
    while(true)
    {
        ch = menu();
        switch(ch)
        {
        case 1:
            do
            {
                cout<< "a = ";
                cin >>a;

                cout <<"b = ";
                cin >>b;

                cout <<"c = ";
                cin >>c;

                if (a == 0)
                    cout <<"Value of a must other 0!Re-enter coefficients!" << endl;
            } while(a == 0);
            break;
        case 2:
        {
            Polinom p (a,b,c);
            number x;
            cout <<"x = ";
            cin >>x;
            cout <<"p(x) = " << p.value(x) << endl;
        }
            break;
        case 3:
        {
            Polinom p(a,b,c);
            number* roots = p.roots();
            if (roots == NULL)
                cout << "The equation has no solution!" << endl;
            else
            {
                if (roots[0] == roots[1])
                    cout << "The equation have double solution: x1 = x2 = " << roots[0] << endl;
                else
                    cout << "The equation have 2 solutions: x1 = " << roots[0] <<", x2 = " << roots[1] << endl;
            }
        }
            break;
        case 4:
        {
            Polinom p(a,b,c);
            p.SetPrintMode(EPrintModeClassic);
            cout << p << endl;
        }
            break;
        case 5:
        {
            Polinom p(a,b,c);
            p.SetPrintMode(EPrintModeCanonic);
            cout << p << endl;
        }
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}
int TApplication::menu(){
    int ch;
    cout <<"0 - exit" << endl;
    cout <<"1 - coefficients" << endl;
    cout <<"2 - value" << endl;
    cout <<"3 - Roots" <<endl;
    cout <<"4 - print(classic)" << endl;
    cout <<"5 - print(canonic)" << endl  << "> ";
    cin >>ch;
    return ch;
}
