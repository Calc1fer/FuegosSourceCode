#include "AmmoPickup.h"

//constructor
AmmoPickup::AmmoPickup()
{
	idle.addFrame(sf::IntRect(0, 0, 32, 32));
	idle.addFrame(sf::IntRect(32, 0, 32, 32));
	idle.setFrameSpeed(1.f / 10.f);		//set speed for animation

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());
}

//deconstructor
AmmoPickup::~AmmoPickup()
{

}

//overriden update function for animation
void AmmoPickup::update(float dt)
{
	currentAnimation = &idle;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

//rectify the collisions between pickup and player
void AmmoPickup::collisionResponse(GameObject* collider)
{
	setAlive(false);
}
