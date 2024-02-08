// Программа, ноходящая все простые числа между 1 и 100 через классический метод "Решето Эратосфена".

#include <iostream>
#include <cmath>
#include <vector>
#include <Windows.h>

/*
Псевдокод:
    Вход: натуральное число n
    Выход: все простые числа от 2 до n.

    Пусть A — булевый массив, индексируемый числами от 2 до n, 
    изначально заполненный значениями true.

    для i = 2, 3, 4, ..., пока i^2 ≤ n:
        если A[i] = true:
            для j = i^2, i^2 + i, i^2 + 2i, ..., пока j ≤ n:
                назначить A[j] := false

    возвращаем: все числа i, для которых A[i] = true.
*/

void primePrint(const std::vector<bool>& v)
// выводит число в виде индекса где true
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == true)
        {
            std::cout << i << ' ';
        }
    }
}

std::vector<bool> primeSearch()
// реализация алгоритма Решета Эратосфена по псевдокоду
// проверяется промежуток чисел от 0 до 100 => numbers.size() == 101
{
    int search_limit{ 101 };
    std::vector<bool> numbers(search_limit, true);

    numbers[0] = false;     // 0 == false always for prime algorithm
    numbers[1] = false;     // 1 == false always for prime algorithm

    for (int i = 2; (pow(i, 2) <= numbers.size()); ++i)
    {
        if (numbers[i] == true)
        {
            for (int j = pow(i, 2); j < numbers.size(); j += i)
            {
                numbers[j] = false;
            }
        }
    }
    return numbers;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<bool> answer = primeSearch();

    std::cout << "Простые числа от 1 до 100: \n";
    primePrint(answer);
}
