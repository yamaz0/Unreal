#include "Lever.h"


Lever::Lever(float x, float y, Rotation r, Type t,sf::Texture &texture) :GameObject(x, y, r, t,texture)
{
	sprite.setTextureRect(sf::IntRect(0,0,size,size));
}


Lever::~Lever()
{

}

void Lever::switchLever()
{
	state = !state;
}
void Lever::update(bool isColision)
{
	//je�li player stoi i klika enter to switchlever
	if(isColision && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	switchLever();
}