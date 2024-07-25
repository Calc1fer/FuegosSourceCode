#pragma once
#include "Fireball.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
#include <math.h>
#include <vector>

class FireBallManager
{
public:

	FireBallManager();
	~FireBallManager();

	void spawn(int playerX, int playerY, sf::Vector2f ammoVel);
	void update(float dt, int windowW, int windowH);
	void deathCheck(int windowW, int windowH);
	void render(sf::RenderWindow* window);
	std::vector<Fireball>* getAmmo();

protected:
	std::vector<Fireball> fireBalls;
	sf::Texture texture;
	int numFireBalls = 10;
	bool isFlipped;
	Fireball fireball;

	AudioManager audio;

	int distance;
	int pX;
};

