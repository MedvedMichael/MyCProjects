#pragma once
#include "Food.h"
#include <SFML/Graphics.hpp>

const unsigned int MAX_LENGTH = 500;
const unsigned int DOWN = 0, LEFT = 1, UP = 2, RIGHT = 3;
const unsigned int wd = sf::VideoMode::getDesktopMode().width, ht = sf::VideoMode::getDesktopMode().height, unitLength = 25;
const unsigned int WIDTH = wd / unitLength, HEIGHT = ht / unitLength;
class Worm
{
public:
	Worm(int numberOfGamer);
	~Worm();
	void move();
	int mX[MAX_LENGTH], mY[MAX_LENGTH];
	unsigned int mEveryDirection[MAX_LENGTH];
	void setDirection(int direction);
	int getDirection();
	int getLength();
	bool isCollision(Food *food);
	bool isCollisionEachOther(Worm otherWorm);
	bool isCollisionItself();
	void setLength(int length);
	const unsigned int DOWN = 0, LEFT = 1, UP = 2, RIGHT = 3;
	
private:
	bool addLength=false;
	int lastX, lastY,lastDirection;
	
	int mNumberOfGamer, mDirection;
	int mLength;
};

