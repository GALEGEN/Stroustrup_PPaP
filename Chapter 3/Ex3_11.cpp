// Предлагает пользователю ввести определенное количество 1-, 5-, 10-, 25-, 50-центовых и долларовых монет. 

#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int one_cent{ 0 };
    int five_cent{ 0 };
    int ten_cent{ 0 };
    int twfive_cent{ 0 };
    int fifty_cent{ 0 };
    int total_cent{ 0 };
    int conv_dollar{ 0 };
    int conv_cent{ 0 };

    std::cout << "Введите количество монет каждого достоинства..." << std::endl;

    std::cout << "Сколько у вас одноцентовых монет?" << std::endl;
    std::cin >> one_cent;
    std::cout << "Сколько у вас пятицентовых монет?" << std::endl;
    std::cin >> five_cent;
    std::cout << "Сколько у вас десятицентовых монет?" << std::endl;
    std::cin >> ten_cent;
    std::cout << "Сколько у вас двадцатипятицентовых монет?" << std::endl;
    std::cin >> twfive_cent;
    std::cout << "Сколько у вас пятидесятицентовых монет?" << std::endl;
    std::cin >> fifty_cent;

    total_cent = one_cent + (five_cent * 5) + (ten_cent * 10) + (twfive_cent * 25) + (fifty_cent * 50);

    std::cout << "У вас " << one_cent;
    if (one_cent == 1) {
        std::cout << " одноцентовая монета." << std::endl;
    }
    else {
        std::cout << " одноцентовых монет." << std::endl;
    }

    std::cout << "У вас " << five_cent;
    if (five_cent == 1) {
        std::cout << " пятицентовая монета." << std::endl;
    }
    else {
        std::cout << " пятицентовых монет." << std::endl;
    }

    std::cout << "У вас " << ten_cent;
    if (ten_cent == 1) {
        std::cout << " десятицентовая монета." << std::endl;
    }
    else {
        std::cout << " десятицентовых монет." << std::endl;
    }

    std::cout << "У вас " << twfive_cent;
    if (twfive_cent == 1) {
        std::cout << " двадцатипятицентовая монета." << std::endl;
    }
    else {
        std::cout << " двадцатипятицентовых монет." << std::endl;
    }

    std::cout << "У вас " << fifty_cent;
    if (fifty_cent == 1) {
        std::cout << " пятидесятицентовая монета." << std::endl;
    }
    else {
        std::cout << " пятидесятицентовых монет." << std::endl;
    }

    std::cout << "Общая стоимость ваших монет равна ";
    if (total_cent == 1) {
        std::cout << total_cent << " центу." << std::endl;
    }
    else if (total_cent < 100) {
        std::cout << total_cent << " цента." << std::endl;
    }
    else {
        conv_dollar = total_cent / 100;
        conv_cent = total_cent % 100;

        if (conv_dollar == 1) {
            std::cout << conv_dollar << " доллар ";
        }
        else {
            std::cout << conv_dollar << " долларов ";
        }
        if (conv_cent == 1) {
            std::cout << conv_cent << " цент." << std::endl;
        }
        else {
            std::cout << conv_cent << " цента." << std::endl;
        }
    }
}
