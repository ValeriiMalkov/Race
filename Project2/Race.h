#include "Auto.h"
#include "Barrier.h"
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
	shared_ptr<Road> road_;
	shared_ptr<Barrier> barrier_;
	Auto car_;
	bool status_;
private:
	void gameOver();
};
#endif;
