#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

class MapEditor
{
	sf::Mouse mouse;
	sf::Keyboard keyboard;
	Text komunikat;
	sf::View view;

public:
	MapEditor(sf::RenderWindow &);
	~MapEditor();
};

