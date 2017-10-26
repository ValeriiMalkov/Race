#ifndef AUTO_H
#define AUTO_H
#include <Windows.h>
#include<ctime>
#include<vector>
#include"Map.h"
class Control;
class Dashboard;
class Auto
{
private:
	int X;
	int Y;
	int size;
	char ** car;
	int speed;
	int maxSpeed;
	Control * control;
	Dashboard * board;
public:
	Auto();
	~Auto();
	void goToRoad(Asphalt & asphalt);
	int getX();
	int getY();
	int getSpeed();
	void changeX(int _X);
	void changeY(int _Y);
	void changeSpeed(int _speed);
	void carControler(Asphalt & asphalt);
	void view();
	void boardViewer();
	void boardOn();
private:
	void carInitializer();
	void carCleaner();
	void newState(Asphalt & asphalt);

};
class Control
{
protected:
	int stateChanger;
	int speedChanger;
public:
	Control();
	virtual void changeState(Auto & car) = 0;
};
class Left : public Control
{
public:
	Left();
	void changeState(Auto & car);
};
class Right : public Control
{
public:
	Right();
	void changeState(Auto & car);
};
class Up : public Control
{
public:
	Up();
	void changeState(Auto & car);
};
class Down : public Control
{
public:
	Down();
	void changeState(Auto & car);
};
class Sensor
{
public:
	Auto* car;
public:
	Sensor() {};
	Sensor(Auto & _car);
	virtual void applyParameter() = 0;
	virtual void viewParameter() = 0;

};
class SpeedSensor :public Sensor
{
private:
	int speed;
public:
	SpeedSensor(Auto & _car);
	void applyParameter();
	void viewParameter();
};
class Dashboard : public Sensor
{
private:
	vector<Sensor*> sensor;
public:
	Dashboard();
	Dashboard(Auto & _car);
	void applyParameter();
	void viewParameter();
};
class DistanceSensor :public Sensor
{
private:
	double distance;
public:
	DistanceSensor(Auto & _car);
	void applyParameter();
	void viewParameter();
};
class TimeSensor : public Sensor
{
private:
	double time;
public:
	TimeSensor(Auto & _car);
	void applyParameter();
	void viewParameter();
};
#endif;
