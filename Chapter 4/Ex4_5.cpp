// Программа, выполняющая самые простые функции калькулятора. Калькулятор должен выполнять четыре основные арифметические
// операции - сложение, вычитание, умножение и деление.

#include <iostream>
#include <Windows.h>

// Предлагает пользователю ввести три аргумента
// Принимает на вход: два значения типа double и символ операции
// Если входные аргументы равны 35.6, 24.1 и '+', то программа должна вывести на экран строку: "Сумма 35.6 и 24.1 равна 59.7"
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Выполняет операции сложения, вычитания, деления, умножения над двумя числами." << std::endl
        << "Введите два значения и символ операции." << std::endl;
    double number1{ 0 };
    double number2{ 0 };
    double result{ 0 };
    char symbol{ ' ' };
    char cycle_stop{ ' ' };
    while (true) {
        std::cin >> number1 >> number2 >> symbol;
        switch (symbol) {
        case '+':
            result = number1 + number2;
            std::cout << "Сумма " << number1 << " и " << number2 << " равна " << result << std::endl;
            break;
        case '-':
            result = number1 - number2;
            std::cout << "Разность " << number1 << " и " << number2 << " равна " << result << std::endl;
            break;
        case '*':
            result = number1 * number2;
            std::cout << "Произведение " << number1 << " и " << number2 << " равно " << result << std::endl;
            break;
        case '/':
            result = number1 / number2;
            std::cout << "Частное " << number1 << " и " << number2 << " равно " << result << std::endl;
            break;
        default:
            std::cout << "Неправильная комманда!";
            return 0;
            break;
        }
    }
}
