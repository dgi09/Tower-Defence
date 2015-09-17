#include "FireAmmo.h"
#include "TexturePool.h"
#include "EnemyBase.h"
#include "GamePlayMediator.h"
#include "DOTEffect.h"
#include "ArenaHeap.h"


FireAmmo::FireAmmo(void)
{
}


FireAmmo::~FireAmmo(void)
{
}

void FireAmmo::onEnemyHit(EnemyBase * enemy)
{
	enemy->takeDamage(damage);
	DOTEffect * dot = new DOTEffect;
	dot->setDamage(dotDamage);
	dot->setDuration(dotDuration);
	dot->setPeriod(dotPeriod);

	enemy->addEffect(dot);
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void FireAmmo::init()
{
	damage.type = FIRE;
	texture = TexturePool::getPtr()->getTexture("Data/Ammos/fire.png",area.w,area.h);
}



void FireAmmo::onEnemyDieBeforeHit()
{
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void FireAmmo::removeFromHeap()
{
	ArenaHeap::getPtr()->FireAmmos.Delete(this);
}

void FireAmmo::setDOTDuration(int duration)
{
	dotDuration = duration;
	
}

void FireAmmo::setDOPPeriod(int period)
{
	dotPeriod = period;
}

void FireAmmo::setDOTDamage(double damage)
{
	dotDamage = damage;
}
