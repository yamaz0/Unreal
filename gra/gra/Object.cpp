#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
}
///ustawienie pozycji
void Object::setPosition(float x, float y)
{
	sprite.setPosition(x,y);
}

void Object::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite,state);
}
