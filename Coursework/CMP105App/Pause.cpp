#include "Pause.h"

//constructor
Pause::Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	texture.loadFromFile("gfx/pauseMenu.png");
	pauseMenu.setSize(sf::Vector2f(1200, 675));
	pauseMenu.setPosition(0, 0);
	pauseMenu.setTexture(&texture);
}

//deconstructor
Pause::~Pause()
{

}

//update
void Pause::update(float dt)
{
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio->playMusicbyName("backTrack");
	}

	sf::View view = window->getView();
	view.setCenter(pauseMenu.getSize().x / 2, pauseMenu.getSize().y / 2);

	window->setView(view);
}

//handle user input for the pause menu
void Pause::handleInput(float dt)
{
	//unpauses the level and returns to where the player left off
	if (input->isPressed(sf::Keyboard::P))
	{
		gameState->setCurrentState(State::LEVEL);
	}

	if (input->isPressed(sf::Keyboard::Q))
	{
		exit(0);
	}
}

//render to the window
void Pause::render()
{
	beginDraw();
	window->draw(pauseMenu);
	endDraw();
}