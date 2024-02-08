// Программа, принимающая на вход число n и находящая первые n простых чисел

#include <iostream>
#include <vector>
#include <Windows.h>

void primePrint(const std::vector<int>& v)
// выводит полученный вектор простых чисел
{
    for (int x : v)
    {
        std::cout << x << ' ';
    }
}

std::vector<int> primeSearch(const int& required_primes)
// алгоритм поиска простых чисел
// первым простым числом является 2, с него идет отчет
{
    std::vector<int> primes;
    int prime_begin{ 2 };

    if (primes.size() == 0)
        primes.push_back(prime_begin);

    for (int i = prime_begin + 1; primes.size() < required_primes; ++i)
    {
        for (int j = 0; j < primes.size(); ++j)
        {
            if (i % primes[j] == 0)
                break;
            if (primes.size() - 1 == j)
                primes.push_back(i);
        }
    }
    return primes;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n_primes{};

    std::cout << "Поиск n простых чисел\nЗадайте необходимое количество простых чисел: ";
    std::cin >> n_primes;

    std::vector<int> answer = primeSearch(n_primes);

    std::cout << "Получено " << n_primes << " простых чисел: \n";
    primePrint(answer);
}
