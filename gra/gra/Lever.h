#pragma once
#include "GameObject.h"
class Lever: 
	public GameObject
{
	short id=0;
	short value = 1;

public:
	
	Lever(float, float, Rotation, Type, int, sf::Texture &);
	~Lever();
	///Przelacza dzwignie, czyli zmienia jej stan
	void switchLever();
	///aktualizuje stan dzwigni
	virtual void update(bool);
	///zwraca wartosc dzwigni(potrzebne do otwarcia przejsc)
	short getValue() { if (state) return value; return 0; }
	bool enterIsPressed = false;
};
