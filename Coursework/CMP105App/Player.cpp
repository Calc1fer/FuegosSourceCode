#include "Player.h"
#include <iostream>

//constructor
Player::Player()
{
	//set up animations for idle
	idle.addFrame(sf::IntRect(0, 0, 32, 32));
	idle.addFrame(sf::IntRect(32, 0, 32, 32));
	idle.addFrame(sf::IntRect(64, 0, 32, 32));
	idle.addFrame(sf::IntRect(96, 0, 32, 32));
	idle.addFrame(sf::IntRect(128, 0, 32, 32));
	idle.addFrame(sf::IntRect(160, 0, 32, 32));
	idle.addFrame(sf::IntRect(192, 0, 32, 32));
	idle.addFrame(sf::IntRect(224, 0, 32, 32));
	idle.setFrameSpeed(1.f / 20.f);	//setting speed

	//set up animations for run
	run.addFrame(sf::IntRect(0, 32, 32, 32));
	run.addFrame(sf::IntRect(32, 32, 32, 32));
	run.addFrame(sf::IntRect(64, 32, 32, 32));
	run.addFrame(sf::IntRect(96, 32, 32, 32));
	run.addFrame(sf::IntRect(128, 32, 32, 32));
	run.addFrame(sf::IntRect(160, 32, 32, 32));
	run.addFrame(sf::IntRect(192, 32, 32, 32));
	run.addFrame(sf::IntRect(224, 32, 32, 32));
	run.setFrameSpeed(1.f / 20.f);	//setting speed

	//set up animations for attack
	attack.addFrame(sf::IntRect(0, 64, 32, 32));
	attack.addFrame(sf::IntRect(32, 64, 32, 32));
	attack.addFrame(sf::IntRect(64, 64, 32, 32));
	attack.addFrame(sf::IntRect(96, 64, 32, 32));
	attack.addFrame(sf::IntRect(128, 64, 32, 32));
	attack.addFrame(sf::IntRect(160, 64, 32, 32));
	attack.addFrame(sf::IntRect(192, 64, 32, 32));
	attack.setFrameSpeed(1.f / 20.f);	//setting speed

	//set up animations for shield
	shield.addFrame(sf::IntRect(0, 96, 32, 32));
	shield.addFrame(sf::IntRect(32, 96, 32, 32));
	shield.addFrame(sf::IntRect(64, 96, 32, 32));
	shield.addFrame(sf::IntRect(96, 96, 32, 32));
	shield.addFrame(sf::IntRect(128, 96, 32, 32));
	shield.addFrame(sf::IntRect(160, 96, 32, 32));
	shield.setFrameSpeed(1.f / 20.f);	//setting speed

	//set up animations for idle shield
	idleShield.addFrame(sf::IntRect(0, 128, 32, 32));
	idleShield.addFrame(sf::IntRect(32, 128, 32, 32));
	idleShield.addFrame(sf::IntRect(64, 128, 32, 32));
	idleShield.addFrame(sf::IntRect(96, 128, 32, 32));
	idleShield.setFrameSpeed(1.f / 20.f);	//setting speed

	//set up animations for taking damage
	takingDamage.addFrame(sf::IntRect(0, 160, 32, 32));
	takingDamage.addFrame(sf::IntRect(32, 160, 32, 32));
	takingDamage.addFrame(sf::IntRect(64, 160, 32, 32));
	takingDamage.addFrame(sf::IntRect(96, 160, 32, 32));
	takingDamage.setFrameSpeed(1.f / 5.f);	//setting speed

	//set up animations for death animation
	death.addFrame(sf::IntRect(0, 192, 32, 32));
	death.addFrame(sf::IntRect(32, 192, 32, 32));
	death.addFrame(sf::IntRect(64, 192, 32, 32));
	death.addFrame(sf::IntRect(96, 192, 32, 32));
	death.addFrame(sf::IntRect(128, 192, 32, 32));
	death.addFrame(sf::IntRect(160, 192, 32, 32));
	death.addFrame(sf::IntRect(192, 192, 32, 32));
	death.addFrame(sf::IntRect(224, 192, 32, 32));
	death.addFrame(sf::IntRect(256, 192, 32, 32));
	death.addFrame(sf::IntRect(288, 192, 32, 32));
	death.addFrame(sf::IntRect(320, 192, 32, 32));
	death.addFrame(sf::IntRect(352, 192, 32, 32));
	death.addFrame(sf::IntRect(384, 192, 32, 32));
	death.addFrame(sf::IntRect(416, 192, 32, 32));
	death.addFrame(sf::IntRect(448, 192, 32, 32));
	death.addFrame(sf::IntRect(480, 192, 32, 32));
	death.addFrame(sf::IntRect(502, 192, 32, 32));
	death.addFrame(sf::IntRect(534, 192, 32, 32));
	death.setFrameSpeed(1.f / 20.f);	//setting speed

	jump.addFrame(sf::IntRect(0, 224, 32, 32));
	jump.addFrame(sf::IntRect(32, 224, 32, 32));
	jump.addFrame(sf::IntRect(64, 224, 32, 32));
	jump.setFrameSpeed(1.f / 20.f);

	//add sounds to the player
	audio.addSound("sfx/Jump.wav", "Jump");
	audio.addSound("sfx/Hit.wav", "Hit");
	audio.addSound("sfx/Teleport.wav", "Teleport");
	audio.addSound("sfx/Pickup.wav", "Pickup");
	audio.addSound("sfx/CollectKey.wav", "Fragment");
	audio.addSound("sfx/LevelComplete.wav", "LevelComplete");

	font.loadFromFile("font/arial.ttf");
	healthText.setFont(font);
	fragText.setFont(font);
	ammoText.setFont(font);

	//reference to the current animation
	currentAnimation = &jump;
	setTextureRect(currentAnimation->getCurrentFrame());

	srand(static_cast<unsigned int>(time(0)));	//seed the random number generator

	scale = 100.f;

	direction = false;
	jumping = false;
	blocking = false;
	attacking = false;
	flipFireBallVel = false;
	attAnimation = false;
	takeDamage = false;
	showHealth = false;
	showAmmo = false;
	showFrag = false;

	ammoVel = sf::Vector2f(400, 0);
	ammoX = 400;
	ammoY = 0;

	jumpVector = sf::Vector2f(0, -4.5f) * scale;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	setCollisionBox(sf::FloatRect(20, 40, 40, 40));

	speed = 150;
	jumpSpeed = 50;

	maxHealth = 30;
	health = maxHealth;
	ammoCount = 20;
	fragmentCount = 0;
}

