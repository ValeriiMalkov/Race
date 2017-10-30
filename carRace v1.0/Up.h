#include"Strategy\Control.h"
#ifndef UP_H
#define UP_H
class Up : public Control
{
public:
	Up();
	~Up();
	void changeState(int& parameter);
private:
	Up(const Control & up);
	void operator=(const Control& control);
};
#endif;
