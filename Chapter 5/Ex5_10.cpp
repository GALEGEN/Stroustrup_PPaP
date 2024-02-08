// Программа, считывающая и сохраняющая ряд double значений, а затем вычисляющая сумму первых N чисел.
// Выводит разности между соседними величинами.

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

double getSum(const int& n, const std::vector<double>& v)
// with int check
{
    double sum{};

    if (n > v.size())
        throw std::runtime_error("User asks for a sum of more numbers than there are in the vector!");

    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }
    return sum;
}

void sum_print(const int& n, const std::vector<double>& v, const double& s)
{
    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << ") is " << s << ".\n";
}

void numbers_diff(const std::vector<double>& v)
{
    double diff_result{};
    std::vector<double> v_diff;

    for (int i = 0; i < (v.size() - 1); ++i)
    {
        diff_result = v[i] - v[i + 1];
        v_diff.push_back(diff_result);
    }

    cout << "The difference between neighboring values: ";
    for (int i = 0; i < v_diff.size(); ++i) 
    {
        cout << v_diff[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << '\n';
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

    double sum = getSum(n_sum, numbers);

    sum_print(n_sum, numbers, sum);

    numbers_diff(numbers);
}
catch (std::runtime_error& e)
{
    std::cerr << e.what() << std::endl;
    return -1;
}