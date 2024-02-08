// Программа для игры "Камень, бумага, ножницы". Машина должна давать случайные ответы.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <Windows.h>

char game_randomAnswer(char& motion, const std::vector<char>& sequence, int& i)
// простой рандомизатор с выводом ответа игры
// принимает ход, вектор последовательности значений и число для генератора случайных чисел
{
    switch (motion) {
    case 'R': {
        if (i >= sequence.size())
            i = 0;
        if (sequence[i] == 'R')
            std::cout << "Камень. Ничья!\n";
        if (sequence[i] == 'P')
            std::cout << "Бумага. Я выиграл!\n";
        if (sequence[i] == 'S')
            std::cout << "Ножницы. Я проиграл!\n";
        ++i;
    }
            break;
    case 'P': {
        if (i >= sequence.size())
            i %= (sequence.size() - 1);
        if (sequence[i] == 'R')
            std::cout << "Камень. Я проиграл!\n";
        if (sequence[i] == 'P')
            std::cout << "Бумага. Ничья!\n";
        if (sequence[i] == 'S')
            std::cout << "Ножницы. Я выиграл!\n";
        i += 2;
    }
            break;
    case 'S': {
        if (i >= sequence.size())
            i %= (sequence.size() - 1);
        if (sequence[i] == 'R')
            std::cout << "Камень. Я выиграл!\n";
        if (sequence[i] == 'P')
            std::cout << "Бумага. Я проиграл!\n";
        if (sequence[i] == 'S')
            std::cout << "Ножницы. Ничья!\n";
        i += 3;
    }
            break;
    default:
        std::cout << "Введено неправильное значение.\n";
        break;
    }
    return 0;
}

char game_main()
// основная функция для игры
{
    const std::vector<char> sequence = { 'R', 'P', 'S', 'S', 'P', 'R', 'R', 'S', 'P', 'P' };
    char motion{};      // Ход в виде R - камень, S - ножницы, P - бумага
    int randomizer{};

    std::cout << "Игра 'Камень, ножницы, бумага'.\nВведите случайную цифру от 0 до 9\nВведите X для выхода из игры.\n";
    std::cin >> randomizer;
    if (randomizer < 0 || randomizer > 9)
        throw std::out_of_range("Ошибка! Выход за указанные пределы.");

    while (true) {
        std::cout << "Ваш ход? (варианты ответа: R, S, P, X)\n";
        std::cin >> motion;
        if (motion == 'X') break;
        game_randomAnswer(motion, sequence, randomizer);
    }
    return 0;
}

int main()
try{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    game_main();
}
catch (std::out_of_range& e)
{
    std::cerr << e.what() << std::endl;
    return -1;
}
