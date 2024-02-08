// Программа, определяющая моду множества положительных чисел

#include <iostream>
#include <stdexcept>
#include <vector>
#include <Windows.h>

double mode_search(const std::vector<int>& v)
// without sort algorithm
// skips checked numbers
// if there is more than one mode => the mode is the arithmetic mean of the several modes
{
    std::vector<double> nums;       // mode vector
    std::vector<bool> v_checked(v.size(), false);        // for checked numbers skip

    int count_defalult{ 0 };      // number repeat counter
    int count1{},
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
            nums.clear();
            nums.push_back(v[i]);
            count1 = count2;
        }
        else if (count1 == count2 && count2 != count_defalult)
            nums.push_back(v[i]);
        count2 = count_defalult;
    }
    if (nums.size() > 1)
    {
        double sum{ 0 };

        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        return sum / nums.size();
    }
    if (nums.size() == 0)
        throw std::runtime_error("Мода неопределена!");
    return nums[0];
}

void mode()
// main mode function
// only works with positive numbers
{
    std::cout << "Введите множество положительных чисел...\n";
    std::vector<int> numbers;

    for (int number{}; std::cin >> number; )
    {
        if (number < 1)
            throw std::runtime_error("Числа должны быть положительными!");
        numbers.push_back(number);
    }

    if (numbers.size() == 0)
        throw std::runtime_error("Vector is empty!");

    std::cout << "Мода множества чисел: " << mode_search(numbers) << '\n';
}

int main()
try {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    mode();
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
}
