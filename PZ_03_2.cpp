// PZ_05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "PZ_05.h"

void printLengthsWords(int maxI, std::string &a, int max);
void AppOne();
void AppTwo();
void AppThree(int &a, int &b, int &row);

enum PressKeys
{
	Key_1 = 0x31,
	Key_2 = 0x32,
	Key_3 = 0x33,
	Key_4 = 0x34,
	Key_Q = 0x71
};

int main()
{
	short q = 0;
	bool game = true;

	int a = 32;
	int b = 123;
	int row = 16;

	std::cout << "Please choose a application.\n";
	std::cout << "Press: [1] - for Short and long word in the string.\n";
	std::cout << "       [2] - for The longest word in the string.\n";
	std::cout << "       [3] - for ASCII chart from 32 - 127.\n";
	std::cout << "       [Q] - for Quit from application.\n\n";

	do
	{
		q = _getch();
		switch (q)
		{
			case Key_1:
				AppOne();

				break;

			case Key_2:
				AppTwo();

				break;

			case Key_3:
				AppThree(a, b, row);

				break;

			case Key_Q:
				game = false;
				exit(0);

				break;

			default:
				std::cout << "default" << std::endl;

				break;
		}
	} while (game);

	system("pause");
	return 0;
}

void AppOne()
{
	std::string a = " ";
	std::cout << "Enter your a string (min two a words): ";
	std::getline(std::cin, a);

	int word = 0;
	int min = 0;
	int minI = 0;
	int max = 0;
	int maxI = 0;
	int last = 0;
	int current = 0;
	int counter = 0;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' || i == (a.length() - 1))
		{
			current = i;

			if (last == 0 || i == (a.length() - 1))
			{
				last = current - last;
			}
			else
			{
				last = current - (last + 1);
			}

			word = last;

			if (max == 0 || max < word)
			{
				max = word;
				maxI = i;
			}

			if (min == 0 || min > word)
			{
				min = word;
				minI = i;
			}

			last = i;
		}
	}

	std::cout << "Your MAX word = " << max << " : ";

	printLengthsWords(maxI, a, max);

	std::cout << "\nYour MIN word = " << min << " : ";

	printLengthsWords(minI, a, min);

	std::cout << std::endl << std::endl;
}

void printLengthsWords(int maxI, std::string &a, int max)
{
	if (maxI == (a.length() - 1))
	{
		for (int i = (maxI + 1) - max; i < (maxI + 1); i++)
		{
			std::cout << a[i];
		}
	}
	else
	{
		for (int i = maxI - max; i < maxI; i++)
		{
			std::cout << a[i];
		}
	}
}

void AppTwo()
{
	std::string enteringString = "Hello world at the world";
	std::string enteringWord = "world";

	std::cout << "Enter your a string (min two a words): ";
	std::getline(std::cin, enteringString);

	std::cout << "Enter your a word: ";
	std::getline(std::cin, enteringWord);

	std::cout << "Your string is: " << enteringString << std::endl;
	std::cout << "  Your word is: " << enteringWord << std::endl;

	int counter = 0;
	int charCounterS = 0;
	int charCounterW = 0;
	for (charCounterS = 0; enteringString[charCounterS]; ++charCounterS)
	{
		//std::cout << "string1 " << charCounter << std::endl;
	}

	for (charCounterW = 0; enteringWord[charCounterW]; ++charCounterW)
	{
		//std::cout << "string1 " << charCounter << std::endl;
	}

	for (int charCounter = 0; charCounter <= (charCounterS); charCounter++)
	{
		for (int charCounter2 = 0; enteringString[charCounter + charCounter2] == enteringWord[charCounter2]; charCounter2++)
		{
			if ((charCounter + charCounter2) >= enteringString.length())
			{
				break;
			}
			counter++;
		}
	}

	if (counter == 0)
	{
		std::cout << "Your word is not in your line." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Your the word is repeated [" << counter / enteringWord.length() << "] in the string." << std::endl << std::endl;
	}
}

void AppThree(int &a, int &b, int &row)
{
	for (int i = a - 1; i <= b; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			++i;
			char k = i;
			std::cout << k << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

