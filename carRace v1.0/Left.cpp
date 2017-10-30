#include"Strategy\Left.h"
void Left::operator=(const Control& control) {}
Left::Left() : Control() {}
Left::Left(const Control& left) {}
Left::~Left() {}
void Left::changeState(int& parameter)
{
	parameter -= stateChanger_;
}