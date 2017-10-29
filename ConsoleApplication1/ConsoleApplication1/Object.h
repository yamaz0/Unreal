#pragma once
#include <SFML/Graphics.hpp>
class Object : public sf::Drawable
{
	double x, y;
	int size;//128x128
	bool visibility;
	bool collision;

	sf::Texture texture;
	sf::Sprite sprite;

//protected :
	//static int amount;

public:
	Object();
	 ~Object();
	 void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	 static int getAmount();
	 virtual void update()=0;

};

