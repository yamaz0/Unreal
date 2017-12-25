#include "Player.h"


Player::Player(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));
	velocity = sf::Vector2f(10,10);
}


Player::~Player()
{

}

void Player::move(sf::Vector2f vect)
{
	sprite.move(vect);
}

void Player::update(bool isColision)
{
	
	move(velocity);
	if (isColision)
		move(-velocity);
	
	

}