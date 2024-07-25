#include "Fireball.h"
#include <iostream>
//constructor
Fireball::Fireball()
{
	idle.addFrame(sf::IntRect(0, 0, 32, 32));
	idle.addFrame(sf::IntRect(32, 0, 32, 32));
	idle.setFrameSpeed(1.f / 10.f);		//set speed for animation

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());

	scale = 100.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
}

//deconstructor
Fireball::~Fireball()
{

}

//update function to update the position of the fireball
void Fireball::update(float dt)
{
	currentAnimation = &idle;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	move(velocity * dt);

	//Apply gravitational force to the fireball object
	//move fireball by the new velocity
	//sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
	//velocity += gravity * dt;
	//setPosition(getPosition() + pos);
}

//When fireball makes contact with any material/object in game world, set alive to false
void Fireball::collisionResponse(GameObject* collider)
{
	setAlive(false);
}

//reference passed into manager when the animation needs to be flipped or not
void Fireball::flip(bool flip)
{
	if (flip == true)
	{
		currentAnimation->setFlipped(true);
	}
	else
	{
		currentAnimation->setFlipped(false);
	}
}