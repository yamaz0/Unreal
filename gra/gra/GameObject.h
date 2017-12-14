#pragma once
#include "Object.h"

enum Rotation { NORTH, SOUTH, EAST, WEST };
enum Type { LEVER, GATEWAY, OBSTACLE, PLAYER };

class GameObject :
	public Object
{
public:

	GameObject(float, float, Rotation, Type,sf::Texture &);
	~GameObject();
	///zwraca w ktorym kierunku jest zwrocony obiekt
	Rotation getRotate();
	///zwraca jakiego typu jest obiekt
	Type getType() { return type; }
	///funkcja czysto wirtualna 
	virtual void update(bool) = 0;

protected:
	bool state;

	const Rotation rotation;
	const Type type;


};