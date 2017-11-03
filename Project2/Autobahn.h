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
	inline void setObject(int x, int y, char** obj, int sizeObj) const;
	void viewer();
private:
	void mapInitializer();
};
inline void Autobahn::setObject(int x, int y, char ** obj, int sizeObj)const
{
	for (int i = 0; i < sizeObj; i++)
	{
		for (int j = 0; j < sizeObj; j++)
		{
			map_[y + i][x + j] = obj[i][j];
		}
	}
}
#endif;
