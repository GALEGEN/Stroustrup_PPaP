// Вычисление количества зерен риса, запрошенных изобретателем шахмат в упр.8. Определение вместимости переменных int и double.

#include <iostream>
#include <float.h>
#include <stdexcept>
#include <Windows.h>

int grains_int_test(int& cell_number, const int& cell_max) {
    unsigned int grains_number{ 1 };    // количество зерен в текущей клетке, начальное кол-во: 1
    unsigned int grains_int_max{};    // максимальное количество зерен риса для int

    for (cell_number = 0; (cell_number < cell_max && (grains_int_max + grains_number) < INT_MAX); ++cell_number) {
        grains_int_max += grains_number;
        grains_number *= 2;
    }
    std::cout << "Максимальное значение типа int:\t" << INT_MAX << std::endl
        << "Заполнено клеток:\t" << cell_number << std::endl 
        << "Зерен риса получено:\t" << (grains_int_max + grains_number) << std::endl;
    return 0;
}

double grains_double_test(int& cell_number, const int& cell_max) {
    double grains_number{ 1 };    // количество зерен в текущей клетке, начальное кол-во: 1
    double grains_double_max{};    // максимальное количество зерен риса для double

    for (cell_number = 0; (cell_number < cell_max && (grains_double_max + grains_number) < DBL_MAX); ++cell_number) {
        grains_double_max += grains_number;
        grains_number *= 2;
    }
    std::cout << "Максимальное значение типа duble:\t" << DBL_MAX << std::endl
        << "Заполнено клеток:\t" << cell_number << std::endl 
        << "Зерен риса получено:\t" << (grains_double_max + grains_number) << std::endl;
    return 0;
}

int main()
try{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int cell_number{};  // номер клетки
    char choice{};
    constexpr unsigned int cell_max{ 64 }; // максимальное число клеток на шахматной доске

    std::cout << "Проверка вместимости переменной int и double." << std::endl
        << "Введите '1' для проверки вместимости int и '2' для проверки double" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case '1': 
        grains_int_test(cell_number, cell_max);
        break;
    case '2': 
        grains_double_test(cell_number, cell_max);
        break;
    default:
        throw std::invalid_argument("Ошибка ввода/выбора!");
        break;
    }
}
catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return -1;
}
