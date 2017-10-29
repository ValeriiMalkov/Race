#include <Windows.h>
#include<ctime>
#include<vector>
#include"Map.h"
#ifndef AUTO_H
#define AUTO_H

class Control;
class Dashboard;
class Auto
{
private:
	int X_;
	int Y_;
	int size_;
	char ** car_;
	int speed_;
	int maxSpeed_;
	Control * control_;
	Dashboard * board_;
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
	void carInitializer();
	void carCleaner();
	void newState(const Asphalt & asphalt);

};
class Control
{
protected:
	int stateChanger_;
	int speedChanger_;
public:
	Control();
	virtual ~Control();
	virtual void changeState(Auto & car) = 0;
private:
	void operator=(const Control& control);
	Control(const Control& control);
};
class Left : public Control
{
public:
	Left();
	
	~Left();
	void changeState( Auto & car);
private:
	Left(const Control & left);
	void operator=(const Control& control);
};
class Right : public Control
{
public:
	Right();
	~Right();
	void changeState( Auto & car);
private:
	Right(const Control & right);
	void operator=(const Control& control);
};
class Up : public Control
{
public:
	Up();
	~Up();
	void changeState( Auto & car);
private:
	Up(const Control & up);
	void operator=(const Control& control);
};
class Down : public Control
{
public:
	Down();
	
	~Down();
	void changeState(Auto & car);
private:
	Down(const Control & down);
	void operator=(const Control& control);
};
class Sensor
{
protected:
	const Auto* car_;
public:
	Sensor();
	Sensor(Auto & car);
	virtual ~Sensor();
	virtual void applyParameter() = 0;
	virtual void viewParameter() = 0;
private:
	Sensor(const Sensor& sensor);
	void operator=(const Sensor& sensor);

};
class SpeedSensor :public Sensor
{
private:
	int speed_;
public:
	SpeedSensor(Auto & car);
	SpeedSensor(const SpeedSensor & speedSensor);
	~SpeedSensor();
	SpeedSensor& operator=(const SpeedSensor& speedSensor);
	void applyParameter();
	void viewParameter();
private:
	SpeedSensor();
};
class Dashboard : public Sensor
{
private:
	vector<Sensor*> sensor_;
public:
	Dashboard();
	Dashboard(Auto & car);
	Dashboard(const Dashboard & dashboard);
	~Dashboard();
	Dashboard& operator=(const Dashboard & dashboard);
	void applyParameter();
	void viewParameter();
};
class DistanceSensor :public Sensor
{
private:
	double distance_;
public:
	DistanceSensor(Auto & car);
	DistanceSensor(const DistanceSensor & distanceSensor);
	~DistanceSensor();
	DistanceSensor& operator=(const DistanceSensor& distanceSensor);
	void applyParameter();
	void viewParameter();
private:
	DistanceSensor();
};
class TimeSensor : public Sensor
{
private:
	double time_;
public:
	TimeSensor(Auto & car);
	TimeSensor(const TimeSensor & timeSensor);
	~TimeSensor();
	TimeSensor& operator=(const TimeSensor& timeSensor);
	void applyParameter();
	void viewParameter();
private:
	TimeSensor();
};
#endif;
