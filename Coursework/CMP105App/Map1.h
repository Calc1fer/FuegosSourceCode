#pragma once
#include "Framework/GameObject.h"
#include "framework/TileMap.h"
#include <vector>
#include "Player.h"

class Map1 :
    public TileMap
{
public:

    Map1();

    GameObject getTileSet();
};

