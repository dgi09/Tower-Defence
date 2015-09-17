#include "Wave.h"
#include "SDL.h"
#include "EnemyBase.h"
#include "GamePlayMediator.h"
#include "ArenaHeap.h"


Wave::Wave(void):Manager()
{
	
}


Wave::~Wave(void)
{

}

void Wave::getFirst(std::vector<EnemyBase*>::iterator & _it)
{
	_it = elements.begin();
}

void Wave::getLast(std::vector<EnemyBase*>::iterator & _it)
{
	_it = elements.end();
}

void Wave::drawAllEnemies(SDL_Renderer * renderer)
{
	for(int i = 0;i < activeEnemies;i++)
	{
		elements[i]->draw(renderer);
	}
}
void Wave::updateAllEnemies()
{
	for(int i = 0;i<activeEnemies;i++)
	{
		if(elements[i] != NULL)
		{
			if(elements[i]->alive())
				elements[i]->update();
			else 
			{
				activeEnemies--;
				ArenaHeap::getPtr()->Enemies.Delete(elements[i]);	
				removeElement(elements[i]);
				continue;
			}

			if(elements[i]->reachEnd())
			{
				GamePlayMediator::getPtr()->takePlayerLife(1);
				activeEnemies--;
				ArenaHeap::getPtr()->Enemies.Delete(elements[i]);
				removeElement(elements[i]);
			}
		}
	}

	if(elements.size() == 0)
	{
		GamePlayMediator::getPtr()->getArena()->removeWave(this);
		ArenaHeap::getPtr()->Waves.Delete(this);
	}
}

void Wave::setSpawnRate(int rate)
{
	spawnRate = rate;
}

int Wave::getSpawnRate()
{
	return spawnRate;
}

void Wave::updateWave()
{
	if(startTimer == false)
	{
		timer.start();
		startTimer = true;
	}

	if(activeEnemies < elements.size())
	{
		if(timer.getMSec() >= spawnRate)
		{
			activeEnemies++;
			timer.start();
		}
	}
}

int Wave::getNumberOfActiveEnemies()
{
	return activeEnemies;
}

void Wave::init()
{
	activeEnemies = 0;
	startTimer = false;
	elements.clear();
}
