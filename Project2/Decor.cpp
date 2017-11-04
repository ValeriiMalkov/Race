#include"Decor.h"
Decor::Decor(shared_ptr<Road>& road) :Road()
{
	road_ = road;
	map_ = road->getMap();
	//map_-> = road_->getMap();
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
