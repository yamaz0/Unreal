#include"Game.h"

Game::Game()
{
	state = MENU;
}
Game::~Game()
{

}

void Game::runGame()
{
	window.create(sf::VideoMode(x, y), "SFML window");
	window.setFramerateLimit(60);

	//font.loadFromFile("arial.ttf");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

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
	window.clear();
	window.display();

}

void Game::game()
{
	Engine engine;
	engine.game();
	state = MENU;
}
void Game::editor()
{
}