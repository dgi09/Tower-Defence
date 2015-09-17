#pragma once 

class PlayerGlobal
{
	static PlayerGlobal * ptr;

	unsigned int points;
public:

	static PlayerGlobal * getPtr();
	static void destroy();

	PlayerGlobal();
	~PlayerGlobal();

	unsigned int getPoints();
	void setPoints(unsigned int points);

	void reducePoints(unsigned int amount);
	void addPoints(unsigned int amount);


	void calculateAllPoints();
};