#include "Player.h"


Player::Player(float x, float y, GameObject::Rotation r, GameObject::Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));
}


Player::~Player()
{
}

void Player::update()
{
	/*
	//pomysl
	player.move(vector2f);
	if(kolizja_z_sciana)
	player.move(-vector2f)
	if(kolizja_z_dzwignia && nacis_enter)
	dzwignia.use();

	if(kolizja_z_przeszkoda)
	player.smierc(xd);

	*/

}