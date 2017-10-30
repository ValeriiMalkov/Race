#include"Sensor.h"
#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H
class DistanceSensor :public Sensor
{
private:
	double distance_;
public:
	DistanceSensor();
	//DistanceSensor(Auto & car);
	DistanceSensor(const DistanceSensor & distanceSensor);
	~DistanceSensor();
	DistanceSensor& operator=(const DistanceSensor& distanceSensor);
	void applyParameter(const int& speed);
	void viewParameter();
private:

};
#endif // !DISTANCESENSOR_H

