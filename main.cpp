#include <iostream>
#include <cmath>

double function(double x)
{
    return pow(x , 2);
}

double goldenSectionSearch(double a, double b, double epsilon)
{
    const double phi = (1 + sqrt(5)) / 2;

    double x1 = b - (b - a) / phi;
    double x2 = a + (b - a) / phi;
    double f1 = function(x1);
    double f2 = function(x2);

    while (abs(b - a) > epsilon)
    {
        if (f1 < f2)
        {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - (b - a) / phi;
            f1 = function(x1);
        }
        else
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + (b - a) / phi;
            f2 = function(x2);
        }
    }

    return (a + b) / 2;
}

int main()
{
    double a = 0; // Начальная точка интервала
    double b = 5; // Конечная точка интервала
    double epsilon = 0.0001; // Точность

    double minimum = goldenSectionSearch(a, b, epsilon);

    std::cout << "Минимум функции: " << M_PI << std::endl;

    return 0;
}
