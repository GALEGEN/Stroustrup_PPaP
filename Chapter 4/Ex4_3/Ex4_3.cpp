// Прочитать последовательности чисел типа double в вектор. Каждое значение представляет собой расстояние между двумя городами.
// Вычислить общее расстояние. Найти наименьшее и наиболшее расстояние между двумя соседними городами. Найти среднее расстояние
// между двумя соседними городами.

#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите значения расстояний..." << std::endl;
	std::vector<double> distances;
	for (double distance; std::cin >> distance; )
		distances.push_back(distance);

	// вычисление общего расстояния, вывод наибольшего и наименьшего расстояния
	double sum{ 0 };
	constexpr int min_distance{ 0 };
	sort(distances.begin(), distances.end());
	for (double x : distances) sum += x;
	std::cout << "Общее расстояние: " << sum << std::endl;

	std::cout << "Наименьшее расстояние: " << distances[min_distance] << "\t" << "Наибольшее расстояние: "
		<< distances[distances.size() - 1] << std::endl;

	// среднее расстояние (при четном количестве значений вектора берется меньшее среднее)
	std::cout << "Среднее расстояние между двумя соседними городами: ";
	if (distances.size() % 2 != 0)
		std::cout << distances[distances.size() / 2] << std::endl;
	else std::cout << distances[(distances.size() / 2) - 1] << std::endl;
}
