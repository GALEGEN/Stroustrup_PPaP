// Программа, вычисляющая сколько клеток надо заполнить, чтобы изобретатель получил не менее 1000 зерен риса, не менее 1 000 000
// зерен риса и не менее 1 000 000 000 зерен риса.

#include <iostream>
#include <iomanip>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unsigned int cell_number{};  // номер клетки
    unsigned int grains_number{};    // количество зерен в текущей клетке
    unsigned int grains_total{}; // количество зерен во всех предыдущих клетках
    unsigned int grains_needed{};    // необходимое количество зерен риса
    constexpr unsigned int cell_max{ 64 }; // максимальное число клеток на шахматной доске

    std::cout << "Сколько клеток нужно заполнить для получения N зерен риса?" << std::endl
        << "Введите нужное количество зерен риса чтобы узнать сколько клеток понадобится..." << std::endl;
    grains_number = 1;   // начальное количество зерен в первой клетке
    std::cin >> grains_needed;
    for (cell_number = 0; (cell_number < cell_max && grains_total < grains_needed); ++cell_number) {
        std::cout << std::setfill('=') << std::setw(50) << "\n"
            << "Текущий номер клетки:\t" << (cell_number + 1) << std::endl << "Количество зерен в текущей клетке:\t" 
            << grains_number << std::endl << "Количество зерен во всех предыдущих клетках:\t" << grains_total << std::endl;
        grains_total += grains_number;
        grains_number *= 2;
    }
    std::cout << "Было необходимо получить не менее " << grains_needed << " зерен риса." << std::endl << "Заполнено клеток:\t" 
        << cell_number << std::endl << "Зерен риса получено:\t" << grains_total << std::endl;
}
