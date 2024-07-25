#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>
class Win :
    public BaseLevel
{
public:

    Win(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
    ~Win();

    void handleInput(float dt) override;
    void update(float dt) override;
    void render();

private:
    GameObject levelwin;
    sf::Texture texture;

    AudioManager* audio;
};

