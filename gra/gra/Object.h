#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class Object : public sf::Drawable
{

protected :
	int size=128;//128x128 domyslny rozmiar
	//czy obiekt jest kolizyjny
	bool collision;
	//sprite obiektu
	sf::Sprite sprite;


public:
	Object();
	 ~Object();
	 ///metoda ustawia pozycje obiektu
	 void setPosition(float , float );
	 ///metoda zwraca rozmiar obiektu(jako kwadrat)
	 int getSize() { return size; }
	 ///zwraca referencje do sprite
	 sf::Sprite& getSprite() { return sprite; }
	 ///metoda rysujaca obiekt
	 void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	
};

