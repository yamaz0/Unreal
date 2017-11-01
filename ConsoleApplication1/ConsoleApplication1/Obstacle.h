#pragma once
#include "GameObject.h"
#include "Path.h"
class Obstacle :
	public GameObject
{
	Path path;

public:
	Obstacle();
	~Obstacle();


};

