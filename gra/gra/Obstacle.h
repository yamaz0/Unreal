#pragma once
#include "GameObject.h"
#include "Path.h"
class Obstacle :
	public GameObject
{


public:
	Obstacle(float, float, Rotation, Type, sf::Vector2f, sf::Vector2f, sf::Texture &);
	~Obstacle();
	///Metoda aktualizujaca obiekt
	virtual void update(bool);
	///Animowanie obiektu
	void animationMove();

private:
	Path path;//sciezka

	sf::Vector2f vector;//wektor o ktory porusza sie obiekt
	short frame_ = 0;
	short frame = 0;
	short maxFrame = 4;

};

