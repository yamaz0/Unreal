#pragma once
#include "GameObject.h"
class Lever: 
	public GameObject
{
	//id dzwigni
	short id=0;
	//wartosc dzwigni
	short value = 1;
	//zmienna pomocnicza ograniczajaca aktywacje dzwigni
	bool enterIsPressed = false;

public:
	
	Lever(float, float, Rotation, int, sf::Texture &);
	~Lever();
	///Przelacza dzwignie, czyli zmienia jej stan
	void switchLever();
	///aktualizuje stan dzwigni
	virtual void update(bool);
	///zwraca wartosc dzwigni(potrzebne do otwarcia przejsc)
	short getValue() { if (state) return value; return 0; }
};
