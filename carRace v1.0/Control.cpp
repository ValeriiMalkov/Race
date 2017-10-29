#include"Auto.h"
Control::Control() :stateChanger_(3), speedChanger_(10) {}
Control::Control(const Control& control)
{
	this->speedChanger_ = control.speedChanger_;
	this->stateChanger_ = control.stateChanger_;
}
Control::~Control() {}
void Control::operator=(const Control& control){}
void Up::operator=(const Control& control) {}
void Down::operator=(const Control& control) {}
void Left::operator=(const Control& control) {}
void Right::operator=(const Control& control) {}
Left::Left() : Control() {}
Left::Left(const Control& left)  {}
Left::~Left() {}
Right::Right(const Control & right)  {}
Right::Right() : Control() {}
Right::~Right() {};
Up::Up():Control() {}
Up::Up(const Control& up) {}
Up::~Up() {}
Down::Down() : Control() {}
Down::Down(const Control& down){}
Down::~Down() {}
void Left::changeState(Auto & car)
{
	car.changeX(-stateChanger_);
}
void Right::changeState(Auto & car)
{
	car.changeX(stateChanger_);
}
void Up::changeState(Auto & car) 
{
	car.changeSpeed(speedChanger_);
}
void Down::changeState(Auto & car)
{
	car.changeSpeed(-speedChanger_);
}
