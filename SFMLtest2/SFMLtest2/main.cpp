#include <SFML/Graphics.hpp>
#include <iostream>
#include "Worm.h"
#include "Food.h"
#include <random>
#include<Windows.h>


using namespace sf;

int getRandomNumber(int* number, int range)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());
	int newNumber = mersenne() % range;
	if (*number == newNumber)
		return getRandomNumber(number, range);

	else return newNumber;
}

void drawWorm(Worm* worm, Sprite sprite, Sprite headSprite, RenderWindow* window)
{
	headSprite.setPosition(unitLength * (worm->mX[0] + 0.5), unitLength * (worm->mY[0] + 0.5));
	headSprite.setOrigin(unitLength, unitLength);
	headSprite.setRotation(90 * worm->mEveryDirection[0]);
	window->draw(headSprite);
	for (int i = 1; i < worm->getLength(); i++)
	{
		sprite.setPosition(unitLength * (worm->mX[i] + 0.5), unitLength * (worm->mY[i] + 0.5));
		sprite.setOrigin(unitLength, unitLength);
		if (worm->mEveryDirection[i] == RIGHT || worm->mEveryDirection[i] == LEFT)
			sprite.setRotation(90);
		else sprite.setRotation(0);
		window->draw(sprite);
		if (worm->mEveryDirection[i] == RIGHT || worm->mEveryDirection[i] == LEFT)
			sprite.setRotation(90);
	}
}

void setPreferencesForText(Text *text,std::string stringText,Font *font,int textSize,Color textColor,Text::Style textStyle, float posX,float posY )
{

	text->setString(stringText);
	text->setCharacterSize(textSize);
	text->setFont(*font);
	text->setColor(textColor);
	text->setStyle(textStyle);

	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(sf::Vector2f(posX, posY));
}

void setOriginToText(Text *text)
{
	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(sf::Vector2f(text->getPosition().x, text->getPosition().y));
}






