#pragma once
#include <vector>
#include "Manager.h"
#include "Timer.h"


struct SDL_Renderer;
class EnemyBase;

class Wave : public Manager<EnemyBase>
{
	Timer timer;
	bool startTimer;
	int spawnRate;
	int activeEnemies;
public:
	Wave(void);
	~Wave(void);

	void getFirst(std::vector<EnemyBase*>::iterator & _it);
	void getLast(std::vector<EnemyBase*>::iterator & _it);

	std::vector<EnemyBase*>::iterator * last();

	void drawAllEnemies(SDL_Renderer * renderer);
	

	void setSpawnRate(int rate);
	int getSpawnRate();

	void updateWave();
	void updateAllEnemies();

	int getNumberOfActiveEnemies();
	void init();
};

