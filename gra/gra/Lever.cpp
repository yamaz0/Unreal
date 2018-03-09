#include "Lever.h"


Lever::Lever(float x, float y, Rotation r, int value_, sf::Texture &texture) :GameObject(x, y, r, texture),value(value_)
{
	state = true;
	sprite.setTextureRect(sf::IntRect(state*size,r*size,size,size));
}


Lever::~Lever()
{

}

void Lever::switchLever()
{
	state = !state;
	sprite.setTextureRect(sf::IntRect(state*size, rotation*size, size, size));
}
void Lever::update(bool isColision)
{
	//jeœli player stoi i klika enter to switchlever
	if (isColision && !enterIsPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		enterIsPressed = true;	
		switchLever();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		enterIsPressed = false;
}