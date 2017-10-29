#include <iostream>
#include <new>   
#ifndef MAP_H
#define MAP_H
using namespace std;
class Asphalt
{
private:
	Asphalt(const Asphalt & asphalt);
	void operator=(const Asphalt& asphalt);
public:
	Asphalt();
	virtual ~Asphalt();
	virtual void add() = 0;
	virtual void viewer() = 0;
	char** getMap();
	virtual void setObject(int X, int Y,char** obj,int sizeObj) const=0;
	int getSize() const;
protected:
	int size_;
	char** map_;
};
class Map : public Asphalt
{
private:
	void mapInitializer();
	Map(const Asphalt& map);
	void operator=(const Map& map);
public:
	Map();
	~Map();
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj) const;
	void viewer();
};
class Road : public Asphalt
{
private:
	Road();
	Road(const Road& road);
	void operator=(const Road& road);
protected:
	Asphalt* asphalt_;
public:
	Road(Asphalt * asphalt);
	~Road();
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj)const;
	void viewer();
};
class OneLineRoad : public Road
{
private:
		OneLineRoad();
		OneLineRoad(const OneLineRoad& one);
		void operator=(const OneLineRoad& one);
public:
	OneLineRoad(Asphalt * asphalt);
	~OneLineRoad();
	void add();
	void viewer();
};
class TwoLineRoad : public Road
{
private:
	TwoLineRoad();
	TwoLineRoad(const TwoLineRoad& two);
	void operator=(const TwoLineRoad& two);
public:
	TwoLineRoad(Asphalt * asphalt);
	~TwoLineRoad();
	void add();
	void viewer();
};
#endif;
