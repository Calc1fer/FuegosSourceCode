#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	playerTexture.loadFromFile("gfx/PlayerSpriteSheet.png");
	playerTexture.setSmooth(false);	//doesn't make it look smoother, just blurry ;)
	player.setSize(sf::Vector2f(80, 80));
	player.setPosition(130, 320);
	player.setTexture(&playerTexture);
	player.setInput(input);
	player.setWindow(window);

	backTexture.loadFromFile("gfx/LevelBackground.png");
	background.setTexture(&backTexture);
	background.setPosition(sf::Vector2f(-1500, -500));
	background.setSize(sf::Vector2f(10000, 6000));
	background.setWindow(window);
	background.setInput(input);

	controlTexture.loadFromFile("gfx/controls.png");
	controls.setSize(sf::Vector2f(380, 480));
	controls.setPosition(player.getPosition().x - 550, 80);
	controls.setTexture(&controlTexture);

	aTexture.loadFromFile("gfx/Ammo.png");
	ammoKey.setSize(sf::Vector2f(80, 80));
	ammoKey.setPosition(player.getPosition().x - 300, 360);
	ammoKey.setTexture(&aTexture);

	fTexture.loadFromFile("gfx/FragmentSpriteSheet.png");
	fragKey.setSize(sf::Vector2f(60, 60));
	fragKey.setPosition(player.getPosition().x - 400, 360);
	fragKey.setTexture(&fTexture);

	pTexture.loadFromFile("gfx/PortalSpriteSheet.png");
	portalKey.setSize(sf::Vector2f(100, 80));
	portalKey.setPosition(player.getPosition().x - 550, 360);
	portalKey.setTexture(&pTexture);

	audio->addMusic("sfx/MusicScore.wav", "backTrack");
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//pause the game here when user presses p
	if (input->isPressed(sf::Keyboard::P))
	{
		gameState->setCurrentState(State::PAUSE);
	}
}

