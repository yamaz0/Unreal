#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
}

void Object::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite,state);
}
