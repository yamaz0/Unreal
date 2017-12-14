#pragma once
#include <SFML/Graphics.hpp>
class Object : public sf::Drawable
{

protected :
	int size=128;//128x128
	bool collision;
	sf::Sprite sprite;


public:
	Object();
	 ~Object();
	 ///zwraca referencje do sprite
	 sf::Sprite& getSprite() { return sprite; }
	 ///metoda rysujaca obiekt
	 void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

