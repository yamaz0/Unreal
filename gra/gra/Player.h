#pragma once
#include"GameObject.h"
class Player :
	public GameObject
{
public:
	Player(float, float, Rotation, Type, sf::Texture &);
	~Player();
	virtual void update(bool);
};

