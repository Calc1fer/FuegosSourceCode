#pragma once
#include "framework/GameObject.h"
#include "Framework/Collision.h"
#include "Framework/Animation.h"
class Portal :
    public GameObject
{
public:

    Portal();
    ~Portal();

    void update(float dt) override;
    void collisionResponse(GameObject* collider);

protected:

    Animation idle;
    Animation* currentAnimation;
};

