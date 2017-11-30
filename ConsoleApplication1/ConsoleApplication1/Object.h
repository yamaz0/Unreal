#pragma once
#include <SFML/Graphics.hpp>
class Object : public sf::Drawable
{
	//static int amount;

protected :
	int size;//128x128
	bool collision;

	sf::Texture texture;
	sf::Sprite sprite;


public:
	Object();
	 ~Object();
	 void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	 static int getAmount();
	 virtual void update()=0;

};

