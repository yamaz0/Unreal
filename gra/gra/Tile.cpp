#include "Tile.h"



Tile::Tile(bool x,sf::Texture &texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, x * size, size, size));
	collision = x;
}


Tile::~Tile()
{
}
