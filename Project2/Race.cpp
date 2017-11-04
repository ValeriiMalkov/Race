#include "Race.h"
Race::Race() :status_(true)
{
	road_ = shared_ptr<Road>(new Line(shared_ptr<Road>
		(new Line(shared_ptr<Road>(new Autobahn), 5)), 18));
	barrier_ = shared_ptr<Barrier>(new Barrier(*road_));
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
	 road_.~shared_ptr();
	barrier_.~shared_ptr();
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
		if ((*road_->getMap())(car_.getY(),car_.getX()) == barrier_->getObject() ||
			(*road_->getMap())(car_.getY(),car_.getX() + 1) == barrier_->getObject() ||
			(*road_->getMap())(car_.getY(),car_.getX() + 2) == barrier_->getObject())
		{
			status_ = false;
		}
		if (!barrier_->newPosition())
		{
			barrier_.~shared_ptr();
			road_ = shared_ptr<Road>(new Line(shared_ptr<Road>
				(new Line(shared_ptr<Road>(new Autobahn), 5)), 18));
			
			barrier_ =shared_ptr<Barrier>( new Barrier(*road_));
		}

		Sleep(1 / static_cast<double>(car_.getSpeed()) * 1000);
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