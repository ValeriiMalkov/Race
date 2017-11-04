#include"Object.h"
Object::Object(int size) :size_(size)
{
		matrix_ = new char*[size];
		for (int i = 0;i < size;i++)
			matrix_[i] = new char[size];
}
Object::Object(const Object& object)
{
	size_ = object.size_;
	matrix_ = object.matrix_;
}
char& Object::operator()(int i, int j)
{
	return matrix_[i][j];
}
int Object::getSize()
{
	return size_;
}
void Object::draw()
{
	for (int i = 0;i < size_;i++)
	{
		for (int j = 0;j < size_;j++)
		{
			cout << matrix_[i][j];
		}
		cout << "\n";
	}
}
Object::~Object()
{
	for (int i = 0;i < size_;i++)
		delete[] matrix_[i];
	delete[] matrix_;
}