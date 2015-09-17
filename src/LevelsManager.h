#pragma once 
#include <string>
#include <vector>


struct Level
{
	std::string folder;
	unsigned int requiredPoints;
	unsigned int wonPoints;
};

class LevelsManager
{
	static LevelsManager * ptr;

	std::vector<Level> levels;

public:

	static LevelsManager * getPtr();
	static void destroy();

	void init();
	unsigned int getNumberOfLevels();
	Level & getLevelAt(unsigned int index);

};