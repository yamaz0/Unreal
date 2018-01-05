#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
class Text
{
	sf::Font font;


public:
	Text();
	~Text();
	///wyswietlanie napisu na srodku ekranu
		void displayText(const std::string &,sf::Vector2f, sf::RenderWindow &);
};

