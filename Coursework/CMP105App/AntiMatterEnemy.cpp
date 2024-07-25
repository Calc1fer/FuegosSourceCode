#include "AntiMatterEnemy.h"
#include <iostream>

//constructor
//set up the frames for animation
AntiMatterEnemy::AntiMatterEnemy()
{
	idle.addFrame(sf::IntRect(0, 0, 32, 32));
	idle.addFrame(sf::IntRect(32, 0, 32, 32));
	idle.addFrame(sf::IntRect(64, 0, 32, 32));
	idle.addFrame(sf::IntRect(96, 0, 32, 32));
	idle.addFrame(sf::IntRect(128, 0, 32, 32));
	idle.setFrameSpeed(1.f / 10.f);		//set speed for animation

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());
}

//deconstructor
AntiMatterEnemy::~AntiMatterEnemy()
{

}

//update the properties of the enemy object
void AntiMatterEnemy::update(float dt)
{
	move(velocity * dt);

	//animate the current animation
	//set current animation again here to allow manager class for enemy update the animation for instances stored in vector array
	currentAnimation = &idle;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

void AntiMatterEnemy::collisionResponseHit(GameObject* collider)
{
	//called by the enemyManager when player collides with enemy
	setAlive(false);
}

void AntiMatterEnemy::collisionResponsePlayer(GameObject* collider)
{
	//invert the speed of the enemies so the player doesn't get damaged constantly
	//doesn't change because the object itself has no velocity.x here...manager class deals with it
	/*setAlive(false);*/
	/*setVelocity(-150, 0);*/

}

void AntiMatterEnemy::collisionResponseWorld(GameObject* collider)
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
			velocity.y = -velocity.y;
			setPosition(getPosition().x, collider->getPosition().y - getSize().y);
		}
		//collision on bottom of collider
		else
		{
			velocity.y = -velocity.y;
			setPosition(getPosition().x, collider->getPosition().y + getSize().y);
		}
	}
}