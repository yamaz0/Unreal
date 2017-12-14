#pragma once
#include "GameObject.h"
#include"Lever.h"
typedef std::vector <Lever&> VecLever;
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
	Gateway(float, float, Rotation, Type,VecLever &, sf::Texture &);
	~Gateway();
	 void update(bool);
};

