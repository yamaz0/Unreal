#include "GameObject.h"


GameObject::GameObject(float x, float y, Rotation r,sf::Texture &texture):rotation(r)
{
	collision = false;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x,y));
	sprite.setTextureRect(sf::IntRect(0,0,128,128));
}


std::ostream & operator<<(std::ostream &s, GameObject *o)
{
	std::cout << o->getPosition().x << ", " << o->getPosition().y << std::endl;
	return s;
}

GameObject::~GameObject()
{

}

Rotation GameObject::getRotate()
{
	return rotation;
}