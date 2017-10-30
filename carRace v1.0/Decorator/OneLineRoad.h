#include "Road.h"
#ifndef ONELINEROAD_H
#define ONELINEROAD_H
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
#endif;
