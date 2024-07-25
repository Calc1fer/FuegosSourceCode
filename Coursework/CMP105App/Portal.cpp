#include "Portal.h"

//constructor
Portal::Portal()
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
Portal::~Portal()
{

}

//update function to update the properties of portal object
void Portal::update(float dt)
{
	//animate the current animation
	currentAnimation = &idle;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

//collision response for when the player has collected all fragments to complete the level
void Portal::collisionResponse(GameObject* collider)
{
	//have a way to change the state of the game to completion window.
}