int main()
{
	sf::RenderWindow* window = new RenderWindow(sf::VideoMode::getDesktopMode(), "Worm",sf::Style::Fullscreen);

	Text* gameOverText = new Text, * startText = new Text, *restartText = new Text;

	Font* font = new Font;
	font->loadFromFile("C:/Users/Eugene Medvedev/Documents/Visual Studio 2015/Projects/SFMLtest2/SHOWG.ttf");

	/*gameOverText->setString("GAME OVER");
	gameOverText->setCharacterSize(150);
	gameOverText->setFont(*font);
	gameOverText->setColor(Color::Red);
	gameOverText->setStyle(Text::Bold);

	sf::FloatRect textRect = gameOverText->getLocalBounds();
	gameOverText->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	gameOverText->setPosition(sf::Vector2f(wd / 2.0f, ht / 2.0f));
	

	startText->setString("Press any button to start");
	startText->setCharacterSize(150);
	startText->setFont(*font);
	startText->setColor(Color::Red);
	startText->setStyle(Text::Bold);

	textRect = startText->getLocalBounds();
	startText->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	startText->setPosition(sf::Vector2f(wd / 2.0f, ht / 2.0f));*/

	Color redWormColor(243, 89,56);
	Color blueWormColor(0, 162, 232);
	setPreferencesForText(startText, "Press SPACE to play", font, 100,Color::Cyan,Text::Bold, wd / 2.0f, ht / 2.0f);
	setPreferencesForText(gameOverText, "BLUE WORM WON", font, 130, blueWormColor, Text::Bold, wd / 2.0f, ht / 2.0f - 50);
	setPreferencesForText(restartText, "Press SPACE to restart", font, 80, Color::Cyan, Text::Bold, wd / 2.0f, ht / 2.0f + 80);


	Texture* groundTexture = new Texture, * worm1Texture = new Texture, * worm2Texture = new Texture, * foodTexture = new Texture;
	Texture* worm1HeadTexture = new Texture, * worm2HeadTexture = new Texture;
	groundTexture->loadFromFile("C:/Users/Eugene Medvedev/Documents/Visual Studio 2015/Projects/SFMLtest2/layout-classic-arch-88.png");
	worm1Texture->loadFromFile("C:/Users/Eugene Medvedev/Documents/Visual Studio 2015/Projects/SFMLtest2/worm_simple.png");
	worm2Texture->loadFromFile("C:/Users/Eugene Medvedev/Documents/Visual Studio 2015/Projects/SFMLtest2/worm2_simple.png");
	worm1HeadTexture->loadFromFile("C:/Users/Eugene Medvedev/Documents/Visual Studio 2015/Projects/SFMLtest2/worm_head_simple.png");
	worm2HeadTexture->loadFromFile("C:/Users/Eugene Medvedev/Documents/Visual Studio 2015/Projects/SFMLtest2/worm2_head_simple.png");
	foodTexture->loadFromFile("C:/Users/Eugene Medvedev/Documents/Visual Studio 2015/Projects/SFMLtest2/food_simple.png");
	Sprite* groundSprite = new Sprite(*groundTexture);
	Sprite* worm1Sprite = new Sprite(*worm1Texture);
	Sprite* worm2Sprite = new Sprite(*worm2Texture);
	Sprite* worm1HeadSprite = new Sprite(*worm1HeadTexture);
	Sprite* worm2HeadSprite = new Sprite(*worm2HeadTexture);

	Sprite* foodSprite = new Sprite(*foodTexture);
	groundSprite->setScale(0.5, 0.5);
	worm1Sprite->setScale(0.5, 0.5);
	worm2Sprite->setScale(0.5, 0.5);
	worm1HeadSprite->setScale(0.5, 0.5);
	worm2HeadSprite->setScale(0.5, 0.5);
	foodSprite->setScale(0.5, 0.5);

	bool isGameRunning = false;
	bool firstTime = true;
	Worm* pWorm1 = new Worm(1);
	Worm* pWorm2 = new Worm(2);
	Food* pFood = new Food;

	/*Clock clock;
	float timer = 0, delay = 0.1;
	float timerForKeyboard = 0;*/
	float delay = 0.07;

	int rotate = 0;
	int rotate2 = 0;
	while (window->isOpen())
	{

		//float time = clock.getElapsedTime().asSeconds();

		//clock.restart();
		//timer += time;
		//timerForKeyboard += time;

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Escape)
					window->close();
				if (!isGameRunning && event.key.code == Keyboard::Space)
				{
					if(firstTime)firstTime = false;

					isGameRunning = true;
					delete pWorm1;
					delete pWorm2;
					delete pFood;
					pWorm1 = new Worm(1);
					pWorm2 = new Worm(2);
					pFood = new Food;
				}
				if (isGameRunning)
				{
					if (event.key.code == Keyboard::A)
						rotate = -1;

					if (event.key.code == Keyboard::D)
						rotate = 1;

					if (event.key.code == Keyboard::J)
						rotate2 = -1;

					if (event.key.code == Keyboard::L)
						rotate2 = 1;
				}
			}
		}

		window->clear();

		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				groundSprite->setPosition(unitLength * j, unitLength * i);
				window->draw(*groundSprite);
			}
		}

		if (isGameRunning)
		{

			if (rotate == 1) pWorm1->setDirection((pWorm1->getDirection() != 3) ? (pWorm1->getDirection() + 1) : (pWorm1->DOWN));
			else if (rotate == -1) pWorm1->setDirection((pWorm1->getDirection() != 0) ? (pWorm1->getDirection() - 1) : (pWorm1->RIGHT));

			if (rotate2 == 1) pWorm2->setDirection((pWorm2->getDirection() != 3) ? (pWorm2->getDirection() + 1) : (pWorm2->DOWN));
			else if (rotate2 == -1) pWorm2->setDirection((pWorm2->getDirection() != 0) ? (pWorm2->getDirection() - 1) : (pWorm2->RIGHT));

			pWorm1->move();
			pWorm2->move();

			if (pWorm1->isCollision(pFood))
				pFood->move(getRandomNumber(&pFood->mX, WIDTH), getRandomNumber(&pFood->mY, HEIGHT));

			if (pWorm2->isCollision(pFood))
				pFood->move(getRandomNumber(&pFood->mX, WIDTH), getRandomNumber(&pFood->mY, HEIGHT));

			if (pWorm2->isCollisionEachOther(*pWorm1) || pWorm2->isCollisionItself())
			{
				isGameRunning = false;
				gameOverText->setColor(redWormColor);
				gameOverText->setString("RED WORM WON");
				setOriginToText(gameOverText);
			}
			if (pWorm1->isCollisionEachOther(*pWorm2) || pWorm1->isCollisionItself())
			{
				gameOverText->setColor(blueWormColor);
				gameOverText->setString("BLUE WORM WON");
				setOriginToText(gameOverText);
				isGameRunning = false;
			}


			foodSprite->setPosition(pFood->mX * unitLength, pFood->mY * unitLength);
			window->draw(*foodSprite);


			drawWorm(pWorm1, *worm1Sprite, *worm1HeadSprite, window);
			drawWorm(pWorm2, *worm2Sprite, *worm2HeadSprite, window);



			rotate = 0;
			rotate2 = 0;

		}
		if (!isGameRunning)
		{
			/*if (gameOverText->getColor() == Color::Blue)
				drawWorm(pWorm2, *worm2Sprite, *worm2HeadSprite, window);
			else if (gameOverText->getColor() == Color::Red)
				drawWorm(pWorm1, *worm1Sprite, *worm1HeadSprite, window);*/
			if (!firstTime)
			{
				window->draw(*gameOverText);
				window->draw(*restartText);
			}
			else {
				
				window->draw(*startText);
			}
		}
	
		window->display();
		Sleep(delay * 1000);

	}

	return 0;
}