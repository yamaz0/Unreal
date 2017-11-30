#include "Map.h"


Map::Map() 
{
}


Map::~Map()
{

}
bool Map::loadTextures(std::map<std::string, sf::Texture>&textures) 
{
	sf::Texture texture;
	const std::vector<std::string> name = {"background","lever","gateway","player","saw","ball","laser"};
	//tutaj ladowanie tekstur
	for (int i = 0; i < name.size(); i++)
	{
		if (!texture.loadFromFile("Assets/Images/" + name[i] + ".png"))
			return false;
		textures[name[i]] = texture;
	}
	return true;

}

 bool Map::loadMap(int ** tab)
{
	std::ifstream f_map("Assets/Maps/"+mapInfo.name+"a.txt");
	if(!f_map.is_open())
	{
		std::cout << "Blad otwarcia pliku mapy" << std::endl;
		return false;
	}
	int i = 0;
	int j = 0;
	int x = 1;
	while(!f_map.eof())
	{
		if(f_map >> x)
			tab[i][j++] = x;
		if (j > mapInfo.size - 1)
		{
			j = 0;
			i++;
		}
	}
	return true;
}

 bool Map::loadGameObjects(	 std::vector<GameObject> &objects)
 {

	 std::string path= "Assets/Maps/" + mapInfo.name;
	 std::ifstream f_obj(path+ "Lever.txt");
	 if (!f_obj.is_open())
	 {
		 std::cout << "Blad otwarcia pliku Lever" << std::endl;
		 return false;
	 }

	 std::map < std::string, GameObject::Rotation>rotation_conversion;
	 rotation_conversion["NORTH"] = GameObject::Rotation::NORTH;
	 rotation_conversion["SOUTH"] = GameObject::Rotation::SOUTH;
	 rotation_conversion["WEST"] = GameObject::Rotation::WEST;
	 rotation_conversion["EAST"] = GameObject::Rotation::EAST;

	 int x, y;
	 std::string rot;
	 while(!f_obj.eof())
	 {
		 //tutaj teraz 
		 f_obj >> x;
		 f_obj >> y;
		 f_obj >> rot;
		 objects.push_back(new Lever(x,y, rotation_conversion[rot],GameObject::Type::LEVER));
	 }
	 ///////////////////////////////////////////
	 //////////////////////////////////////////
	 f_obj.close();
	 f_obj.open(path + "Gateway.txt");
	 if (!f_obj.is_open())
	 {
		 std::cout << "Blad otwarcia pliku Gateway" << std::endl;
		 return false;
	 }


	 ///////////////////////////////////////////
	 //////////////////////////////////////////
	 f_obj.close();
	 f_obj.open(path + "Obstacle.txt");
	 if (!f_obj.is_open())
	 {
		 std::cout << "Blad otwarcia pliku Obstacle" << std::endl;
		 return false;
	 }

	 f_obj.close();
 }

bool Map::loadMapsName(std::vector<Map::MapInfo> &Names)
{
	std::ifstream mapNames("Assets/Maps/maps.txt");
	if (!mapNames.is_open())
	{
		std::cout << "Blad wczytania nazw map" << std::endl;
		return false;
	}
	std::string name;
	int size;
	while (!mapNames.eof())
	{
		if(mapNames >> name >> size)
		Names.push_back({ name,size });
	}
	mapNames.close();
//	std::cout << "plik";
	return true;
}
