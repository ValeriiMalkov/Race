#include <iostream>
#include <new>  
#include<memory>
#include"Object.h"
#ifndef ASPHALT_H
#define ASPHALT_H
using namespace std;
class Road
{
public:
	Road();
	virtual ~Road();
	virtual void add() = 0;
	virtual void viewer() = 0;
	shared_ptr<Object>& getMap();
	virtual void setObject(int X, int Y, Object& object) const = 0;
	int getSize() const;
protected:
	int size_;
	shared_ptr<Object> map_;
private:
};

#endif;
