// Программа, вычисляющая начальный отрезок последовательности Фибоначчи.
// Поиск наибольшего числа Фибоначчи, которое можно записать в переменную типа int.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
using std::cin;
using std::cout;

std::vector<int> fib_calculate(const int& n)
{
    unsigned int sum{};
    std::vector<int> fib_v{ 1, 1 };

    for (unsigned int i = 0; fib_v.size() < n; ++i)
    {
        sum = fib_v[i] + fib_v[i + 1];

        if (sum > std::numeric_limits<int>::max())
        {
            cout << "Integer out of range!\nMax number of elements of the Fibonacci sequence for int: "
                << fib_v.size() << '\n';
            return fib_v;
        }

        fib_v.push_back(sum);
    }

    return fib_v;
}

void fib_print(const int& n, const std::vector<int>& v)
{
    cout << "Fibonacci sequence of " << n << " numbers: ";
    for (int x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int fibonacci()
// Fibonacci main function
try {
    int n_fib{};
    std::vector<int> fib_nums;

    cout << "Enter N elements of the initial segment...\n";
    cin >> n_fib;
    if (n_fib <= 0)
        throw std::runtime_error("A positive number is required!");

    std::vector<int> fib_numbers = fib_calculate(n_fib);

    fib_print(n_fib, fib_numbers);

    return 0;
}
catch (std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
}

int main()
{
    fibonacci();
}