#include "Gateway.h"



Gateway::Gateway(float x, float y, Rotation r, Type t, VecLever &levers_, sf::Texture &texture) :GameObject(x, y, r, t, texture),levers(levers_)
{
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));

	//suma wszystkich value od levers

}


Gateway::~Gateway()
{
}

void Gateway::update(bool isColision)
{
	if (isColision && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		//napisz przejscie zamkniete poszukaj dzwigni

	}

	short suma = 0;
	for(auto it = levers.begin(); it != levers.end(); it++)
	{
		suma += (*it).getValue();
	}
	if (suma == gateValue)
		state = false;
	else
		state = true;

}