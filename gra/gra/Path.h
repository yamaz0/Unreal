#pragma once
#include <SFML/Graphics.hpp>
class Path
{

	//punkt startowy 
	float x, y;
	sf::Vector2f distance;//odleglosc od punktu startu do konca 

public:
	Path();
	~Path();
	//!sprawdza czy obiekt nie wyszedl poza sciezke
	//!je¿eli tak to zmienia kierunek ruchu na przeciwny
	bool check(float,float);

	///Parametry: x ,y distance
	///ustawia sciezke.
	void setPath(float,float,sf::Vector2f);
};

