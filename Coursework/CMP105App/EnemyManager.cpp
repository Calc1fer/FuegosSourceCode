#include "EnemyManager.h"
#include <iostream>

//constructor
EnemyManager::EnemyManager()
{
	//randomise position to the screen for now
	//spawnPoint = sf::Vector2f(rand() % 1000 - 100, 110);

	srand(static_cast<unsigned int>(time(0)));	//seed the random number generator

	if (!texture.loadFromFile("gfx/AntiMatterSpriteSheet.png"))
	{
		std::cout << "Could not load enemy sprite\n";
	}
	else
	{
		texture.loadFromFile("gfx/AntiMatterSpriteSheet.png");
	}

	for (size_t i = 0; i < numAntiMatter; i++)
	{
		anti.push_back(AntiMatterEnemy());
		anti[i].setAlive(false);
		anti[i].setTexture(&texture);
		anti[i].setSize(sf::Vector2f(90, 90));
		anti[i].setCollisionBox(sf::FloatRect(20, 20, 40, 40));
		isKilled = false;

	}
	speedX = 150;
	speedY = 0;
}

//deconstructor
EnemyManager::~EnemyManager()
{

}

//spawn a new enemy
void EnemyManager::spawn()
{
	for (size_t i = 0; i < anti.size(); i++)
	{
		if (!anti[i].isAlive())
		{
			location = enemyPositions();
			vel = velocities();

			isKilled = false;
			anti[i].setAlive(true);
			anti[i].setVelocity(vel);
			anti[i].setPosition(location);

			return;
		}
	}
}

//update the properties of enemy sprites and carry out animations
void EnemyManager::update(float dt)
{
	for (size_t i = 0; i < anti.size(); i++)
	{
		if (anti[i].isAlive())
		{
			anti[i].update(dt);
		}
		if (anti[i].getPosition().x <= 0)
		{
			anti[i].setVelocity(-speedX, speedY);
		}
	
		//loop through object iterations and check if dead or not
		deathCheck();
	}
}

//check if the enemy is dead. If the enemy is not alive and has not been killed then spawn
void EnemyManager::deathCheck()
{
	for (size_t i = 0; i < anti.size(); i++)
	{
		if (!anti[i].isAlive() && isKilled == true)
		{
			//do nothing
		}
		else if(!anti[i].isAlive() && isKilled == false)
		{
			spawn();
		}
	}
}

//function will choose the random starting locations for each enemy within a range and spawn them
sf::Vector2f EnemyManager::enemyPositions()
{
	for (size_t i = 0; i < anti.size(); i++)
	{
		if (!anti[i].isAlive())
		{
			//cycle through the different spawn ranges for where I want the enemies to be located. Change this based on the level.
			//if statement for randomly picking number between 1 and 5, select this vector and store it in a new vector
			//return this vector
			int pos = rand() % 8 + 1;
			sf::Vector2f sp;

			//designate the random ranges for positioning enemies
			spawnPoint1 = sf::Vector2f(rand() % 150 + 900, rand() % 150 + 50);
			spawnPoint2 = sf::Vector2f(rand() % 150 + 1400, rand() % 150 + 320);
			spawnPoint3 = sf::Vector2f(rand() % 150 + 1800, rand() % 150 + 480);
			spawnPoint4 = sf::Vector2f(rand() % 150 + 2300, rand() % 150 + 800);
			spawnPoint5 = sf::Vector2f(rand() % 150 + 600, rand() % 150 + 720);
			spawnPoint6 = sf::Vector2f(rand() % 150 + 400, rand() % 150 + 1420);
			spawnPoint7 = sf::Vector2f(rand() % 150 + 2500, rand() % 150 + 1450);
			spawnPoint8 = sf::Vector2f(rand() % 150 + 1500, rand() % 150 + 850);

			//depending on the random number generated, this will correspond to where the enemy objects are spawned
			switch (pos)
			{
			case 1:
				sp = spawnPoint1;
				break;
			case 2:
				sp = spawnPoint2;
				break;
			case 3:
				sp = spawnPoint3;
				break;
			case 4:
				sp = spawnPoint4;
				break;
			case 5:
				sp = spawnPoint5;
				break;
			case 6:
				sp = spawnPoint6;
				break;
			case 7:
				sp = spawnPoint7;
				break;
			case 8:
				sp = spawnPoint8;
				break;
			}

			return sp;
			
		}
	}
}

//dictate whether positive or negative velocity for each object
//this will help to space them out a bit more
sf::Vector2f EnemyManager::velocities()
{
	for (size_t i = 0; i < anti.size(); i++)
	{
		if (!anti[i].isAlive())
		{
			int vel = rand() % 20 + 1;
			sf::Vector2f v;

			if (vel >= 0 && vel <= 10)
			{
				v = sf::Vector2f(-speedX, speedY);
			}
			else if (vel >= 11 && vel <=20)
			{
				v = sf::Vector2f(speedX, speedY);
			}

			return v;
		}
	}
}

//function prevents the enemies from being spawned again when killed
void EnemyManager::setKilled()
{
	isKilled = true;
}

std::vector<AntiMatterEnemy>* EnemyManager::getEnemy()
{
	return &anti;
}

void EnemyManager::reset()
{
	isKilled == false;
	spawn();
}

//control the rendering directly to the window from here
void EnemyManager::render(sf::RenderWindow* window)
{
	for (size_t i = 0; i < anti.size(); i++)
	{
		if (anti[i].isAlive())
		{
			window->draw(anti[i]);
		}
	}
}