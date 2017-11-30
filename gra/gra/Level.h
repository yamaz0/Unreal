#pragma once

#include"Map.h"
//#include<iostream>

class Level
{
	sf::RenderWindow &window;
	//Tablica kafelek(2) pod�ogi i �ciany.
	Tile tile[2] = { Tile(false),Tile(true) };
	int size;
	int **map= new int * [2];
	std::vector<GameObject>objects;
	Map &mapIO;
public:
	Level(sf::RenderWindow &, Map &);//konstruktor
	~Level();//destruktor 

	///Metoda wczytuj�ca z pliku map�(w postaci 0,1/floor,wall) i obiekty.
	bool loadLevel();
	///Metoda rysuj�ca poziom na ekranie.
	void drawLevel();
	void update();
};

