#pragma once
#include"GameObject.h"
#include"Level.h"
//#include"Player.h"
//#include"Colision.h"
//#include"Map.h"
//#include"Text.h"
class Engine
{


public:
	Engine(sf::RenderWindow&);
	~Engine();

	void game();
	void update();
	void menu();
	bool loadGame();

private:
	sf::RenderWindow &window;
	
	Level level;
	int size;
	std::vector<GameObject*>objects;
	enum State { GAME, MENU, END }state;

	//tablica dwuwymiarowa reprezentuj¹ca mape w postaci 0-podloga 1 - sciana
	int **map = new int *[2];
	//mapa textur
	std::map<std::string, sf::Texture>textures;
	//Tablica kafelek(2) pod³ogi i œciany.
	Tile tile[2] = { Tile(false,textures["background"]),Tile(true,textures["background"]) };



};

