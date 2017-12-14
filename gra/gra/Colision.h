#pragma once
#include"GameObject.h"


class Colision
{
public:
	Colision();
	~Colision();
	
	///Metoda sprawdza kolizje dwóch obiektów
	bool isColision(GameObject*, GameObject*);
};

