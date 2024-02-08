// Реализация игры "Быки и коровы" для четырех букв, а не цифр.

#include <iostream>
#include <vector>
#include <utility>
#include <limits>
using std::cin;
using std::cout;

bool vector_check(const std::vector<char>& rv)
// check by the ASCII table of chars converted to int
{
    if (rv.size() != 4) {
        return false;
    }

    for (int i = 0; i < rv.size(); ++i)
    {
        //if ((static_cast<int>(rv[i]) < 65 || static_cast<int>(rv[i]) > 90)
        //    && (static_cast<int>(rv[i]) < 97 || static_cast<int>(rv[i]) > 122)) {
        //    return false;
        //}
        if (!isalpha(rv[i])) {       // condition analog
            return false;
        }
        for (int j = i + 1; j < rv.size(); ++j)
        {
            if (rv[i] == rv[j]) {
                return false;
            }
        }
    }

    return true;
}

std::vector<char> get_numbers()
{
    std::vector<char> letters;

    while (true)
    {
        for (char ch; (cin >> ch && ch != '|'); ) {
            letters.push_back(ch);
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // restoring cin flow after a stop '|' sign

        if (!vector_check(letters))
        {
            letters.clear();
            cout << "Wrong set of letters. Repeat...\n";
        }
        else {
            return letters;
        }
    }
}

std::pair<int, int> bc_search(const std::vector<char>& rv1, const std::vector<char>& rv2)
// search for bulls and cows by comparing vectors
{
    int b{};
    int c{};

    for (int i = 0; i < rv1.size(); ++i)
    {
        for (int j = 0; j < rv2.size(); ++j)
        {
            if (rv1[i] == rv2[j])
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

void guessing(const std::vector<char>& rv)
// guessing function
{
    int bulls{};
    int cows{};
    std::vector<char> guesses;

    while (bulls < rv.size())
    {
        bulls = 0;
        cows = 0;
        guesses.clear();

        cout << "Enter the expected four letters...\n";

        guesses = get_numbers();

        std::pair<int, int> p = bc_search(rv, guesses);
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
    std::vector<char> letters;

    cout << "Bulls and Cows Game.\nEnter four different letters(press '|' to stop)...\n";

    letters = get_numbers();

    guessing(letters);

    return 0;
}

int main()
{
    simple_game();
}