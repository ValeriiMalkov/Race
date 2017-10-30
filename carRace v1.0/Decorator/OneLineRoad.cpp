#include"OneLineRoad.h"
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

			map_[i][size_ - 2] = '|';
			map_[i][j] = ' ';
		}
	}
}
void OneLineRoad::viewer()
{
	Road::viewer();
}