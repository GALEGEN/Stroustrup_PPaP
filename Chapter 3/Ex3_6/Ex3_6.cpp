// Программа, предлагающая пользователю ввести три целых числа, а затем выводи их в порядке возрастания, разделяя запятыми.

#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    int val1{ 0 };
    int val2{ 0 };
    int val3{ 0 };
    int first_num{ 0 };
    int secound_num{ 0 };
    int third_num{ 0 };


    std::cout << "Введите три целых числа для сортировки..." << std::endl;

    while (std::cin >> val1 >> val2 >> val3)
    {
        if (val1 <= val2 && val1 <= val3)
        {
            first_num = val1;
            if (val2 <= val3) 
            {
                secound_num = val2;
                third_num = val3;
            }
            else
            {
                secound_num = val3;
                third_num = val2;
            }
        }
        else if (val2 <= val1 && val2 <= val3)
        {
            first_num = val2;
            if (val1 <= val3)
            {
                secound_num = val1;
                third_num = val3;
            }
            else
            {
                secound_num = val3;
                third_num = val1;
            }
        }
        else
        {
            first_num = val3;
            if (val1 <= val2)
            {
                secound_num = val1;
                third_num = val2;
            }
            else
            {
                secound_num = val2;
                third_num = val1;
            }
        }

        std::cout << "По порядку возрастания: " << first_num << ", " << secound_num << ", " << third_num << "." << std::endl;
    }
}
