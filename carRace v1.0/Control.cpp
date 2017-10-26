#include"Auto.h"
Control::Control() :stateChanger(3), speedChanger(10) {}
Left::Left() : Control() {}
Right::Right() : Control() {}
Up::Up():Control() {}
Down::Down() : Control() {}
void Left::changeState(Auto & car)
{
	car.changeX(-stateChanger);
}
void Right::changeState(Auto & car)
{
	car.changeX(stateChanger);
}
void Up::changeState(Auto & car)
{
	car.changeSpeed(speedChanger);
}
void Down::changeState(Auto & car)
{
	car.changeSpeed(-speedChanger);
}
