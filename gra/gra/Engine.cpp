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
		mapIO.loadGameObjects(objects,textures,&checkpoint)//wczytanie wszystkich obiektow
		)//jesli sie powiodlo zwroc true w przeciwnym wypadku false
		return true;

	return false;

}

void Engine::game()
{
	Player player(checkpoint->getSprite().getPosition().x, 
		checkpoint->getSprite().getPosition().y,
		SOUTH,PLAYER,textures["player"]);//stworzenie gracza
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
	//wyswietlenie tekstu o mozliwosci wyjscia do menu
	text.displayText("Enter aby wyjsc, exit aby odpauzowac.",window.getView().getCenter(),window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		state = END;

	window.display();
}

void Engine::update(Player &player)
{	
	bool anim = false;//zmienna pomocnicza do animacji
	if  (frame++ == 5) 
	{
		frame = 0;
		anim = true;
	}
	
		player.update(anim);//aktualizuje stan gracza

			player.move(player.getVector());//przesuwa postac
			
		if (colision.isColision(&player))//jesli kolizja z sciana to cofa gracza
			player.move(-player.getVector());


		bool isColision;//zmienna pomocnicza do przechowania czy wystapila kolizja
		for (auto it = objects.begin(); it != objects.end(); it++)
		{
			isColision = colision.isColision(&player, (*it));//ustawienie zmiennej isColision

			(*it)->update(isColision);//aktualizowanie stanu obiektu
			
			if (isColision )
			{
			if ( (*it)->isColider())//sprawdza czy kolizja zaszla z obiektem kolizyjnym
			{
				player.move(-player.getVector());//jesli tak to cofa postac
			}
			auto typeTmp=(*it)->getType();//zmienna pomocnicza przechowujaca typ obiektu
				if ( typeTmp == Type::OBSTACLE)//jesli przeszkoda to cofa postac do checkpointu
					player.setPosition(checkpoint->getSprite().getPosition().x,
						checkpoint->getSprite().getPosition().y);
				else if( typeTmp==Type::CHECKPOINT)//jesli checkpoint to ustawia jako aktywny
				{
					if (!(checkpoint == (*it)))
					{
						checkpoint = (*it);
					}
				}
				else if (typeTmp == Type::END)//jesli dojdzie do konca to idzie do menu
				{
					//wygrana
					state = END;
					return;
				}

			}
	}
		//ustawienie srodka kamery na graczu
	view.setCenter(player.getSprite().getPosition());
	window.setView(view);//przypisanie kamery do okna 
	window.clear(sf::Color::White);//czyszczenie ekranu

	level.drawLevel(window,objects,tile,size,map);//rysowanie mapy i obiektow
	window.draw(player);//rysowanie gracza

	window.display();//wyswietlenie 
}

