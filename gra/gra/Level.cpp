#include "Level.h"



Level::Level()
{

}


Level::~Level()
{
}

void Level::drawLevel(sf::RenderWindow &window,VectorGameObject &objects,Tile tile[],int size,int *map[])
{
	//Rysowanie planszy(sciany i podloga)
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			tile[map[j][i]].setPosition(j*128,i*128);
			window.draw(tile[map[j][i]]);
		}
	}
	//rysowanie obiektow 
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		window.draw(**it);
	}
} 