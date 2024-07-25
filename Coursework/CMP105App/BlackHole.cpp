#include "BlackHole.h"
#include <iostream>
//constructor
BlackHole::BlackHole()
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
BlackHole::~BlackHole()
{

}

//update the properties of the blackhole obstacle
void BlackHole::update(float dt)
{
	move(velocity * dt);

	//animate the current animation
	currentAnimation = &idle;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
	//setVelocity(50, 0);

	//std::cout << getPosition().x << " " << getPosition().y << std::endl;
}

void BlackHole::collisionResponseHit(GameObject* collider)
{
	//do nothing
	//no damage to black holes
}

void BlackHole::collisionResponsePlayer(GameObject* collider)
{
	//we will teleport the player to a set position on the map
	//play teleport sound
}

void BlackHole::collisionResponseWorld(GameObject* collider)
{
	//setVelocity(-velocity.x, 0);
	sf::Vector2f diff = getPosition() - collider->getPosition();

	//horizontal collisions
	if (abs(diff.x) > abs(diff.y))
	{
		//x-axis collision on left of collider
		if (diff.x < 0)
		{
			velocity.x = -velocity.x;
			setPosition(collider->getPosition().x - getSize().x, getPosition().y);
		}
		//collision on the right of the collider
		else
		{
			velocity.x = -velocity.x;
			setPosition(collider->getPosition().x + getSize().x, getPosition().y);
		}

	}

	//vertical collisions
	if (abs(diff.x) < abs(diff.y))
	{
		//y-axis collision on top
		if (diff.y < 0)
		{
			setPosition(getPosition().x, collider->getPosition().y - getSize().y);
		}
		//collision on bottom of collider
		else
		{
			setPosition(getPosition().x, collider->getPosition().y + getSize().y);
		}
	}
}