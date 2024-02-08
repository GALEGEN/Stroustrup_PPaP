// Найдите ошибки и исправьте программу

/*
original code:

double ctok(double c)
{
    int k = c + 273.15;
    return int;
}

int main()
{
    double c = 0;
    cin >> d;
    double k = ctok("c");
    Cout << k << '\n';
}
*/

#include <iostream>
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
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double c{};             // declare input variable
    cin >> c;               // retrieve temperature to input variable
    double k = ctok(c);     // convert temperature
    cout << k << '\n';      // print out temperature
}
