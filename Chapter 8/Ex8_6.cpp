// Write two functions that reverse the order of elements in a vector<string>.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// prints a vector of ints to cout
void print(const std::string& rs, const std::vector<std::string>& rv)
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
void vectorSwap(std::vector<std::string>& rv)
{
    if (rv.size() <= 1) {
        throw std::runtime_error("vectorSwap() - vector empty or vector.size() < 2");
    }
    for (int i = 0; i < (rv.size() - 1 - i); i++) {
        std::swap(rv[i], rv[(rv.size() - 1) - i]);
    }
}

void unchangedVector(const std::vector<std::string>& rv)
{
    std::vector<std::string> vector = rv;
    std::string label{ "Result: " };
    std::string label2{ "Original vector: " };

    vectorSwap(vector);
    print(label, vector);
    print(label2, rv);
}

void changedVector(std::vector<std::string>& rv)
{
    std::string label{ "Result: " };

    vectorSwap(rv);
    print(label, rv);
}

int main()
try {
    std::vector<std::string> vector{ "one", "three", "five", "seven", "nine"};
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