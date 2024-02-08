// Программа, проверяющая корректность предложений в соответствии с правилами "английской грамматики".
// Для каждого введенного предложения программа должна просто отвечать "Да" или "Нет".
/*
Sentence:
    Noun Verb
    Sentence Conjunction Sentence

Noun:
    Noun
    Article Noun

Conjunction :
    "and"
    "or"
    "but"

Noun :
    "birds"
    "fish"
    "C++"

Verb :
    "rules"
    "fly"
    "swim"

Article :
    "the"
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
using std::cin;
using std::cout;

const char quit = 'q';

const std::string prompt = "> ";
const std::string result = "= ";

bool isConjunction(const std::string& rs)
{
    std::vector<std::string> conjunctions{ "and", "or", "but" };

    for (std::string conjunction : conjunctions)
    {
        if (rs == conjunction)
            return true;
    }
    return false;
}

bool isArticle(const std::string& rs)
// eats "the"
{
    std::string article{ "the" };

    if (rs == article)
        return true;

    return false;
}

bool isNoun(const std::string& rs)
{
    std::vector<std::string> nouns{ "birds", "fish", "C++" };

    for (std::string noun : nouns)
    {
        if (rs == noun)
            return true;
    }
    return false;
}

bool isVerb(const std::string& rs)
{
    std::vector<std::string> verbs{ "rules", "fly", "swim" };

    for (std::string verb : verbs)
    {
        if (rs == verb)
            return true;
    }
    return false;
}

bool sentence()
{
    std::string w1;
    cin >> w1;
    if (isArticle(w1))
        cin >> w1;
    if (!isNoun(w1))
        return false;

    std::string w2;
    cin >> w2;
    if (!isVerb(w2))
        return false;

    std::string w3;
    cin >> w3;
    if (w3 == ".")
        return true;
    if (!isConjunction(w3))
        return false;
    return sentence();
}

void engGrammar()
{
    while (cin)
    {
        std::cout << prompt;
        char ch;
        cin >> ch;
        //cout << "ch: " << ch << std::endl;
        if (ch == quit) return;       // "q" to exit
        cin.putback(ch);
        if (sentence())
        {
            std::cout << result << "Yes!" << '\n';
        }
        else
        {
            std::cout << result << "No!" << '\n';
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
try {
    engGrammar();
}
catch (std::runtime_error& e)
{
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Exception!" << std::endl;
    return 2;
}