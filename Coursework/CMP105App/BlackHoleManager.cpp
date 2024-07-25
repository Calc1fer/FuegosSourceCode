#include "BlackHoleManager.h"
#include <iostream>
#include <algorithm>

//constructor
BlackHoleManager::BlackHoleManager()
{
	srand(static_cast<unsigned int>(time(0)));	//seed the random number generator

	if (!texture.loadFromFile("gfx/BlackHole.png"))
	{
		std::cout << "could not load blackHole sprite\n";
	}
	else
	{
		texture.loadFromFile("gfx/BlackHole.png");
	}

	for (size_t i = 0; i < numObstacles; i++)
	{
		obstacle.push_back(BlackHole());
		obstacle[i].setAlive(false);
		obstacle[i].setTexture(&texture);
		obstacle[i].setSize(sf::Vector2f(100, 80));
	}

	//set the x,y coordinates for each spawnpoint
	spawnPoint1 = sf::Vector2f(155, 20);
	spawnPoint2 = sf::Vector2f(2700, 1515);
	spawnPoint3 = sf::Vector2f(1500, 915);
	spawnPoint4 = sf::Vector2f(640, 815);
	spawnPoint5 = sf::Vector2f(1400, 1195);
	spawnPoint6 = sf::Vector2f(2800, 715);
	speedX = 150;
	speedY = 0;
}

//deconstructor
BlackHoleManager::~BlackHoleManager()
{

}

//spawning a new obstacle
void BlackHoleManager::spawn()
{
	//assign spawnpoint to each obstacle in array
	for (size_t i = 0; i < obstacle.size(); i++)
	{
		switch (i)
		{
		case 0:
			location = spawnPoint1;
			vel = sf::Vector2f(0, 0);
			break;
		case 1:
			location = spawnPoint2;
			vel = sf::Vector2f(-speedX, speedY);
			break;
		case 2:
			location = spawnPoint3;
			vel = sf::Vector2f(speedX, speedY);
			break;
		case 3:
			location = spawnPoint4;
			vel = sf::Vector2f(-speedX, speedY);
			break;
		case 4:
			location = spawnPoint5;
			vel = sf::Vector2f(speedX, speedY);
			break;
		case 5:
			location = spawnPoint6;
			break;
		}

		if (!obstacle[i].isAlive())
		{
			obstacle[i].setAlive(true);
			obstacle[i].setVelocity(vel);
			obstacle[i].setPosition(location);
			obstacle[i].setCollisionBox(sf::FloatRect(0, 0, 100, 80));
			return;
		}
	}
}

//updating position and other properties of obstacle
void BlackHoleManager::update(float dt)
{
	for (size_t i = 0; i < obstacle.size(); i++)
	{
		if (obstacle[i].isAlive())
		{
			obstacle[i].update(dt);
		}
	}
	deathCheck();
}

//check if alive or not
void BlackHoleManager::deathCheck()
{
	for (size_t i = 0; i < obstacle.size(); i++)
	{
		if (obstacle[i].isAlive())
		{
			if (obstacle[i].getPosition().x <= 0)
			{
				obstacle[i].setVelocity(speedX, speedY);
			}
		}
		
		spawn();
	}
}

//return ref of each obstacle in the vector back to level to determine the collisions
std::vector<BlackHole>* BlackHoleManager::getBlackHole()
{
	return &obstacle;
}

//render obstacle to the window
void BlackHoleManager::render(sf::RenderWindow* window)
{
	for (size_t i = 0; i < obstacle.size(); i++)
	{
		if (obstacle[i].isAlive())
		{
			window->draw(obstacle[i]);
		}
	}
}