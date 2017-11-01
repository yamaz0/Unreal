#pragma once
#include "Object.h"
class GameObject :
	public Object
{

protected:
	bool state;
	enum Rotation{NORTH, EAST, WEST, SOUTH};

public:
	GameObject();
	~GameObject();

	Rotation rotate(Rotation);
};

