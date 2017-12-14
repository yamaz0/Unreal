#pragma once
#include "GameObject.h"
class Lever: 
	public GameObject
{
	static int amountOfObject;
	short value = 1;

public:
	//static int getAmount();

	Lever(float, float, Rotation, Type,sf::Texture &);
	~Lever();
	///Przelacza dzwignie, czyli zmienia jej stan
	void switchLever();
	///aktualizuje stan dzwigni
	virtual void update(bool);
	///zwraca wartosc dzwigni(potrzebne do otwarcia przejsc)
	short getValue() { return value; }
};

 int Lever::amountOfObject = 0;

