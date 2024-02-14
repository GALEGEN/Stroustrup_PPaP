﻿// Create a vector of Fibonacci numbers and print them using the function from exercise 2.

#include <iostream>
#include <vector>
#include <stdexcept>

void print(const std::string& rs, const std::vector<int>& rv)
// prints a vector of ints to cout
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

void fibonacci(const int& rx, const int& ry, std::vector<int>& rv, const int& rn)
// int rx and ry are a starting sequence
// rv is an empty vector for sequence generation
// rn is the number of elements to put into rv
try {
    if (!rv.empty()) {
        throw std::runtime_error("fibonacci() - vector is not empty!");
    }

    if (rn > 0)     // add rx and ry to empty vector
    {
        rv.push_back(rx);
        if (rn > 1) {
            rv.push_back(ry);
        }
    }
    for ( ; rv.size() < rn; ) {
        rv.push_back(rv[rv.size() - 2] + rv.back());
    }
}
catch (std::exception& e)
{
    std::cerr << "Error: " << e.what() << std::endl;
    return;
}

int main()
{
    std::vector<int> v;
    int x{}, y{}, n{};
    std::string label{ "Result: " };

    std::cout << "Enter x y n..." << std::endl;
    std::cin >> x >> y >> n;

    fibonacci(x, y, v, n);
    print(label, v);
}