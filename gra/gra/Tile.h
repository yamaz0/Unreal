#pragma once
#include "Object.h"
 class Tile :
	public Object
{

public:

	///1-floor,2-wall
	Tile(bool);
	~Tile();

};

