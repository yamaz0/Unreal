#pragma once
#include "Object.h"
class GameObject :
	public Object
{
public:

	static enum Rotation{NORTH, SOUTH, EAST, WEST};
	static enum Type{LEVER,GATEWAY,OBSTACLE,PLAYER};
	
	GameObject(float, float, Rotation, Type,sf::Texture &);
	~GameObject();

	Rotation getRotate();

	virtual void update() = 0;

protected:
	bool state;

	const Rotation rotation;
	const Type type;


};