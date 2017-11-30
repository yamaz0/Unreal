#include "Level.h"



Level::Level(sf::RenderWindow &win,Map &map_) :window(win),mapIO(map_)
{
	size = mapIO.getSize();

	for (int i = 0; i<2; i++)
		map[i] = new int[size];
}


Level::~Level()
{
	for (int i = 0; i<2; i++)
		delete[] map[i];

	delete[] map;
}

bool Level::loadLevel()
{
	///tutaj teraz
	if(	
		mapIO.loadTextures(Object::getTextures())&&
		mapIO.loadMap(map)&&
		mapIO.loadGameObjects(objects)
	  )
	return true;

	return false;
}


void Level::drawLevel()
{//Rysowanie planszy(sciany i podloga)
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			window.draw(tile[map[j][i]]);
		}
	}
	//rysowanie obiektow 
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		window.draw(*it);
	}
} 


void Level::update()
{
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		(*it).update();
	}

	drawLevel();
}