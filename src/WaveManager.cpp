#include "WaveManager.h"
#include <fstream>
#include <string>
#include "Wave.h"
#include "EnemyBase.h"
#include "GamePlayMediator.h"
#include "ArenaHeap.h"


using namespace std;


WaveManager::WaveManager(void)
{
	start = false;
	currentWave = 0;
}


WaveManager::~WaveManager(void)
{
}

void WaveManager::loadFromFile(std::string fileName)
{
	ifstream file(fileName.c_str());
	int numberOfWaves;
	file >> numberOfWaves;
	int wavesSpawnRate;
	file >> wavesSpawnRate;

	setWaveSpawnRate(wavesSpawnRate);

	for(int i = 0;i < numberOfWaves;i++)
	{
		int numberOfEnemies;
		file >> numberOfEnemies;


		WaveData wave;
		file >> wave.spawnRate;

		for(int j = 0;j < numberOfEnemies;j++)
		{
			EnemyData en;
			file >> en.skinFileName;			
			file >> en.life;
			file >> en.speed;
			file >> en.gold;

			wave.enemies.push_back(en);
		}


		waves.push_back(wave);
	}

	file.close();
}


void WaveManager::setWaveSpawnRate(int rate)
{
	spawnRate = rate;
}

void WaveManager::update()
{
	if(start == false)
	{
		if(waves.size() > 0)
			next = spawnRate;

		resetTimer();
		start = true;


	}

	if(timer.getMSec() - period >= 100)
	{
		period = timer.getMSec();
		notify((int)Tick);
	}


	if(currentWave < waves.size())
	{
		if(timer.getMSec() >= next)
		{
			WaveData w = waves[currentWave];
			Wave * wave = ArenaHeap::getPtr()->Waves.New();
			wave->init();
			wave->setSpawnRate(w.spawnRate);

			for(int i = 0;i < w.enemies.size();i++)
			{
				EnemyBase * enemy = ArenaHeap::getPtr()->Enemies.New();
				enemy->init();
				string s = "Data/Enemies/" + w.enemies[i].skinFileName;
				enemy->loadTextureFromFile(s.c_str());
				enemy->setGold(w.enemies[i].gold);
				enemy->setMaxLife(w.enemies[i].life);
				enemy->setLife(w.enemies[i].life);
				enemy->setSpeed(w.enemies[i].speed);

				wave->addElement(enemy);
			}

			GamePlayMediator::getPtr()->getArena()->addWave(wave);


			
			next = waves[currentWave].spawnRate * waves[currentWave].enemies.size() + spawnRate;
			

			currentWave++;
			if(currentWave >= waves.size())
			{
				GamePlayMediator::getPtr()->getArena()->setFinalWaveAdded(true);
				notify((int)FinalWave);
			}
			else 
				resetTimer();
		}
	}

}

void WaveManager::resetTimer()
{
	timer.start();
	period = 0;

	notify((int)Tick);
}

double WaveManager::getTimeToNextWave()
{
	unsigned int ms = timer.getMSec();
	if(next - ms <= 0)
		return 0.0;
	else return (double)(next - ms) /  1000.0;
}
