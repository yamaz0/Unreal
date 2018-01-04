#include "Text.h"


Text::Text()
{
	if (!font.loadFromFile("Assets/Fonts/arial.ttf"))
	{
		std::cout << "Blad wczytania czcionki arial";
		return;
	}
}


Text::~Text()
{
}

void Text::displayText(const std::string &_text,sf::Vector2f position_, sf::RenderWindow &_window)
{

		sf::Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(position_);
	text.setString(_text);
	text.setFillColor(sf::Color(250,69,69));
	_window.draw(text);

}
