#include"Dashboard.h"
Dashboard::Dashboard()
{
	sensor_.push_back(new SpeedSensor());
	sensor_.push_back(new DistanceSensor());
	sensor_.push_back(new TimeSensor());
}
//Dashboard::Dashboard(Auto & car):Sensor(car)
//{
//	sensor_.push_back(new SpeedSensor(car));
//	sensor_.push_back(new DistanceSensor(car));
//	sensor_.push_back(new TimeSensor(car));
//}
Dashboard::Dashboard(const Dashboard & dashboard)
{
	this->sensor_ = dashboard.sensor_;
	//this->car_ = dashboard.car_;
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
		//this->car_ = dashboard.car_;
		return *this;
	}
	else return *this;
}
void Dashboard::applyParameter(const int& speed)
{
	for (int i = 0; i < sensor_.size(); i++)
		sensor_[i]->applyParameter(speed);
}
void Dashboard::viewParameter()
{
	for (int i = 0; i < sensor_.size(); i++)
		sensor_[i]->viewParameter();
}