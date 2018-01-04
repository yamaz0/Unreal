#pragma once
#include "GameObject.h"
class Field :
	public GameObject
{
public:
	Field(float x, float y, Rotation r, Type t, sf::Texture &texture);
	~Field();
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	void update(bool);
};

