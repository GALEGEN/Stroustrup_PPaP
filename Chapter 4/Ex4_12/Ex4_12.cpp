// Аналог программы из предыдущего упражнения, но проводит поиск от 1 до max, где max - задается при запуске.

#include <iostream>
#include <vector>
#include <Windows.h>

bool isVecors_equal(const std::vector<int>& v1, const std::vector<int>& v2)
// поиск различий векторов для первых n значений
// принимает два вектора
{
    bool vectors_equal{ true };
    int searchRange{ 100 };

    for (int i = 0; (i < searchRange && i < v1.size() && i < v2.size()); ++i)
    {
        if (v1[i] != v2[i])
        {
            vectors_equal = false;
            break;
        }
    }
    return vectors_equal;
}

void vectorPrimes_output(const std::vector<int>& v)
// Вывод значений полученного вектора
{
    std::cout << "Полученные значения: ";
    for (int x : v)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

std::vector<int> primesSearch(const std::vector<int>& primes, const int& search_limit)
// проверяет делится ли число на действительные простые числа, не превосходящие данное
// принимает действительный вектор простых чисел в пределах от 1 до max
{
    std::vector<int> prime_numbers;

    for (int number = 2; number <= search_limit; ++number)
    {
        for (int j = 0; j < primes.size(); ++j)
        {
            if (primes[j] == number) {
                prime_numbers.push_back(number);
                break;
            }
            if (number % primes[j] == 0) break;
            if (primes.size() - 1 == j)
                prime_numbers.push_back(number);
        }
    }
    return prime_numbers;
}

void primesOutput()
// вывод найденных простых чисел с сравнением результатов
{
    const std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    int max{};

    std::cout << "Простые числа между 1 и max\nЗадайте интервал поиска простых чисел max: ";
    std::cin >> max;
    std::vector<int> answer = primesSearch(primes, max);

    vectorPrimes_output(answer);

    if (isVecors_equal(answer, primes))
        std::cout << "первая часть векторов совпадает!\n";
    else
        std::cout << "первая часть векторов не совпадает!\n";
    return;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    primesOutput();
}
