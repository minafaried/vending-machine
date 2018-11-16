#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Header.h"

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void menu(FoodItem menu[10])
{



	menu[0].foodname = " Bisco_Misr_Chocolate";
	menu[1].foodname = " Samba_Chocolate";
	menu[2].foodname = "Coconut_Chocolate";
	menu[3].foodname = " tea";
	menu[4].foodname = " coffee";
	menu[5].foodname = " Chipsy";
	menu[6].foodname = " orange_juice";
	menu[7].foodname = " apple_juice";
	menu[8].foodname = " guava_juice";
	menu[9].foodname = " Mango_juice";

	menu[0].fooditem_price = 1;
	menu[1].fooditem_price = 2;
	menu[2].fooditem_price = 1.5;
	menu[3].fooditem_price = 2.5;
	menu[4].fooditem_price = 3;
	menu[5].fooditem_price = 2;
	menu[6].fooditem_price = 3;
	menu[7].fooditem_price = 3;
	menu[8].fooditem_price = 3;
	menu[9].fooditem_price = 3;

	for (int i = 0; i<10; i++)
	{
		menu[i].Quantity = 1;
	}

}
void FoodItem::print()
{
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

	if (Quantity == 0)
	{
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout <<  setw(21)<<foodname  << setw(10) << fooditem_price << setw(16)<< Quantity << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
		cout << setw(21) << foodname << setw(10) << fooditem_price << setw(16) << Quantity << endl;
	}
}
int  isfound(FoodItem f[10])

{
	int choose;
	cout << "\n\nenter your choose...... \nif you want to end choose 0 ....\n=>";
	cin >> choose;
	if (choose == 0)
	{
		exit(0);
	}
	if (f[choose - 1].Quantity != 0&&choose<=10)
	{
		return choose-1;
	}

	else
	{
		cout << "\n sorry this Product not founded";
		return isfound(f);
	}
}
void coins::add_coin(float coin)
{

	while (coin != 0)
	{
		if (20 <= coin)
		{
			coin_arr[4]++;
			coin -= 20;
		}
		else if (10 <= coin)
		{
			coin_arr[3]++;
			coin -= 10;
		}
		else if (5 <= coin)
		{
			coin_arr[2]++;
			coin -= 5;
		}
		else if (1 <= coin)
		{
			coin_arr[1]++;
			coin -=1;
		}
		else if (.5 <= coin)
		{
			coin_arr[0]++;
			coin -= .5;
		}
	}
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "the coins in the machine after added coins : \n";
	cout << "1/2 LE		1 LE		5 LE		10 LE		20 LE\n"<<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << coin_arr[i]<< "		 ";
	}
	cout << endl;
}
void coins::sub_coin(float coin)
{
	while (coin != 0)
	{
		if(coin_arr[4]!=0&& coin>=20)
		{ 
			coin_arr[4]--;
			coin -= 20;
		}
		else if(coin_arr[3] != 0&&coin>=10)
		{
			coin_arr[3]--;
			coin -= 10;
		}
		else if (coin_arr[2] != 0 && coin >= 5)
		{
			coin_arr[2]--;
			coin -= 5;
		}
		else if (coin_arr[1] != 0 && coin >= 1)
		{
			coin_arr[1]--;
			coin -= 1;
		}
		else if (coin_arr[0] != 0 && coin >= .5)
		{
			coin_arr[0]--;
			coin -= .5;
		}

	}		
	    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "the coins in the machine afrer return The rest : \n";
		cout << "1/2 LE		1 LE		5 LE		10 LE		20 LE\n" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << coin_arr[i] << "		 ";
		}
		cout << endl;
}
void FoodItem::output(coins &c)
{
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

	cout << "please enter the coins (1/2 , 1 , 5, 10 or 20 )LE....\nif you want to end enter 0....\n=>";
	float coin;
	cin >> coin;
	if (coin == 0)
	{
	  exit(0);
	}
	if (coin != .5 && coin != 1 && coin != 5 && coin != 10 && coin != 20)
	{
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "valid coin.\nthere is " << coin << " LE\n";
		return output(c);
	}


	if (coin == fooditem_price)
	{
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "there is :" << foodname<<endl;
		Quantity-=1;
	    c.add_coin(coin);
	}
	else if (coin > fooditem_price)
	{
		Quantity-=1;
		c.add_coin(coin);
		c.sub_coin(coin - fooditem_price);
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "there is :" << foodname <<" and "<< coin - fooditem_price <<"LE"<< endl;

	}
	else if(coin < fooditem_price)
	{

		int a;
		while (true)
		{
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

			cout << "sorry this coins is < " << fooditem_price << endl;
			cout << "please enter  " << fooditem_price - coin << " LE\n";
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "please enter the coins (1/2 , 1 , 5, 10 or 20 )LE....\nif you want to end enter 0....\n=>";
			cin >> a;
			if (a == 0)
			{
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "there is your coins :" << coin<<endl;
				exit(0);
			}
			if (a != .5 && a != 1 && a != 5 && a != 10 && a != 20)
			{
				while (true)
				{
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "valid coin.\nthere is " << a << " LE\n";
					SetConsoleTextAttribute(h, FOREGROUND_INTENSITY| FOREGROUND_INTENSITY);
					cout << "please enter the coins (1/2 , 1 , 5, 10 or 20 )LE....\nif you want to end enter 0....\n=>";
					cin >> a;
					if (a == .5 || a == 1 || a == 5 || a == 10 || a == 20)
					{
						break;
					}

				}
			}
			coin += a;
			if (coin == fooditem_price)
			{
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "there is :" << foodname << endl;
				Quantity -= 1;
				c.add_coin(coin);
				break;
			}
			else if (coin > fooditem_price)
			{
				Quantity -= 1;
				c.add_coin(coin);
				c.sub_coin(coin - fooditem_price);
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "there is :" << foodname << " and " << coin - fooditem_price << "LE" << endl;
				break;
			}
        }
	}

}