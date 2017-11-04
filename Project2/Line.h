#include "Decor.h"
#ifndef LINE_H
#define LINE_H
class Line : public Decor
{
public:
	int  coord_;
public:
	Line(shared_ptr<Road>& road, int x);
	~Line();
	void add();
private:
	Line();
};
#endif;
