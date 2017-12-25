#pragma once
#include"GameObject.h"
class Player :
	public GameObject
{
	sf::Vector2f velocity;

public:
	Player(float, float, Rotation, Type, sf::Texture &);
	~Player();
	virtual void update(bool);

	void move(sf::Vector2f);
};

