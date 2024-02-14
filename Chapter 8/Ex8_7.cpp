// Read names into a vector<string> name, then prompt the user for the ages of the people named
// and store the ages in a vector<double> age. Then print out the five (name[i],age[i]) pairs.
// Sort the names (sort(name.begin(),name.end())) and print out the (name[i],age[i]) pairs.

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

// print sequence like (name[i],age[i])
void solutionPrint(const std::vector<std::string>& rvStr, const std::vector<double>& rvD)
{
    if (rvStr.size() != rvD.size()) {
        throw std::runtime_error("The size of the vectors are not equal.");
    }
    for (size_t i = 0; i < rvStr.size(); i++)
    {
        std::cout << '(' << rvStr[i] << ", " << rvD[i] << ") ";
        if (i == rvStr.size() - 1) {
            std::cout << std::endl;
        }
    }
}

int findIndex(const std::string& str, const std::vector<std::string>& rv)
{
    for (size_t i = 0; i < rv.size(); i++)
    {
        if (str == rv[i]) {
            return i;
        }
    }
    throw std::runtime_error("No match found.");
}

std::vector<std::string> getNames()
{
    std::vector<std::string> v;
    char ch;

    std::cout << "Enter names..." << std::endl;
    while (true)        // skips all chars except alphabetic characters and newline (\n) char
    {
        std::cin.get(ch);
        if (isalpha(ch))
        {
            std::cin.unget();
            std::string s;
            std::cin >> s;
            v.push_back(s);
        }
        if (ch == '\n') {
            break;
        }
    }
    return v;
}

std::vector<double> getAges(const std::vector<std::string>& rv)
{
    std::vector<double> v;
    int i{};

    for (std::string str : rv) {
        std::cout << "Enter the age for the name " << str << ": ";
        std::cin >> i;
        v.push_back(i);
    }
    return v;
}

int solution()
try {
    std::vector<std::string> name = getNames();
    std::vector<double> age = getAges(name);
    std::vector<std::string> nameCopy = name;       // make name copy
    std::vector<double> ageCopy;

    std::sort(nameCopy.begin(), nameCopy.end());        // sort name copy
    for (size_t i = 0; i < nameCopy.size(); i++) {      // restore age data
        ageCopy.push_back(age[findIndex(nameCopy[i], name)]);
    }

    std::cout << "Unsorted: ";
    solutionPrint(name, age);

    std::cout << "Sorted: ";
    solutionPrint(nameCopy, ageCopy);

    return 0;
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

int main()
{
    solution();
}