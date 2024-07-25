#pragma once
#include "framework/GameObject.h"
class BackgroundTest :
    public GameObject
{
public:

    BackgroundTest();
    ~BackgroundTest();

    void update(float dt, GameObject player);

private:
    int speedx;
    int speedy;
    int delay;
    float position;
};

