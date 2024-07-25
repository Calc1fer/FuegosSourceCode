#include "PickupManager.h"

//constructor
PickupManager::PickupManager()
{
	texture.loadFromFile("gfx/Ammo.png");

	for (int i = 0; i < numPickup; i++)
	{
		pickup.push_back(AmmoPickup());
		pickup[i].setAlive(false);
		pickup[i].setTexture(&texture);
		pickup[i].setSize(sf::Vector2f(80, 80));
		pickup[i].setCollisionBox(sf::FloatRect(0, 0, 80, 80));
	}

	spawnPoint1 = sf::Vector2f(2100, 1300);
	spawnPoint2 = sf::Vector2f(1000, 1400);
	spawnPoint3 = sf::Vector2f(2700, 100);
	spawnPoint4 = sf::Vector2f(1700, 120);

	lifted = false;
	pickupValue = 10;
}

//deconstructor
PickupManager::~PickupManager()
{

}

//spawn the pickups
void PickupManager::spawn()
{
	for (int i = 0; i < pickup.size(); i++)
	{
		switch (i)
		{
		case 0:
			location = spawnPoint1;
			break;
		case 1:
			location = spawnPoint2;
			break;
		case 2:
			location = spawnPoint3;
			break;
		case 3:
			location = spawnPoint4;
			break;
		}

		if (!pickup[i].isAlive())
		{
			pickup[i].setAlive(true);
			pickup[i].setPosition(location);
			return;
		}
	}
}

//update the pickup properties
void PickupManager::update(float dt)
{
	for (int i = 0; i < pickup.size(); i++)
	{
		if (pickup[i].isAlive())
		{
			pickup[i].update(dt);
		}

		if (!pickup[i].isAlive() && lifted == false)
		{
			spawn();
		}
	}
}

//draw the pickups directly to the window
void PickupManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < pickup.size(); i++)
	{
		if (pickup[i].isAlive())
		{
			window->draw(pickup[i]);
		}
	}
}

//function called by player to add on ammo when pickups are collided with
int PickupManager::addAmmo()
{
	return pickupValue;

}

void PickupManager::setLifted()
{
	lifted = true;
}

//return a reference of the pickups objects back to level to determine collisions
std::vector<AmmoPickup>* PickupManager::getPickup()
{
	return &pickup;
}

//reset the positions of the pickups
void PickupManager::reset()
{
	lifted = false;

	spawn();
}