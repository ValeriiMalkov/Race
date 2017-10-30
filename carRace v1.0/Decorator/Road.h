#include "Asphalt.h"
#ifndef ROAD_H
#define ROAD_H
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
#endif;
