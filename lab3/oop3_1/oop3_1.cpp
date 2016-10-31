// oop3_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"
#include <iostream>

using namespace std;

void PrintMenuAndChooseAction(int &menuChoose)
{
	cout << ("1 - Info.\n");
	cout << ("2 - EngineOn.\n");
	cout << ("3 - EngineOff.\n");
	cout << ("4 - SetGear.\n");
	cout << ("5 - SetSpeed.\n");
	cout << ("6 - Exit.\n");
	cout << ("Choose action: ");
	cin >> menuChoose;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CCar car;
	int gear = 0, speed = 0, menuChoose = 0;
	
	do
	{
		PrintMenuAndChooseAction(menuChoose);
		if (menuChoose == 1)
		{
			cout << "Gear : " << car.GetGear() << "\n";
			cout << "Speed : " << car.GetSpeed() << "\n";
			if (car.IsTurnedOn())
			{
				cout << "Car is turned on.\n";
			}
			else
			{
				cout << "Car is turned off.\n";
			}
			if (car.GetDirection() == 1)
			{
				cout << "Car rides forward.\n";
			}
			else
			{
				if (car.GetDirection() == -1)
				{
					cout << "Car rides backward.\n";
				}
				else
				{
					cout << "Car dont ride.\n";
				}
			}		
		}
		if (menuChoose == 2)
		{
			if (car.TurnOnEngine())
			{
				cout << "Engine is turned on.\n";
			}
			else
			{
				cout << "Engine is already turned on.\n";
			}		
		}
		if (menuChoose == 3)
		{
			if (car.TurnOffEngine())
			{
				cout << "Engine is turned off.\n";
			}
			else
			{
				cout << "Couldnt turn off engine!\n";
			}		
		}
		if (menuChoose == 4)
		{
			cout << "Choose gear : ";
			cin >> gear;
			if (car.SetGear(gear))
			{
				cout << "Switching gear was successful.\n";
			}
			else
			{
				cout << "Impossible to set new gear.\n";
			}	
		}
		if (menuChoose == 5)
		{
			cout << "Choose speed : ";
			cin >> speed;
			if (car.SetSpeed(speed))
			{
				cout << "Switching speed was successful.\n";
			}
			else
			{
				cout << "Impossible to set new speed.\n";
			}	
		}
	} while (menuChoose != 6);
	return 0;
}

