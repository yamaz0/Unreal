#include"Engine.h"
#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

class Game
{
	const int x = 800;
	const int y = 600;
	sf::RenderWindow window;

	void menu();
	void menu2();

protected:
	enum GameState {MENU,MENU2, GAME, EDITOR, END};
	GameState state;

	sf::Font font;


	//sf::Text text;
	//text.setFont(font);
	//text.setString("Hello world");
	//text.setFillColor(sf::Color(69,69,69));

public:
	Game();
	~Game();
	void runGame();
	void game();
	void editor();
	void end();
};