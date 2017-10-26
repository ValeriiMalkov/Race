#include "Map.h"
Asphalt::Asphalt():size(27) {}
Asphalt::~Asphalt()
{
	cout << "~Asphalt";
}
char** Asphalt::getMap()
{
	return map;
}
int Asphalt::getSize()
{
	return size;
}
Map::Map() : Asphalt()
{
	add();
}
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
			map = new char*[size];
			for (int i = 0;i < size;i++)
				map[i] = new char[size];
			return;
		}
		catch (bad_alloc) 
		{
		}
	}
}
void Map::setObject(int X, int Y, char ** obj, int sizeObj)
{
	for (int i = 0; i < sizeObj; i++)
	{
		for (int j = 0; j < sizeObj; j++)
		{
			map[Y + i][X + j] = obj[i][j];
		}
	}
}
Road::Road(Asphalt* _asphalt)
{
	asphalt = _asphalt;
	map = asphalt->getMap();
}
void Road::add()
{
	asphalt->add();
}
void Road::viewer()
{
	asphalt->viewer();
}
void Road::setObject(int X, int Y, char ** obj, int sizeObj)
{
	for (int i = 0; i < sizeObj; i++)
	{
		for (int j = 0; j < sizeObj; j++)
		{
			map[Y + i][X + j] = obj[i][j];
		}
	}
	asphalt->setObject(X, Y, obj, sizeObj);
}
OneLineRoad::OneLineRoad(Asphalt* _asphalt) :Road(_asphalt) { add(); }
void OneLineRoad::add()
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
			{
				map[i][0] = '|';
				
				map[i][size-2] = '|';
				map[i][j] = ' ';
			}
		}
}
void OneLineRoad::viewer()
{
	Road::viewer();
}
TwoLineRoad::TwoLineRoad(Asphalt* _asphalt) : Road(_asphalt) { add(); }
void TwoLineRoad::add()
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			map[i][0] = '|';
			map[i][size-2] = '|';
			map[i][(size-2)/2] = '|';
			map[i][j] = ' ';
		}
	}
}
void TwoLineRoad::viewer()
{
	Road::viewer();
}
void Map::viewer()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}