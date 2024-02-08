// Write a function print() that prints a vector of ints to cout.

#include <iostream>
#include <vector>

void print(const std::string& rs, const std::vector<int>& rv)
// prints a vector of ints to cout
{
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

int main()
{
    std::vector<int> vector{ 1, 2, 3, 4, 5 };
    std::string label{ "Test: " };

    print(label, vector);
}