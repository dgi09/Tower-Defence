#include "MeteorAmmo.h"
#include "Splash.h"
#include "ArenaHeap.h"
#include "GamePlayMediator.h"
#include "Arena.h"
#include "TexturePool.h"


MeteorAmmo::MeteorAmmo(void)
{
}


MeteorAmmo::~MeteorAmmo(void)
{
}

void MeteorAmmo::onEnemyHit(EnemyBase * enemy)
{
	Splash * splash = ArenaHeap::getPtr()->Splashes.New();
	splash->init();
	splash->setDamageType(PHISICAL);
	splash->setDamageValue(damage.value);
	splash->setRange(splashRange);
	splash->setPosition(getX(),getY());

	GamePlayMediator::getPtr()->getArena()->addArenaObject(splash);
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void MeteorAmmo::init()
{
	texture = TexturePool::getPtr()->getTexture("Data/Ammos/meteor.png",area.w,area.h);
}

void MeteorAmmo::removeFromHeap()
{
	ArenaHeap::getPtr()->MeteorAmmos.Delete(this);
}

void MeteorAmmo::onEnemyDieBeforeHit()
{
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void MeteorAmmo::setSplashRange(int range)
{
	splashRange = range;
}
