#pragma once
#include"GameObject.h"


class Colision
{
public:
	Colision();
	~Colision();
	
	///Metoda sprawdza kolizje dw�ch obiekt�w
	bool isColision(GameObject*, GameObject*);
};

