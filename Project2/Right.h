#include"Control.h"
#ifndef RIGHT_H
#define RIGHT_H
class Right : public Control
{
public:
	Right();
	~Right();
	void changeState(int& parameter);
private:
	Right(const Control & right);
	void operator=(const Control& control);
};
#endif;
