#include "Player.h"


Player::Player(float x, float y, Rotation r, Type t, sf::Texture &texture) :GameObject(x, y, r, t, texture)
{
	size = 64;
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));
	vector = sf::Vector2f(10,10);
}


Player::~Player()
{

}

void Player::move(sf::Vector2f vect)
{
	sprite.move(vect);
}

void Player::update(bool time)
{
	if(time)
	{
	int x=0, y=0;
	Rotation rotation_=SOUTH;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		x = -distance;
		rotation_ = WEST;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		x = distance;
		rotation_ = EAST;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		y = -distance;
		rotation_ = NORTH;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		y = distance;
		rotation_ = SOUTH;
	}

	vector = sf::Vector2f(x, y);

	//animationMove(rotation_);
	rotation = rotation_;
	}
	else
	{
		//animationDeath();
	}
}
void Player::animationDeath()
{
	//tutaj animacja smierci i ostatnia klatka zostaje na zawsze
}
	
void Player::animationMove(Rotation rotation_)
{
	if (rotation_ != rotation || frame >= maxFrame)
	{
		frame = 0;
	}

	sprite.setTextureRect(sf::IntRect(size*rotation_,size*frame,size,size));
	
	frame++;
}