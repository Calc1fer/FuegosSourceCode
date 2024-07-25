#pragma once
#include "framework/GameObject.h"
#include "framework/Collision.h"
#include "Framework/Animation.h"

class AmmoPickup :
    public GameObject
{
public:

    AmmoPickup();
    ~AmmoPickup();

    void update(float dt) override;
    void collisionResponse(GameObject* collider);

protected:
    Animation idle;
    Animation* currentAnimation;

    sf::Texture texture;
};

