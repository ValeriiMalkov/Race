#include"Composite\Sensor.h"
#ifndef TIMESENSOR_H
#define TIMESENSOR_H
class TimeSensor : public Sensor
{
public:
	//TimeSensor(Auto & car);
	TimeSensor();
	TimeSensor(const TimeSensor & timeSensor);
	~TimeSensor();
	TimeSensor& operator=(const TimeSensor& timeSensor);
	void applyParameter(const int& speed);
	void viewParameter();
private:
	double time_;


};
#endif // !TIMESENSOR_H

