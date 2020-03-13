#include "Race.h"
#ifdef __linux__
#include <unistd.h>
#endif

Race::Race() :status_(true)
{
	road_ = new Line(new Line(new Autobahn, 15), 5);
	barrier_ = new Barrier(*road_);
	car_.boardOn();
}
Race::Race(const Race& race)
{
	this->road_ = race.road_;
	this->barrier_ = race.barrier_;
	this->car_ = race.car_;
	this->status_ = race.status_;
}
Race& Race::operator=(const Race& race)
{
	if (this != &race)
	{
		this->road_ = race.road_;
		this->barrier_ = race.barrier_;
		this->car_ = race.car_;
		this->status_ = race.status_;
		return *this;
	}
	else return *this;
}
Race::~Race()
{
	delete road_;
	delete barrier_;
	car_.~Auto();
}
void Race::Start()
{
	while (status_)
	{
		car_.goToRoad(*road_);
		barrier_->goToRoad();
		road_->viewer();
		car_.boardViewer();
		car_.carControler(*road_);
		if (road_->getMap()[car_.getY()][car_.getX()] == barrier_->getObject() ||
			road_->getMap()[car_.getY()][car_.getX() + 1] == barrier_->getObject() ||
			road_->getMap()[car_.getY()][car_.getX() + 2] == barrier_->getObject())
		{
			status_ = false;
		}
		if (!barrier_->newPosition())
		{
			barrier_->~Barrier();
			road_ = new Line(new Line(new Autobahn, 15), 5);
			barrier_ = new Barrier(*road_);
		}

		#ifdef _WIN32
		Sleep(1 / static_cast<double>(car_.getSpeed()) * 1000);
		#elif __linux__
		sleep(1 / static_cast<double>(car_.getSpeed()) * 1000);
		#endif

		system("cls");
	}
	gameOver();
}
void Race::gameOver()
{
	cout << "Game over";
	cin.get();
	return;
}