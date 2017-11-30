#include "Level.h"



Level::Level()
{

}


Level::~Level()
{
}

void Level::drawLevel(sf::RenderWindow &window,std::vector<GameObject*>&objects,Tile tile[],int size,int *map[])
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
		window.draw(**it);
	}
} 