#include"Game.h"
//#include<string>
#include<iostream>

Game::Game()
{
	state = END;

	if (!font.loadFromFile("arial.ttf"))
	{		
		std::cout << "Blad wczytania czcionki arial";
		return;
	}
	state = MENU;
}
Game::~Game()
{

}

void Game::runGame()
{
	window.create(sf::VideoMode(x, y), "SFML window");
	window.setFramerateLimit(60);

	while (state!=END)
	{
		switch (state)
		{
		case Game::MENU:
			menu();	break;
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
{
	const int number = 3;
	const std::string texts[] = {"Play","Map editor","Exit"};
	sf::Text text[number];
	sf::Text title("Tytul gry",font,130);

	title.setPosition(x/3-20,20);
	for(int i =0;i<number;i++)
	{
		text[i].setString(texts[i]);
		text[i].setFont(font);
		text[i].setPosition(x/3,y/number*i+100);
		text[i].setCharacterSize(65);
	}

	while (state == MENU)
	{

		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Escape || event.type == sf::Event::MouseButtonReleased&&text[2].getGlobalBounds().contains(mouse)&&event.key.code==sf::Mouse::Button::Left)
				state = END;
			else if (text[0].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				state = MENU2;
			else if (text[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				state = EDITOR;			
		}

		for (int i = 0; i < number; i++)
		{
			if (text[i].getGlobalBounds().contains(mouse))
				text[i].setColor(sf::Color::Yellow);
			else
				text[i].setColor(sf::Color::Black);
		}

		window.clear(sf::Color::Cyan);

	window.draw(title);
	for (int i = 0; i < number; i++)
		window.draw(text[i]);

	window.display();

	}
}

void Game::menu2()
{


}

void Game::game()
{
	Engine engine(window);
	engine.game();
	state = MENU2;
}
void Game::editor()
{
}