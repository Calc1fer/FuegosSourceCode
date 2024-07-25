#pragma once
#include "AntiMatterEnemy.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Player.h"
#include <math.h>
#include <vector>

class EnemyManager
{
public:

	EnemyManager();
	~EnemyManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void setKilled();
	sf::Vector2f enemyPositions();
	sf::Vector2f velocities();
	std::vector<AntiMatterEnemy>* getEnemy();
	void render(sf::RenderWindow* window);
	void reset();

protected:
	std::vector<AntiMatterEnemy> anti;
	sf::Vector2f spawnPoint1;
	sf::Vector2f spawnPoint2;
	sf::Vector2f spawnPoint3;
	sf::Vector2f spawnPoint4;
	sf::Vector2f spawnPoint5;
	sf::Vector2f spawnPoint6;
	sf::Vector2f spawnPoint7;
	sf::Vector2f spawnPoint8;
	sf::Vector2f vel;
	sf::Vector2f location;
	sf::Texture texture;

	int numAntiMatter = 24;
	int speedX;
	int speedY;

	bool isKilled;
};

