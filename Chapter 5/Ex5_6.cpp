// Программа, преобразующая температуру в градусах Цельсия в температуру в градусах Фаренгейта и обратно

#include <iostream>
#include <stdexcept>
#include <Windows.h>
using std::cin;
using std::cout;

double ctof(double c)
// converts Celsius to Fahrenheit
{
    if (c < -273.15)
        throw std::runtime_error("Температура ниже абсолютного нуля, т.е. ниже -273.15С");

    double f = 9.0 / 5 * c + 32;    // formula from 4.3.3
    return f;
}

double ftoc(double f)
// converts Fahrenheit to Celsius
{
    double c = (f - 32) * 5.0 / 9;
    return c;
}

int main()
try {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double dc{};             // declare input variable
    cin >> dc;               // retrieve temperature to input variable
    double df = ctof(dc);     // convert temperature
    cout << df << '\n';      // print out temperature
    double conv_c = ftoc(df);       // reverse conversion
    cout << "Reverse convertation result: " << conv_c << '\n';
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
    return -1;
}