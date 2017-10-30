#include"Sensor.h"
#include"SpeedSensor.h"
#include"DistanceSensor.h"
#include"TimeSensor.h"
#include<vector>
#ifndef DASHBOARD_H
#define DASHBOARD_H
class Dashboard : public Sensor
{
private:
	vector<Sensor*> sensor_;
public:
	Dashboard();
	//Dashboard(Auto & car);
	Dashboard(const Dashboard & dashboard);
	~Dashboard();
	Dashboard& operator=(const Dashboard & dashboard);
	void applyParameter(const int& speed);
	void viewParameter();
};
#endif;
