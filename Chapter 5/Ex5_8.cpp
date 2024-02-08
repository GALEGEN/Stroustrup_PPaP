// Программа, считывающая и сохраняющая ряд целочисленных значений, а затем вычисляющая сумму первых N чисел.

/*
Output example:

Please enter the number of values you want to sum:
3
Please enter some integers (press '|' to stop):
12 23 13 24 15 |
The sum of the first 3 numbers ( 12 23 13 ) is 48.
*/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int getSum(const int& n, const std::vector<int>& v)
{
    int sum{};

    if (n > v.size())
        throw std::runtime_error("User asks for a sum of more numbers than there are in the vector!");

    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }
    return sum;
}

void sum_print(const int& n, const std::vector<int>& v, const int& s)
{
    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << ") is " << s << ".\n";
}

int main()
try {
    int n_sum{};
    std::vector<int> numbers;

    cout << "Please enter the number of values you want to sum:\n";
    cin >> n_sum;

    cout << "Please enter some integers (press '|' to stop):\n";
    for (int number; cin >> number; )
        numbers.push_back(number);

    int sum = getSum(n_sum, numbers);

    sum_print(n_sum, numbers, sum);
}
catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return -1;
}