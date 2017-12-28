#pragma once
#include"GameObject.h"


class Colision
{
	int **map = nullptr;
public:
	Colision();
	~Colision();
	
	///Metoda sprawdza kolizje dwóch obiektów
	bool isColision(GameObject*, GameObject*);
	/// Metoda sprawdza kolizje miedzy player i mapa
	bool isColision(GameObject *);
	///Metoda ustawia tablice dwuwymiarowa reprezentujaca mape
	void setMap(int **tab) { map = tab; }
};

