#pragma once
#include "GameObject.h"
#include"Lever.h"
class Gateway :
	public GameObject
{

	//vector Levers
	std::vector <int> levers;
public:
	Gateway(float, float, Rotation, Type, std::vector <int>&, sf::Texture &);
	~Gateway();
	std::vector<int> getLeversId() { return levers; }
	virtual void update();
};

