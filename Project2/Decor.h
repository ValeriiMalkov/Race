#include "Autobahn.h"
#ifndef ROAD_H
#define ROAD_H
class Decor : public Road
{
public:
	Decor();
	Decor(shared_ptr<Road>& road);
	~Decor();
	void add();
	inline void setObject(int X, int Y, Object& object)const;
	void viewer();
protected:
	shared_ptr<Road> road_;
};
inline void Decor::setObject(int X, int Y, Object& object)const
{
	for (int i = 0; i < object.getSize(); i++)
	{
		for (int j = 0; j < object.getSize(); j++)
		{
			(*map_)(Y + i, X + j) = object(i, j);
		}
	}
	road_->setObject(X, Y, object);
}
#endif;
