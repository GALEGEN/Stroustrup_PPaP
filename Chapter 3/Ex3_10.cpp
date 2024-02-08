// Принимает на входе символ операции с двумя операндами и выводящая на экран результат вычисления

#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string operation{ " " };
    double val1{ 0 };
    double val2{ 0 };
    double result{ 0 };

    std::cout << "Введите число в виде слова..." << std::endl;
    while (std::cin >> operation >> val1 >> val2)
    {
        if (operation == "+") {
            result = val1 + val2;
            std::cout << "Результат сложения: " << result << std::endl;
        }
        else if (operation == "-") {
            result = val1 - val2;
            std::cout << "Результат вычитания: " << result << std::endl;
        }
        else if (operation == "*") {
            result = val1 * val2;
            std::cout << "Результат умножения: " << result << std::endl;
        }
        else if (operation == "/") {
            result = val1 / val2;
            std::cout << "Результат деления: " << result << std::endl;
        }
        else if (operation == "plus") {
            result = val1 + val2;
            std::cout << "Результат сложения: " << result << std::endl;
        }
        else if (operation == "minus") {
            result = val1 - val2;
            std::cout << "Результат вычитания: " << result << std::endl;
        }
        else if (operation == "mul") {
            result = val1 * val2;
            std::cout << "Результат умножения: " << result << std::endl;
        }
        else if (operation == "div") {
            result = val1 / val2;
            std::cout << "Результат деления: " << result << std::endl;
        }
        else {
            std::cout << "Ошибка ввода!" << std::endl;
        }
    }
}
