// Calcus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		try
		{
		float firstNumber=0, secondNumber=0;
		string symbol="";
		
			cout << "Enter first number: ";
			cin >> firstNumber;
			cout << "Enter second number: ";
			cin >> secondNumber;
		
		cout << "+, -, *, /: ";
		cin >> symbol;
		float result = 0;
		if (symbol == "+")
			result = firstNumber + secondNumber;
		else if (symbol == "-")
			result = firstNumber - secondNumber;
		else if (symbol == "*")
			result = firstNumber * secondNumber;
		else if (symbol == "/")
			result = firstNumber / secondNumber;
		else cout << "Wrong input!";

		cout << "Result is: " << result << endl;
		}
		catch (...) {
			cout << "AAAAAA";
		}
	}
	return 0;
}

