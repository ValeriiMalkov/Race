#include "Decor.h"
#ifndef LINE_H
#define LINE_H
class Line : public Decor
{
public:
	int  coord_;
public:
	Line(Road * road, int x);
	~Line();
	void add();
	/*void viewer();*/
private:
	Line();
	/*Line(const Line& two);
	void operator=(const TwoLineRoad& two);*/
};
#endif;
