#include"Asphalt.h"
#ifndef MAP_H
#define MAP_H
using namespace std;
class Map : public Asphalt
{
private:
	void mapInitializer();
	Map(const Asphalt& map);
	void operator=(const Map& map);
public:
	Map();
	~Map();
	void add();
	void setObject(int X, int Y, char** obj, int sizeObj) const;
	void viewer();
};
#endif;
