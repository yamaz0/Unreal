#pragma once
#include "GameObject.h"
#include"Lever.h"
typedef std::vector <Lever&> VecLever;
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
	Gateway(float, float, Rotation, Type,VecLever &, sf::Texture &);
	~Gateway();
	 void update(bool);
};

