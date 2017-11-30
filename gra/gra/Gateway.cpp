#include "Gateway.h"



Gateway::Gateway(float x, float y, GameObject::Rotation r, GameObject::Type t, std::vector <int>&levers_):GameObject(x,y,r,t),levers(levers_)
{
	sprite.setTexture(Object::getTextures()["gateway"]);
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));
}


Gateway::~Gateway()
{
}

void Gateway::update()
{
	//jesli dzwignie beda mykniete to przejscie sie otwiera
}