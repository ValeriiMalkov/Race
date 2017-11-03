#include"Decor.h"
Decor::Decor(Road* road) :Road()
{
	road_ = road;
	map_ = road_->getMap();
}
Decor::Decor() {}
//Road::Road(const Road& road) {}
//void Road::operator=(const Road& road) {}
Decor::~Decor() {}
void Decor::add()
{
	road_->add();
}
void Decor::viewer()
{
	road_->viewer();
}
void Decor::setObject(int X, int Y, char ** obj, int sizeObj)const
{
	for (int i = 0; i < sizeObj; i++)
	{
		for (int j = 0; j < sizeObj; j++)
		{
			map_[Y + i][X + j] = obj[i][j];
		}
	}
	road_->setObject(X, Y, obj, sizeObj);
}