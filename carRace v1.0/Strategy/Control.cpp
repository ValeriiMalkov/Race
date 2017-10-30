#include"Control.h"
Control::Control() :stateChanger_(3), speedChanger_(10) {}
Control::Control(const Control& control)
{
	this->speedChanger_ = control.speedChanger_;
	this->stateChanger_ = control.stateChanger_;
}
Control::~Control() {}
void Control::operator=(const Control& control){}





