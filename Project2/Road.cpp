#include"Road.h"
Road::Road() :size_(27)
{ 
	map_ = shared_ptr<Object>(new Object(size_));
}
Road::~Road()
{

	map_.~shared_ptr();
}
shared_ptr<Object>& Road::getMap()
{
	return map_;
}
int Road::getSize() const
{
	return size_;
}