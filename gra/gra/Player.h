#pragma once
#include"GameObject.h"
class Player :
	public GameObject
{
	sf::Clock clock;


	sf::Vector2f vector;
	short frame = 0;
	short maxFrame = 4;
	short distance = 10;
public:
	///Konstruktor o parametrach float pozycja x, float pozycja y, Rotation kierunek ustawienia obiektu,Type typ obiektu,Texture tekstura obiektu
	Player(float, float, Rotation, Type, sf::Texture &);
	~Player();
	///Metoda aktualizuje obiekt
	virtual void update(bool);

	///Metoda zwraca wektor ruchu
	sf::Vector2f getVector() { return vector; }

	/// Metoda przemieszcza obiekt o podany wektor
	void move(sf::Vector2f);
	/// Animacja ruchu postaci
	void animationMove(Rotation);
	/// Aanimacji smierci postaci
	void animationDeath();
};