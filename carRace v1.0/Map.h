#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <new>   
using namespace std;
class Asphalt
{
private:
public:
	Asphalt();
	~Asphalt();
	virtual void add() = 0;
	virtual void viewer() = 0;
	char** getMap();
	virtual void setObject(int X, int Y,char** obj,int sizeObj)=0;
	int getSize();
protected:
	int size;
	char** map;
};
class Map : public Asphalt
{
private:
private:
	void mapInitializer();
public:
	Map();
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj);
	void viewer();
};
class Road : public Asphalt
{
protected:
	Asphalt* asphalt;
public:
	Road(Asphalt * _asphalt);
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj);
	void viewer();
};
class OneLineRoad : public Road
{
public:
	OneLineRoad(Asphalt * _asphalt);
	void add();
	void viewer();
};
class TwoLineRoad : public Road
{
public:
	TwoLineRoad(Asphalt * asphalt);
	void add();
	void viewer();
};
#endif;
