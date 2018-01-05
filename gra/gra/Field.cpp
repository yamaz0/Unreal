#include "Field.h"

Field::Field(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{
	size = 64;//wielkosc obiektu
	state = false;//stan nieaktywny
	sprite.setTextureRect(sf::IntRect(state * 64, 0, size, size));

}


Field::~Field()
{
}
void Field::update(bool isColision)
{
	if (isColision)//jesli kolizja z graczem
	{
		if (type == END)
		{
			//animacja albo dzwiek wygranej
		}
		state = true;//stan aktywny

		sprite.setTextureRect(sf::IntRect(state * 64, 0, size, size));//zmiana tekstury
	}
}
