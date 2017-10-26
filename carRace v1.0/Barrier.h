#ifndef BARRIER_H
#define BARRIER_H
#include<ctime>
#include<cstdlib>
#include "Map.h"
class Barrier
{
private:
	char ** barrier;
	char object;
	int size;
	int X;
	int Y;
	Asphalt *asphalt;
public:
	Barrier(Asphalt & _asphalt);
	~Barrier();
	void goToRoad();
	void view();
	bool newPosition();
	char getObject();
private:
	void barrierInitializer();
	void barrierCleaner();
};
#endif;
