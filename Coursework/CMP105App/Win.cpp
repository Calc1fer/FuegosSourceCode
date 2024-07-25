#include "Win.h"

//constructor
Win::Win(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	texture.loadFromFile("gfx/levelwin.png");
	levelwin.setSize(sf::Vector2f(1200, 675));
	levelwin.setPosition(0, 0);
	levelwin.setTexture(&texture);
}

//deconstructor
Win::~Win()
{

}

//update
void Win::update(float dt)
{
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio->playMusicbyName("backTrack");
	}

	sf::View view = window->getView();
	view.setCenter(levelwin.getSize().x / 2, levelwin.getSize().y / 2);

	window->setView(view);
}

//handle user input
void Win::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Q))
	{
		exit(0);
	}

	if (input->isPressed(sf::Keyboard::P))
	{
		gameState->setCurrentState(State::MENU);

	}
}

//render to the window
void Win::render()
{
	beginDraw();
	window->draw(levelwin);
	endDraw();
}