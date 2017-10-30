#include"Strategy\Control.h"
#ifndef DOWN_H
#define DOWN_H
class Down : public Control
{
public:
	Down();
	~Down();
	void changeState(int& parameter);
private:
	Down(const Control & down);
	void operator=(const Control& control);
};
#endif;
