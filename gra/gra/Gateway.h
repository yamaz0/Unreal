#pragma once
#include "GameObject.h"
#include"Lever.h"
typedef std::vector <Lever *> VecLever;
class Gateway :
	public GameObject
{
	//warto�� kt�ra jest zmieniana przez d�wignie. 
	//je�li z d�wigni wyjdzi warto�� to przej�cie
	//otwiera si�.
	short gateValue = 0;
	//vector referencji do d�wig�
	VecLever levers;
public:
	///konstruktor
	///parametry: pozycja x,y ,zwrot , typ , referencja do dzwigni, wartosc otwierajaca przejscie, tekstura
	Gateway(float, float, Rotation, Type,VecLever &,short , sf::Texture &);
	~Gateway();
	//aktualizuje stan gry
	 void update(bool);
};

