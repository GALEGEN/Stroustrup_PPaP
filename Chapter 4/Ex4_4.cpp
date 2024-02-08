// Программа, угадывающая число. Пользователь должен задумать число от 1 до 100, а программа должна задавать вопросы, чтобы 
// выяснить, какое число он задумал. Программа должна уметь идентифицировать с помощью не более чем семи попыток.

#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Задумайте число от 1 до 100." << std::endl;

	char answer{ ' ' };
	int min_guess{ 1 };
	int max_guess{ 100 };
	int cycle_counter{ 0 };
	while (min_guess != max_guess) {
		std::cout << "Задуманное число меньше " << ((min_guess + max_guess) / 2) << '?' << std::endl 
			<< "'y' если число меньше, 'n' если больше." << std::endl;
		std::cout << min_guess << '\t' << max_guess << std::endl;
		std::cin >> answer;
		if (answer == 'y') {
			max_guess = (min_guess + max_guess) / 2;
			++cycle_counter;
		}
		else if (answer == 'n') {
			min_guess = (min_guess + max_guess + 1) / 2;
			++cycle_counter;
		}
		else {
			std::cout << "Введено ошибочное значение ответа!" << std::endl;
		}
	}
	std::cout << "Задуманное число " << min_guess << "! Попыток потрачено: " << cycle_counter << std::endl;
}
