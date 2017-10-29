#include"Auto.h"
Sensor::Sensor() {}
Sensor::Sensor( Auto & car)
{
	car_ = &car;
}
Sensor::Sensor(const Sensor& sensor) {}
void Sensor::operator=(const Sensor & sensor){}
Sensor::~Sensor() { car_ = nullptr; }
SpeedSensor::SpeedSensor() {}
SpeedSensor::SpeedSensor(const SpeedSensor& speedSensor)
{
	this->car_ = speedSensor.car_;
	this->speed_ = speedSensor.speed_;
}
SpeedSensor& SpeedSensor::operator=(const SpeedSensor& speedSensor)
{
	if (this != &speedSensor)
	{
		this->car_ = speedSensor.car_;
		this->speed_ = speedSensor.speed_;
		return *this;
	}
	else return *this;
}
SpeedSensor::~SpeedSensor() {}
SpeedSensor::SpeedSensor(Auto & car) :Sensor(car) {}
DistanceSensor::DistanceSensor() {}
DistanceSensor::DistanceSensor(const DistanceSensor& distanceSensor)
{
	this->car_ = distanceSensor.car_;
	this->distance_ = distanceSensor.distance_;
}
DistanceSensor& DistanceSensor::operator=(const DistanceSensor& distanceSensor)
{
	if (this != &distanceSensor)
	{
		this->car_ = distanceSensor.car_;
		this->distance_ = distanceSensor.distance_;
		return *this;
	}
	else return *this;
}
DistanceSensor::~DistanceSensor() {}
DistanceSensor::DistanceSensor(Auto  & car) : Sensor(car) {}
TimeSensor::TimeSensor() {}
TimeSensor::TimeSensor(const TimeSensor& timeSensor)
{
	this->car_ = timeSensor.car_;
	this->time_ = timeSensor.time_;
}
TimeSensor& TimeSensor::operator=(const TimeSensor& timeSensor)
{
	if (this != &timeSensor)
	{
		this->car_ = timeSensor.car_;
		this->time_ = timeSensor.time_;
		return *this;
	}
	else return *this;
}
TimeSensor::~TimeSensor() {}
TimeSensor::TimeSensor(Auto & car) : Sensor(car) {}
void SpeedSensor::applyParameter()
{
	speed_ = car_->getSpeed();
}
void SpeedSensor::viewParameter()
{
	cout <<"Speed: "<< speed_ << '\n';
}
void DistanceSensor::applyParameter()
{
	distance_ = car_->getSpeed()*(clock()/1000)/60;
}
void DistanceSensor::viewParameter()
{
	cout <<"Distance: "<< distance_ <<" Meter"<<'\n';
}
void TimeSensor::applyParameter()
{
	time_ = clock()/1000;
}
void TimeSensor::viewParameter()
{
	cout << "Time: " << time_ << '\n';
}