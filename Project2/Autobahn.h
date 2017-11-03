#include"Road.h"
#ifndef MAP_H
#define MAP_H
using namespace std;
class Autobahn : public Road
{
public:
	Autobahn();
	~Autobahn();
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj) const;
	void viewer();
private:
	void mapInitializer();

};
#endif;
