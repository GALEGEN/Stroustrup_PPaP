// Программа, считывающая цифры и составляющая из них целые числа.
// Например, число 123 считывается как последовательность символов 1, 2 и 3.
// Программа выводит на экран сообщение "123 - это 1 сотня, 2 десятки и 3
// единицы".

#include <iostream>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;

void printResults(const std::vector<int>& rv_i, const std::vector<std::string>& rv_s)
{
    for (int x : rv_i) {
        cout << x;
    }
    cout << " is ";

    for (size_t i = 0; i < rv_i.size(); ++i)
    {
        cout << rv_i[i] << rv_s[rv_i.size() - i - 1];
        if ((rv_i.size() - 1) != i) {
            cout << "and ";
        }
        else {
            cout << '.';
        }
    }
}

std::vector<int> vectorEntry()
{
    std::vector<int> nums;

    for (char ch; cin >> ch; )
    {
        if (ch < '0' || ch > '9') {     // stop reading after a non-number symbol
            break;
        }
        nums.push_back(ch - '0');
    }

    if (nums.size() == 0) {
        throw std::runtime_error("Empty number vector!");
    }
    return nums;
}

void intoIntegers()
//  main Ex function
{
    std::vector<int> result;
    std::vector<std::string> unit{ " ones", " tens ", " hundred ", " thousand " };

    cout << "Enter a sequence of numbers..." << std::endl
        << "(Any symbol to exit)" << std::endl;

    result = vectorEntry();
    if (result.size() > unit.size()) {
        throw std::runtime_error("More than planned!");
    }

    printResults(result, unit);
}

int main()
try {
    intoIntegers();
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