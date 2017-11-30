#pragma once
#include"GameObject.h"
class Player :
	public GameObject
{
public:
	Player(float, float, Rotation, Type);
	~Player();
	void update();
};

