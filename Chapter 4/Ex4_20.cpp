// Программа, выводящая не печать соответствующее количество баллов запрошенного имени/пользователя или сообщение "Имя не найдено". 
// Повторение введеного имени вызывает предупреждение.
// NoName 0 = конец ввода пар

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
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

std::pair<std::vector<std::string>, std::vector<int>> pairs()
// main pair construction function
// input a set of name and value pairs
{
    std::string name;
    std::string stop_string{ "NoName" };        // for output stop
    int score{};
    int stop_score{ 0 };        // for output stop
    std::vector<std::string> names;
    std::vector<int> scores;

    std::cout << "Введите набор пар, состоящих из имени и значения...\n";

    for (; (std::cin >> name >> score && (name != stop_string && score != stop_score)); )
    {
        names.push_back(name);
        scores.push_back(score);
    }

    pairs_check(names);
    pairs_print(names, scores);

    return std::make_pair(names, scores);
}

void score_search(const std::vector<std::string>& v_s, const std::vector<int>& v_i)
// enter 'stop' to end the search cycle
{
    std::string stop = "stop";
    bool not_found{ true };

    std::cout << "Введите имя для поиска соответствующего количества баллов...\n";

    for (std::string s; (std::cin >> s && s != stop); )
    {
        for (int i = 0; i < v_s.size(); ++i)
        {
            if (s == v_s[i])
            {
                not_found = false;
                std::cout << "Найденному имени " << s << " соответствует количество баллов: " << v_i[i] << '\n';
            }
        }
        if (not_found)
            std::cout << "Имя не найдено\n";
        not_found = true;       // reset
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::pair<std::vector<std::string>, std::vector<int>> p = pairs();

    std::vector<std::string> names = p.first;
    std::vector<int> scores = p.second;

    score_search(names, scores);
}
