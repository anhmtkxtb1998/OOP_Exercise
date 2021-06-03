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
                    std::cout<<"\nside1 = ";
                    std::cin >> a;
                    std::cout<<"\nside2 = ";
                    std::cin >> b;
                    std::cout<<"\nangle between sides = ";
                    std::cin >> angle;

                    if( a < 0 || b < 0 ||angle < 0 || angle > 180)
                        std::cout <<"\nIncorrect input for triangle!!!" << std::endl;
                    else
                        figure = new TTriangle(a, b, angle);
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
                    std::cout<<"\nside = ";
                    std::cin >> a;
                    std::cout<<"\napex angle = ";
                    std::cin >> angle;

                    if(a < 0 || angle < 0 || angle > 180)
                        std::cout <<"\nIncorrect input for isosceles triangle!!!" << std::endl;
                    else
                        figure = new TIsoscelesTriangle(a, angle);
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
                    std::cout<<"\nside = ";
                    std::cin >> a;
                    if(a < 0)
                        std::cout <<"\nIncorrect input for equilateral triangle!!!" << std::endl;
                    else
                        figure = new TEquilateralTriagle(a);
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
                    std::cout<<"\nsemiaxis1 = ";
                    std::cin >> a;
                    std::cout<<"\nsemiaxis2 = ";
                    std::cin >> b;

                    if(a < 0|| b < 0)
                        std::cout <<"\nIncorrect input for ellipse!!!" << std::endl;
                    else
                        figure = new TEllipse(a, b);
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
                    std::cout<<"\nradius = ";
                    std::cin >> a;
                    if(a < 0)
                        std::cout <<"\nIncorrect input for circle!!!" << std::endl;
                    else
                        figure = new TCircle(a);
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
                    std::cout<<"\nside1 = ";
                    std::cin >> a;
                    std::cout<<"\ndiagonal = ";
                    std::cin >> b;
                    std::cout<<"\nside2 = ";
                    std::cin >> c;
                    std::cout<<"\nangle between side1 and diagonal = ";
                    std::cin >> angle1;
                    std::cout<<"\nangle between side2 and diagonal = ";
                    std::cin >> angle2;
                    if(a < 0|| b < 0|| c < 0 || angle1 < 0 || angle1 > 180 || angle2 < 0 || angle2 > 180)
                        std::cout <<"\nIncorrect input for Quadrangle!!!" << std::endl;
                    else
                        figure = new TQuadrangle(a, b, c, angle1, angle2);
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
                    std::cout<<"\nside = ";
                    std::cin >> a;
                    std::cout<<"\ndiagonal = ";
                    std::cin >> b;
                    std::cout<<"\nangle between side and diagonal = ";
                    std::cin >> angle;
                    if(a < 0 || b < 0 || angle < 0 || angle > 180)
                        std::cout <<"\nIncorrect input for Parallelogram!!!" << std::endl;
                    else
                        figure = new TParallelogram(a, b, angle);
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
                    std::cout<<"\nside = ";
                    std::cin >> a;
                    std::cout<<"\nangle between sides = ";
                    std::cin >> angle;
                    if(a < 0|| angle < 0 || angle > 180)
                        std::cout <<"\nIncorrect input for rhombus!!!" << std::endl;
                    else
                        figure = new TRhombus(a, angle);
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
                    std::cout<<"\nside1 = ";
                    std::cin >> a;
                    std::cout<<"\nside2 = ";
                    std::cin >> b;
                    if(a < 0 || b < 0)
                        std::cout <<"\nIncorrect input for rectangle!!!" << std::endl;
                    else
                        figure = new TRectangle(a, b);
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
                    std::cout<<"\nside = ";
                    std::cin >> a;
                    if(a < 0)
                        std::cout <<"\nIncorrect input for square!!!" << std::endl;
                    else
                    figure = (TRectangle*)(new TSquare(a));
                }
                while(figure == NULL);
                figure->output(std::cout);
            }
                break;

            default:
                std::cout << "\nNo command for this input. Enter number from 0 to 10" << std::endl;
                break;
            }

        delete figure;
        std::cout << "\n" << std::endl;

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
