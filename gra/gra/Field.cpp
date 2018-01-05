#include "Field.h"

Field::Field(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{
	size = 64;
	state = false;
	sprite.setTextureRect(sf::IntRect(state * 64, 0, size, size));

}


Field::~Field()
{
}
void Field::update(bool isColision)
{
	if (isColision)
	{
		if (type == END)
		{
			//animacja albo dzwiek wygranej
		}
		state = true;

		sprite.setTextureRect(sf::IntRect(state * 64, 0, size, size));
	}
	else
		state = false;
}
