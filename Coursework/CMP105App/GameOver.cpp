#include "GameOver.h"
//constructor
GameOver::GameOver(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	texture.loadFromFile("gfx/gameOver.png");
	gameOver.setSize(sf::Vector2f(1200, 675));
	gameOver.setPosition(0, 0);
	gameOver.setTexture(&texture);
}

//deconstructor
GameOver::~GameOver()
{

}

//update
void GameOver::update(float dt)
{
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio->playMusicbyName("backTrack");
	}

	sf::View view = window->getView();
	view.setCenter(gameOver.getSize().x / 2, gameOver.getSize().y / 2);

	window->setView(view);
}

//handle user input for the gameOver screen
void GameOver::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::P))
	{
		gameState->setCurrentState(State::MENU);
	}

	if (input->isPressed(sf::Keyboard::Q))
	{
		exit(0);
	}
}

//render to the window
void GameOver::render()
{
	beginDraw();
	window->draw(gameOver);
	endDraw();
}