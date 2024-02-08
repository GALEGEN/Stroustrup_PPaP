// Программа, находящая все простые числа между 1 и 100. Все найденные простые числа выводятся на экран. Полученные результаты 
// срвниваются с вектором primes.

#include <iostream>
#include <vector>
#include <Windows.h>

std::vector<int> primesSearch(const std::vector<int>& primes)
// проверяет делится ли число на действительные простые числа, не превосходящие данное
// принимает действительный вектор простых чисел в пределах от 1 до 100
{
    std::vector<int> prime_numbers;
    unsigned int search_limit{ 100 };

    for (int number = 1; number <= search_limit; ++number)
    {
        for (int j = 0; (primes[j] <= number && j < primes.size()); ++j)
        {
            if (primes[j] == number) 
                prime_numbers.push_back(number);
            if (number % primes[j] == 0) break;
        }
    }
    return prime_numbers;
}

bool isVecors_equal(std::vector<int>& vector1, const std::vector<int>& vector2)
// поиск различий векторов
// принимает два вектора
{
    bool vectors_equal{ true };

    if (vector1.size() != vector2.size())
        vectors_equal = false;
    else
    {
        for (int i = 0; i < vector1.size(); ++i)
        {
            if (vector1[i] != vector2[i])
            {
                vectors_equal = false;
                break;
            }
        }
    }
    return vectors_equal;
}

char primesOutput()
// вывод действительных и найденных простых чисел с сравнением результатов
{
    const std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    std::vector<int> answer = primesSearch(primes);

    std::cout << "Простые числа между 1 и 100:\n";
    std::cout << "Действительные простые числа: ";
    for (int x : primes)
    {
        std::cout << x << ' ';
    }
    std::cout << "\nНайденные простые числа: ";
    for (int x : answer)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    if (isVecors_equal(answer, primes))
        std::cout << "Векторы совпадают!\n";
    else 
        std::cout << "Векторы не совпадают!\n";
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    primesOutput();
}
