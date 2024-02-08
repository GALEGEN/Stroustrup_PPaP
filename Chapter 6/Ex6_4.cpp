// Программа, выводящая не печать все пары (имя, баллы) по одной в строке. Повторение имени вызывает предупреждение.
// NoName 0 = конец ввода пар

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>

class Name_value {
public:
    std::string name;
    int value;
    Name_value(std::string str, int val)
        :name(str), value(val) {}
};

void pairs_print(const std::vector<Name_value>& v)
{
    std::cout << "All pairs (name, scores):\n";

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << std::setw(10) << v[i].name << std::setw(10) << v[i].value << '\n';
    }
}

void pairs_check(const std::vector<Name_value>& v)
// checking for repeated names
// skips checked names
{
    std::vector<bool> v_checked(v.size(), false);
    bool is_repeted{ false };

    for (int i = 0; i < v.size(); ++i)
    {
        if (v_checked[i] == true)
            continue;
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[i].name == v[j].name)
            {
                is_repeted = true;
                v_checked[j] = true;
            }
        }
        if (is_repeted)
        {
            std::cout << "Attention! The name " << v[i].name << " is repeated!\n";
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
    std::vector<Name_value> names;

    std::cout << "Enter a set of pairs consisting of a name and a value...\n";

    for (; std::cin >> name >> score; )
    {
        if (name == stop_string && score == stop_score)
            break;
        names.push_back(Name_value{ name, score });
    }

    pairs_check(names);
    pairs_print(names);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    pairs();
}