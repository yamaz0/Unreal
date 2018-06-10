#pragma once
#include "Lever.h"
class Buton :
	public Lever
{
	sf::Clock clock;
	int time = 10;
public:
	Buton(float, float, Rotation, sf::Texture &,int);
	~Buton();

	void update(bool);

};

