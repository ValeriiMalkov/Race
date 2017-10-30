#include "Decorator\Road.h"
#ifndef ONELINEROAD_H
#define ONELINEROAD_H
class OneLineRoad : public Road
{
public:
	OneLineRoad(Asphalt * asphalt);
	~OneLineRoad();
	void add();
	void viewer();
private:
	OneLineRoad();
	OneLineRoad(const OneLineRoad& one);
	void operator=(const OneLineRoad& one);

};
#endif;
