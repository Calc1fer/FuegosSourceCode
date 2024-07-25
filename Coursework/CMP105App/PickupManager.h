#pragma once
#include "AmmoPickup.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
#include <math.h>
#include <vector>
class PickupManager
{
public:

	PickupManager();
	~PickupManager();

	void spawn();
	void update(float dt);
	void render(sf::RenderWindow* window);
	int addAmmo();
	void setLifted();
	std::vector<AmmoPickup>* getPickup();
	void reset();

protected:
	std::vector<AmmoPickup> pickup;
	sf::Texture texture;
	int numPickup = 5;
	int pickupValue = 0;

	sf::Vector2f spawnPoint1;
	sf::Vector2f spawnPoint2;
	sf::Vector2f spawnPoint3;
	sf::Vector2f spawnPoint4;
	sf::Vector2f location;

	bool lifted;
};

