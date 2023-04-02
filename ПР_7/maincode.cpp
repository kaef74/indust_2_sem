#include <iostream>
#include <ctime>
#include "Datchik.h"
#include "item.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int size = 16;
	item* items = new item[size];

	for (int i = 0; i < size; i++)
	{
		items[i].set(rand() % 101, rand() % 101, (rand() % 101 - 50) / 10.0, (rand() % 101 - 50) / 10.0, 0, 100, 100, 0);
	}

	Datchik datchik1(20, 20, 20);
	Datchik datchik2(20, 20, 10);
	Datchik datchik3(50, 50, 25);
	Datchik datchik4(35, 20, 20);

	while (true)
	{
		for (int i = 0; i < size; i++) items[i].update();

		Sleep(1000);

		if (datchik1.cheak(items, size)) cout << "Датчик 1 регистрирует " << datchik1.count(items, size) << " объектов\n";
		else cout << "Датчик 1 не регистрирует движения\n";
		if (datchik2.cheak(items, size)) cout << "Датчик 2 регистрирует " << datchik2.count(items, size) << " объектов\n";
		else cout << "Датчик 2 не регистрирует движения\n";
		if (datchik3.cheak(items, size)) cout << "Датчик 3 регистрирует " << datchik3.count(items, size) << " объектов\n";
		else cout << "Датчик 3 не регистрирует движения\n";
		if (datchik4.cheak(items, size)) cout << "Датчик 4 регистрирует " << datchik4.count(items, size) << " объектов\n";
		else cout << "Датчик 4 не регистрирует движения\n";
		cout << "\n";
	}

	return 0;
}

