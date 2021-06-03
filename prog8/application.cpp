#include "application.h"
#include <iostream>
#include "equilateraltriagle.h"
#include "circle.h"
#include "square.h"

TApplication::TApplication()
{

}
int TApplication::exec()
{
    TFigure * figure;
    int choose;
    do
    {
        choose = menu();
        figure = NULL;
        switch (choose)
        {
            case 0:
                break;

            case 1:
            {
                double a, b, angle;
                do
                {
                    std::cout<<"\nside1 = "; cin >> a;
                    std::cout<<"\nside2 = "; cin >> b;
                    std::cout<<"\nangle between sides = "; cin >> angle;
                    figure = TTriangle::create(a, b, angle);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for triangle!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 2:
            {
                double a, angle;
                do
                {
                    std::cout<<"\nside = "; cin >> a;
                    std::cout<<"\nangle between sides = "; cin >> angle;
                    figure = TIsoscelesTriangle::create(a, angle);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for isosceles triangle!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 3:
            {
                double a;
                do
                {
                    std::cout<<"\nside = "; cin >> a;
                    figure = TEquilateralTriagle::create(a);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for equilateral triangle!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 4:
            {
                double a, b;
                do
                {
                    std::cout<<"\nradius1 = "; cin >> a;
                    std::cout<<"\nradius2 = "; cin >> b;
                    figure = TEllipse::create(a, b);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for ellipse!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 5:
            {
                double a;
                do
                {
                    std::cout<<"\nradius = "; cin >> a;
                    figure = TCircle::create(a);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for circle!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 6:
            {
                double a, b, c, angle1, angle2;
                do
                {
                    std::cout<<"\nside1 = "; cin >> a;
                    std::cout<<"\ndiagonal = "; cin >> b;
                    std::cout<<"\nside2 = "; cin >> c;
                    std::cout<<"\nangle between side1 and diagonal = "; cin >> angle1;
                    std::cout<<"\nangle between side2 and diagonal = "; cin >> angle2;
                    figure = TQuadrangle::create(a, b, c, angle1, angle2);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for Quadrangle!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;
            case 7:
            {
                double a, b, angle;
                do
                {
                    std::cout<<"\nside1 = "; cin >> a;
                    std::cout<<"\nside2 = "; cin >> b;
                    std::cout<<"\nangle between side1 and diagonal = "; cin >> angle;
                    figure = TParallelogram::create(a, b, angle);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for Parallelogram!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 8:
            {
                double a, angle;
                do
                {
                    std::cout<<"\nside = "; cin >> a;
                    std::cout<<"\nangle between side and diagonal = "; cin >> angle;
                    figure = TRhombus::create(a, angle);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for rhombus!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 9:
            {
                double a, b;
                do
                {
                    std::cout<<"\nside = "; cin >> a;
                    std::cout<<"\ndiagonal = "; cin >> b;
                    figure = TRectangle::create(a, b);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for rectangle!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            case 10:
            {
                double a;
                do
                {
                    std::cout<<"\nside = "; cin >> a;
                    figure = (TRectangle *)TSquare::create(a);
                    if(figure == NULL)
                        std::cout <<"\nIncorrect input for square!!!" << std::endl;
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
            break;

            default:
                break;
            }

        delete figure;

    }while(choose != 0);
    return 0;

}
int TApplication::menu()
{
    int ch;
    std::cout << "1 - Triangle" << std::endl;
    std::cout << "2 - Isosceles triangle" << std::endl;
    std::cout << "3 - Equilateral triangle" << std::endl;
    std::cout << "4 - Ellipse" << std::endl;
    std::cout << "5 - Circle" << std::endl;
    std::cout << "6 - Quadrangle" << std::endl;
    std::cout << "7 - Parallelogram" << std::endl;
    std::cout << "8 - Rhombus" << std::endl;
    std::cout << "9 - Rectangle" << std::endl;
    std::cout << "10 - Square" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << ">> ";
    std::cin >> ch;
    return ch;
}
