// Программа, выводящая не печать все пары (имя, баллы) по одной в строке. Повторение имени вызывает предупреждение.
// NoName 0 = конец ввода пар

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>

void pairs_print(const std::vector<std::string>& v_s, const std::vector<int>& v_i)
{
    std::cout << "Все пары (имя, баллы):\n";

    for (int i = 0; (i < v_s.size() && i < v_i.size()); ++i)
    {
        std::cout << std::setw(10) << v_s[i] << std::setw(10) << v_i[i] << '\n';
    }
}

void pairs_check(const std::vector<std::string>& v_s)
// checking for repeated names
// skips checked names
{
    std::vector<bool> v_checked(v_s.size(), false);
    bool is_repeted{ false };
    
    for (int i = 0; i < v_s.size(); ++i)
    {
        if (v_checked[i] == true)
            continue;
        for (int j = i + 1; j < v_s.size(); ++j)
        {
            if (v_s[i] == v_s[j])
            {
                is_repeted = true;
                v_checked[j] = true;
            }
        }
        if (is_repeted)
        {
            std::cout << "Внимание! Имя " << v_s[i] << " повторяется!\n";
            is_repeted = false;     // check reset
        }
    }
}

void pairs()
// main function
// input a set of name and value pairs
{
    std::string name;
    std::string stop_string{ "NoName" };        // for output stop
    int score{};
    int stop_score{ 0 };        // for output stop
    std::vector<std::string> names;
    std::vector<int> scores;

    std::cout << "Введите набор пар, состоящих из имени и значения...\n";

    for (; std::cin >> name >> score; )
    {
        if (name == stop_string && score == stop_score)
            break;
        names.push_back(name);
        scores.push_back(score);
    }

    pairs_check(names);
    pairs_print(names, scores);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    pairs();
}
