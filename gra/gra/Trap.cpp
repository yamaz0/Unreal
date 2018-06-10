#include "Trap.h"



Trap::Trap(float x, float y, Rotation r,  sf::Texture &texture,int _time) :GameObject(x, y, r, texture), time(_time)
{
	state = true;
	//size = 128;
}


Trap::~Trap()
{
}


void Trap::update(bool a)
{
	if (clock.getElapsedTime().asSeconds() > time)
	{
		state = !state;
		collision = state;
		sprite.setTextureRect(sf::IntRect(state*size, rotation*size, size, size));
		clock.restart();
	}

}
