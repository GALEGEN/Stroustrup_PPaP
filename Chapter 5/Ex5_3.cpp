// Поместить в функцию main() проверку, которая будет выводить сообщение об ошибке для температур ниже -273.15С

#include <iostream>
#include <stdexcept>
#include <Windows.h>
using std::cin;
using std::cout;

double ctok(double c)
// converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}

int main()
try {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double c{};             // declare input variable
    cin >> c;               // retrieve temperature to input variable
    if (c < -273.15)
        throw std::runtime_error("Температура ниже абсолютного нуля, т.е. ниже -273.15С");
    double k = ctok(c);     // convert temperature
    cout << k << '\n';      // print out temperature
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
    return -1;
}