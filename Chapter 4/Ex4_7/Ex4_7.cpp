// Модификация мини-калькулятора из упр. 5. Теперь он принимает на вход цифры, записанные как в цисловом, так и в строковом
// формате

#include <iostream>
#include <vector>
#include <stdexcept>
#include <Windows.h>

int to_digit(std::string& digit, std::vector<std::string>& string_digits, std::vector<std::string>& digits)
// Преобразует строковое представление цифры в числовое.
{
    for (int i = 0; i < digits.size(); ++i) {
        if (digit == digits[i])
            return i;
    }
    for (int i = 0; i < string_digits.size(); ++i) {
        if (digit == string_digits[i])
            return i;
    }
    throw std::invalid_argument("Недопустимое строковое представление цифры");
}

int calculation(double& number1, double& number2, char& symbol)
// Принимает на вход: два числа типа double и символ операции
{
    switch (symbol) {
    case '+':
        std::cout << "Сумма " << number1 << " и " << number2 << " равна " << number1 + number2 << std::endl;
        return 0;
        break;
    case '-':
        std::cout << "Разность " << number1 << " и " << number2 << " равна " << number1 - number2 << std::endl;
        return 0;
        break;
    case '*':
        std::cout << "Произведение " << number1 << " и " << number2 << " равно " << number1 * number2 << std::endl;
        return 0;
        break;
    case '/':
        std::cout << "Частное " << number1 << " и " << number2 << " равно " << number1 / number2 << std::endl;
        return 0;
        break;
    default:
        throw std::invalid_argument("Ошибка ввода");
        break;
    }
}

// Предлагает пользователю ввести три аргумента
// Принимает на вход: две цифры типа string и символ операции; два числа типа double и символ операции
// Если входные аргументы равны 35.6, 24.1 и '+', то программа должна вывести на экран строку: "Сумма 35.6 и 24.1 равна 59.7"
int main()
try {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double number1{}; // {} определятеся нулем
    double number2{};
    std::string number3{};
    std::string number4{};
    char symbol{};
    char function_selection{};
    std::vector<std::string> string_digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::vector<std::string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

    std::cout << "Если нужна первая итерация программы (работа с большими числами double), введите 1." << std::endl
        << "Если нужна вторая итерация программы (работа с цифрами и их строковыми значениями), введите 2." << std::endl;
    std::cin >> function_selection;
    if (function_selection != '1' && function_selection != '2')
        throw std::runtime_error("Введено неверное значение при выборе действия");
    std::cout << "Выполняет операции сложения, вычитания, деления, умножения над двумя числами." << std::endl
        << "Введите два значения и символ операции." << std::endl;

    if (function_selection == '1') {
        std::cin >> number1 >> number2 >> symbol;
        calculation(number1, number2, symbol);
    }
    else {
        std::cin >> number3 >> number4 >> symbol;
        number1 = to_digit(number3, string_digits, digits);
        number2 = to_digit(number4, string_digits, digits);
        calculation(number1, number2, symbol);
    }
}
catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return -1;
}
catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return -2;
}
