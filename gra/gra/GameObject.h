#pragma once
#include "Object.h"
enum Rotation { NORTH, SOUTH, EAST, WEST };

class GameObject :
	public Object
{
public:
	///Konsturktor parametry: pozycja x,y ,zwrot,typ,tekstura
	GameObject(float, float, Rotation,sf::Texture &);
	~GameObject();
	/// zwraca w ktorym kierunku jest zwrocony obiekt
	Rotation getRotate();
	/// funkcja czysto wirtualna. Aktualizuje stan obiektu.
	///Jako parametr jest podany typ bool przekazuj¹cy informacje o kolizji z graczem
	virtual void update(bool) = 0;
	///zwraca pozycje sprite'a
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	///operator do wyswietlania pozycji
	friend std::ostream & operator<<(std::ostream &, GameObject *);
	///zwraca czy obiekt jest kolizyjny
	bool isColider() { return collision; }
	//zwraca stan obiektu(aktywny lub nie)
	bool getState() { return state; }
	//ustawia stan obiektu
	void setState(bool state_) { state = state_; }

protected:
	//stan obiektu(aktywny/nieaktywny)
	bool state;

	//kierunek zwrotu
	Rotation rotation;
};