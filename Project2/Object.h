#include <iostream>
#ifndef OBJECT_H
#define OBJECT_H
using namespace std;
class Object
{
public:
	explicit Object(int size);
	Object(const Object& object);
	~Object();
	int getSize();
	char& operator()(int i, int j);
	void draw();
private:
	mutable  int size_;
	char** matrix_;
private:
	Object();
};
#endif // !OBJECT_H
