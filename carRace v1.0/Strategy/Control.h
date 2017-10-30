#ifndef CONTROL_H
#define CONTROL_H
class Control
{
protected:
	int stateChanger_;
	int speedChanger_;
public:
	Control();
	virtual ~Control();
	virtual void changeState(int& parameter) = 0;
private:
	void operator=(const Control& control);
	Control(const Control& control);
};
#endif;
