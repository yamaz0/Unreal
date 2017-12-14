#include "Player.h"


Player::Player(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));
}


Player::~Player()
{

}

void Player::update(bool isColision)
{
	/*
	player.move(vector2f);
	if(isColision)
	player.move(-vector2f)
	
	*/

}