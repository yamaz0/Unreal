#include"Engine.h"
#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

#include"Level.h"
#include"Map.h"
class Game
{
	//szerokosc okna
	const int x = 800;
	//wysokosc okna
	const int y = 600;

	//okno programu
	sf::RenderWindow window;

	//nazwa mapy(potrzebne do wczytania wybranej mapy)
	std::string mapName;

	///Metoda odpowiadajaca za pierwsze menu
	void menu();
	///Metoda odpowiadajaca za drugie menu
	void menu2();

	//Czcionka
	sf::Font font;

	//typ wyliczeniowy okreslajacy stan gry
	enum GameState {MENU,MENU2, GAME, EDITOR, END};

	//zmienna okreslajaca stan gry
	GameState state;

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