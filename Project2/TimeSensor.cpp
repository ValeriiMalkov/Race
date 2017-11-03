#include"TimeSensor.h"
TimeSensor::TimeSensor() {}
TimeSensor::TimeSensor(const TimeSensor& timeSensor)
{
	//this->car_ = timeSensor.car_;
	this->time_ = timeSensor.time_;
}
TimeSensor& TimeSensor::operator=(const TimeSensor& timeSensor)
{
	if (this != &timeSensor)
	{
		//this->car_ = timeSensor.car_;
		this->time_ = timeSensor.time_;
		return *this;
	}
	else return *this;
}
TimeSensor::~TimeSensor() {}
//TimeSensor::TimeSensor(Auto & car) : Sensor(car) {}
void TimeSensor::applyParameter(const int& speed)
{
	time_ = clock() / 1000;
}
void TimeSensor::viewParameter()
{
	cout << "Time: " << time_ << '\n';
}