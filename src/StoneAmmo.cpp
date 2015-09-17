#include "StoneAmmo.h"
#include "EnemyBase.h"
#include "TexturePool.h"
#include "GamePlayMediator.h"
#include "ArenaHeap.h"


StoneAmmo::StoneAmmo(void)
{
}


StoneAmmo::~StoneAmmo(void)
{

}

void StoneAmmo::init()
{
	texture = TexturePool::getPtr()->getTexture("Data/Ammos/stone.png",area.w,area.h);

}
void StoneAmmo::onEnemyHit(EnemyBase * enemy)
{
	enemy->takeDamage(damage);
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void StoneAmmo::onEnemyDieBeforeHit()
{
	GamePlayMediator::getPtr()->getArena()->removeArenaObject(this);
}

void StoneAmmo::removeFromHeap()
{
	ArenaHeap::getPtr()->StoneAmmos.Delete(this);
}
