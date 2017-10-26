#include"Auto.h"
Dashboard::Dashboard() {}
Dashboard::Dashboard(Auto & _car):Sensor(_car)
{
	sensor.push_back(new SpeedSensor(_car));
	sensor.push_back(new DistanceSensor(_car));
	sensor.push_back(new TimeSensor(_car));
}
void Dashboard::applyParameter()
{
	for (int i = 0;i < sensor.size();i++)
		sensor[i]->applyParameter();
}
void Dashboard::viewParameter()
{
	for (int i = 0;i < sensor.size();i++)
		sensor[i]->viewParameter();
}