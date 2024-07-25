#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "framework/GameObject.h"
#include "Map1.h"
#include "BlackHoleManager.h"
#include "EnemyManager.h"
#include "FireBallManager.h"
#include "AmmoPickup.h"
#include "PickupManager.h"
#include "PortalManager.h"
#include "Portal.h"
#include "Fragment.h"
#include "FragmentManager.h"
#include "Fireball.h"
#include "AntiMatterEnemy.h"
#include "Player.h"
#include "BackgroundTest.h"
#include "Controls.h"
#include <chrono>
#include <cstdlib>
#include <Windows.h>

class Level : BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	//default variables for level class

	BlackHoleManager obstacleManager;
	EnemyManager enemyManager;
	FireBallManager ammoManager;
	PickupManager pickupManager;
	PortalManager portalManager;
	FragmentManager fragmentManager;

	//variables with no collision to show player how to play and what to go for
	AmmoPickup ammoKey;
	Fragment fragKey;
	Portal portalKey;
	sf::Texture aTexture;
	sf::Texture fTexture;
	sf::Texture pTexture;


	Player player;
	sf::Texture playerTexture;

	Controls controls;
	sf::Texture controlTexture;

	BackgroundTest background;
	sf::Texture backTexture;
	sf::View view;

	Map1 map1;
	
	sf::Clock clock;
	float time;

	int deathHeight = 5000;
};