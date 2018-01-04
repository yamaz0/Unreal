#include"Engine.h"
#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

#include"Level.h"
#include"Map.h"
class Game
{
	const int x = 800;
	const int y = 600;
	sf::RenderWindow window;
	std::string mapName;
	///Metoda odpowiadajaca za pierwsze menu
	void menu();
	///Metoda odpowiadajaca za drugie menu
	void menu2();

	sf::Font font;

	enum GameState {MENU,MENU2, GAME, EDITOR, END};
	GameState state;

	//sf::Text text;
	//text.setFont(font);
	//text.setString("Hello world");
	//text.setFillColor(sf::Color(69,69,69));

public:
	Game();
	~Game();
	///Metoda, ktora steruje gra
	void runGame();
	///Metoda uruchamia gre
	void game();
	///To bedzie w przyszlosci
	void editor();
};