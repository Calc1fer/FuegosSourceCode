#include "Fragment.h"

//constructor
Fragment::Fragment()
{
	idle.addFrame(sf::IntRect(0, 0, 32, 32));
	idle.addFrame(sf::IntRect(32, 0, 32, 32));
	idle.addFrame(sf::IntRect(64, 0, 32, 32));
	idle.addFrame(sf::IntRect(96, 0, 32, 32));
	idle.setFrameSpeed(1.f / 10.f);		//set speed for animation

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());
}

//deconstructor
Fragment::~Fragment()
{

}

//update the properties of the fragment object pickup
void Fragment::update(float dt)
{
	//animate the current animation
	currentAnimation = &idle;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

//rectify the collision between player and the pickup
void Fragment::collisionResponse(GameObject* collider)
{
	setAlive(false);
}