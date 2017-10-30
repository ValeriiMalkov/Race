#include"Strategy\Up.h"
void Up::operator=(const Control& control) {}
Up::Up() :Control() {}
Up::Up(const Control& up) {}
Up::~Up() {}
void Up::changeState(int& parameter)
{
	parameter += speedChanger_;
}