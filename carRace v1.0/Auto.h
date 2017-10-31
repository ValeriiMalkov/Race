#include <Windows.h>
#include<ctime>
#include"Composite\Dashboard.h"
#include"Map.h"
#include"Strategy\Control.h"
#include"Strategy\Left.h"
#include"Strategy\Right.h"
#include"Strategy\Up.h"
#include"Strategy\Down.h"
#ifndef AUTO_H
#define AUTO_H
class Auto
{
public:
	Auto();
	~Auto();
	Auto& operator=(const Auto& car);
	Auto(const Auto & car);
	void goToRoad(const Asphalt & asphalt);
	int getX()const;
	int getY()const;
	 int getX();
	int getY();
	int getSpeed()const;
	int getSpeed();
	void changeX(int X);
	void changeY(int Y);
	void changeSpeed(int speed);
	void carControler(const Asphalt & asphalt);
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
	void newState(const Asphalt & asphalt);

};
#endif;
