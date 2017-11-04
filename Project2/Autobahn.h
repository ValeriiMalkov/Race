#include"Road.h"
#ifndef MAP_H
#define MAP_H
using namespace std;
class Autobahn : public Road
{
public:
	Autobahn();
	~Autobahn();
	void add();
	inline void setObject(int x, int y, Object& object) const;
	void viewer();
private:
};
inline void Autobahn::setObject(int x, int y, Object& object)const
{
	for (int i = 0; i < object.getSize(); i++)
	{
		for (int j = 0; j < object.getSize(); j++)
		{
			(*map_)(i + y, j + x) = object(i, j);
		}
	}
}
#endif;
