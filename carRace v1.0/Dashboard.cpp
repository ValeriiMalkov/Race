#include"Auto.h"
Dashboard::Dashboard() {}
Dashboard::Dashboard(Auto & car):Sensor(car)
{
	sensor_.push_back(new SpeedSensor(car));
	sensor_.push_back(new DistanceSensor(car));
	sensor_.push_back(new TimeSensor(car));
}
Dashboard::Dashboard(const Dashboard & dashboard)
{
	this->sensor_ = dashboard.sensor_;
	this->car_ = dashboard.car_;
}
Dashboard::~Dashboard()
{
	sensor_.~vector();
}
Dashboard& Dashboard::operator=(const Dashboard& dashboard)
{
	if (this != &dashboard)
	{
		this->sensor_ = dashboard.sensor_;
		this->car_ = dashboard.car_;
		return *this;
	}
	else return *this;
}
void Dashboard::applyParameter()
{
	for (int i = 0;i < sensor_.size();i++)
		sensor_[i]->applyParameter();
}
void Dashboard::viewParameter()
{
	for (int i = 0;i < sensor_.size();i++)
		sensor_[i]->viewParameter();
}