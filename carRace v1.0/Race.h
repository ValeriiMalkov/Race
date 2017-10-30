#include "Auto.h"
#include "Barrier.h"
#include "Decorator\Map.h"
#include "Decorator\OneLineRoad.h"
#include"Decorator\TwoLineRoad.h"
#ifndef RACE_H
#define RACE_H
class Race
{
public:
	Race();
	Race(const Race& race);
	Race& operator=(const Race& race);
	~Race();
	void Start();
private:
	Asphalt * asphalt_;
	Barrier * barrier_;
	Auto car_;
	bool status_;
private:
	void gameOver();
};
#endif;
