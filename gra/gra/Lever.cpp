#include "Lever.h"


Lever::Lever(float x, float y, GameObject::Rotation r, GameObject::Type t,sf::Texture &texture) :GameObject(x, y, r, t,texture)
{
	//amountOfObject++;
	sprite.setTextureRect(sf::IntRect(0,0,size,size));
}


Lever::~Lever()
{
//	amountOfObject--;
}
//int Lever::getAmount()
//{
//	//return 0;
//	return amountOfObject;
//}

void Lever::switchLever()
{
	state = !state;
}
void Lever::update()
{

}