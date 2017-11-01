#pragma once
#include "GameObject.h"
#include"Lever.h"
class Gateway :
	public GameObject
{
	//vector Levers
	std::vector <Lever*> levers;
public:
	Gateway();
	~Gateway();
};

