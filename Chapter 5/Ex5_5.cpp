// Программа, преобразующая температуру в градусах Кельвина в температуру в градусах Цельсия

#include <iostream>
#include <stdexcept>
#include <Windows.h>
using std::cin;
using std::cout;

double ktoc(double k)
// converts Kelvin to Celsius
{
    if (k < 0)
        throw std::runtime_error("Температура ниже абсолютного нуля, т.е. ниже -273.15С");

    double c = k - 273.15;
    return c;
}

int main()
try {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double k{};             // declare input variable
    cin >> k;               // retrieve temperature to input variable
    double c = ktoc(k);     // convert temperature
    cout << c << '\n';      // print out temperature
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
    return -1;
}