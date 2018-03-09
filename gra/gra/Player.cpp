#include "Player.h"


Player::Player(float x, float y, Rotation r, sf::Texture &texture,Colision &col_) :GameObject(x, y, r, texture),col(col_)
{
	size = 64;
	sprite.setTextureRect(sf::IntRect(0, 0, size, size));
	vector = sf::Vector2f(20,20);
}


Player::~Player()
{

}

void Player::move( )
{
	int x = 0, y = 0;
	 rotation = SOUTH;

	//----poruszanie postaci----------------------------
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		//sf::Vector2f(x, y)
		y = -distance;
		//sprite.move(sf::Vector2f(0, -distance));
		rotation = NORTH;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		y = distance;
		//sprite.move(sf::Vector2f(0, distance));
		rotation = SOUTH;
	}

	sprite.move(sf::Vector2f(0, y));

	if(col.isColision(this))
		sprite.move(sf::Vector2f(0, -y));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		x = -distance;
		rotation = WEST;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		x = distance;
		rotation = EAST;
	}
	sprite.move(sf::Vector2f(x, 0));

	if (col.isColision(this))
		sprite.move(sf::Vector2f(-x, 0));

	vector = sf::Vector2f(x, y);




	//if(col.isColision(this))
		//sprite.move(-vector);
}

void Player::update(bool colide)
{
	if(colide)
		sprite.move(-vector);
	
	animationMove();	
}
	
	//----animacja--------------------------------------
void Player::animationMove()
{
	frameAnim++;
	if (frameAnim > 5)
	{
		frameAnim = 0;
		frame++;
	}

	if (vector==sf::Vector2f(0,0) || frame >= maxFrame)
	{
		frame = 0;
	}

	sprite.setTextureRect(sf::IntRect(size*frame, size*rotation, size,size));
}