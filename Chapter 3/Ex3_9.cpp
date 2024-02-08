// Преобразует слова "нуль", "два" и так далее в цифры 0, 2 и т.д. Когда пользователь вводит число в виде слова, программа должна
// вывести на экран соответствующую цифру.

#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string number_word{ " " };

    std::cout << "Введите число в виде слова..." << std::endl;
    while (std::cin >> number_word)
    {
        if (number_word == "нуль") {
            std::cout << '0' << std::endl;
        } 
        else if (number_word == "один") {
            std::cout << '1' << std::endl;
        } 
        else if (number_word == "два") {
            std::cout << '2' << std::endl;
        }
        else if (number_word == "три") {
            std::cout << '3' << std::endl;
        }
        else if (number_word == "четыре") {
            std::cout << '4' << std::endl;
        }
        else if (number_word == "пять") {
            std::cout << '5' << std::endl;
        }
        else if (number_word == "шесть") {
            std::cout << '6' << std::endl;
        }
        else if (number_word == "семь") {
            std::cout << '7' << std::endl;
        }
        else if (number_word == "восемь") {
            std::cout << '8' << std::endl;
        }
        else if (number_word == "девять") {
            std::cout << '9' << std::endl;
        }
        else {
            std::cout << "Я не знаю такого числа!" << std::endl;
        }
    }
}
