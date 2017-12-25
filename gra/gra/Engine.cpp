#include "Engine.h"


Engine::Engine(sf::RenderWindow &window_):window(window_)
{
	state = State::GAME;
	
}


Engine::~Engine()
{
	for (int i = 0; i<2; i++)
		delete[] map[i];

	delete[] map;

}

bool Engine::loadGame(std::string mapName_)
{
	Map mapIO;
	mapIO.setMapInfo(mapName_);
	 size = mapIO.getSize();

	for (int i = 0; i<2; i++)
		map[i] = new int[size];

	///tutaj teraz
	if ( 
		mapIO.loadTextures(textures) &&
		mapIO.loadMap(map) &&
		mapIO.loadGameObjects(objects,textures)
		)
		return true;

	return false;

}

void Engine::game()
{
	Player player(0.0,0.0,SOUTH,PLAYER,textures["player"]);
	

	while (state!=State::END)
	{
		switch (state)
		{
		case GAME:
			update(player);
			break;
		case MENU:
			menu();
			break;

		default:
			break;
		}

	}
}

void Engine::menu()
{

	sf::Vector2f mouse(sf::Mouse::getPosition(window));

}

void Engine::update(Player &player)
{

//	player.update();
	//level.getValue(0,0);

	bool isColision;
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		isColision = colision.isColision(&player, (*it));

		(*it)->update(isColision);

		if (isColision && (*it)->getType() == Type::OBSTACLE)
		{
			//player.death();
		}

	}

	level.drawLevel(window,objects,tile,size,map);

	//tutaj 
	//window.draw(player);
	//albo

	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		window.draw((**it));
	}
	//tutaj
	window.draw(player);
	//do przemyslenia
}

