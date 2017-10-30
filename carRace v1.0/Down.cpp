#include"Strategy\Down.h"
void Down::operator=(const Control& control) {}
Down::Down() : Control() {}
Down::Down(const Control& down) {}
Down::~Down() {}
void Down::changeState(int& parameter)
{
	parameter -= stateChanger_;
}