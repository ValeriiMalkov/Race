#include"Decorator\Road.h"
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