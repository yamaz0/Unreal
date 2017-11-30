#pragma once
#include <SFML/Graphics.hpp>
class Object : public sf::Drawable
{
	static std::map<std::string, sf::Texture>textures;

protected :
	int size=128;//128x128
	bool collision;
	sf::Sprite sprite;


public:
	static std::map<std::string, sf::Texture> getTextures() { return textures; }
	Object();
	 ~Object();
	 void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

