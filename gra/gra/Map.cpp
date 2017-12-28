#include "Map.h"


Map::Map() 
{
}


Map::~Map()
{

}

bool Map::loadTextures(MapTexture &textures) 
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
	std::ifstream f_map("Assets/Maps/"+name+"/map.txt");
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
		if(i==20)
		{
			return true;
		}
		f_map >> x;

		if(i<size)
			tab[j++][i] = x;
		if (j > size - 1)
		{

			j = 0;
			i++;
		}
	}
	return true;
}

 bool Map::loadGameObjects(	VectorGameObject &objects, MapTexture &textures)
 {
	 const std::vector<std::string> type = { "background","lever","gateway","player","saw","ball","laser" };
	 std::string path= "Assets/Maps/" +name;
	 std::ifstream f_obj(path+ "/Lever.txt");
	 if (!f_obj.is_open())
	 {
		 std::cout << "Blad otwarcia pliku Lever" << std::endl;
		 return false;
	 }

	 std::map < std::string, Rotation>rotation_conversion;
	 rotation_conversion["NORTH"] = Rotation::NORTH;
	 rotation_conversion["SOUTH"] = Rotation::SOUTH;
	 rotation_conversion["WEST"] = Rotation::WEST;
	 rotation_conversion["EAST"] = Rotation::EAST;

	 int i = 0;
	 int tmp = 0;
	 float x, y;
	 std::string rot;


	 VecLever levers;

	 while(!f_obj.eof())
	 {
		 f_obj >> x;
		 f_obj >> y;
		 f_obj >> rot;
		 f_obj >> tmp;
		 Lever *lever = new Lever(x, y, rotation_conversion[rot], Type::LEVER, tmp, textures["lever"]);
		 levers.push_back(lever);
		 objects.push_back(lever);//spr
	 }
	 ///////////////////////////////////////////
	 //////////////////////////////////////////
	 f_obj.close();
	 f_obj.open(path + "/Gateway.txt");
	 if (!f_obj.is_open()) 
	 {
		 std::cout 
			 << "Blad otwarcia pliku Gateway" << std::endl;
		 return false;
	 }

	 VecLever tmpLevers;
	 i = 0;
	 while (!f_obj.eof())
	 {
		 f_obj >> x;
		 f_obj >> y;
		 f_obj >> rot;
		 f_obj >> i;
		 for (int j = 0; j < i; j++)
		 {
			 f_obj >> tmp;
			 tmpLevers.push_back(levers[tmp]);
		 }
		 int sum = 0;
		 for (auto it = tmpLevers.begin(); it != tmpLevers.end(); it++)
		 {
			 sum+=(*it)->getValue();
		 }

		 objects.push_back(new Gateway(x, y, rotation_conversion[rot], Type::GATEWAY,tmpLevers,sum ,textures["gateway"]));
		 tmpLevers.clear();
	 }
	 ///////////////////////////////////////////
	 //////////////////////////////////////////
	 f_obj.close();
	 f_obj.open(path + "/Obstacle.txt");
	 if (!f_obj.is_open())
	 {
		 std::cout << "Blad otwarcia pliku Obstacle" << std::endl;
		 return false;
	 }
		 //tutaj teraz 

	 f_obj.close();
	 return true;
 }

bool Map::loadMapsName(VectorString &Names)
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
	std::ifstream file("Assets/Maps/" + name_ + "/Info.txt");
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