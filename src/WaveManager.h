#pragma once
#include <string>
#include "Resistance.h"
#include <vector>
#include "Timer.h"
#include "IObservee.h"

class EnemyData
{
public:
	std::string skinFileName;
	double life;
	int speed;
	int gold;
	std::vector<Resistance> resistances;	
};

class WaveData
{
public:
	std::vector<EnemyData> enemies;
	int spawnRate;
};

enum WaveManagerEvents
{
	Tick = 2,
	FinalWave
};

class WaveManager : public IObservee
{
	std::vector<WaveData> waves;
	Timer timer;
	int spawnRate;
	bool start;
	unsigned int currentWave;
	int next;
	long period;
public:
	WaveManager(void);
	~WaveManager(void);

	void loadFromFile(std::string fileName);
	void setWaveSpawnRate(int rate);
	void update();

	double getTimeToNextWave();

private:
	void resetTimer();

};

