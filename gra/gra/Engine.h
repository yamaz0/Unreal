#pragma once
#include"GameObject.h"
#include"Level.h"
#include"Player.h"
#include"Colision.h"
//#include"Map.h"
//#include"Text.h"
class Engine
{
	

public:
	Engine(sf::RenderWindow&);
	~Engine();

	///g³ówna pêtla gry
	void game();
	///aktualizowanie klatki gry
	void update(Player &);
	///menu podczas gry
	void menu();
	///ladowanie gry
	bool loadGame();

private:
	sf::RenderWindow &window;

	Colision colision;

	Level level;
	sf::Clock clock;
	sf::Event event;


	int size;

	std::vector<GameObject*>objects;
	std::vector<GameObject*>levers;

	enum State { GAME, MENU, END }state;

	//tablica dwuwymiarowa reprezentuj¹ca mape w postaci 0-podloga 1 - sciana
	int **map = new int *[2];
	//mapa textur
	MapTexture textures;
	//Tablica kafelek(2) pod³ogi i œciany.
	Tile tile[2] = { Tile(false,textures["background"]),Tile(true,textures["background"]) };



};

