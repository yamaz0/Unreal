#include "Engine.h"


Engine::Engine(sf::RenderWindow &window_):window(window_)
{
	state = State::GAME;
	view.reset(sf::FloatRect(384, 320, 768, 640));
}


Engine::~Engine()
{
	checkpoint = nullptr;
	delete checkpoint;
	for (int i = 0; i<size; i++)
		delete[] map[i];

	delete[] map;

	for (auto it = objects.begin(); it != objects.end(); it++)
	{
	delete (*it);
	}

	objects.clear();

}

bool Engine::loadGame(std::string mapName_)
{
	Map mapIO;
	mapIO.setMapInfo(mapName_);
	 size = mapIO.getSize();

	 map = new int*[size];

	for (int i = 0; i<size; i++)
		map[i] = new int[size];
	
	colision.setMap(map);

	if ( 
		mapIO.loadTextures(textures) &&
		mapIO.loadMap(map) &&
		mapIO.loadGameObjects(objects,textures,&checkpoint)
		)
		return true;

	return false;

}

void Engine::game()
{
	//checkpoint = (*objects.end());
	Player player(checkpoint->getSprite().getPosition().x, 
		checkpoint->getSprite().getPosition().y,
		SOUTH,PLAYER,textures["player"]);
	bool death = false;
	
	

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
				player.setPosition(checkpoint->getSprite().getPosition().x,
					checkpoint->getSprite().getPosition().y);
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

	window.setView(window.getDefaultView());

}

void Engine::menu()
{
	text.displayText("Enter aby wyjsc, exit aby odpauzowac.",window.getView().getCenter(),window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		state = END;

	window.display();
}

void Engine::update(Player &player,bool death)
{	
	bool anim = false;
	if  (frame++ == 5) 
	{
		frame = 0;
		anim = true;
	}
	

	if (!death)
	{
		player.update(anim);////teraz tutaj

			player.move(player.getVector());
			
		if (colision.isColision(&player))
			player.move(-player.getVector());


		bool isColision;
		for (auto it = objects.begin(); it != objects.end(); it++)
		{
			isColision = colision.isColision(&player, (*it));

			(*it)->update(isColision);
			
			if (isColision )
			{
			if ( (*it)->isColider())
			{
				player.move(-player.getVector());
			}
			auto typeTmp=(*it)->getType();
				if ( typeTmp == Type::OBSTACLE)
					player.setPosition(checkpoint->getSprite().getPosition().x,
						checkpoint->getSprite().getPosition().y);
				else if( typeTmp==Type::CHECKPOINT)
				{
					if (!(checkpoint == (*it)))
					{
						checkpoint = (*it);
					}
				}
				else if (typeTmp == Type::END)
				{
					//wygrana
					state = END;
					return;
				}

			}

		}
	}

	view.setCenter(player.getSprite().getPosition());
	window.setView(view);
	window.clear(sf::Color::White);

	level.drawLevel(window,objects,tile,size,map);
	window.draw(player);

	window.display();
}

