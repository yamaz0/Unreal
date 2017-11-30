#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<string>

#include"Tile.h"
#include"Lever.h"
#include"Gateway.h"
#include"Obstacle.h"
#include"Player.h"

class Map
{

	public:
	//Struktura przechowuj�ca informacje o mapie(nazwa,rozmiar). 
	struct MapInfo { std::string name; int size; }; 

	Map();//kontruktor domy�lny.
	~Map();//destruktor domy�lny.

	///Metoda wczytuj�ca nazwy i rozmiary map z pliku.
	bool loadMapsName(std::vector<MapInfo>&Names);


	///
	bool loadTextures(std::map<std::string, sf::Texture>&);
	///Metoda wczytuj�ca obiekty z pliku
	bool loadGameObjects(std::vector<GameObject>&);
	///Metoda wczytuj�ca mape z pliku do tablicy dwuwymiarowej.
	bool loadMap(int **);
	///Metoda ustawiajaca strukture mapInfo.
	void setMapInfo(MapInfo &map) { mapInfo = map; }
	///Metoda zwracaj�ca rozmiar mapy.
	int getSize() { return mapInfo.size; }
	///Metoda zwracaj�ca nazw� mapy.
	std::string& getName() { return mapInfo.name; };

private:
	MapInfo mapInfo={".........",0};
	//std::vector<sf::Texture> textures;

};

