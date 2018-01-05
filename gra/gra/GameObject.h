#pragma once
#include "Object.h"

enum Rotation { NORTH, SOUTH, EAST, WEST };
enum Type { LEVER, GATEWAY, OBSTACLE, PLAYER, END, CHECKPOINT, ACTIVATOR };

class GameObject :
	public Object
{
public:
	///Konsturktor parametry: pozycja x,y ,zwrot,typ,tekstura
	GameObject(float, float, Rotation, Type,sf::Texture &);
	~GameObject();
	/// zwraca w ktorym kierunku jest zwrocony obiekt
	Rotation getRotate();
	/// zwraca jakiego typu jest obiekt
	Type getType() { return type; }
	/// funkcja czysto wirtualna. Aktualizuje stan obiektu.
	///Jako parametr jest podany typ bool przekazuj¹cy informacje o kolizji z graczem
	virtual void update(bool) = 0;
	///zwraca pozycje sprite'a
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	///operator do wyswietlania pozycji
	friend std::ostream & operator<<(std::ostream &, GameObject *);
	///zwraca czy obiekt jest kolizyjny
	bool isColider() { return collision; }

protected:
	//stan obiektu(aktywny/nieaktywny)
	bool state;

	//kierunek zwrotu
	Rotation rotation;

	//typ obiektu
	const Type type;
};