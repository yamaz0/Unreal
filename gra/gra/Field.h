#pragma once
#include "GameObject.h"
class Field :
	public GameObject
{
public:
	///konstruktor
	///parametry: pozycja x,y, zwrot, typ , tekstura
	Field(float x, float y, Rotation r, sf::Texture &texture);
	~Field();
	///Metoda pobiera pozycje pola
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	///Metoda aktualizujaca pole
	void update(bool);
	//dezaktywuje pole
	void disable();
};

