#include "Colision.h"


Colision::Colision()
{

}



Colision::~Colision()
{
}

bool Colision::isColision(GameObject* obj1, GameObject* obj2)
{
	return false;
	//return (obj1->getSprite().getPosition().x > obj2->getSprite().getPosition().x
		//&&obj1->getSprite().getPosition().x + obj1->getSize() < obj2->getSprite().getPosition().x + obj2->getSize()
		//&& obj1->getSprite().getPosition().y > obj2->getSprite().getPosition().y
		//&&obj1->getSprite().getPosition().y + obj1->getSize() < obj2->getSprite().getPosition().y + obj2->getSize()
		//)
}