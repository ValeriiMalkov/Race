#include "Map.h"
Map::Map() : Asphalt()
{
	add();
}
Map::~Map() {}
Map::Map(const Asphalt& map) {}
void Map::operator=(const Map& map) {}
void Map::add()
{
	mapInitializer();
}
void Map::mapInitializer()
{
	while (true)
	{
		try
		{
			map_ = new char*[size_];
			for (int i = 0;i < size_;i++)
				map_[i] = new char[size_];
			return;
		}
		catch (bad_alloc) 
		{
		}
	}
}
void Map::setObject(int X, int Y, char ** obj, int sizeObj)const
{
	for (int i = 0; i < sizeObj; i++)
	{
		for (int j = 0; j < sizeObj; j++)
		{
			map_[Y + i][X + j] = obj[i][j];
		}
	}
}
void Map::viewer()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			cout << map_[i][j];
		}
		cout << '\n';
	}
}