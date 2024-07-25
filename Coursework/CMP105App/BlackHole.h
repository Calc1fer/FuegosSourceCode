#pragma once
#include "framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/VectorHelper.h"

class BlackHole :
    public GameObject
{
public:

    BlackHole();
    ~BlackHole();

    void update(float dt) override;
    void collisionResponseHit(GameObject* collider);
    void collisionResponsePlayer(GameObject* collider);
    void collisionResponseWorld(GameObject* collider);

protected:
    Animation idle;
    Animation* currentAnimation;
};

