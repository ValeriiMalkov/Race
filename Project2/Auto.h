#include <Windows.h>
#include<ctime>
#include"Dashboard.h"
//#include"Decorator\Autobahn.h"
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
	int X_;
	int Y_;
	int size_;
	char ** car_;
	int speed_;
	int maxSpeed_;
	Control * control_;
	Dashboard * board_;
private:
	void carInitializer();
	void carCleaner();
	void newState(const Road & Road);

};
inline int Auto::getX()
{
	return X_;
}
inline int Auto::getY()
{
	return Y_;
}
inline int Auto::getX()const
{
	return X_;
}
inline int Auto::getY()const
{
	return Y_;
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
