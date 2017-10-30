#include"Sensor.h"
#ifndef TIMESENSOR_H
#define TIMESENSOR_H
class TimeSensor : public Sensor
{
private:
	double time_;
public:
	//TimeSensor(Auto & car);
	TimeSensor();
	TimeSensor(const TimeSensor & timeSensor);
	~TimeSensor();
	TimeSensor& operator=(const TimeSensor& timeSensor);
	void applyParameter(const int& speed);
	void viewParameter();
private:

};
#endif // !TIMESENSOR_H

