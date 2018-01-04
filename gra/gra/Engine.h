#pragma once
#include"GameObject.h"
#include"Level.h"
#include"Field.h"
#include"Player.h"
#include"Colision.h"
//#include"Map.h"
#include"Text.h"
class Engine
{
	

public:
	Engine(sf::RenderWindow&);
	~Engine();

	///g³ówna pêtla gry
	void game();
	///aktualizowanie klatki gry
	void update(Player &, bool);
	///menu podczas gry
	void menu();
	///ladowanie gry
	bool loadGame(std::string);

private:
	sf::RenderWindow &window;

	Colision colision;

	Level level;

	sf::View view;

	int size;

	Text text;

	std::vector<GameObject*>objects;
	std::vector<GameObject*>levers;

	enum State { GAME, MENU, END }state;
	//numer klatki aktualnej
	short frame = 0;

	//pole na ktore sie teleportuje po smierci
	GameObject* checkpoint;

	//tablica dwuwymiarowa reprezentuj¹ca mape w postaci 0-podloga 1 - sciana
	int **map = nullptr;
	//mapa textur
	MapTexture textures;
	//Tablica kafelek(2) pod³ogi i œciany.
	Tile tile[2] = { Tile(false,textures["background"]),Tile(true,textures["background"]) };
};