#include "Race.h"
Race::Race():status_(true)
{
	asphalt_ = new Road(new OneLineRoad(new Map));
	barrier_ = new Barrier(*asphalt_);
	car_.boardOn();
}
Race::Race(const Race& race)
{
	this->asphalt_ = race.asphalt_;
	this->barrier_ = race.barrier_;
	this->car_ = race.car_;
	this->status_ = race.status_;
}
Race& Race::operator=(const Race& race)
{
	if (this != &race)
	{
		this->asphalt_ = race.asphalt_;
		this->barrier_ = race.barrier_;
		this->car_ = race.car_;
		this->status_ = race.status_;
		return *this;
	}
	else return *this;
}
Race::~Race()
{
	delete asphalt_;
	delete barrier_;
	car_.~Auto();
}
void Race::Start()
{
	while (status_)
	{
		car_.goToRoad(*asphalt_);
		barrier_->goToRoad();
		asphalt_->viewer();
		car_.boardViewer();
		car_.carControler(*asphalt_);
	if (asphalt_->getMap()[car_.getY()][car_.getX()] == barrier_->getObject()|| 
	asphalt_->getMap()[car_.getY()][car_.getX()+1] == barrier_->getObject() ||
	asphalt_->getMap()[car_.getY()][car_.getX() + 2] == barrier_->getObject())
		{
			status_ = false;
		}
		if (!barrier_->newPosition())
		{
			barrier_->~Barrier();
			asphalt_ = new Road(new TwoLineRoad(new Map));
			barrier_ = new Barrier(*asphalt_);
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
