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
	std::ifstream f_map("Assets/Maps/"+name+"a.txt");
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
		if (j > size - 1)
		{
			j = 0;
			i++;
		}
	}
	return true;
}

 bool Map::loadGameObjects(	 std::vector<GameObject*> &objects, std::map<std::string, sf::Texture>&textures)
 {
	 const std::vector<std::string> type = { "background","lever","gateway","player","saw","ball","laser" };
	 std::string path= "Assets/Maps/" +name;
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

	 float x, y;
	 std::string rot;
	 while(!f_obj.eof())
	 {
		 //tutaj teraz 
		 f_obj >> x;
		 f_obj >> y;
		 f_obj >> rot;
		 objects.push_back(new Lever(x,y, rotation_conversion[rot],GameObject::Type::LEVER,textures["lever"]));
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
	 return true;
 }

bool Map::loadMapsName(std::vector<std::string> &Names)
{
	std::ifstream mapNames("Assets/Maps/maps.txt");
	if (!mapNames.is_open())
	{
		std::cout << "Blad wczytania nazw map" << std::endl;
		return false;
	}
	std::string name_;

	while (!mapNames.eof())
	{
		if(mapNames >> name)
		Names.push_back(name);
	}
	mapNames.close();
	return true;
}

bool Map::setMapInfo(std::string &name_)
{
	std::ifstream file("Assets/Maps/" + name_ + "Info.txt");
	if (!file.is_open())
	{
		std::cout << "Blad otwarcia pliku Lever" << std::endl;
		return false;
	}
	name = name_;
	int size_=0;
	file >> size_;
	size = size_;
	file.close();
	return true;
}