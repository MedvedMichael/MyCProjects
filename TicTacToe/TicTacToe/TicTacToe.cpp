// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool turn = true;
const int width_height = 3;
char gameBoard[width_height][width_height];

void printBoard()
{
	for (int i = 0; i < width_height; i++)
	{
		for (int j = 0; j < width_height; j++)
		{
			cout << "[" << gameBoard[j][i] << "]";
		}
		cout << endl;
	}
}


int main()
{
	while (true)
	{
		char string[255];
		memset(string, 0, sizeof(string));
		cout << "Turn " << ((turn) ? "X" : "O") << ", please enter input: ";
		cin.getline(string, 255);
		int x = (int)string[0] - '0', y = (int)string[2] - '0';

		if (x < 0 || x>2 || y < 0 || y>2 || gameBoard[x][y] == 'X' || gameBoard[x][y] == 'Y')
		{
			cout << "Wrong input! \nBye, you\'re fuckin\' bitch!" << endl;
			break;
		}
		else
		{
			if (turn) gameBoard[x][y] = 'X';
			else gameBoard[x][y] = 'O';
		}
		turn = !turn;
		printBoard();
	}

	return 0;
}

