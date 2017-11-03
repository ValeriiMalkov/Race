#include "Autobahn.h"
Autobahn::Autobahn() : Road()
{
	add();
	mapInitializer();
}
Autobahn::~Autobahn()
{

}
void Autobahn::add()
{
	while (true)
	{
		try
		{
			map_ = new char*[size_];
			for (int i = 0; i < size_; i++)
				map_[i] = new char[size_];
			return;
		}
		catch (bad_alloc)
		{
		}
	}

}
void Autobahn::mapInitializer()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			map_[i][0] = '|';

			map_[i][size_ - 2] = '|';
			map_[i][j] = ' ';
		}
	}
}

void Autobahn::viewer()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			cout << map_[i][j];
		}
		cout << '\n';
	}
}