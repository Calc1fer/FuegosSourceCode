#pragma once
#include "Fragment.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
#include <math.h>
#include <vector>
class FragmentManager
{
public:

	FragmentManager();
	~FragmentManager();

	void spawn();
	void update(float dt);
	void render(sf::RenderWindow* window);
	std::vector<Fragment>* getFragment();
	void setLifted();
	void reset();

protected:
	std::vector<Fragment> fragments;
	sf::Texture texture;
	int numFragment = 3;

	sf::Vector2f spawnPoint1;
	sf::Vector2f spawnPoint2;
	sf::Vector2f spawnPoint3;
	sf::Vector2f location;

	bool lifted;
};

