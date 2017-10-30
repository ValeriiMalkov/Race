#include"Composite\DistanceSensor.h"
DistanceSensor::DistanceSensor() {}
DistanceSensor::DistanceSensor(const DistanceSensor& distanceSensor)
{
	//this->car_ = distanceSensor.car_;
	this->distance_ = distanceSensor.distance_;
}
DistanceSensor& DistanceSensor::operator=(const DistanceSensor& distanceSensor)
{
	if (this != &distanceSensor)
	{
		//this->car_ = distanceSensor.car_;
		this->distance_ = distanceSensor.distance_;
		return *this;
	}
	else return *this;
}
DistanceSensor::~DistanceSensor() {}
//DistanceSensor::DistanceSensor(Auto  & car) : Sensor(car) {}
void DistanceSensor::applyParameter(const int& speed)
{
	distance_ = speed*(clock() / 1000) / 60;
}
void DistanceSensor::viewParameter()
{
	cout << "Distance: " << distance_ << " Meter" << '\n';
}