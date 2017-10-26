#include"Auto.h"
Sensor::Sensor(Auto & _car)
{
	car = &_car;
}
SpeedSensor::SpeedSensor(Auto & car) :Sensor(car) {}
DistanceSensor::DistanceSensor(Auto  & car) : Sensor(car) {}
TimeSensor::TimeSensor(Auto & car) : Sensor(car) {}
void SpeedSensor::applyParameter()
{
	speed = car->getSpeed();
}
void SpeedSensor::viewParameter()
{
	cout <<"Speed: "<< speed << '\n';
}
void DistanceSensor::applyParameter()
{
	distance = car->getSpeed()*(clock()/1000)/60;
}
void DistanceSensor::viewParameter()
{
	cout <<"Distance: "<< distance<<" Meter"<<'\n';
}
void TimeSensor::applyParameter()
{
	time = clock()/1000;
}
void TimeSensor::viewParameter()
{
	cout << "Time: " << time << '\n';
}