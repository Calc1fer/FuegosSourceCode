#pragma once
#include "Portal.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
class PortalManager
{
public:

	PortalManager();
	~PortalManager();

	void spawn();
	void update(float dt);
	Portal& getPortal();
	void render(sf::RenderWindow* window);
	void reset();

protected:
	sf::Texture texture;
	Portal portal;

	sf::Vector2f spawnPoint;

	bool setVisible;
};

