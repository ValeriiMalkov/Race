#include"Control.h"
#ifndef LEFT_H
#define LEFT_H
class Left : public Control
{
public:
	Left();

	~Left();
	void changeState(int& parameter);
private:
	Left(const Control & left);
	void operator=(const Control& control);
};
#endif;
