#include "Gateway.h"
#include<iostream>


Gateway::Gateway(float x, float y, Rotation r,  VecLever &levers_ ,sf::Texture &texture) :GameObject(x, y, r, texture),levers(levers_)
{
	state = true;
	sprite.setTextureRect(sf::IntRect(state*size, r*size, size, size));
	collision = true;

	//suma wszystkich value od levers

}


Gateway::~Gateway()
{
}

void Gateway::update(bool isColision)
{
	if (isColision && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		//przejscie zamkniete poszukaj dzwigni

	}

	//sprawdzanie czy mozna otworzyc drzwi
	bool isOpen = true;
	for (auto it = levers.begin(); it != levers.end() && isOpen; it++)
	{
		if (!(*it)->getState())
		{
			isOpen = false;
		}
	}
	if (isOpen)
	{
		state = false;
		collision = false;
		sprite.setTextureRect(sf::IntRect(size, rotation*size, size, size));
	}
	else
	{
		collision = true;
		state = true;
		sprite.setTextureRect(sf::IntRect(0, rotation*size, size, size));
	}

	//std::cout << suma << "<od dzwigni od drzwi>"<<gateValue << std::endl;

}