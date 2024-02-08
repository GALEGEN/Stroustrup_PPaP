// Реализация игры "Быки и коровы".

#include <iostream>
#include <vector>
#include <utility>
#include <limits>
using std::cin;
using std::cout;

bool vector_check(const std::vector<int>& v)
{
    if (v.size() != 4) {
        return false;
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] < 0 || v[i] > 9) {
            return false;
        }
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[i] == v[j]) {
                return false;
            }
        }
    }

    return true;
}

std::vector<int> get_numbers()
{
    std::vector<int> numbers;

    while (true)
    {        
        for (int number; cin >> number; ) {
            numbers.push_back(number);
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');      // restoring cin flow after a stop '|' sign

        if (!vector_check(numbers))
        {
            numbers.clear();
            cout << "Wrong set of numbers. Repeat...\n";
        }
        else {
            return numbers;
        }
    }
}

std::pair<int, int> bc_search(const std::vector<int>& v1, const std::vector<int>& v2)
// search for bulls and cows by comparing vectors
{
    int b{};
    int c{};

    for (int i = 0; i < v1.size(); ++i)
    {
        for (int j = 0; j < v2.size(); ++j)
        {
            if (v1[i] == v2[j])
            {
                if (i == j) {
                    ++b;
                }
                else {
                    ++c;
                }
            }
        }
    }

    return std::make_pair(b, c);
}

void guessing(const std::vector<int>& v)
// guessing function
{
    int bulls{};
    int cows{};
    std::vector<int> guesses;

    while (bulls < v.size())
    {
        bulls = 0;
        cows = 0;
        guesses.clear();

        cout << "Enter the expected four numbers...\n";

        guesses = get_numbers();

        std::pair<int, int> p = bc_search(v, guesses);
        bulls = p.first;
        cows = p.second;

        cout << "Bulls: " << bulls << "; Cows: " << cows << ".\n";
    }
    cout << "You guessed it!\n";
}

int simple_game()
// main game function
// creates a vector for the game
{
    std::vector<int> numbers;

    cout << "Bulls and Cows Game.\nEnter four different numbers on the range from 0 to 9 (press '|' to stop)...\n";

    numbers = get_numbers();

    guessing(numbers);

    return 0;
}

int main()
{
    simple_game();
}