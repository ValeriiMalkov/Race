#include "Decorator\Road.h"
#ifndef TWOLINEROAD_H
#define TWOLINEROAD_H
class TwoLineRoad : public Road
{
public:
	TwoLineRoad(Asphalt * asphalt);
	~TwoLineRoad();
	void add();
	void viewer();
private:
	TwoLineRoad();
	TwoLineRoad(const TwoLineRoad& two);
	void operator=(const TwoLineRoad& two);
};
#endif;