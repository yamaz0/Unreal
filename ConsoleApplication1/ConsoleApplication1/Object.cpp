#include "Object.h"



Object::Object()
{
//	amount++;
}


Object::~Object()
{
	//amount--;
}

void Object::draw(sf::RenderTarget& target, sf::RenderStates state) const 
{
	target.draw(this->sprite,state);
}

int Object::getAmount()
{
	//return amount;
	return 0;
}