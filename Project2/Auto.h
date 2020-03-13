#ifdef _WIN32
#include <Windows.h>
#endif;
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
	int getX()const;
	int getY()const;
	int getX();
	int getY();
	int getSpeed()const;
	int getSpeed();
	void changeX(int X);
	void changeY(int Y);
	void changeSpeed(int speed);
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
#endif;
