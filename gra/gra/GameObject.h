#pragma once
#include "Object.h"
class GameObject :
	public Object
{
	static int amountOfObject;
public:

	static enum Rotation{NORTH, SOUTH, EAST, WEST};
	static enum Type{LEVER,GATEWAY,OBSTACLE,PLAYER};
	
	GameObject(float, float, Rotation, Type);
	~GameObject();
	int getAmount();

	Rotation getRotate();

	virtual void update() = 0;

protected:
	bool state;

	int id;

	const Rotation rotation;
	const Type type;


};

