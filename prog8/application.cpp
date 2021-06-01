#include "application.h"
#include<iostream>
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
                std::cout<<"\na = "; cin >> a;
                std::cout<<"\nb = "; cin >> b;
                std::cout<<"\nangle = "; cin >> angle;
                figure = TTriangle::create(a, b, angle);
                if(figure == NULL)
                    std::cout <<"\nВводные данные для треугольника не правильный!!!" << std::endl;
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
                    std::cout<<"\na = "; cin >> a;
                    std::cout<<"\nangle = "; cin >> angle;
                    figure = TIsoscelesTriangle::create(a, angle);
                    if(figure == NULL)
                        std::cout <<"\nВводные данные для равнобедренного треугольника не правильный!!!" << std::endl;
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
                    std::cout<<"\na = "; cin >> a;
                    figure = TEquilateralTriagle::create(a);
                    if(figure == NULL)
                        std::cout <<"\nВводные данные для равносторонного треугольника не правильный!!!" << std::endl;
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
                    std::cout<<"\na = "; cin >> a;
                    std::cout<<"\nb = "; cin >> b;
                    figure = TEllipse::create(a, b);
                    if(figure == NULL)
                        std::cout <<"\nВводные данные для эллипса не правильный!!!" << std::endl;
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
                    std::cout<<"\na = "; cin >> a;
                    figure = TCircle::create(a);
                    if(figure == NULL)
                        std::cout <<"\nВводные данные для окружности не правильный!!!" << std::endl;
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
               std::cout<<"\na = "; cin >> a;
               std::cout<<"\nb = "; cin >> b;
               std::cout<<"\nc = "; cin >> c;
               std::cout<<"\nangle1 = "; cin >> angle1;
               std::cout<<"\nangle2 = "; cin >> angle2;
               figure = TQuadrangle::create(a, b, c, angle1, angle2);
               if(figure == NULL)
                   std::cout <<"\nВводные данные для четырехугольника не правильный!!!" << std::endl;
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
               std::cout<<"\na = "; cin >> a;
               std::cout<<"\nb = "; cin >> b;
               std::cout<<"\nangle = "; cin >> angle;
               figure = TParallelogram::create(a, b, angle);
               if(figure == NULL)
                   std::cout <<"\nВводные данные для четырехугольника не правильный!!!" << std::endl;
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
               std::cout<<"\na = "; cin >> a;
               std::cout<<"\nangle = "; cin >> angle;
               figure = TRhombus::create(a, angle);
               if(figure == NULL)
                   std::cout <<"\nВводные данные для четырехугольника не правильный!!!" << std::endl;
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
               std::cout<<"\na = "; cin >> a;
               std::cout<<"\nb = "; cin >> b;
               figure = TRectangle::create(a, b);
               if(figure == NULL)
                   std::cout <<"\nВводные данные для четырехугольника не правильный!!!" << std::endl;
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
               std::cout<<"\na = "; cin >> a;
               figure = TSquare::create(a);
               if(figure == NULL)
                   std::cout <<"\nВводные данные для четырехугольника не правильный!!!" << std::endl;
           }
           while(figure == NULL);
           figure->output(std::cout);
           }
              break;

           default:
                break;
           }
    }while(choose != 0);
    delete figure;
    return 0;

}
int TApplication::menu()
{
    int ch;
    std::cout << "1- Треугольник" << std::endl;
    std::cout << "2- Равнобедренный треугольник" << std::endl;
    std::cout << "3- Равносторонний треугольник" << std::endl;
    std::cout << "4- Эллипс" << std::endl;
    std::cout << "5- Окружность" << std::endl;
    std::cout << "6- Четырехугольник" << std::endl;
    std::cout << "7- Параллелограмм" << std::endl;
    std::cout << "8- Ромб" << std::endl;
    std::cout << "9- Прямоугольник" << std::endl;
    std::cout << "10- Квадрат" << std::endl;
    std::cout << "0- Выход" << std::endl;
    std::cout <<">> ";
    std::cin >> ch;
    return ch;
}
