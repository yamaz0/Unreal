#pragma once
#include"GameObject.h"
#include"Colision.h"
class Player :
	public GameObject
{
	//sf::Clock clock;

	//wektor do poruszania postacia
	sf::Vector2f vector;
	//do kolizji
	Colision &col;
	
	int frameAnim = 0;
	short frame = 0;
	short maxFrame = 3;
	//odleglosc o ile ma sie przesuwac postac
	short distance = 8;

public:
	///Konstruktor o parametrach float pozycja x, float pozycja y, Rotation kierunek ustawienia obiektu,Type typ obiektu,Texture tekstura obiektu
	Player(float, float, Rotation, sf::Texture &,Colision &);
	~Player();
	///Metoda aktualizuje obiekt
	virtual void update(bool);

	/// Metoda poruszania gracza
	void move();

	///Metoda zwraca wektor ruchu
	sf::Vector2f getVector() { return vector; }

	/// Animacja ruchu postaci
	void animationMove();
	/// Aanimacji smierci postaci
	//void animationDeath();
};