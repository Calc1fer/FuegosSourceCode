#include "PortalManager.h"

//constructor
PortalManager::PortalManager()
{
	texture.loadFromFile("gfx/PortalSpriteSheet.png");
	portal.setTexture(&texture);
	portal.setSize(sf::Vector2f(100, 80));
	portal.setPosition(sf::Vector2f(-500, 0));
	portal.setCollisionBox(sf::FloatRect(0, 0, 100, 80));

	spawnPoint = sf::Vector2f(1900, 1200);

	setVisible = false;
}

//deconstructor
PortalManager::~PortalManager()
{

}

//spawn at the correct time, when player has collected all fragments
void PortalManager::spawn()
{
	//set position to origin of screen and setalive to false so player does not collide{
	portal.setPosition(spawnPoint);
	portal.setAlive(true);
}

//update the portal door
void PortalManager::update(float dt)
{
	if (portal.isAlive() == true)
	{
		portal.update(dt);
	}
}

//return ref of portal to determine the collision between portal and player for end of game condition
Portal& PortalManager::getPortal()
{
	return portal;
}

//reset the position
void PortalManager::reset()
{
	if (portal.isAlive() == true)
	{
		portal.setAlive(false);
		portal.setPosition(-500, 0);
	}
}

//render the portal to the window
void PortalManager::render(sf::RenderWindow* window)
{
	if (portal.isAlive())
	{
		window->draw(portal);
	}
}