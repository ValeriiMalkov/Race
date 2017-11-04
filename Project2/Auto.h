#include <Windows.h>
#include<ctime>
#include"Dashboard.h"
#include"Line.h"
#include"Control.h"
#include"Left.h"
#include"Right.h"
#include"Up.h"
#include"Down.h"
#ifndef AUTO_H
#define AUTO_H
class Auto
{
public:
	Auto();
	~Auto();
	Auto& operator=(const Auto& car);
	Auto(const Auto & car);
	void goToRoad(const Road & road);
	inline int getX()const;
	inline int getY()const;
	inline int getX();
	inline int getY();
	inline int getSpeed()const;
	inline int getSpeed();
	inline void changeX(int X);
	inline void changeY(int Y);
	inline void changeSpeed(int speed);
	void carControler(const Road & Road);
	void view();
	void boardViewer();
	void boardOn();
private:
	int x_;
	int y_;
	int size_;
	int speed_;
	int maxSpeed_;
	shared_ptr<Object> car_;
	shared_ptr<Control> control_;
	shared_ptr<Dashboard> board_;
private:
	void carInitializer();
	void carCleaner();
	void newState(const Road & Road);

};
inline int Auto::getX()
{
	return x_;
}
inline int Auto::getY()
{
	return y_;
}
inline int Auto::getX()const
{
	return x_;
}
inline int Auto::getY()const
{
	return y_;
}
inline int Auto::getSpeed()
{
	return speed_;
}
inline int Auto::getSpeed()const
{
	return speed_;
}
#endif;
