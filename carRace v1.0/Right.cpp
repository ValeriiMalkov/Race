#include"Strategy\Right.h"
void Right::operator=(const Control& control) {}
Right::Right(const Control & right) {}
Right::Right() : Control() {}
Right::~Right() {};
void Right::changeState(int& parameter)
{
	parameter += stateChanger_;
}
