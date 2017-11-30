#pragma once
#include "GameObject.h"
#include "Path.h"
class Obstacle :
	public GameObject
{

	Path path;

public:
	Obstacle(float, float, Rotation, Type, sf::Texture &);
	~Obstacle();
	virtual void update();


};

