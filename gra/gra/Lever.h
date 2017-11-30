#pragma once
#include "GameObject.h"
class Lever: 
	public GameObject
{
public:
	Lever(float, float, Rotation, Type);
	~Lever();
	void switchLever();
	void update();
};

