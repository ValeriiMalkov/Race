#include<ctime>
#include<iostream>
#ifndef SENSOR_H
#define SENSOR_H
using namespace std;
class Sensor
{

public:
	Sensor();
	virtual ~Sensor();
	virtual void applyParameter(const int& speed) = 0;
	virtual void viewParameter() = 0;
private:
	Sensor(const Sensor& sensor);
	void operator=(const Sensor& sensor);
};
#endif;
