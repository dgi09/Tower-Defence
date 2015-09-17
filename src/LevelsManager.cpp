#include "LevelsManager.h"
#include <fstream>


LevelsManager * LevelsManager::ptr = nullptr;

LevelsManager * LevelsManager::getPtr()
{
	if(ptr == nullptr)
		ptr = new LevelsManager();

	return ptr;
}

void LevelsManager::destroy()
{
	if(ptr != nullptr)
		delete ptr;
}

void LevelsManager::init()
{
	std::fstream file("Data/levels.txt");
	int numberOfLevels;
	file >> numberOfLevels;

	levels.reserve(numberOfLevels);
	for(int i = 0;i < numberOfLevels;i++)
	{
		Level l;
		l.wonPoints = 0;
		file >> l.folder;
		file >> l.requiredPoints;

		levels.push_back(l);
	}

	file.close();
}

unsigned int LevelsManager::getNumberOfLevels()
{
	return levels.size();
}

Level & LevelsManager::getLevelAt(unsigned int index)
{
	return levels[index];
}
