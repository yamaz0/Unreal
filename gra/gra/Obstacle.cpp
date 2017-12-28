#include "Obstacle.h"



Obstacle::Obstacle(float x, float y, Rotation r, Type t, sf::Vector2f dist, sf::Vector2f vect, sf::Texture &texture) :GameObject(x, y, r, t, texture), vector(vect)
{
	path.setPath(x,y,dist);
}


Obstacle::~Obstacle()
{

}

void Obstacle::update(bool state_)
{
	if (state != state_)
		state = state_;
	if (state)
	{
	
		if (path.check(sprite.getPosition().x, sprite.getPosition().y))
		{
				rotation = Rotation((rotation + 1) % 2);
			if (rotation == EAST || rotation == WEST)
				rotation = Rotation(rotation + 2);

		vector = -vector;
		}

	sprite.move(vector);
	animationMove();
	}
}

void Obstacle::animationMove()
{
	if ( frame >= maxFrame)
	{
		frame = 0;
	}

	sprite.setTextureRect(sf::IntRect(size*rotation, size*frame, size, size));

	frame++;
}
