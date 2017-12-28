#include "Colision.h"
#include<iostream>

Colision::Colision()
{

}



Colision::~Colision()
{
	delete[] map;
}

bool Colision::isColision(GameObject* obj1)
{
		std::cout << obj1->getSprite().getPosition().x / 128;
	switch (obj1->getRotate())
	{
	case NORTH:
		return map[int(obj1->getSprite().getPosition().x  / 128)][int(obj1->getSprite().getPosition().y / 128)]
			|| map[int((obj1->getSprite().getPosition().x + obj1->getSize()) / 128)][int(obj1->getSprite().getPosition().y / 128)];
		break;
	case SOUTH:
		return map[int(obj1->getSprite().getPosition().x / 128)][int((obj1->getSprite().getPosition().y + obj1->getSize()) / 128)]
			|| map[int((obj1->getSprite().getPosition().x + obj1->getSize()) / 128)][int((obj1->getSprite().getPosition().y + obj1->getSize()) / 128)];
		break;
	case EAST:
		return map[int((obj1->getSprite().getPosition().x + obj1->getSize()) / 128)][int(obj1->getSprite().getPosition().y / 128)]
			|| map[int((obj1->getSprite().getPosition().x + obj1->getSize()) / 128)][int((obj1->getSprite().getPosition().y + obj1->getSize()) / 128)];
		break;
	case WEST:
		return map[int(obj1->getSprite().getPosition().x / 128)][int(obj1->getSprite().getPosition().y / 128)]
			|| map[int(obj1->getSprite().getPosition().x / 128)][int((obj1->getSprite().getPosition().y + obj1->getSize()) / 128)];
		break;
	}
}

bool Colision::isColision(GameObject* obj1, GameObject* obj2)
{
	return (obj1->getSprite().getPosition().x + obj1->getSize() > obj2->getSprite().getPosition().x
		&& obj1->getSprite().getPosition().x < obj2->getSprite().getPosition().x + obj2->getSize()
		&& obj1->getSprite().getPosition().y + obj1->getSize() > obj2->getSprite().getPosition().y
		&& obj1->getSprite().getPosition().y < obj2->getSprite().getPosition().y + obj2->getSize()
		);
}