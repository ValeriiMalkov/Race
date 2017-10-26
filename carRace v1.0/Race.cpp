#include "Race.h"
Race::Race():status(true)
{
	asphalt = new Road(new OneLineRoad(new Map));
	barrier = new Barrier(*asphalt);
	car.boardOn();
}
Race::~Race()
{
	delete asphalt;
	delete barrier;
	car.~Auto();
}
void Race::Start()
{
	while (status)
	{
		car.goToRoad(*asphalt);
		barrier->goToRoad();
		asphalt->viewer();
		car.boardViewer();
		car.carControler(*asphalt);
		if (asphalt->getMap()[car.getY()][car.getX()] == barrier->getObject() || asphalt->getMap()[car.getY()][car.getX()+1] == barrier->getObject() || asphalt->getMap()[car.getY()][car.getX() + 2] == barrier->getObject())
		{
			status = false;
		}
		if (!barrier->newPosition())
		{
			barrier->~Barrier();
			asphalt = new Road(new TwoLineRoad(new Map));
			barrier = new Barrier(*asphalt);
		}
		
		Sleep(1 / static_cast<double>(car.getSpeed()) * 1000);
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
