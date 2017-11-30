#include "Tile.h"



Tile::Tile(bool x)
{
	sprite.setTexture(Object::getTextures()["background"]);
	sprite.setTextureRect(sf::IntRect(x * size, x * size, size, size));
	collision = x;
}


Tile::~Tile()
{
}