//deconstructor
Player::~Player()
{

}

//handle user keypresses
void Player::handleInput(float dt)
{
	if (takeDamage == false)
	{
		//flip animation frames, move left and initiate run animation
		if (input->isKeyDown(sf::Keyboard::Left))
		{
			currentAnimation->setFlipped(true);
			currentAnimation = &run;

			if (blocking == false && attacking == false)
			{
				velocity.x = -speed;
				move(velocity * dt);
			}

			//check if player is moving off left of window
			if (getPosition().x <= 0 - getSize().x / 3)
			{
				velocity.x = -velocity.x;
			}
		}
		//moving right, and initiating run animation
		else if (input->isKeyDown(sf::Keyboard::Right))
		{
			currentAnimation->setFlipped(false);
			currentAnimation = &run;

			if (blocking == false && attacking == false)
			{
				velocity.x = speed;
				move(velocity * dt);
			}

			//check if the player moves off the right side of the screen
			//if (getPosition().x >= window->getSize().x - getSize().x / 2)
			//{
			//	velocity.x = -velocity.x;
			//}
		}
		else
		{
			//velocity.x = 0;
			currentAnimation = &idle;
		}

		//code for using shield
		//if player is shielding, then blocking is set to true, preventing player moving simultaneously
		//depending on which way the player faces, this is the direction they will shield
		if (input->isKeyDown(sf::Keyboard::LControl) || input->isKeyDown(sf::Keyboard::RControl))
		{
			if (currentAnimation->getFlipped() == true)
			{
				blocking = true;
				currentAnimation = &idleShield;
				currentAnimation->setFlipped(true);
				velocity.x = 0;
			}
			else
			{
				blocking = true;
				currentAnimation = &idleShield;
				currentAnimation->setFlipped(false);
				velocity.x = 0;
			}
		}

		//code for jumping, and initiating jump animation
		if (input->isPressed(sf::Keyboard::Space))
		{
			//if not jumping, then set jumping to true and allow player to jump
			if (!jumping && currentAnimation->getFlipped() == true)
			{
				audio.playSoundbyName("Jump");
				jumping = true;
				velocity = jumpVector;
				currentAnimation = &jump;
				currentAnimation->setFlipped(true);
			}
			else if (!jumping && currentAnimation->getFlipped() == false)
			{
				audio.playSoundbyName("Jump");
				jumping = true;
				velocity = jumpVector;
				currentAnimation = &jump;
				currentAnimation->setFlipped(false);
			}

			move(velocity * dt);
		}

		//code for attacking
		//play animation for attacking when key press is registered, update function will spawn a fireball at player position
		if (input->isKeyDown(sf::Keyboard::LShift) || input->isKeyDown(sf::Keyboard::RShift))
		{
			if (currentAnimation->getFlipped() == true)
			{
				attacking = true;
				currentAnimation = &attack;
				currentAnimation->setFlipped(true);
			}
			else if (currentAnimation->getFlipped() == false)
			{
				attacking = true;
				currentAnimation = &attack;
				currentAnimation->setFlipped(false);
			}
		}
	}
}

