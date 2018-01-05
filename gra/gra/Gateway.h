#pragma once
#include "GameObject.h"
#include"Lever.h"
typedef std::vector <Lever *> VecLever;
class Gateway :
	public GameObject
{
	//wartoœæ która jest zmieniana przez dŸwignie. 
	//jeœli z dŸwigni wyjdzi wartoœæ to przejœcie
	//otwiera siê.
	short gateValue = 0;
	//vector referencji do dŸwigñ
	VecLever levers;
public:
	///konstruktor
	///parametry: pozycja x,y ,zwrot , typ , referencja do dzwigni, wartosc otwierajaca przejscie, tekstura
	Gateway(float, float, Rotation, Type,VecLever &,short , sf::Texture &);
	~Gateway();
	//aktualizuje stan gry
	 void update(bool);
};

