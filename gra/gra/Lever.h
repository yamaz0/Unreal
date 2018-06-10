#pragma once
#include "GameObject.h"
class Lever: 
	public GameObject
{
	//id dzwigni
	short id=0;
	//zmienna pomocnicza ograniczajaca aktywacje dzwigni
	bool enterIsPressed = false;

public:
	
	Lever(float, float, Rotation, sf::Texture &);
	~Lever();
	///Przelacza dzwignie, czyli zmienia jej stan
	void switchLever();
	///aktualizuje stan dzwigni
	virtual void update(bool);
};
