#include "application.h"
#include <iostream>
#include "polinom.h"

TApplication::TApplication()
{

}

int TApplication::exec()
{
    int ch;
    number a = 1, b =2, c=1;
    while(true)
    {
        ch = menu();
        switch(ch)
        {
        case 1:
            do
            {
                std::cout << "a = ";
                std::cin >> a;
                std::cout << "b = ";
                std::cin >> b;
                std::cout << "c = ";
                std::cin >> c;

                if (a == 0)
                    std::cout << "Value of 'a' cant be 0! Reenter coefficients!" << std::endl;
            } while(a == 0);
            break;

        case 2:
        {
            Polinom p (a, b, c);
            number x;
            std::cout <<"x = ";
            std::cin >> x;
            std::cout << "p(x) = " << p.value(x) << std::endl;
        }
            break;

        case 3:
        {
            Polinom p(a, b, c);
            number* roots = p.roots();
            if (roots == NULL)
                std::cout << "The equation has no solutions!" << std::endl;
            else
            {
                if (roots[0] == roots[1])
                    std::cout << "The equation has one solution: x1 = " << roots[0] << std::endl;
                else
                    std::cout << "The equation has two solutions: x1 = " << roots[0] << ", x2 = " << roots[1] << std::endl;
            }
        }
            break;

        case 4:
        {
            Polinom p(a, b, c);
            p.setPrintMode(EPrintModeClassic);
            std::cout << p << std::endl;
        }
            break;

        case 5:
        {
            Polinom p(a, b, c);
            p.setPrintMode(EPrintModeCanonic);
            std::cout << p << std::endl;
        }
            break;

        case 0:
            return 0;

        default:
            std::cout << "No command for this input. Enter number from 0 to 5" << std::endl;
            break;
        }
    }
}

int TApplication::menu()
{
    int ch;
    std::cout << "0 - exit" << std::endl;
    std::cout << "1 - enter coefficients" << std::endl;
    std::cout << "2 - calculate value" << std::endl;
    std::cout << "3 - find roots" << std::endl;
    std::cout << "4 - print polinom (classic form)" << std::endl;
    std::cout << "5 - print polinom (canonic form)" << std::endl << "> ";
    std::cin >> ch;
    return ch;
}
