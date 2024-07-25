#include "Menu.h"

//constructor
Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	texture.loadFromFile("gfx/MainMenu.png");
	mainMenu.setSize(sf::Vector2f(1200, 675));
	mainMenu.setPosition(0,0);
	mainMenu.setTexture(&texture);
}

//deconstructor
Menu::~Menu()
{

}

//update
void Menu::update(float dt)
{
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio->playMusicbyName("backTrack");
	}

	sf::View view = window->getView();
	view.setCenter(mainMenu.getSize().x / 2, mainMenu.getSize().y / 2);

	window->setView(view);
}

//handle user input
void Menu::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Escape))
	{
		exit(0);
	}

	if (input->isPressed(sf::Keyboard::P))
	{
		gameState->setCurrentState(State::LEVEL);

	}
}

//render to the window
void Menu::render()
{
	beginDraw();
	window->draw(mainMenu);
	endDraw();
}