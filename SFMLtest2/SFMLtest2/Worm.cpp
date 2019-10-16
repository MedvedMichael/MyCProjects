#include "Worm.h"
#include <iostream>
#include <cmath>
#include "Food.h"



Worm::Worm(int numberOfGamer)
{

	mLength = 5;
	mDirection = DOWN;
	lastDirection = mDirection;
	if (numberOfGamer == 1)
	{
		mX[0] = 5;
		mY[0] = 5;
		
	}
	else if (numberOfGamer == 2)
	{
		mX[0] = WIDTH-5;
		mY[0] = 5;
	}



	for (int i = 1; i < mLength; i++)
	{
		mX[i] = mX[i - 1];
		mY[i] = mY[i - 1] - 1;
		mEveryDirection[i] = mDirection;

	}

	lastX = mX[mLength - 1];
	lastY = mY[mLength - 1];
	lastDirection = mEveryDirection[mLength - 1];

	/*lastX = sizeof(mX) / sizeof(mX[0]);
	lastY = sizeof(mY) / sizeof(mY[0]);*/

	mNumberOfGamer = numberOfGamer;

	
}



Worm::~Worm()
{
}

void Worm::move()
{
	
	//	std::cout << mDirection<<std::endl;
	lastX = mX[mLength - 1];
	lastY = mY[mLength - 1];
	lastDirection = mEveryDirection[mLength - 1];

	for (int i = mLength - 1; i > 0; i--)
	{
		mX[i] = mX[i - 1];
		mY[i] = mY[i - 1];
		mEveryDirection[i] = mEveryDirection[i - 1];
	}

	mEveryDirection[0] = mDirection;
	//std::cout << mY[0] << std::endl;
	if (mDirection == DOWN)
	{
		mY[0] ++;
		if (mY[0] >= HEIGHT)
			mY[0] = 0;
	}
	
	else if (mDirection == LEFT)
	{
		mX[0] --;
		if (mX[0] < 0)
			mX[0] = WIDTH - 1;
	}
	else if (mDirection == UP)
	{
		mY[0] --;
		if (mY[0] < 0)
			mY[0] = HEIGHT - 1;
	}
	else if (mDirection == RIGHT)
	{
		mX[0] ++;
		if (mX[0] > WIDTH)
			mX[0] = 0;
	}



}

void Worm::setDirection(int direction)
{
	mDirection = direction;
}

int Worm::getDirection()
{
	return mDirection;
}

int Worm::getLength()
{
	return mLength;
}

bool Worm::isCollision(Food *food)
{
	if (mX[0] == food->mX && mY[0] == food->mY)
	{
		mX[mLength] = lastX;
		mY[mLength] = lastY;
		mLength++;

		
		return true;
	}
	else
	{
		
		return false;
	}
}

bool Worm::isCollisionEachOther(Worm otherWorm)
{
	for (int i = 0; i < sizeof(otherWorm.mX) / sizeof(otherWorm.mX[0]); i++)
	{
		if (mX[0] == otherWorm.mX[i] && mY[0] == otherWorm.mY[i])
			return true;
	}
	return false;
}

bool Worm::isCollisionItself()
{
	for (int i = 1; i < sizeof(mX) / sizeof(mX[0]); i++)
		if (mX[0] == mX[i] && mY[0] == mY[i])
			return true;
	return false;
}

void Worm::setLength(int length)
{
	mLength = length;
}




