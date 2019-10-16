#include "Food.h"
#include <cmath>
#include "Worm.h"

Food::Food()
{
	mX = rand() %WIDTH  + 1;
	mY = rand() % HEIGHT + 1;
}


Food::~Food()
{
}

void Food::move(int x, int y)
{
	mX = x;
	mY = y;
}


