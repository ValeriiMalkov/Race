#include <iostream>
#include <new>  
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
	char** getMap();
	virtual void setObject(int X, int Y, char** obj, int sizeObj) const = 0;
	int getSize() const;
protected:
	int size_;
	char** map_;
private:
	/*Road(const Road & road);
	void operator=(const Road& asphalt);*/
};
#endif;
