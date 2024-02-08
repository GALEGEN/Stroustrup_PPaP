// Программа, определяющая наименьшее и набольшее значения, а также моду последовательности строк типа string
// Введите ';' в конце ввода для предотвращения считывания в вектор

#include <iostream>
#include <stdexcept>
#include <vector>
#include <Windows.h>

void mode_print(const std::vector<std::string>& v)
{
    std::cout << "Мода последовательности строк: ";
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];
        if (i != v.size() - 1)
            std::cout << ", ";
    }
    std::cout << '\n';
}

void mode_stringSearch(const std::vector<std::string>& v)
// without sort algorithm
// skips checked words
// searches several modes
{
    std::vector<std::string> mode_strings;       // mode vector
    std::vector<bool> v_checked(v.size(), false);        // for checked numbers skip

    short count_defalult{ 0 };      // number repeat counter
    short count1{},
        count2{};

    for (int i = 0; i < v.size(); ++i)
    {
        if (v_checked[i] == true)
            continue;
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[i] == v[j])
            {
                v_checked[j] = true;
                ++count2;
            }
        }
        if (count1 < count2)
        {
            mode_strings.clear();
            mode_strings.push_back(v[i]);
            count1 = count2;
        }
        else if (count1 == count2 && count2 != count_defalult)
            mode_strings.push_back(v[i]);
        count2 = count_defalult;
    }
    
    if (mode_strings.size() == 0)
        throw std::runtime_error("Мода неопределена!");

    mode_print(mode_strings);
}

void lowest_highest(const std::vector<std::string>& v)
// string compare function
{
    std::string highest{v[0]};
    std::string lowest{v[0]};

    for (int i = 1; i < v.size(); ++i)
    {
        if (highest < v[i])
        {
            highest = v[i];
            continue;
        }
        if (lowest > v[i])
            lowest = v[i];
    }

    std::cout << "Наименьшее значение: " << highest << '\n';
    std::cout << "Наибольшее значение: " << lowest << '\n';
}

void string_statistic()
// main search string function
{
    std::vector<std::string> strings;

    std::cout << "Введите последовательность строк...\n";

    for (std::string string; std::cin >> string; )
    {
        if (string == ";")      // ';' - input stop
            break;
        strings.push_back(string);
    }

    if (strings.size() == 0)
        throw std::runtime_error("Vector is empty!");

    lowest_highest(strings);
    mode_stringSearch(strings);
}

int main()
try {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string_statistic();
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
}
