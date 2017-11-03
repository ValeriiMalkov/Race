#include "Autobahn.h"
#ifndef ROAD_H
#define ROAD_H
class Decor : public Road
{
public:
	Decor();
	Decor(Road * road);
	~Decor();
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj)const;
	void viewer();
protected:
	Road* road_;
private:

	/*Decor(const Road& road);
	void operator=(const Road& road);*/


};
#endif;
