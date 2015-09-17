#include "ColdAmmo.h"
#include "EnemyBase.h"
#include "TexturePool.h"
#include "GamePlayMediator.h"
#include "Arena.h"
#include "Damage.h"
#include "SlowEffect.h"
#include "ArenaHeap.h"


ColdAmmo::ColdAmmo(void)
{
}


ColdAmmo::~ColdAmmo(void)
{
}

void ColdAmmo::onEnemyHit(EnemyBase * enemy)
{
	enemy->takeDamage(damage);
	SlowEffect * effect = new SlowEffect;
	effect->setDuration(duration);
	effect->setSpeedDecrease(decrease);
	enemy->addEffect(effect);
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void ColdAmmo::init()
{
	damage.type = COLD;
	texture = TexturePool::getPtr()->getTexture("Data/Ammos/cold.png",area.w,area.h);
}

void ColdAmmo::onEnemyDieBeforeHit()
{
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void ColdAmmo::setSlowDuration(unsigned int duration)
{
	this->duration = duration;
}

void ColdAmmo::setSpeedDecrease(unsigned int decrease)
{
	this->decrease = decrease;
}

void ColdAmmo::removeFromHeap()
{
	ArenaHeap::getPtr()->ColdAmmos.Delete(this);
}
