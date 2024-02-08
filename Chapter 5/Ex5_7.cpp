// Программа для решения квадратных уравнений
// Same solution from Ex 4-18

#include <iostream>
#include <cmath>
#include <Windows.h>

void quadratic_equation(const double& a, const double& b, const double& c)
{
    double dis{};
    double x1{};
    double x2{};

    dis = ((b * b) - 4 * a * c);
    if (dis < 0)
        std::cout << "Дискриминант равен: " << dis << "\nКорней нет.\n";
    else {
        if (dis == 0) {
            x1 = ((-b) / 2 * a);
            std::cout << "Дискриминант равен: " << dis << "\nКорень равен: " << x1 << '\n';
        }
        else {
            x1 = ((-b) - sqrt(dis)) / (2 * a);
            x2 = ((-b) + sqrt(dis)) / (2 * a);
            std::cout << "Дискриминант равен: " << dis << "\nКорни равны: " << x1 << ", " << x2 << '\n';
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a{};
    double b{};
    double c{};

    std::cout << "Решение квадратных уравнений ax2+bx+c=0.\nВведите a, b, c...\n";

    std::cin >> a >> b >> c;

    quadratic_equation(a, b, c);
}