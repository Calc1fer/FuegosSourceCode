#pragma once
#include "framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/VectorHelper.h"

class AntiMatterEnemy :
    public GameObject
{
public:

    AntiMatterEnemy();
    ~AntiMatterEnemy();

    void update(float dt);
    void collisionResponseHit(GameObject* collider);
    void collisionResponsePlayer(GameObject* collider);
    void collisionResponseWorld(GameObject* collider);

protected:
    Animation idle;
    Animation* currentAnimation;
};

