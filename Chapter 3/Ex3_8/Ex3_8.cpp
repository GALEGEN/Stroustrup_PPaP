// Проверяет четность или нечетность введеных целых чисел

#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int number_check{ 0 };
    int remainder{ 0 };

    std::cout << "Введите целое число для проверки четности или нечетности..." << std::endl;
    while (std::cin >> number_check)
    {
        remainder = number_check % 2;
        std::cout << "Число " << number_check << " является ";
        if (remainder == 0)
        {
            std::cout << "четным." << std::endl;
        }
        else
        {
            std::cout << "нечетным." << std::endl;
        }
    }
}
