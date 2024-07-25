// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Level.h"
#include "Menu.h"
#include "Pause.h"
#include "GameOver.h"
#include "Win.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"

void windowProcess(sf::RenderWindow* window, Input* in)
{
	// Handle window events.
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			window->setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
			break;
		case sf::Event::KeyPressed:
			// update input class
			in->setKeyDown(event.key.code);
			break;
		case sf::Event::KeyReleased:
			//update input class
			in->setKeyUp(event.key.code);
			break;
		case sf::Event::MouseMoved:
			//update input class
			in->setMousePosition(event.mouseMove.x, event.mouseMove.y);
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setLeftMouse(Input::MouseState::DOWN);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setRightMouse(Input::MouseState::DOWN);
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setLeftMouse(Input::MouseState::UP);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setRightMouse(Input::MouseState::UP);
			}
			break;
		default:
			// don't handle other events
			break;
		}
	}
}

int main()
{
	//Create the window
	//Stopping user from resizing the window
	sf::RenderWindow window(sf::VideoMode(1200, 675), "Fuego's Universal Adventure!", sf::Style::Close);

	// Initialise input and level objects.
	AudioManager audioManager;
	Input input;
	GameState gameState;
	Menu menu(&window, &input, &gameState, &audioManager);
	Level level(&window, &input, &gameState, &audioManager);
	Pause pause(&window, &input, &gameState, &audioManager);
	GameOver gameOver(&window, &input, &gameState, &audioManager);
	Win win(&window, &input, &gameState, &audioManager);

	//set current state to be menu so this is what is seen when game is launched
	gameState.setCurrentState(State::MENU);

	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;

	// Game Loop
	while (window.isOpen())
	{
		//Process window events
		windowProcess(&window, &input);

		// Calculate delta time. How much time has passed 
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();

		// Call standard game loop functions (input, update and render)
		switch (gameState.getCurrentState())
		{
		case(State::MENU) :
			menu.handleInput(deltaTime);
			menu.update(deltaTime);
			menu.render();
			break;
		case(State::LEVEL):
			level.handleInput(deltaTime);
			level.update(deltaTime);
			level.render();
			break;
		case(State::PAUSE) :
			pause.handleInput(deltaTime);
			pause.update(deltaTime);
			pause.render();
			break;
		case(State::GAMEOVER) :
			gameOver.handleInput(deltaTime);
			gameOver.update(deltaTime);
			gameOver.render();
			break;
		case(State::WIN):
			win.handleInput(deltaTime);
			win.update(deltaTime);
			win.render();
			break;
		}


		// Update input class, handle pressed keys
		// Must be done last.
		input.update();
	}

}
