#include "Engine.h"


Engine::Engine(sf::RenderWindow &window_):window(window_)
{
	state = State::GAME;//poczatkowy stan gry
	view.reset(sf::FloatRect(384, 320, 768, 640));//ustawienie kamery
}


Engine::~Engine()
{
	checkpoint = nullptr;//wyzerowanie wskaznika
	delete checkpoint;//usuniecie wskaznika
	for (int i = 0; i<size; i++)
		delete[] map[i];

	delete[] map;//usuniecie tablicy dynamicznej

	for (auto it = objects.begin(); it != objects.end(); it++)
	{
	delete (*it);//usuwanie wskaznikow
	}

	objects.clear();//czyszczenie wektora

}

bool Engine::loadGame(std::string mapName_)
{
	Map mapIO;//klasa do operacji na plikach
	mapIO.setMapInfo(mapName_);//wczytuje nazwe i rozmiar mapy
	 size = mapIO.getSize();//ustawienie rozmiaru mapy 

	 map = new int*[size];//tablica dynamiczna
	 
	for (int i = 0; i<size; i++)
		map[i] = new int[size];
	
	colision.setMap(map);//ustawienie mapy do klasy Colision(potrzebne do sprawdzania kolizji ze scianami)

	if ( 
		mapIO.loadTextures(textures) &&//wczytywanie tekstur
		mapIO.loadMap(map) &&//wczytanie mapy do tablicy dynamicznej
		mapIO.loadGameObjects(objects,textures,&checkpoint,&end)//wczytanie wszystkich obiektow
		)//jesli sie powiodlo zwroc true w przeciwnym wypadku false
		return true;

	return false;

}

void Engine::game()
{
	Player player(checkpoint->getSprite().getPosition().x, 
		checkpoint->getSprite().getPosition().y,
		SOUTH,textures["player"],colision);//stworzenie gracza
	//bool death = false;
	
	

	while (state!=State::END)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//jesli zamknie sie okno
				state = END;//stan ustawiony na END
			else if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Escape)
			{//jesli nacisnie sie escape to 
				if (state == GAME)//jesli stan jest GAME
					state = MENU;//ustawia stan na MENU
				else if (state == MENU)//w przeciwnym wypadku
					state = GAME;//ustawia GAME
			}
			else if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::R)
			{//jesli kliknie sie R to przenosi nas do ostatniego checkpointu
				player.setPosition(checkpoint->getSprite().getPosition().x,
					checkpoint->getSprite().getPosition().y);
			}
		}
		//---maszyna stanow---------------------------------
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
	//resetowanie kamery
	window.setView(window.getDefaultView());

}

void Engine::menu()
{
	auto center = window.getView().getCenter();
	//wyswietlenie tekstu o mozliwosci wyjscia do menu
	text.displayText("Enter aby wyjsc",sf::Vector2f(center.x-250,center.y+50) , window);
	text.displayText("ESC aby odpauzowac", sf::Vector2f(center.x - 250, center.y - 50), window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		state = END;

	window.display();
}

void Engine::update(Player &player)
{	
	player.move();//sterowanie postaci
	if (colision.isColision(&player, end))
	{
		//wygranko
		state = END;
		return;
	}

		bool isColision;//zmienna pomocnicza do przechowania czy wystapila kolizja
		bool playerColision = false;//zmienna pomocnicza do kolizji gracza z obiektem

		for (auto it = objects.begin(); it != objects.end(); it++)
		{
			isColision = colision.isColision(&player, (*it));//ustawienie zmiennej isColision

			(*it)->update(isColision);//aktualizowanie stanu obiektu
			
			if (isColision )
			{
			if ( (*it)->isColider())//sprawdza czy kolizja zaszla z obiektem kolizyjnym
			{
				playerColision = true;//jesli tak to ustawia kolizje postaci
			}
			if ( typeid(**it)==typeid(Obstacle))//jesli przeszkoda to cofa postac do checkpointu
					player.setPosition(checkpoint->getSprite().getPosition().x,
						checkpoint->getSprite().getPosition().y);
				else if(typeid(**it) == typeid(Field))//jesli checkpoint to ustawia jako aktywny
				{
					if (!(checkpoint == (*it)))
					{
						dynamic_cast<Field*>(checkpoint)->disable();
						checkpoint = (*it);
					}
				}
			}
	}

		player.update(playerColision);//aktualizuje stan gracza

		//ustawienie srodka kamery na graczu
	view.setCenter(player.getSprite().getPosition());
	window.setView(view);//przypisanie kamery do okna 
	window.clear(sf::Color::White);//czyszczenie ekranu

	level.drawLevel(window,objects,tile,size,map);//rysowanie mapy i obiektow
	window.draw(player);//rysowanie gracza

	window.display();//wyswietlenie 
}

