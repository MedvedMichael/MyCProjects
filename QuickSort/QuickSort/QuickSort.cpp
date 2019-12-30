// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



void moveToHomeOfArray(int *arr, int arrLength, int index)
{

	int number = *(arr + index);
	if (index != 0)
	{
		for (int i = index - 1; i >= 0; i--)
			*(arr + i + 1) = *(arr + i);
		*arr = number;
	}
}

void moveToEndOfArray(int *arr, int arrLength, int index)
{
	int number = *(arr + index);
	if (index != arrLength - 1)
	{
		for (int i = index; i < arrLength - 1; i++)
			*(arr + i) = *(arr + 1 + i);

		*(arr + arrLength - 1) = number;
	}

}


void sort(int *arr, int arrLength)
{
	float num = 0;
	for (int i = 0; i < arrLength; i++)
		num += *(arr + i);
	num /= arrLength;

	float delta = abs((*arr) - num);
	int indexOfCenterNumber = 0;
	for (int i = 0; i < arrLength; i++)
		if (abs(*(arr + i) - num) < delta)
		{
			delta = abs(arr[i] - num);
			indexOfCenterNumber = i;
		}

	int centerNumber = *(arr + indexOfCenterNumber);

	cout << centerNumber << endl;

	for (int i = 0; i < arrLength; i++)
	{
		if (*(arr + i) < centerNumber && i > indexOfCenterNumber)
		{
			moveToHomeOfArray(arr, arrLength, i);
			indexOfCenterNumber++;
		}
		else if (*(arr + i) > centerNumber && i < indexOfCenterNumber)
		{
			moveToEndOfArray(arr, arrLength, i);
			indexOfCenterNumber--;
			i--;
		}
		for (int i = 0; i < arrLength; i++)
			cout << *(arr + i) << " ";
		cout << endl;
	}

	if (arrLength >= 3)
	{
		sort(arr, indexOfCenterNumber + 1);
		sort(arr + indexOfCenterNumber + 1, arrLength - indexOfCenterNumber - 1);
	}

}

int main()
{
	int mArr[25];
	for (int i = 0; i < sizeof(mArr) / 4; i++)
		mArr[i] = rand() % 100 + 1;

	int *pointerToArray = mArr;
	for (int i = 0; i < sizeof(mArr) / 4; i++)
		cout << mArr[i] << " ";
	cout << endl;

	sort(mArr, sizeof(mArr) / 4);
	for (int i = 0; i < sizeof(mArr) / 4; i++)
		cout << mArr[i] << " ";
	cout << endl;

	return 0;
}





