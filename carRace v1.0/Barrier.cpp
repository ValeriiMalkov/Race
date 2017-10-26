#include "Barrier.h"
Barrier::Barrier(Asphalt & _asphalt) :size(2),object(static_cast<char>(219)),Y(0)
{
	asphalt = &_asphalt;
	X = rand()%23+1;
	while (true)
	{
		try
		{
			barrier = new char*[size];
			for (int i = 0;i < size;i++)
				barrier[i] = new char[size];
			return;
		}
		catch (bad_alloc)
		{
			
		}
	}
	
}
Barrier::~Barrier()
{
	barrierCleaner();
	for (int i = 0;i < size;i++)
		delete[] barrier[i];
}
void Barrier::barrierInitializer()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			barrier[i][j] = object;
		}
	}
}
void Barrier::barrierCleaner()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			barrier[i][j] = ' ';
		}
	}
	asphalt->setObject(X, Y, barrier, size);
}
void Barrier::goToRoad()
{
	barrierInitializer();
	asphalt->setObject(X, Y, barrier, size);
}
void Barrier::view()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout<<barrier[i][j];
		}
		cout << '\n';
	}
}
bool Barrier::newPosition()
{
	if ((Y +2) >= asphalt->getSize())return false;
	else
	{
		barrierCleaner();
		Y++;
		goToRoad();
		return true;
	}
}
char Barrier::getObject()
{
	return object;
}