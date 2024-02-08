// ���������, ������������� ����������� � �������� �������� � ����������� � �������� �������

#include <iostream>
#include <stdexcept>
#include <Windows.h>
using std::cin;
using std::cout;

double ktoc(double k)
// converts Kelvin to Celsius
{
    if (k < 0)
        throw std::runtime_error("����������� ���� ����������� ����, �.�. ���� -273.15�");

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