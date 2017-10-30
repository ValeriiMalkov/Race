#include "Decorator\Asphalt.h"
#ifndef ROAD_H
#define ROAD_H
class Road : public Asphalt
{
public:
	Road(Asphalt * asphalt);
	~Road();
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj)const;
	void viewer();
protected:
	Asphalt* asphalt_;
private:
	Road();
	Road(const Road& road);
	void operator=(const Road& road);


};
#endif;
