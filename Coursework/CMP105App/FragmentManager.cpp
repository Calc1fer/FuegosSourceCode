#include "FragmentManager.h"

//constructor
FragmentManager::FragmentManager()
{
	texture.loadFromFile("gfx/FragmentSpriteSheet.png");
	
	for (int i = 0; i < numFragment; i++)
	{
		fragments.push_back(Fragment());
		fragments[i].setAlive(false);
		fragments[i].setTexture(&texture);
		fragments[i].setSize(sf::Vector2f(60, 60));
	}

	spawnPoint1 = sf::Vector2f(2800, 200);
	spawnPoint2 = sf::Vector2f(100, 1700);
	spawnPoint3 = sf::Vector2f(2200, 1600);

	lifted = false;
}

//deconstructor
FragmentManager::~FragmentManager()
{

}

//spawn the fragment objects around the map
void FragmentManager::spawn()
{
	//assign spawnpoint to each obstacle in array
	for (int i = 0; i < fragments.size(); i++)
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
		}

		if (!fragments[i].isAlive())
		{
			fragments[i].setAlive(true);
			fragments[i].setPosition(location);
			fragments[i].setCollisionBox(sf::FloatRect(0, 0, 60, 60));
			return;
		}
	}
}

//update the properties of the fragment objects
void FragmentManager::update(float dt)
{
	for (int i = 0; i < fragments.size(); i++)
	{
		if (fragments[i].isAlive())
		{
			fragments[i].update(dt);
		}

		if (!fragments[i].isAlive() && lifted == false)
		{
			spawn();
		}
	}
}

//return a reference of the objects back to level to determine the collisions between player and object
std::vector<Fragment>* FragmentManager::getFragment()
{
	return &fragments;
}

void FragmentManager::setLifted()
{
	lifted = true;
}

//reset the locations of the fragment pickups
void FragmentManager::reset()
{
	lifted = false;
	
	spawn();

}

//render the objects directly to the window
void FragmentManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < fragments.size(); i++)
	{
		if (fragments[i].isAlive())
		{
			window->draw(fragments[i]);
		}
	}
}