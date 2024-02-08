// Программа, преобразующая цифру в соответстсующее строковое представление и наоборот. 

#include <iostream>
#include <vector>
#include <stdexcept>
#include <Windows.h>

std::string to_string(int digit, std::vector<std::string>& names)
// Преобразует цифру в соответствующее строковое представление. 
// При вводе цифры 7 на экран должна быть выведена строка "seven".
{
    if (digit < 0 || digit > 9)
        throw std::invalid_argument("Недопустимое значение цифры");
    return names[digit];
}

int to_digit(std::string digit, std::vector<std::string>& names)
// Преобразует строковое представление цифры в числовое. 
// При вводе строки "seven" на экран должна быть выведена цифра 7.
{
    for (int i = 0; i < names.size(); ++i) {
        if (digit == names[i])
            return i;
    }
    throw std::invalid_argument("Недопустимое строковое представление цифры");
}

int main()
try{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char function_selection{};
    std::vector<std::string> names = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    std::cout << "Если нужна первая итерация программы (перевод из цифры в строку), введите 1." << std::endl
        << "Если нужна вторая итерация программы (перевод из строки в число), введите 2." << std::endl;
    std::cin >> function_selection;
    if (function_selection != '1' && function_selection != '2')
        throw std::runtime_error("Введено неверное значение при выборе действия");
    if (function_selection == '1') {
        int number;
        std::cout << "Введите цифру для преобразования:\t";
        std::cin >> number;
        std::cout << "Результат преобразования:\t" << to_string(number, names) << std::endl;
    }
    else {
        std::string number;
        std::cout << "Введите строковое значение цифры для преобразования:\t";
        std::cin >> number;
        std::cout << "Результат преобразования:\t" << to_digit(number, names) << std::endl;
    }

    return 0;
}
catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return -1;
}
catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return -2;
}
