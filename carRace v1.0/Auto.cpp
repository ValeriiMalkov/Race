#include "Auto.h"
Auto::Auto() :X_(10), Y_(24),size_(3),speed_(100),
control_(nullptr),maxSpeed_(400)
{

	while (true)
	{
		try
		{
			car_ = new char*[size_];
			for (int i = 0;i < size_;i++)
				car_[i] = new char[size_];
			//carInitializer();
			return;
		}
		catch (bad_alloc)
		{
		}
	}
	
}
Auto& Auto::operator=(const Auto& car)
{
	if (this != &car)
	{
		this->car_ = car.car_;
		this->X_ = car.X_;
		this->Y_ = car.Y_;
		this->size_ = car.size_;
		this->board_ = car.board_;
		this->control_ = car.control_;
		this->maxSpeed_ = car.maxSpeed_;
		this->speed_ = car.speed_;
		return *this;
	}
	else return *this;
}
Auto::Auto(const Auto & car)
{
		this->car_ = car.car_;
		this->X_ = car.X_;
		this->Y_ = car.Y_;
		this->size_ = car.size_;
		this->board_ = car.board_;
		this->control_ = car.control_;
		this->maxSpeed_ = car.maxSpeed_;
		this->speed_ = car.speed_;
}
Auto::~Auto()
{
	for (int i = 0;i < size_;i++)
		delete[] car_[i];
	delete control_;
	delete board_;
}
void Auto::carInitializer()
{
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			if (i == 0)
			{
				if (j == 0 || j == 2)
					car_[i][j] = 'O';
				else car_[i][j] = ' ';
			}
			if (i == 1)
			{
				if (j == 0 || j == 2)
					car_[i][j] = '|';
				else car_[i][j] = 'X';
			}
			if (i == 2)
			{
				if (j == 0 || j == 2)
					car_[i][j] = 'O';
				else car_[i][j] = ' ';
			}
		}
	}
}
void Auto::carCleaner()
{
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			car_[i][j] = ' ';
		}
	}
}
void Auto::view()
{
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			cout << car_[i][j];
		}
		cout << "\n";
	}
}
void Auto::goToRoad(const Asphalt & asphalt)
{
	carInitializer();
	asphalt.setObject(X_, Y_, car_, size_);
}
void Auto::boardViewer()
{
	board_->applyParameter();
	board_->viewParameter();
}
void Auto::boardOn()
{
	board_ = new Dashboard(*this);
}
void Auto::newState(const Asphalt & asphalt)
{
	carCleaner();
	asphalt.setObject(X_, Y_, car_, size_);
}
void Auto::changeX(int X)
{
	X_ += X;
}
void Auto::changeY(int Y)
{
	Y_ += Y;
}
void Auto::changeSpeed(int speed)
{
	if ((speed_ + speed) <= 0)return;
	else if (speed_ +speed >= maxSpeed_)return;
	else
	speed_ += speed;
}
int Auto::getX()
{
	return X_;
}
int Auto::getY()
{
	return Y_;
}
int Auto::getX()const
{
	return X_;
}
int Auto::getY()const
{
	return Y_;
}
int Auto::getSpeed()
{
	return speed_;
}
int Auto::getSpeed()const
{
	return speed_;
}
void Auto::carControler(const Asphalt & asphalt)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if ((X_ - 3+1) >= 1)
		{
			newState(asphalt);
			control_ = new Left();
			control_->changeState(*this);
		}
		else return;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if ((X_ + size_) < asphalt.getSize()-2 )
		{
			newState(asphalt);
			control_ = new Right();
			control_->changeState(*this);
		}
		if((X_ +size_)== asphalt.getSize()) return;
		else return;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		control_ = new Up();
		control_->changeState(*this);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		control_ = new Down();
		control_->changeState(*this);
	}
	else return;
	

}
