#include "Lever.h"


Lever::Lever()
{
	sprite.setTexture(Object::getTextures()["lever"]);
	sprite.setTextureRect(sf::IntRect(0,0,size,size));
}


Lever::~Lever()
{
}

void Lever::switchLever()
{
	state = !state;
}
