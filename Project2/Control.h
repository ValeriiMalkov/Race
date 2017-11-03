#ifndef CONTROL_H
#define CONTROL_H
class Control
{
public:
	Control();
	virtual ~Control();
	virtual void changeState(int& parameter) = 0;
protected:
	int stateChanger_;
	int speedChanger_;
private:
	void operator=(const Control& control);
	Control(const Control& control);
};
#endif;
