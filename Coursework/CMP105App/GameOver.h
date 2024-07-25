#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "framework/GameObject.h"
#include <string>
#include <iostream>
class GameOver :
    public BaseLevel
{
public:

    GameOver(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
    ~GameOver();

    void handleInput(float dt) override;
    void update(float dt) override;
    void render();

private:
    GameObject gameOver;
    sf::Texture texture;

    AudioManager* audio;
};
