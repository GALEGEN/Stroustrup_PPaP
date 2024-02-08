// Программа, считывающая и сохраняющая ряд целочисленных значений, а затем вычисляющая сумму первых N чисел.
// Выводит сообщение об ошибке, если результат не может быть представлен в виде значения типа int.

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

double getSum(const int& n, const std::vector<double>& v)
// with int check
{
    double sum{};
    int check_type{};

    if (n > v.size())
        throw std::runtime_error("User asks for a sum of more numbers than there are in the vector!");

    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }

    check_type = sum;
    if (sum != check_type)
        throw std::runtime_error("The result cannot be represented as an int!");

    return sum;
}

void sum_print(const int& n, const std::vector<double>& v, const int& s)
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
    std::vector<double> numbers;

    cout << "Please enter the number of values you want to sum:\n";
    cin >> n_sum;

    cout << "Please enter some integers (press '|' to stop):\n";
    for (double number; cin >> number; ) {
        numbers.push_back(number);
    }

    int sum = getSum(n_sum, numbers);

    sum_print(n_sum, numbers, sum);
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
    return -1;
}