#pragma once

#include"Map.h"
//#include<iostream>

class Level
{

public:
	Level();//konstruktor
	~Level();//destruktor 

	//Metoda wczytuj�ca z pliku map�(w postaci 0,1/floor,wall) i obiekty.
	//bool loadLevel(Map &, std::vector<GameObject*>&);

	///Metoda rysuj�ca poziom na ekranie.
	void drawLevel(sf::RenderWindow &,VectorGameObject &,Tile[], int,int *[]);
};

