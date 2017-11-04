#include "Auto.h"
Auto::Auto() :x_(10), y_(24), size_(3), speed_(100),
control_(nullptr), maxSpeed_(400)
{
	car_ = shared_ptr<Object>(new Object(size_));
}
Auto& Auto::operator=(const Auto& car)
{
	if (this != &car)
	{
		this->car_ = car.car_;
		this->x_ = car.x_;
		this->y_ = car.y_;
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
	this->x_ = car.x_;
	this->y_ = car.y_;
	this->size_ = car.size_;
	this->board_ = car.board_;
	this->control_ = car.control_;
	this->maxSpeed_ = car.maxSpeed_;
	this->speed_ = car.speed_;
}
Auto::~Auto()
{
	car_.~shared_ptr();
	control_.~shared_ptr();
	board_.~shared_ptr();
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
					(*car_)(i,j) = 'O';
				else (*car_)(i,j) = ' ';
			}
			if (i == 1)
			{
				if (j == 0 || j == 2)
					(*car_)(i, j) = '|';
				else (*car_)(i, j) = 'X';
			}
			if (i == 2)
			{
				if (j == 0 || j == 2)
					(*car_)(i, j) = 'O';
				else (*car_)(i, j) = ' ';
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
			(*car_)(i, j) = ' ';
		}
	}
}
void Auto::view()
{
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			cout << (*car_)(i,j);
		}
		cout << "\n";
	}
}
void Auto::goToRoad(const Road & road)
{
	carInitializer();
	road.setObject(x_, y_, *car_);
}
void Auto::boardViewer()
{
	board_->applyParameter(speed_);
	board_->viewParameter();
}
void Auto::boardOn()
{
	board_ = shared_ptr<Dashboard>(new Dashboard());
}
void Auto::newState(const Road & road)
{
	carCleaner();
	road.setObject(x_, y_, *car_);
}
void Auto::changeX(int x)
{
	x_ += x;
}
void Auto::changeY(int y)
{
	y_ += y;
}
void Auto::changeSpeed(int speed)
{
	if ((speed_ + speed) <= 0)return;
	else if (speed_ + speed >= maxSpeed_)return;
	else
		speed_ += speed;
}
void Auto::carControler(const Road & road)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if ((x_ - 3 + 1) >= 1)
		{
			newState(road);
			control_ =shared_ptr<Control>( new Left());
			control_->changeState(x_);
		}
		else return;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if ((x_ + size_) < road.getSize() - 2)
		{
			newState(road);
			control_ = shared_ptr<Control>(new Right());
			control_->changeState(x_);
		}
		if ((x_ + size_) == road.getSize()) return;
		else return;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		control_ = shared_ptr<Control>( new Up());
		if (speed_ <= maxSpeed_)
			control_->changeState(speed_);
		else return;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		control_ = shared_ptr<Control>( new Down());
		if (speed_>10)
			control_->changeState(speed_);
		else return;
	}
	else return;


}