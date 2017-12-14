#include "Colision.h"


Colision::Colision()
{

}



Colision::~Colision()
{
}

bool Colision::isColision(GameObject* obj1, GameObject* obj2)
{
	return obj1->getSprite().getGlobalBounds().contains(obj2->getSprite().getPosition().x, obj2->getSprite().getPosition().y);
}