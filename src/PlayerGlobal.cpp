#include "PlayerGlobal.h"
#include "LevelsManager.h"


PlayerGlobal * PlayerGlobal::ptr = nullptr;

PlayerGlobal * PlayerGlobal::getPtr()
{
	if(ptr == nullptr)
		ptr = new PlayerGlobal();

	return ptr;
}

void PlayerGlobal::destroy()
{
	if(ptr != nullptr)
		delete ptr;
}

PlayerGlobal::PlayerGlobal()
{
	setPoints(0);
}

PlayerGlobal::~PlayerGlobal()
{

}

unsigned int PlayerGlobal::getPoints()
{
	return points;
}

void PlayerGlobal::setPoints(unsigned int points)
{
	this->points = points;
}

void PlayerGlobal::reducePoints(unsigned int amount)
{
	points -= amount;
}

void PlayerGlobal::addPoints(unsigned int amount)
{
	points += amount;
}

void PlayerGlobal::calculateAllPoints()
{
	unsigned int p = 0;

	for(int i = 0; i < LevelsManager::getPtr()->getNumberOfLevels();i++)
	{
		Level l = LevelsManager::getPtr()->getLevelAt(i);
		p += l.wonPoints;
	}

	setPoints(p);
}
