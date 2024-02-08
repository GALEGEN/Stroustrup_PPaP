// Преобразует мили в километры

#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    double mile{ 0 };
    double mile_to_km{ 1.609 };
    double translation_result{ 0 };

    std::cout << "Введите количество миль для перевода в километры..." << std::endl;

    while (std::cin >> mile)
    {
        translation_result = mile * mile_to_km;
        std::cout << "Введено:" << mile << "миль." << std::endl
            << "Результат перевода из миль в км: " << translation_result << std::endl;
    }
}
