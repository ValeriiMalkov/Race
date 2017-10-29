#include "Auto.h"
#include "Barrier.h"
#include "Map.h"
#ifndef RACE_H
#define RACE_H
class Race
{
private:
	Asphalt * asphalt_;
	Barrier * barrier_;
	Auto car_;
	bool status_;
public:
	Race();
	Race(const Race& race);
	Race& operator=(const Race& race);
	~Race();
	void Start();
private:
	void gameOver();
};
#endif;
