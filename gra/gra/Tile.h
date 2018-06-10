#pragma once
#include "Object.h"
 class Tile :
	public Object
{

public:

	///0-floor,1-wall
	Tile(bool, sf::Texture &);
	~Tile();

};

