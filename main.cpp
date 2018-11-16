#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Header.h"

using namespace std;
HANDLE X = GetStdHandle(STD_OUTPUT_HANDLE);
void print(FoodItem f[10])
{
	SetConsoleTextAttribute(X, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
	cout << "         food item             " << "price           " << "Quantity" << endl << endl;

	for (int i = 0; i < 10; i++)
	{ 
		cout <<setw(2)<< i+1 << " -";
		f[i].print();
	}
}

int main()
{
	FoodItem food[10];
	coins coin;
	menu(food);
	while (true)
	{
	print(food);
	int choose = isfound(food);
	food[choose].output(coin);
	}

	return 0;
}