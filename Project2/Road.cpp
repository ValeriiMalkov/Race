#include"Road.h"
Road::Road() :size_(27) {}
Road::~Road()
{
	for (int i = 0; i < size_; i++)
		delete[] map_[i];
}
char** Road::getMap()
{
	return map_;
}
int Road::getSize() const
{
	return size_;
}