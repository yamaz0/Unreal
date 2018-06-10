#include "Buton.h"



Buton::Buton(float x, float y, Rotation r, sf::Texture &texture,int _time) :Lever(x, y, r, texture),time(_time)
{
}


Buton::~Buton()
{
}

void Buton::update(bool col)
{
	if (!state)
		Lever::update(col);
	else if (clock.getElapsedTime().asSeconds() > time)
	{
		switchLever();
		clock.restart();	
	}
	std::cout << this->getState()<<std::endl;
}
