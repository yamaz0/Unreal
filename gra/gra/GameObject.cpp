#include "GameObject.h"


GameObject::GameObject(float x, float y, Rotation r,Type t,sf::Texture &texture):rotation(r),type(t)
{
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x,y));
}


GameObject::~GameObject()
{

}

Rotation GameObject::getRotate()
{
	return rotation;
}