#include "GameObject.h"


GameObject::GameObject(float x, float y, Rotation r,Type t,sf::Texture &texture):rotation(r),type(t)
{
	collision = false;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x,y));
	sprite.setTextureRect(sf::IntRect(0,0,128,128));
}


GameObject::~GameObject()
{

}

Rotation GameObject::getRotate()
{
	return rotation;
}