#pragma once
#include"Tile.h"
class Map
{
	std::vector <Tile*> tiles;

public:
	Map();
	~Map();
	bool loadMap();
	bool saveMap();
	void drawMap();
};

