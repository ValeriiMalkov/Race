#include"Sensor.h"
#ifndef SPEEDSENSOR_H
#define SPEEDSENSOR_H
class SpeedSensor :public Sensor
{
private:
	int speed_;
public:
	//SpeedSensor(Auto & car);
	SpeedSensor();
	SpeedSensor(const SpeedSensor & speedSensor);
	~SpeedSensor();
	SpeedSensor& operator=(const SpeedSensor& speedSensor);
	void applyParameter(const int& speed);
	void viewParameter();
private:

};
#endif;
