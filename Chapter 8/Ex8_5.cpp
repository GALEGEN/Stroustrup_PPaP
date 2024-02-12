// Write two functions that reverse the order of elements in a vector<int>.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// prints a vector of ints to cout
void print(const std::string& rs, const std::vector<int>& rv)
{
    std::cout << rs;
    for (size_t i = 0; i < rv.size(); i++)
    {
        std::cout << rv[i];
        if (i < rv.size() - 1) {
            std::cout << ", ";
        }
        else {
            std::cout << std::endl;
        }
    }
}

// swap vector elements
void vectorSwap(std::vector<int>& rv)
{
    if (rv.size() <= 1) {
        throw std::runtime_error("vectorSwap() - vector empty or vector.size() < 2");
    }
    for (int i = 0; i < (rv.size() - 1 - i); i++) {
        std::swap(rv[i], rv[(rv.size() - 1) - i]);
    }
}

void unchangedVector(const std::vector<int>& rv)
{
    std::vector<int> vector = rv;
    std::string label{ "Result: " };

    vectorSwap(vector);
    print(label, vector);
}

void changedVector(std::vector<int>& rv)
{
    std::string label{ "Result: " };

    vectorSwap(rv);
    print(label, rv);
}

int main()
try {
    std::vector<int> vector{ 1, 3, 5, 7, 9 };
    char answer{};

    std::cout << "What do you want?" << std::endl << "Prodece a new vector with th reversed "
        << "sequence (1), or reverse the elements of its vector (2)?" << std::endl << "Enter 1 "
        << "or 2." << std::endl;
    std::cin >> answer;

    switch (answer)
    {
    case '1': {
        unchangedVector(vector);
        break;
    }
    case '2': {
        changedVector(vector);
        break;
    }
    default:
        throw std::runtime_error("Wrong answer!");
        break;
    }
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