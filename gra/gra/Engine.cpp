#include "Engine.h"


Engine::Engine(sf::RenderWindow &window_):window(window_)
{
	state = State::GAME;
	
}


Engine::~Engine()
{
	for (int i = 0; i<size; i++)
		delete[] map[i];

	delete[] map;

}

bool Engine::loadGame(std::string mapName_)
{
	Map mapIO;
	mapIO.setMapInfo(mapName_);
	 size = mapIO.getSize();

	for (int i = 0; i<size; i++)
		map[i] = new int[size];
	
	colision.setMap(map);

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
	Player player(256.0,256.0,SOUTH,PLAYER,textures["player"]);
	bool death = false;
	//Checkpoint
	//Text text

	sf::Event event;

	while (state!=State::END)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				state = END;
			else if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Escape)
			{
				if (state == GAME)
					state = MENU;
				else if (state == MENU)
					state = GAME;
			}
			else if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::R)
			{
				////jakis reset albo checkpoint
			}
		}
		switch (state)
		{
		case GAME:
			update(player,death);
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

void Engine::update(Player &player,bool death)
{	
	 
	if (!death)
	{
		player.update(true);////teraz tutaj//clock<clock+time

			player.move(player.getVector());
			
		if (colision.isColision(&player))
			player.move(-player.getVector());

		bool isColision;
		for (auto it = objects.begin(); it != objects.end(); it++)
		{
			isColision = colision.isColision(&player, (*it));

			(*it)->update(isColision);
			
			if (isColision && (*it)->getType() == Type::OBSTACLE)
			{
				death = true;
			}

		}
	}
	
	window.clear(sf::Color::White);

	level.drawLevel(window,objects,tile,size,map);
	window.draw(player);

	window.display();
}

