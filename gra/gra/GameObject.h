#pragma once
#include "Object.h"

enum Rotation { NORTH, SOUTH, EAST, WEST };
enum Type { LEVER, GATEWAY, OBSTACLE, PLAYER, END, CHECKPOINT, ACTIVATOR };

class GameObject :
	public Object
{
public:

	GameObject(float, float, Rotation, Type,sf::Texture &);
	~GameObject();
	/// zwraca w ktorym kierunku jest zwrocony obiekt
	Rotation getRotate();
	/// zwraca jakiego typu jest obiekt
	Type getType() { return type; }
	/// funkcja czysto wirtualna. Aktualizuje stan obiektu 
	virtual void update(bool) = 0;

	bool isColider() { return collision; }

protected:
	bool state;

	Rotation rotation;
	const Type type;



};