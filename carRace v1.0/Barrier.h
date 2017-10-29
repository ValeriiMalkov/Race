#include<ctime>
#include<cstdlib>
#include "Map.h"
#ifndef BARRIER_H
#define BARRIER_H

class Barrier
{
private:
	char ** barrier_;
	char object_;
	int size_;
	int X_;
	int Y_;
	Asphalt *asphalt_;
public:
	Barrier(const Barrier& barrier);
	Barrier& operator=(const Barrier& barrier);
	Barrier(Asphalt & asphalt);
	~Barrier();
	void goToRoad();
	void view();
	bool newPosition();
	char getObject();
private:
	Barrier();
	void barrierInitializer();
	void barrierCleaner();
};
#endif;
