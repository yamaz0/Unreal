#include "Gateway.h"
#include<iostream>


Gateway::Gateway(float x, float y, Rotation r, Type t, VecLever &levers_,short value ,sf::Texture &texture) :GameObject(x, y, r, t, texture),levers(levers_),gateValue(value)
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
	short suma = 0;
	for (auto it = levers.begin(); it != levers.end(); it++)
	{
		suma += (**it).getValue();
	}
	if (suma == gateValue)
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