#include<ctime>
#include<cstdlib>
#include "Autobahn.h"
#ifndef BARRIER_H
#define BARRIER_H
class Barrier
{
public:
	Barrier(const Barrier& barrier);
	Barrier& operator=(const Barrier& barrier);
	Barrier(Road & road);
	~Barrier();
	void goToRoad();
	void view();
	bool newPosition();
	inline char getObject();
private:
	char ** barrier_;
	char object_;
	int size_;
	int x_;
	int y_;
	Road *road_;
private:
	Barrier();
	void barrierInitializer();
	void barrierCleaner();
};
inline char Barrier::getObject()
{
	return object_;
}
#endif;
