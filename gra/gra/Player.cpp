#include "Player.h"


Player::Player(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{
	size = 64;
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));
	vector = sf::Vector2f(20,20);
}


Player::~Player()
{

}

void Player::move(sf::Vector2f vect)
{
	sprite.move(vect);
}

void Player::update(bool anim)
{
	
	int x=0, y=0;
	Rotation rotation_=SOUTH;

	//----poruszanie postaci----------------------------
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		y = -distance;
		rotation = NORTH;
		if (anim)
		frame++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		y = distance;
		rotation = SOUTH;
	if(anim)
	frame++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		x = -distance;
		rotation = WEST;
		if (anim)
		frame++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		x = distance;
		rotation = EAST;
		if (anim)
		frame++;
	}


	vector = sf::Vector2f(x, y);

	if(anim)
	{
	animationMove(rotation);
	}
	
}
	
	//----animacja--------------------------------------
void Player::animationMove(Rotation rotation_)
{
	if (rotation_ != rotation || frame >= maxFrame)
	{
		frame = 0;
	}

	sprite.setTextureRect(sf::IntRect(size*frame, size*rotation_, size,size));
}