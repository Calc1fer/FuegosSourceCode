#pragma once
#include "framework/GameObject.h"
#include "Framework/Collision.h"
#include "Framework/Animation.h"
#include "Framework/VectorHelper.h"

class Fireball :
    public GameObject
{
public:

    Fireball();
    ~Fireball();

    void update(float dt) override;
    void collisionResponse(GameObject* collider);
    void flip(bool flip);


protected:
    Animation idle;
    Animation* currentAnimation;

    sf::Vector2f gravity;
    float scale;
};

