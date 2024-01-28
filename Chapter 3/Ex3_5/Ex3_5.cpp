// Определяет наименьшее и наиобольшее значение, сумму, разность, произведение и частное введеных двух значений
// Просит пользователя ввести два числа с плавающей точкой

#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    double val1{ 0 };
    double val2{ 0 };

    std::cout << "Введите два цисла с плавающей точкой:" << std::endl;
    while (std::cin >> val1 >> val2)
    {
        if (val1 < val2) {
            std::cout << "Наименьшее: " << val1 << ". Наибольшее: " << val2 << "." << std::endl;
        }
        else {
            std::cout << "Наименьшее: " << val2 << ". Наибольшее: " << val1 << "." << std::endl;
        }
        std::cout << "Сумма: " << (val1 + val2) << ". Разность: " << (val1 - val2) << ". Произведение: " << (val1 * val2)
            << ". Частное: " << (val1 / val2) << std::endl;
    }
}
