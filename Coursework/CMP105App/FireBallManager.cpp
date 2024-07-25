#include "FireBallManager.h"
#include <iostream>

//constructor
FireBallManager::FireBallManager()
{
	if (!texture.loadFromFile("gfx/Ammo.png"))
	{
		std::cout << "Could not load the fireball sprite\n";
	}
	else
	{
		texture.loadFromFile("gfx/Ammo.png");
	}

	//add sounds here to play when spawning new fireball
	audio.addSound("sfx/Shoot.wav", "Shoot");

	for (int i = 0; i < numFireBalls; i++)
	{
		fireBalls.push_back(Fireball());
		fireBalls[i].setAlive(false);
		fireBalls[i].setTexture(&texture);
		fireBalls[i].setSize(sf::Vector2f(40, 40));
		fireBalls[i].setCollisionBox(sf::FloatRect(0, 0, 30, 30));
		isFlipped = false;
	}

	distance = 1000;
	pX = 0;
}

//deconstructor
FireBallManager::~FireBallManager()
{

}

void FireBallManager::spawn(int playerX, int playerY, sf::Vector2f ammoVel)
{
	//using this to check how far the fireballs have travelled before setting alive to false
	pX = playerX;

	for (int i = 0; i < fireBalls.size(); i++)
	{
		if (!fireBalls[i].isAlive())
		{
			audio.playSoundbyName("Shoot");
			fireBalls[i].setAlive(true);
			fireBalls[i].setVelocity(ammoVel);
			fireBalls[i].setPosition(playerX, playerY);
			return;
		}
	}
}
void FireBallManager::update(float dt, int windowW, int windowH)
{
	//call update on all Alive fireballs

	for (int i = 0; i < fireBalls.size(); i++)
	{
		if (fireBalls[i].isAlive() && isFlipped == true)
		{
			fireBalls[i].update(dt);
		}
		else if(fireBalls[i].isAlive() && isFlipped == false)
		{
			fireBalls[i].update(dt);
		}
		deathCheck(windowW, windowH);
	}
}

//check all Alive fireballs to see if out of screen borders. If so, make dead
void FireBallManager::deathCheck(int windowW, int windowH)
{
	for (int i = 0; i < fireBalls.size(); i++)
	{
		if (fireBalls[i].isAlive())
		{
			if (fireBalls[i].getPosition().x < pX - distance)
			{
				fireBalls[i].setAlive(false);
			}
			if (fireBalls[i].getPosition().x > pX + distance)
			{
				fireBalls[i].setAlive(false);
			}
			//if (fireBalls[i].getPosition().y < 0)
			//{
			//	fireBalls[i].setAlive(false);
			//}
			//if (fireBalls[i].getPosition().y > windowH)
			//{
			//	fireBalls[i].setAlive(false);
			//}
		}
	}
}

//pointer to the fireball vector, which returns ref of alive fireballs to player when called
std::vector<Fireball>* FireBallManager::getAmmo()
{
	return &fireBalls;
}

//render all alive fireballs
void FireBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < fireBalls.size(); i++)
	{
		if (fireBalls[i].isAlive())
		{
			window->draw(fireBalls[i]);
		}
	}
}