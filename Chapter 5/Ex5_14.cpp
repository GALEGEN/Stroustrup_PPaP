// Считывает пары (день недели, значение) из потока ввода. Выводит все значения семи векторов для каждого дня недели.
// Печатает сумму чисел в каждом из векторов. Выводит на печать количество отвергнутых значений. 

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout;
using std::cin;

int what_day(const std::string& word)
{
    std::vector<std::vector<std::string>> days_of_the_week = { { "Monday", "monday", "Mon", "mon" }, 
        { "Tuesday", "tuesday", "Tues", "tues" }, 
        { "Wednesday", "wednesday", "Wed", "wed" }, 
        { "Thursday", "thursday", "Thur", "thur" }, 
        { "Friday", "friday", "Fri", "fri" }, 
        { "Saturday", "saturday", "Sat", "sat" }, 
        { "Sunday", "sunday", "Sun", "sun" } };

    for (int i = 0; i < days_of_the_week.size(); ++i)
    {
        for (int j = 0; j < days_of_the_week[i].size(); ++j)
        {
            if (word == days_of_the_week[i][j]) {
                return i;
            }
        }
    }

    return -1;
}

int day_input(std::vector<std::vector<int>>& v, std::vector<int>& fails)
// vector filling function
// caution: the function changes arguments
{
    std::string word;
    std::string stop{ "|" };
    int number{};
    int day{};
    bool end{ false };

    while (!end && cin.good())
    {
        cin >> word;
        if (word != stop)
        {
            cin >> number;

            day = what_day(word);

            switch (day)
            {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: {
                v[day].push_back(number);
                break;
            }
            case -1: {      // invalid day argument
                fails.push_back(number);
                break;
            }
            default: {
                throw std::runtime_error("Unexpected pairs push_back error!");
                break;
            }
            }
        }
        else end = true;
    }

    return 0;
}

void vector_print(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';
        if (i == v.size() - 1) {
            cout << std::endl;
        }
    }
}

int vector_sum(const std::vector<int>& v)
{
    int sum{};

    for (int x : v) {
        sum += x;
    }
    return sum;
}

void weekDays_print(const std::vector<std::vector<int>>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].size() > 0)
        {
            switch (i)
            {
            case 0: {       // monday
                cout << "Monday: ";
                vector_print(v[i]);
                cout << "Monday sum: " << vector_sum(v[i]) << std::endl;
                break;
            }
            case 1: {       // tuesday
                cout << "Tuesday: ";
                vector_print(v[i]);
                cout << "Tuesday sum: " << vector_sum(v[i]) << std::endl;
                break;
            }
            case 2: {       // wednesday
                cout << "Wednesday: ";
                vector_print(v[i]);
                cout << "Wednesday sum: " << vector_sum(v[i]) << std::endl;
                break;
            }
            case 3: {       // thursday
                cout << "Thursday: ";
                vector_print(v[i]);
                cout << "Thursday sum: " << vector_sum(v[i]) << std::endl;
                break;
            }
            case 4: {       // friday
                cout << "Friday: ";
                vector_print(v[i]);
                cout << "Friday sum: " << vector_sum(v[i]) << std::endl;
                break;
            }
            case 5: {       // saturday
                cout << "Saturday: ";
                vector_print(v[i]);
                cout << "Saturday sum : " << vector_sum(v[i]) << std::endl;
                break;
            }
            case 6: {       // sunday
                cout << "Sunday: ";
                vector_print(v[i]);
                cout << "Sunday sum: " << vector_sum(v[i]) << std::endl;
                break;
            }
            default: {
                throw std::runtime_error("Unexpected print error!");
                break;
            }
            }
        }
    }
}

int day_pairs()
// main function using two-dimencsional vector
{
    int days_in_a_week{ 7 };
    std::vector<std::vector<int>> days(days_in_a_week, std::vector<int>());     // 0 - Monday, 1 - Tuesday, 2 - Wednesday, etc
    std::vector<int> fails;

    cout << "Enter the pairs (day of the week, value)...\nEnter symbol '|' to stop pairs input.\n";

    day_input(days, fails);

    weekDays_print(days);
    
    if (fails.size() > 0)       // print fails values if any
    {
        cout << fails.size() << " fail nums: ";
        vector_print(fails);
    }
    
    return 0;
}

int main()
try {
    day_pairs();
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
    return -1;
}