#include "Auto.h"
Auto::Auto() :X(10), Y(24),size(3),speed(100),control(nullptr),maxSpeed(400)
{

	while (true)
	{
		try
		{
			car = new char*[size];
			for (int i = 0;i < size;i++)
				car[i] = new char[size];
			//carInitializer();
			return;
		}
		catch (bad_alloc)
		{
		}
	}
	
}
Auto::~Auto()
{
	for (int i = 0;i < size;i++)
		delete[] car[i];
	delete control;
	delete board;
}
void Auto::carInitializer()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (i == 0)
			{
				if (j == 0 || j == 2)
					car[i][j] = 'O';
				else car[i][j] = ' ';
			}
			if (i == 1)
			{
				if (j == 0 || j == 2)
					car[i][j] = '|';
				else car[i][j] = 'X';
			}
			if (i == 2)
			{
				if (j == 0 || j == 2)
					car[i][j] = 'O';
				else car[i][j] = ' ';
			}
		}
	}
}
void Auto::carCleaner()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			car[i][j] = ' ';
		}
	}
}
void Auto::view()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << car[i][j];
		}
		cout << "\n";
	}
}
void Auto::goToRoad(Asphalt & asphalt)
{
	carInitializer();
	asphalt.setObject(X, Y, car, size);
}
void Auto::boardViewer()
{
	board->applyParameter();
	board->viewParameter();
}
void Auto::boardOn()
{
	board = new Dashboard(*this);
}
void Auto::newState(Asphalt & asphalt)
{
	carCleaner();
	asphalt.setObject(X, Y, car, size);
}
void Auto::changeX(int _X)
{
	X += _X;
}
void Auto::changeY(int _Y)
{
	Y += _Y;
}
void Auto::changeSpeed(int _speed)
{
	if ((speed + _speed) <= 0)return;
	else if (speed+_speed >= maxSpeed)return;
	else
	speed += _speed;
}
int Auto::getX()
{
	return X;
}
int Auto::getY()
{
	return Y;
}
int Auto::getSpeed()
{
	return speed;
}
void Auto::carControler(Asphalt & asphalt)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if ((X - 3+1) >= 1)
		{
			newState(asphalt);
			control = new Left();
			control->changeState(*this);
		}
		else return;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if ((X + size) < asphalt.getSize()-2 )
		{
			newState(asphalt);
			control = new Right();
			control->changeState(*this);
		}
		if((X+size)== asphalt.getSize()) return;
		else return;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		control = new Up();
		control->changeState(*this);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		control = new Down();
		control->changeState(*this);
	}
	else return;
	

}
