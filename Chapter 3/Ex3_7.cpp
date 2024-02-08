// Программа, предлагающая пользователю ввести три строковых значения, а затем выводит их в порядке возрастания, разделяя запятыми.

#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string str1{ " " };
    std::string str2{ " " };
    std::string str3{ " " };
    std::string first_str{ " " };
    std::string secound_str{ " " };
    std::string third_str{ " " };


    std::cout << "Введите три строковых значения для сортировки..." << std::endl;

    while (std::cin >> str1 >> str2 >> str3)
    {
        if (str1 <= str2 && str1 <= str3)
        {
            first_str = str1;
            if (str2 <= str3)
            {
                secound_str = str2;
                third_str = str3;
            }
            else
            {
                secound_str = str3;
                third_str = str2;
            }
        }
        else if (str2 <= str1 && str2 <= str3)
        {
            first_str = str2;
            if (str1 <= str3)
            {
                secound_str = str1;
                third_str = str3;
            }
            else
            {
                secound_str = str3;
                third_str = str1;
            }
        }
        else
        {
            first_str = str3;
            if (str1 <= str2)
            {
                secound_str = str1;
                third_str = str2;
            }
            else
            {
                secound_str = str2;
                third_str = str1;
            }
        }

        std::cout << "По порядку возрастания: " << first_str << ", " << secound_str << ", " << third_str << "." << std::endl;
    }
}
