#include"Game.h"
//#include<string>

Game::Game()
{
	state = END;//ustawia stan na koniec aby w razie bledu wyjsc z programu

	if (!font.loadFromFile("Assets/Fonts/arial.ttf"))
	{		
		std::cout << "Blad wczytania czcionki arial";
		return;
	}
	state = MENU;//ustawia stan na MENU
}
Game::~Game()
{

}



void Game::runGame()
{
	//tworzenie okna i ograniczenie FPS
	window.create(sf::VideoMode(768, 640), "SFML window");
	window.setFramerateLimit(60);

	while (state!=END)
	{//prosta maszyna stanow
		switch (state)
		{
		case Game::MENU:
			menu();	break;
		case Game::MENU2:
			menu2(); break;
		case Game::GAME:
			game(); break;
		case Game::EDITOR:
			editor(); break;
		case Game::END:
			break;
		default:
			break;
		}
	}
}
void Game::menu()
{//menu glowne

	//stworzenie napisow do wyswietlenia w menu
	const int number = 3;
	const std::string texts[] = {"Play","Map editor","Exit"};
	sf::Text text[number];
	sf::Text title("Bardzo fajny tytul",font,80);

	title.setPosition(x/3-200,0);
	for(int i =0;i<number;i++)
	{
		text[i].setString(texts[i]);
		text[i].setFont(font);
		text[i].setPosition(x/5,y/(number+2)*i+200);
		text[i].setCharacterSize(65);
	}

	while (state == MENU)//petla glowna menu
	{

		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Escape || event.type == sf::Event::MouseButtonReleased&&text[2].getGlobalBounds().contains(mouse) && event.key.code == sf::Mouse::Button::Left)
				state = END;//jesli okno zostanie zamkniete lub nacisniety escape to wyjscie
			else if (text[0].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				state = MENU2;//jesli nacisniecie Play to przejscie do menu wyboru mapy
			else if (text[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				//state = EDITOR;			//wejscie w edytor mapy(nie ma)
			}
		}

		for (int i = 0; i < number; i++)
		{
			if (text[i].getGlobalBounds().contains(mouse))//jesli mysz znajduje sie na napisie
				text[i].setColor(sf::Color::Yellow);//to ustawia kolor napisu 
			else
				text[i].setColor(sf::Color::Black);//w przeciwnym razie wraca do czarnego
		}

		window.clear(sf::Color::Cyan);//czyszczenie ekranu

	window.draw(title);//rysowanie napisow
	for (int i = 0; i < number; i++)
		window.draw(text[i]);

	window.display();//wyswietlenie

	}
}

void Game::menu2()
{
	Map mapIO;//klasa odpowiada za operacje na plikach
	int page = 0;//aktualna strona 
	const int number = 5;//ilosc map na stronie
	//------------tworzenie napisow--------------------- 
	sf::Text text[number];
	sf::Text back("Back", font, 80);
	sf::Text next("-->", font, 35);
	sf::Text previous("<--", font, 35);
	
	//------------modyfikacje napisow-------------------
	back.setPosition(x / 10, y - 100);
	next.setPosition(x-100, y/3);
	previous.setPosition(100 , y/3);
	//--------------------------------------------------
	std::vector<std::string>Names;
	//------------wczytywanie nazw map-----------------
	if (!mapIO.loadMapsName(Names))
	{
	state = END;
	return;
	}
	
	//------------modyfikacja nazw map-----------------
	for (int i = 0; i<number; i++)
	{
		if(Names.size()-1<i)
			text[i].setString("..............");
		else
			text[i].setString(Names[i]);

		text[i].setFont(font);
		text[i].setPosition(x / 3, y / (number+1)*i);
		text[i].setCharacterSize(65);
	}
	
	//-------------petla menu wybierania map-----------
	while (state == MENU2)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::Event event;

		//----------petla wydarzen-------------------------
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				state = END;
			else if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Escape)
				state = MENU;

			//------------poprzednia strona----------------
			else if (previous.getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				//Previous
				if(page>0)
				{
					page--;
					for (int i = 0; i < number; i++)
					{
						int tmp = page*number + i;
						if (Names.size() - 1 < tmp)
							text[i].setString("..............");
						else
							text[i].setString(Names[tmp]);
					}
				}
			}
			//------------------nastepna strona-----------------
			else if (next.getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				//Next
				if (page<Names.size()/5)
				{

				page++;
				for (int i = 0; i < number; i++)
				{
					int tmp = page*number + i;
					if (Names.size() - 1< tmp)
						text[i].setString("..............");
					else
						text[i].setString(Names[tmp]);
				}
				}
			}
			//---------powrot do menu glownego------------------
			else if (back.getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			//Back
				state = MENU;
			}
			for (int i = 0; i < Names.size()%number; i++)
			{
				//------------wybranie mapy-------------------------
				if (text[i].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				{
					mapName=Names[(number*page) + i];
					state=GAME;
					//return;
				}
			}
		}
		//modyfikacja napisow
		if (back.getGlobalBounds().contains(mouse))
			back.setColor(sf::Color::Magenta);
		else
			back.setColor(sf::Color::White);

		for (int i = 0; i < Names.size()%number; i++)
		{
			if (text[i].getGlobalBounds().contains(mouse))
				text[i].setColor(sf::Color::Yellow);
			else
				text[i].setColor(sf::Color::Black);
		}
		
		//------rysowanie i wyswietlanie napisow------------
		window.clear(sf::Color::Blue);

		window.draw(back);
		window.draw(next);
		window.draw(previous);

		for (int i = 0; i < number; i++)
			window.draw(text[i]);

		window.display();

	}

}

void Game::game()
{//utworzenie silnika gry
	Engine engine(window);
	//wczytywanie gry
	if(engine.loadGame(mapName))
		//uruchomienie gry
	engine.game();	
	//po skonczeniu ustawienie stanu gry na MENU
	state = MENU;
}

void Game::editor()
{
	//soon
}