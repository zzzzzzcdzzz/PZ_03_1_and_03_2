// PZ_04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cmath>
#include "PZ_04.h"


int main()
{
	short q = 0;
	bool game = true;

	std::cout << "Please choose a application.\n";
	std::cout << "Press: [1] - Equal numbers.\n";
	std::cout << "       [2] - Numbers.\n";
	std::cout << "       [3] - Discriminant.\n";
	std::cout << "       [Q] - for Quit from application.\n\n";

	do
	{
		q = _getch();
		switch (q)
		{
			case 0x31:
				AppOne();

				break;

			case 0x32:
				AppTwo();

				break;

			case 0x33:
				AppThree();

				break;

			case 0x71:
				game = false;
				exit(0);

				break;
		}
	} while (game);

    return 0;
}

void AppThree()
{
	double a = 0;
	double b = 0;
	double c = 0;
	double D = 0;

	do
	{
		std::cout << "Enter value for a, b, c (a value > 0): ";
		std::cin >> a >> b >> c;
	} while (a <= 0 || b <= 0 || c <= 0);

	D = (b * b) - (4 * a * c);
	std::cout << "Discriminant equal " << D << std::endl;

	if (D >= 0)
	{
		double x1 = (-1 * b + std::sqrt(D)) / (2 * a);
		double x2 = (-1 * b - sqrt(D)) / (2 * a);
		std::cout << "root x1 = " << x1 << std::endl;
		std::cout << "root x2 = " << x2 << std::endl;
	}
	else
	{
		std::cout << "Discriminant < 0" << std::endl;
	}

	std::cout << std::endl;
}

void AppTwo()
{
	int Numbers = 0;

	std::cout << "Enter number > \"0\" but < \"100000\": ";
	std::cin >> Numbers;

	if (Numbers < 0)
	{
		Numbers *= -1;
	}

	if (Numbers < 100000)
	{
		int counter = 0;
		int N = Numbers;

		while (N)
		{
			N /= 10;
			counter++;
		}

		for (int i = pow(10, counter - 1); i > 0; i /= 10)
		{
			std::cout << Numbers / i << std::endl;
			Numbers = Numbers % i;
		}
	}
	else
	{
		std::cout << Numbers << " >= 100000" << std::endl;
	}

	std::cout << std::endl;
}

void AppOne()
{
	int Number1 = 0;
	int Number2 = 0;
	int Number3 = 0;

	std::cout << "Enter 3 munbers: ";
	std::cin >> Number1 >> Number2 >> Number3;

	std::cout << "before:" << std::endl;
	std::cout << "Number1 " << Number1 << std::endl;
	std::cout << "Number2 " << Number2 << std::endl;
	std::cout << "Number3 " << Number3 << std::endl;

	if (Number1 == Number2 || Number1 == Number3 || Number2 == Number3)
	{
		Number1 += 5;
		Number2 += 5;
		Number3 += 5;

		std::cout << "\nafter:" << std::endl;
		std::cout << "Number1 " << Number1 << std::endl;
		std::cout << "Number2 " << Number2 << std::endl;
		std::cout << "Number3 " << Number3 << std::endl;
	}
	else
	{
		std::cout << "Numbers is unequal" << std::endl;
	}

	std::cout << std::endl;
}

