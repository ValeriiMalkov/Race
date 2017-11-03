#include "Autobahn.h"
#ifndef ROAD_H
#define ROAD_H
class Decor : public Road
{
public:
	Decor();
	Decor(Road * road);
	~Decor();
	void add();
	inline void setObject(int X, int Y, char** obj, int sizeObj)const;
	void viewer();
protected:
	Road* road_;
private:

	/*Decor(const Road& road);
	void operator=(const Road& road);*/


};
inline void Decor::setObject(int X, int Y, char ** obj, int sizeObj)const
{
	for (int i = 0; i < sizeObj; i++)
	{
		for (int j = 0; j < sizeObj; j++)
		{
			map_[Y + i][X + j] = obj[i][j];
		}
	}
	road_->setObject(X, Y, obj, sizeObj);
}
#endif;