// Update game objects
void Level::update(float dt)
{
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio->playMusicbyName("backTrack");
	}

	//get the references of objects in order to determine collisions
	std::vector<Fireball>* ammos = player.getAmmo();
	std::vector<AntiMatterEnemy>* enemies = enemyManager.getEnemy();
	std::vector<BlackHole>* obstacles = obstacleManager.getBlackHole();
	std::vector<AmmoPickup>* pickup = pickupManager.getPickup();
	std::vector<Fragment>* fragments = fragmentManager.getFragment();
	Portal portal = portalManager.getPortal();

	if (Collision::checkBoundingBox(&player, &portal))
	{
		player.collisionResponsePortal(&portal);

		gameState->setCurrentState(State::WIN);
		player.reset();
		enemyManager.reset();
		portalManager.reset();
		pickupManager.reset();
		fragmentManager.reset();
	}


	//loop through the vector of fragment pickups and check if they have collided with player
	for (int i = 0; i < fragments->size(); i++)
	{
		Fragment& currentFragment = (fragments->at(i));

		if (Collision::checkBoundingBox(&player, &currentFragment))
		{
			fragmentManager.setLifted();
			player.collisionResponseFragment(&currentFragment);
			currentFragment.collisionResponse(&player);
			player.displayFragments();
		}
	}

	//loop through the vector of ammo pickups and check if they have collided with player
	for (int i = 0; i < pickup->size(); i++)
	{
		AmmoPickup& currentPickup = (pickup->at(i));

		if (Collision::checkBoundingBox(&player, &currentPickup))
		{
			pickupManager.setLifted();
			player.collisionResponsePickup(&currentPickup);
			currentPickup.collisionResponse(&player);
			player.displayAmmo();
			player.displayHealth();
		}
	}

	//loop through the ammo vector and enemy vector to see if a collision has occurred between ALIVE fireballs and enemies
	//if there has been a collision, then resolve this by calling the relevant collision responses
	for (int i = 0; i < ammos->size(); i++)
	{
		for (int j = 0; j < enemies->size(); j++)
		{
			Fireball & currentFireball = (ammos->at(i));
			AntiMatterEnemy& currentEnemy = (enemies->at(j));

			if (currentFireball.isAlive() && currentEnemy.isAlive())
			{
				if (Collision::checkBoundingBox(&currentFireball, &currentEnemy))
				{
					//call enemy manager to set enemies to no longer spawn when enemy is killed
					enemyManager.setKilled();
					currentEnemy.collisionResponseHit(&currentFireball);
					currentFireball.collisionResponse(&currentEnemy);
				}
			}

			if (currentEnemy.isAlive())
			{
				if (Collision::checkBoundingBox(&player, &currentEnemy))
				{
					//damage the player when colliding with enemy
					player.displayHealth();
					player.collisionResponseEnemy(&currentEnemy);
					currentEnemy.collisionResponsePlayer(&player);
				}
			}
		}
	}

	//check if the obstacle blackholes have collided with the world, ammo or player
	for (int i = 0; i < obstacles->size(); i++)
	{
		BlackHole& currentObstacle = (obstacles->at(i));

		//check for collision between the player and the obstacles
		if (Collision::checkBoundingBox(&player, &currentObstacle))
		{
			player.collisionResponseObstacle(&currentObstacle);
		}

		for (int j = 0; j < ammos->size(); j++)
		{
			Fireball& currentFireball = (ammos->at(j));

			if (Collision::checkBoundingBox(&currentFireball, &currentObstacle))
			{
				currentFireball.collisionResponse(&currentObstacle);
				currentObstacle.collisionResponseHit(&currentFireball);
			}
		}
	}

	//pass the reference of tile to the player class to determine the collision response
	std::vector<GameObject>* world = map1.getLevel();
	for (int i = 0; i < (int)world->size(); i++)
	{
		//if a collision check occurs
		if ((*world)[i].isCollider())
		{
			if (Collision::checkBoundingBox(&player, &(*world)[i]))
			{
				player.collisionResponseWorld(&(*world)[i]);
			}
		}

		//check if the enemy has collided with the world tiles
		for (int j = 0; j < enemies->size(); j++)
		{
			AntiMatterEnemy& currentEnemy = (enemies->at(j));

			//if a collision check occurs
			if ((*world)[i].isCollider())
			{
				if (Collision::checkBoundingBox(&currentEnemy, &(*world)[i]))
				{
					currentEnemy.collisionResponseWorld(&(*world)[i]);
				}
			}
		}

		//check if ammo has collided with the world tiles
		for (int k = 0; k < ammos->size(); k++)
		{
			Fireball& currentFireball = (ammos->at(k));

			//if a collision check occurs
			if ((*world)[i].isCollider())
			{
				if (Collision::checkBoundingBox(&currentFireball, &(*world)[i]))
				{
					currentFireball.collisionResponse(&(*world)[i]);
				}
			}
		}

		for (int l = 0; l < obstacles->size(); l++)
		{
			BlackHole& currentObstacle = (obstacles->at(l));

			//if a collision check occurs
			if ((*world)[i].isCollider())
			{
				if (Collision::checkBoundingBox(&currentObstacle, &(*world)[i]))
				{
					currentObstacle.collisionResponseWorld(&(*world)[i]);
				}
			}
		}
	}

	//end the game when the player health reaches 0
	if (player.getHealth() <= 0)
	{
		gameState->setCurrentState(State::GAMEOVER);
		player.reset();
		enemyManager.reset();
		portalManager.reset();
		pickupManager.reset();
		fragmentManager.reset();
	}

	//make portal appear for player to complete level when they have collected all fragments
	player.getFragCount();
	if (player.getFragCount() == 3)
	{
		portalManager.spawn();
	}

	if (player.getPosition().y >= deathHeight)
	{
		gameState->setCurrentState(State::GAMEOVER);

		//call reset functions here
		player.reset();
		enemyManager.reset();
		portalManager.reset();
		pickupManager.reset();
		fragmentManager.reset();
	}

	//std::cout << player.getPosition().x << " " << player.getPosition().y << std::endl;

	//update the objects and managers
	player.update(dt);
	player.handleInput(dt);
	obstacleManager.update(dt);
	enemyManager.update(dt);
	pickupManager.update(dt);
	background.update(dt, player);
	portalManager.update(dt);
	fragmentManager.update(dt);
	controls.update(dt);
	ammoKey.update(dt);
	fragKey.update(dt);
	portalKey.update(dt);
}

// Render level
void Level::render()
{
	//render in order I want to display game elements (layers)
	beginDraw();
	window->draw(background);
	map1.render(window);
	window->draw(player);
	player.render(window);
	obstacleManager.render(window);
	enemyManager.render(window);
	pickupManager.render(window);
	portalManager.render(window);
	fragmentManager.render(window);
	window->draw(controls);
	window->draw(ammoKey);
	window->draw(fragKey);
	window->draw(portalKey);
	endDraw();
}