//update the properties of player object
void Player::update(float dt)
{
	//Apply gravitational force to the player object
	//move the player by the new velocity
	sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
	velocity += gravity * dt;
	setPosition(getPosition() + pos);

	//if the player leaves the bottom of the window, we want to reset player position to bottom of window
	//if (getPosition().y >= window->getSize().y - getSize().y)
	//{
	//	//I will make this change to a gameOver game state screen before giving player option to start again or quit
	//	exit(0);
	//}

	//reset blocking to false so player can move
	if (!input->isKeyDown(sf::Keyboard::LControl) && !input->isKeyDown(sf::Keyboard::RControl))
	{
		blocking = false;
	}

	//reset attacking to false so player can move
	//refers only to the attacking state
	if (!input->isKeyDown(sf::Keyboard::LShift) && !input->isKeyDown(sf::Keyboard::RShift))
	{
		if (currentAnimation->getFlipped() == true && attacking == true)
		{
			if (ammoCount != 0)
			{
				ammoVel = sf::Vector2f(-ammoX, 0);
				ammoManager.spawn(getPosition().x, getPosition().y, ammoVel);
				ammoCount--;
			}
		}
		else if (currentAnimation->getFlipped() == false && attacking == true)
		{
			if (ammoCount != 0)
			{
				ammoVel = sf::Vector2f(ammoX, 0);
				ammoManager.spawn(getPosition().x, getPosition().y, ammoVel);
				ammoCount--;
			}
		}
		attacking = false;
		attack.reset();	//reset the animation when there is no keypress
	}

	//while player is not situated on the ground then play jump animation.
	//update this so when colliding with a platform then we do not play the jumping animation
	if (jumping == true)
	{
		if (currentAnimation->getFlipped() == true)
		{
			currentAnimation = &jump;
			//currentAnimation->setFlipped(true);
		}
		else if(currentAnimation->getFlipped() == false)
		{
			currentAnimation = &jump;
			//currentAnimation->setFlipped(false);
		}
	}
	//This will stop the player sliding across platforms when no keypresses
	else if (jumping == false)
	{
		velocity.x = 0;
	}

	//if the player is below platforms and not making contact then play jump animation while player falls
	if (getPosition().y > colliderPos.y)
	{
		//stop the player from being able to jump if they fall off an edge
		jumping = true;

		if (currentAnimation->getFlipped() == true)
		{
			currentAnimation = &jump;
			currentAnimation->setFlipped(true);
		}
		else if (currentAnimation->getFlipped() == false)
		{
			currentAnimation = &jump;
			currentAnimation->setFlipped(false);
		}
	}

	//when take damage is set to true, play the taking damage animation
	if (takeDamage == true)
	{
		currentAnimation->animate(dt);
	}

	//play death animation when the players health reaches 0
	if (health == 0)
	{
		currentAnimation = &death;
		currentAnimation->animate(dt);
	}

	ammoManager.update(dt, window->getSize().x, window->getSize().y);

	//animate the current animation
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

//ref of fireball vector which returns a ref of alive fireballs to level class
std::vector<Fireball>* Player::getAmmo()
{
	return ammoManager.getAmmo();
}

//function that resolves a collision event
//play taking damage animation when colliding with enemies
void Player::collisionResponseEnemy(GameObject* collider)
{
	sf::Vector2f diff = getPosition() - collider->getPosition();
	colliderPos = collider->getPosition();

	if (input->isKeyDown(sf::Keyboard::LControl) || input->isKeyDown(sf::Keyboard::RControl))
	{
		takeDamage = false;
		std::cout << health << std::endl;
	}
	else
	{
		audio.playSoundbyName("Hit");
		currentAnimation = &takingDamage;

		takeDamage = true;

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
				velocity.y = 0;
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
	setTakeDamage();
}

//check for collision in the world
void Player::collisionResponseWorld(GameObject* collider)
{
	//sf::Vector2f playerCentre = sf::Vector2f(getSize().x / 2, getSize().y / 2);
	//sf::Vector2f colliderCentre = sf::Vector2f(collider->getSize().x / 2, collider->getSize().y / 2);
	sf::Vector2f diff = getPosition() - collider->getPosition();
	colliderPos = collider->getPosition();
	jumping = false;

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
			velocity.y = 0;
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

void Player::collisionResponseObstacle(GameObject* collider)
{
	//teleport the player to set coordinates around the level
	//make sure the camera will still be centred on the player
	audio.playSoundbyName("Teleport");

	int num = rand() % 4 + 1;

	randLocation1 = sf::Vector2f(2700, 420);
	randLocation2 = sf::Vector2f(50, 1120);
	randLocation3 = sf::Vector2f(850, 1520);
	randLocation4 = sf::Vector2f(2800, 1520);

	switch (num)
	{
	case 1:
		setPosition(randLocation1);
		break;
	case 2:
		setPosition(randLocation2);
		break;
	case 3:
		setPosition(randLocation3);
		break;
	case 4:
		setPosition(randLocation4);
		break;
	}
}

void Player::collisionResponsePickup(GameObject* collider)
{
	//add the necessary ammo back to player
	audio.playSoundbyName("Pickup");
	ammoCount = pickupManager.addAmmo() + ammoCount;
	collider->setPosition(0, 0);

	if (ammoCount > 20)
	{
		ammoCount = 20;
	}

	health = maxHealth;

	std::cout << ammoCount << std::endl;
}

void Player::collisionResponseFragment(GameObject* collider)
{
	audio.playSoundbyName("Fragment");
	fragmentCount = fragmentCount + 1;
	collider->setPosition(0, 0);
	std::cout << fragmentCount << std::endl;
}

void Player::collisionResponsePortal(GameObject* collider)
{
	audio.playSoundbyName("LevelComplete");
	collider->setPosition(-500, 0);
}

//get the health of player for changing the gamestate
int Player::getHealth()
{
	return health;
}

//display health when damaged
void Player::displayHealth()
{
	std::string disHealth = std::to_string(health);
	showHealth = true;

	if (showHealth == true)
	{
		healthText.setPosition(sf::Vector2f(getPosition().x - getSize().x / 2, getPosition().y - 40));
		healthText.setString(disHealth);
		healthText.setCharacterSize(30);
		healthText.setFillColor(sf::Color::Yellow);
	}
}

//display text of how much ammo player has
void Player::displayAmmo()
{
	std::string disHealth = std::to_string(ammoCount);
	showAmmo = true;

	if (showAmmo == true)
	{
		ammoText.setPosition(sf::Vector2f(getPosition().x - getSize().x / 2, getPosition().y - 80));
		ammoText.setString(disHealth);
		ammoText.setCharacterSize(30);
		ammoText.setFillColor(sf::Color::Green);
	}
}

//display how many fragments the player has
void Player::displayFragments()
{
	std::string disHealth = std::to_string(fragmentCount);
	showFrag = true;

	if (showFrag == true)
	{
		fragText.setPosition(sf::Vector2f(getPosition().x - getSize().x / 2, getPosition().y - 40));
		fragText.setString(disHealth);
		fragText.setCharacterSize(30);
		fragText.setFillColor(sf::Color::Magenta);
	}
}

//get the fragment count back to level
int Player::getFragCount()
{
	return fragmentCount;
}

//reset player position and health
void Player::reset()
{
	setPosition(130, 320);
	health = maxHealth;
	fragmentCount = 0;
	ammoCount = 20;
}

//call when player animation for taking damage has played for 1 second
//allows the player to gain control again
void Player::setTakeDamage()
{
	takeDamage = false;
	health = health - 1;
}

void Player::render(sf::RenderWindow* window)
{
	ammoManager.render(window);
	window->draw(fragText);
	window->draw(ammoText);
	window->draw(healthText);
	//if (showAmmo == true)
	//{
	//	window->draw(ammoText);
	//}

	//if (showFrag == true)
	//{
	//	window->draw(fragText);
	//}

	//if (showHealth == true)
	//{
	//	window->draw(healthText);
	//}

	showAmmo = false;
	showFrag = false;
	showHealth = false;
}