#include "Splash.h"
#include "ArenaInternalMenager.h"
#include "ArenaHeap.h"
#include "Wave.h"
#include "GamePlayMediator.h"
#include <cmath>
#include "EnemyBase.h"
#include "ArenaHeap.h"

void Splash::removeFromHeap()
{
	ArenaHeap::getPtr()->Splashes.Delete(this);
}

void Splash::onArenaAdd(ArenaInternalMenager * mgr)
{
	mgr->addWaveInteractor(this);
}

void Splash::onArenaRemove(ArenaInternalMenager * mgr)
{
	mgr->removeWaveInteractor(this);
	removeFromHeap();
}

void Splash::setDamageType(DamageType type)
{
	damage.type = type;
}

void Splash::setDamageValue(double value)
{
	damage.value = value;
}

void Splash::setPosition(int x,int y)
{
	this->x = x;
	this->y = y;
}

void Splash::setRange(int range)
{
	this->range = range;
}

void Splash::wavesInteract(Wave ** waves,int size)
{

	for(int iWave = 0;iWave < size;iWave++)
	{
		Wave * wave = waves[iWave];

		if(wave->size() > 0)
		{
			if(wave->getNumberOfActiveEnemies() > 0)
			{
				for(int i = 0;i < wave->getNumberOfActiveEnemies();i++)
				{
					EnemyBase * enemy = wave->getElementByIndex(i);

					if(enemy->alive() && enemy->reachEnd() == false)
					{
						double dist = std::sqrt(std::pow(enemy->getCenterX() - x,2) + std::pow(enemy->getCenterY() - y,2));
						if(dist <= range)
						{
							enemy->takeDamage(damage);
						}
					}

				}
			}
		}
	}
	
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void Splash::init()
{
	
}

int Splash::getRange()
{
	return range;
}

Splash * Splash::copy()
{
	Splash * splash = ArenaHeap::getPtr()->Splashes.New();
	splash->damage = damage;
	splash->range = range;
	splash->setPosition(x,y);

	return splash;
}

double Splash::getDamageValue()
{
	return damage.value;
}
