#include <iostream>
#include <new>  
#ifndef ASPHALT_H
#define ASPHALT_H
using namespace std;
class Asphalt
{

public:
	Asphalt();
	virtual ~Asphalt();
	virtual void add() = 0;
	virtual void viewer() = 0;
	char** getMap();
	virtual void setObject(int X, int Y, char** obj, int sizeObj) const = 0;
	int getSize() const;
protected:
	int size_;
	char** map_;
private:
	Asphalt(const Asphalt & asphalt);
	void operator=(const Asphalt& asphalt);
};
#endif;
