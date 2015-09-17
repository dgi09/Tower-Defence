#include "StoneTower.h"
#include "TexturePool.h"
#include "StoneAmmo.h"
#include "ArenaHeap.h"
#include "ArenaHeap.h"


StoneTower::StoneTower(void) : TowerBase()
{
}


StoneTower::~StoneTower(void)
{
}


void StoneTower::init()
{
	initCommon();
	ammoDamage.type =  PHISICAL;
	texture = TexturePool::getPtr()->getTexture("Data/Towers/turret.png",area.w,area.h);
	
}

void StoneTower::destroy()
{
	
}

Ammo * StoneTower::createAmmo()
{
	StoneAmmo * stone = ArenaHeap::getPtr()->StoneAmmos.New();
	stone->init();
	stone->setDamageValue(getDamageValue());
	stone->setSpeed(getAmmoSpeed());

	return stone;
	
}

TowerBase * StoneTower::copy()
{
	StoneTower * tower = ArenaHeap::getPtr()->StoneTowers.New();
	tower->texture = this->texture;
	tower->setAmmoSpeed(getAmmoSpeed());
	tower->setDamageValue(getDamageValue());
	tower->setVisible(this->isVisible());
	tower->setHeight(this->getHeight());
	tower->setWidth(this->getWidth());
	tower->setRangeValue(getRangeValue());
	tower->setShootRate(getShootRate());
	tower->setPosition(this->getX(),this->getY());
	tower->showRange(this->isRangeVisible());
	tower->range.setPosition(range.getX(),range.getY());

	return tower;
}

void StoneTower::removeFromHeap()
{
	ArenaHeap::getPtr()->StoneTowers.Delete(this);
}
