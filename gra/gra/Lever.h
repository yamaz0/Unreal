#pragma once
#include "GameObject.h"
class Lever: 
	public GameObject
{
	//static int amountOfObject;

public:
	//static int getAmount();

	Lever(float, float, Rotation, Type,sf::Texture &);
	~Lever();
	void switchLever();
	virtual void update();
};

//int Lever::amountOfObject = 0;

