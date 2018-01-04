#include "Field.h"

Field::Field(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{

	
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
		else if (type == CHECKPOINT)
		{
			//sprite.setTextureRect(cos tam);
		}
	}
}
