#ifndef RACE_H
#define RACE_H
#include "Auto.h"
#include "Barrier.h"
#include "Map.h"
class Race
{
private:
	Asphalt * asphalt;
	Barrier * barrier;
	Auto car;
	bool status;
public:
	Race();
	~Race();
	void Start();
private:
	void gameOver();
};
#endif;
