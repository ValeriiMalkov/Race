#include"Decorator\Asphalt.h"
Asphalt::Asphalt() :size_(27) {}
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