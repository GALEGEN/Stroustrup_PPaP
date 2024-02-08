// Определение медианы последовательности как "число, относительно которого ровно половина элементов меньше, а другая 
// половина - больше" для четного и нечетного количества элементов в векторе.

#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

// Вычисляем медиану значений температур
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите значения температур..." << std::endl;
	std::vector<double> temps;
	for (double temp; std::cin >> temp; )
		temps.push_back(temp);

	// Вычисление медианы температуры:
	sort(temps.begin(), temps.end());
	std::cout << temps.size() << std::endl;
	std::cout << "Медианная температура: ";
	if (temps.size() % 2 != 0)
		std::cout << temps[temps.size() / 2] << std::endl;
	else std::cout << (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2 << std::endl;
}
