#include"Composite\SpeedSensor.h"
SpeedSensor::SpeedSensor() {}
SpeedSensor::SpeedSensor(const SpeedSensor& speedSensor)
{
	//this->car_ = speedSensor.car_;
	this->speed_ = speedSensor.speed_;
}
SpeedSensor& SpeedSensor::operator=(const SpeedSensor& speedSensor)
{
	if (this != &speedSensor)
	{
		//this->car_ = speedSensor.car_;
		this->speed_ = speedSensor.speed_;
		return *this;
	}
	else return *this;
}
SpeedSensor::~SpeedSensor() {}
//SpeedSensor::SpeedSensor(Auto & car) :Sensor(car) {}
void SpeedSensor::applyParameter(const int& speed)
{
	speed_ = speed;
}
void SpeedSensor::viewParameter()
{
	cout << "Speed: " << speed_ << '\n';
}