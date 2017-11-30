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

bool Engine::loadGame()
{
	Map mapIO;

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
//	Player player(0,0,GameObject::SOUTH,GameObject::PLAYER);
	
	sf::Clock clock;
	
	while (state!=State::END)
	{
		switch (state)
		{
		case GAME:
			update();
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


}

void Engine::update()
{


//	player.update();
	//level.getValue(0,0);

	
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
	(**it).update();
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
	//window.draw(player);
	//do przemyslenia
}

