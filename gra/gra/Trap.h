#pragma once
#include "GameObject.h"
class Trap :
	public GameObject
{
	int time = 1;
	sf::Clock clock; 
public:
	Trap(float, float, Rotation, sf::Texture &, int);
	~Trap();
	void update(bool);
};

