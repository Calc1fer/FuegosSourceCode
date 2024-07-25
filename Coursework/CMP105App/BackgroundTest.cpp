#include "BackgroundTest.h"
#include <iostream>

//constructor
BackgroundTest::BackgroundTest()
{
	speedx = 0;
	speedy = 0;
	delay = 100;
	position = 0;
}

//deconstructor
BackgroundTest::~BackgroundTest()
{

}

//update function
//pass a ref to the player so we can determine when and how to move the camera view
void BackgroundTest::update(float dt, GameObject player)
{
	sf::View view = window->getView();
	view.setCenter(player.getPosition());

	//get the player velocities for movement of camera
	speedx = player.getVelocity().x * 2;
	speedy = player.getVelocity().y;

	//move with the player, decelerate at the view catches up to the player, and speed up if the player is falling
	sf::Vector2f movement = player.getPosition() - view.getCenter();

	view.move(movement * dt);

	window->setView(view);
}