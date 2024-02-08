// Реализация игры "Быки и коровы".
// Вариант, в котором игрок може тиграть постоянно и в каждой новой игре генерируются новые четыре цифры.

#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <limits>
using std::cin;
using std::cout;

// from std_lib_facilities.h using this part:

inline std::default_random_engine& get_rand()
{
    static std::default_random_engine ran;	// note: not thread_local
    return ran;
};

inline void seed_randint(int s) { get_rand().seed(s); }

inline int randint(int min, int max) { return std::uniform_int_distribution<>{min, max}(get_rand()); }

inline int randint(int max) { return randint(0, max); }

// ---------------------------------------------------------------------------------------------------

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

std::vector<int> random_numbers()
// random non-repeating numbers generation
{
    std::vector<int> random_num;
    int require_num{ 4 };       // numbers needed
    int generated{};
    bool is_repeated{ false };

    for (int i = 0; random_num.size() < require_num; ++i)
    {
        generated = randint(9);

        for (int x : random_num)
        {
            if (x == generated) {
                is_repeated = true;
            }
        }

        if (!is_repeated) {
            random_num.push_back(generated);
        }
        is_repeated = false;
    }

    /*cout << "Generated numbers: ";        // print correct answer
    for (int j = 0; j < random_num.size(); ++j)
    {
        cout << random_num[j] << ' ';
        if (j == random_num.size() - 1) {
            cout << std::endl;
        }
    }*/

    return random_num;
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

void simple_game()
// creates a vector for the game and starts guessing
{
    std::vector<int> numbers;
    int n{};

    cout << "Enter any number for randomization:\n";        // seed set
    cin >> n;
    seed_randint(n);

    numbers = random_numbers();

    cout << "Enter four different numbers on the range from 0 to 9 (press '|' to stop)...\n";

    guessing(numbers);
}

int game_start()
// main game function
{
    const char positive = 'y';
    const char negative = 'n';
    char answer{ ' ' };

    cout << "Bulls and Cows Game.\n";

    while (true)
    {
        cout << "Play the game? (y/n)\n";
        cin >> answer;

        switch (answer)
        {
        case positive: 
        {
            simple_game();
            break;
        }
        case negative:
        {
            return 0;
            break;
        }
        default:
        {
            cout << "Incorrect answer!\n";
            break;
        }
        }
    }
}

int main()
{
    game_start();
}