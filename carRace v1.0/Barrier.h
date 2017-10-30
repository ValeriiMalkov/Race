#include<ctime>
#include<cstdlib>
#include "Map.h"
#ifndef BARRIER_H
#define BARRIER_H
class Barrier
{
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
	char ** barrier_;
	char object_;
	int size_;
	int X_;
	int Y_;
	Asphalt *asphalt_;
private:
	Barrier();
	void barrierInitializer();
	void barrierCleaner();
};
#endif;
