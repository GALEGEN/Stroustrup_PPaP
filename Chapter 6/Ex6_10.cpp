// Программа, запрашивающая у пользователя два числа и что для них необходимо вычислить
// (количество перестановок или сочетаний), а также выводящую требуемый результат на экране.

/*
    Attention: unsigned long long used for factorial calculation supports only numbers under 21!
    Factorial calculation of numbers like 21 and higher will lead to incorrect results.

    To solve this problem we can use double instead ulong long, but result will be approximated.
*/

#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;

unsigned long long prodTree(int l, const int& ri)
{
    if (l > ri) {
        return 1;
    }
    if (l == ri) {
        return l;
    }
    if (ri - l == 1) {
        return (unsigned long long)l * ri;
    }
    int m = (l + ri) / 2;
    return prodTree(l, m) * prodTree(m + 1, ri);
}

unsigned long long factTree(const int& ri)
//  tree calculation
{
    if (ri < 0) {
        return 0;
    }
    if (ri == 0) {
        return 1;
    }
    if (ri == 1 || ri == 2) {
        return ri;
    }
    return prodTree(2, ri);
}

unsigned long long permutation(const int& ri_l, const int& ri_r)
{
    unsigned long long result = factTree(ri_l) / factTree(ri_l - ri_r);
    return result;
}

unsigned long long combination(const int& ri_l, const int& ri_r)
{
    unsigned long long result = permutation(ri_l, ri_r) / factTree(ri_r);
    return result;
}

void pcCalculation()
//  main permutations and combinations calculation function
{
    int a{}, b{};
    char ch{};

    cout << "Enter two numbers and what are you want to calculate (p or c)" << std::endl
        << "where p - permutations, c - combinations." << std::endl
        << "Input example: 60 3 p" << std::endl;

    cin >> a >> b >> ch;

    cout << "Result: ";
    switch (ch)
    {
    case 'p':
    {
        cout << permutation(a, b);
        break;
    }
    case 'c':
    {
        cout << combination(a, b);
        break;
    }
    default: {
        throw std::runtime_error("Wrong calculation mode!");
    }
    }
}

int main()
try {
    pcCalculation();
}
catch (std::runtime_error& e)
{
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Unexpected error!" << std::endl;
    return 2;
}