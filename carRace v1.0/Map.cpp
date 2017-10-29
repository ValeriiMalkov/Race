#include "Map.h"
Asphalt::Asphalt():size_(27) {}
Asphalt::Asphalt(const Asphalt& asphalt) {}
void Asphalt::operator=(const Asphalt& asphalt) {}
Asphalt::~Asphalt()
{
	for (int i = 0;i < size_;i++)
		delete[] map_[i];
}
char** Asphalt::getMap()
{
	return map_;
}
int Asphalt::getSize() const
{
	return size_;
}
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
Road::Road(Asphalt* asphalt)
{
	asphalt_ = asphalt;
	map_ = asphalt_->getMap();
}
Road::Road() {}
Road::Road(const Road& road) {}
void Road::operator=(const Road& road) {}
Road::~Road() {}
void Road::add()
{
	asphalt_->add();
}
void Road::viewer()
{
	asphalt_->viewer();
}
void Road::setObject(int X, int Y, char ** obj, int sizeObj)const
{
	for (int i = 0; i < sizeObj; i++)
	{
		for (int j = 0; j < sizeObj; j++)
		{
			map_[Y + i][X + j] = obj[i][j];
		}
	}
	asphalt_->setObject(X, Y, obj, sizeObj);
}
OneLineRoad::OneLineRoad(Asphalt* asphalt) :Road(asphalt) { add(); }
void OneLineRoad::operator=(const OneLineRoad& one) {}
OneLineRoad::~OneLineRoad() {}
void OneLineRoad::add()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
			{
				map_[i][0] = '|';
				
				map_[i][size_ -2] = '|';
				map_[i][j] = ' ';
			}
		}
}
void OneLineRoad::viewer()
{
	Road::viewer();
}
TwoLineRoad::TwoLineRoad(Asphalt* asphalt) : Road(asphalt) { add(); }
void TwoLineRoad::operator=(const TwoLineRoad& two) {}
TwoLineRoad::~TwoLineRoad() {}
void TwoLineRoad::add()
{
	for (int i = 0; i < size_; ++i) {
		for (int j = 0; j < size_; ++j) {
			map_[i][0] = '|';
			map_[i][size_ -2] = '|';
			map_[i][(size_ -2)/2] = '|';
			map_[i][j] = ' ';
		}
	}
}
void TwoLineRoad::viewer()
{
	Road::viewer();
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