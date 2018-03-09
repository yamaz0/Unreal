#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<string>

#include"Tile.h"
#include"Field.h"
#include"Lever.h"
#include"Gateway.h"
#include"Obstacle.h"
#include"Player.h"


typedef std::map<std::string, sf::Texture> MapTexture;
typedef std::vector<GameObject *> VectorGameObject;
typedef std::vector<std::string> VectorString;

class Map
{

	public:
	
	Map();//kontruktor domyœlny.
	~Map();//destruktor domyœlny.

	///Metoda wczytuj¹ca nazwy i rozmiary map z pliku.
	bool loadMapsName(VectorString &);


	///wczytywanie tetxtur
 bool loadTextures(MapTexture&);
	///Metoda wczytuj¹ca obiekty z pliku
	bool loadGameObjects(VectorGameObject&, MapTexture&, GameObject **, GameObject **);
	///Metoda wczytuj¹ca mape z pliku do tablicy dwuwymiarowej.
	bool loadMap(int **);
	///Metoda zapisuje nazwe mapy
	bool setMapInfo(std::string &);
	///Metoda zapisuje rozmiar mapy
	void setSize(int size_) { size = size_; }
	///Metoda zwracaj¹ca rozmiar mapy.
	int getSize() { return size; }
	///Metoda zwracaj¹ca nazwê mapy.
	std::string& getName() { return name; }

private:
	//nazwa mapy
	std::string name;
	//rozmiar mapy
	int size;
	
};

