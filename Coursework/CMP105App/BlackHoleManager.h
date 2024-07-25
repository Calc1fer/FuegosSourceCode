#pragma once
#include "BlackHole.h"
#include <math.h>
#include <vector>
#include "Framework/Collision.h"

class BlackHoleManager
{
public:

	BlackHoleManager();
	~BlackHoleManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	std::vector<BlackHole>* getBlackHole();
	void render(sf::RenderWindow* window);

protected:
	std::vector<BlackHole> obstacle;
	sf::Vector2f spawnPoint;
	int numObstacles = 6;

	sf::Vector2f spawnPoint1;
	sf::Vector2f spawnPoint2;
	sf::Vector2f spawnPoint3;
	sf::Vector2f spawnPoint4;
	sf::Vector2f spawnPoint5;
	sf::Vector2f spawnPoint6;
	sf::Vector2f vel;
	sf::Vector2f location;

	sf::Texture texture;
	int speedX;
	int speedY;

};

