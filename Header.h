#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
using namespace std;

class coins
{	
	float coin_arr[5];
public:
	coins()
	{
		for (int i = 0; i < 5; i++)
		{
			coin_arr[i] = 10;
		}
	}
	void add_coin(float coin);
	void sub_coin(float coin);
};
class FoodItem
{	string foodname;
	float fooditem_price;
	int Quantity;

public :
	friend void menu(FoodItem menu[10]);
	friend int isfound(FoodItem f[10]);
	void output(coins &c);
	 void print();
};

