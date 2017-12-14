#include "Obstacle.h"



Obstacle::Obstacle(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{

}


Obstacle::~Obstacle()
{
}

void Obstacle::update(bool isColision)
{
	if (isColision && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		//player.death();
	{ }
}