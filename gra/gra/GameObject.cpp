#include "GameObject.h"



GameObject::GameObject(float x, float y, GameObject::Rotation r,GameObject::Type t):rotation(r),type(t)
{
	amountOfObject++;
	id = amountOfObject;
	sprite.setPosition(sf::Vector2f(x,y));
}


GameObject::~GameObject()
{
	amountOfObject--;
}


int GameObject::getAmount()
{
	//return 0;
	return amountOfObject;
}
GameObject::Rotation GameObject::getRotate()
{
	return rotation;
}