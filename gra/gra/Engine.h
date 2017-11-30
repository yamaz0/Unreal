#pragma once
#include"GameObject.h"
#include"Level.h"
//#include"Player.h"
//#include"Colision.h"
//#include"Map.h"
//#include"Text.h"
class Engine
{
	Level &level;
	Player player;



public:
	Engine(Level &);
	~Engine();

	void game();
	void update();
};

