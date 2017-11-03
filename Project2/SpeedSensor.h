#include"Sensor.h"
#ifndef SPEEDSENSOR_H
#define SPEEDSENSOR_H
class SpeedSensor :public Sensor
{
public:
	//SpeedSensor(Auto & car);
	SpeedSensor();
	SpeedSensor(const SpeedSensor & speedSensor);
	~SpeedSensor();
	SpeedSensor& operator=(const SpeedSensor& speedSensor);
	void applyParameter(const int& speed);
	void viewParameter();
private:
	int speed_;


};
#endif;
