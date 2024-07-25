#pragma once
#include "framework/GameObject.h"
#include "Framework/Collision.h"
#include "Framework/Animation.h"

class Fragment :
    public GameObject
{
public:

    Fragment();
    ~Fragment();

    void update(float dt) override;
    void collisionResponse(GameObject* collider);

protected:

    Animation idle;
    Animation* currentAnimation;
};

