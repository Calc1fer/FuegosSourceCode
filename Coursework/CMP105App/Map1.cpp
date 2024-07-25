#include "Map1.h"

//constructor
Map1::Map1()
{
	//load texture
	texture.loadFromFile("gfx/TestMap.png");
	//texture.setSmooth(true); //I used this and when the view moves, horizontal lines appear. Deactivating this seemed to solve my problem

	GameObject map;

	//set the sizes for specific tiles
	for (int i = 0; i < 9; i++)
	{
		map.setSize(sf::Vector2f(100, 100));
		map.setCollisionBox(sf::FloatRect(0, 0, 90, 90));
		map.setCollider(true);
		tileSet.push_back(map);
	}

	//set size for tiles that will be used as columns
	//for (int i = 6; i < 9; i++)
	//{
	//	map.setSize(sf::Vector2f(80, 50));
	//	map.setCollisionBox(0, 0, 80, 50);
	//	map.setCollider(true);
	//	tileSet.push_back(map);
	//}

	//create the tileSet
	tileSet[0].setCollider(false);
	tileSet[0].setTextureRect(sf::IntRect(0, 400, 300, 100));
	tileSet[1].setTextureRect(sf::IntRect(0, 0, 300, 100));
	tileSet[2].setTextureRect(sf::IntRect(0, 100, 300, 100));
	tileSet[3].setTextureRect(sf::IntRect(0, 200, 300, 100));
	tileSet[4].setTextureRect(sf::IntRect(0, 300, 300, 100));
	tileSet[5].setTextureRect(sf::IntRect(300, 0, 160, 100));
	tileSet[6].setTextureRect(sf::IntRect(300, 100, 160, 100));
	tileSet[7].setTextureRect(sf::IntRect(300, 200, 160, 100));
	tileSet[8].setTextureRect(sf::IntRect(300, 300, 160, 100));

	//temporary map dimensions
	mapDimensions = sf::Vector2u(31, 20);

	//build the map here
	tileMap = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4,
		0, 1, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 4,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 1, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 4,
		1, 0, 0, 0, 1, 4, 4, 4, 4, 4, 8, 0, 0, 0, 0, 0, 4, 4, 4, 4, 2, 0, 0, 0, 0, 0, 4, 0, 1, 4, 4,
		4, 2, 0, 0, 0, 7, 8, 7, 8, 7, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 0, 0, 0, 0, 4, 0, 0, 4, 4,
		4, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 1, 2, 4, 2, 0, 0, 4,
		4, 4, 4, 4, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 2, 0, 8, 7, 4, 0, 0, 0, 4,
		4, 8, 7, 8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4,
		4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4,
		7, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 4, 0, 3, 0, 0, 0, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4,
		0, 0, 0, 0, 0, 1, 4, 0, 0, 1, 4, 8, 0, 8, 0, 3, 0, 0, 4, 8, 0, 3, 0, 0, 0, 0, 4, 4, 4, 4, 4,
		0, 0, 0, 0, 1, 4, 4, 0, 1, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 8, 0, 3, 0, 0, 0, 0, 0, 4, 4,
		1, 2, 4, 4, 4, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 8, 3, 0, 0, 0, 0, 4, 4,
		4, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 4, 4, 4, 2, 0, 0, 0, 0, 8, 1, 2, 0, 0, 4, 4,
		4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4, 0, 7, 8, 7, 8, 0, 1, 4, 0, 0, 0, 0, 0, 1, 4, 4,
		4, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 1, 0, 1, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4,
		4, 0, 0, 4, 4, 2, 0, 4, 4, 4, 4, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 3, 0, 3, 0, 4, 4,
		4, 0, 1, 4, 4, 4, 0, 8, 7, 8, 7, 8, 0, 7, 8, 0, 0, 0, 0, 0, 0, 4, 2, 0, 1, 4, 0, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 0, 7, 8, 7, 8,
		7, 8, 7, 8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	setPosition(sf::Vector2f(0, 0));
	buildLevel();
}

//return a reference of each tile back to level
GameObject Map1::getTileSet()
{
	for (int i = 0; i < tileSet.size(); i++)
	{
		return tileSet[i];
	}
}