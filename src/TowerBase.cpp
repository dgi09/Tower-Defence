#include "TowerBase.h"
#include "Wave.h"
#include "EnemyBase.h"
#include "GamePlayMediator.h"
#include "TexturePool.h"

#include <iostream>
#include "ArenaInternalMenager.h"


TowerBase::TowerBase(void):Sprite()
{
	ammoDamage.value = 0;
}


TowerBase::~TowerBase(void)
{

}

void TowerBase::wavesInteract(Wave ** waves,int size)
{
	if(timerStarterd == false)
	{
		timer.start();
		timerStarterd = true;
	}

	EnemyBase * target = nullptr;
	double furthestEntityDistance = 0.0;

	for(int iWave = 0;iWave < size;iWave++)
	{
		Wave * wave = waves[iWave];

		if(wave->size() > 0)
		{
			if(timer.getMSec() >= shootRate)
			{
				if(wave->getNumberOfActiveEnemies() > 0)
				{
					for(int i = 0;i<wave->getNumberOfActiveEnemies();i++)
					{
						EnemyBase * enemy = wave->getElementByIndex(i);

						if(enemy->getDistanceFromCentral(this) <= range.getValue())
						{
							double dist = enemy->getCoveredDistance();
							if(dist > furthestEntityDistance)
							{
								furthestEntityDistance = dist;
								target = enemy;
							}
						}
					}

				}	
			}
		}
	}

	if(target != nullptr)
	{
		shoot(target);
		timer.start();
	}


}

void TowerBase::init()
{

}
void TowerBase::destroy()
{

}

void TowerBase::setDamageValue(double dmgValue)
{
	ammoDamage.value = dmgValue;
}

double TowerBase::getDamageValue()
{
	return ammoDamage.value;
}

void TowerBase::setRangeValue(double val)
{
	range.setValue(val);
	range.centerToPoint(getCenterX(),getCenterY());
}
double TowerBase::getRangeValue()
{
	return range.getValue();
}

void TowerBase::showRange(bool val)
{
	range.setVisible(val);
}

void TowerBase::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	{
		range.draw(renderer);
		SDL_RenderCopy(renderer,texture,NULL,&area);
	}
}

void TowerBase::shoot(EnemyBase * enemy)
{

	Ammo * ammo = createAmmo();

	ammo->setPosition(getCenterX(),getCenterY());
	ammo->init();
	ammo->setEnemyTarget(enemy);

	GamePlayMediator::getPtr()->getArena()->addArenaObject(ammo);


}

void TowerBase::onAreaChange()
{
	range.centerToPoint(getCenterX(),getCenterY());
}

void TowerBase::setShootRate(int ms)
{
	shootRate = ms;
}
int TowerBase::getShootRate()
{
	return shootRate;
}

SDL_Rect TowerBase::getInteractionArea()
{
	return area;
}

void TowerBase::onClick()
{
	if(range.isVisible())
		showRange(false);
	else 
		showRange(true);
}

void TowerBase::onOutOfFocus()
{
	if(range.isVisible())
		showRange(false);
}


void TowerBase::setAmmoSpeed(int ammoSpeed)
{
	this->ammoSpeed = ammoSpeed;
}
int TowerBase::getAmmoSpeed()
{
	return ammoSpeed;
}

bool TowerBase::isRangeVisible()
{
	return range.isVisible();
}

void TowerBase::initCommon()
{
	timerStarterd = false;
}

void TowerBase::onArenaAdd(ArenaInternalMenager * mgr)
{
	mgr->addDrawableObject(this);
	mgr->addWaveInteractor(this);
	mgr->addClickableObject(this);

	//int locX = getX() / TILEWIDTH;
	//int locY = getY()  / TILEWIDTH;
}

void TowerBase::onArenaRemove(ArenaInternalMenager * mgr)
{
	mgr->removeDrawableObject(this);
	mgr->removeWaveInteractor(this);
	mgr->removeClickableObject(this);

	removeFromHeap();
}


