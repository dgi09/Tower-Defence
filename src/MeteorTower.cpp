#include "MeteorTower.h"
#include "TexturePool.h"
#include "ArenaHeap.h"
#include "MeteorAmmo.h"


MeteorTower::MeteorTower(void)
{
}


MeteorTower::~MeteorTower(void)
{
}

void MeteorTower::init()
{
	initCommon();
	this->ammoDamage.type = PHISICAL;
	texture = TexturePool::getPtr()->getTexture("Data/Towers/meteorTurret.png",area.w,area.h);
}

void MeteorTower::destroy()
{
	
}

TowerBase * MeteorTower::copy()
{
	MeteorTower * tower = ArenaHeap::getPtr()->MeteorTowers.New();

	tower->texture = this->texture;
	tower->setAmmoSpeed(getAmmoSpeed());
	tower->setDamageValue(getDamageValue());
	tower->setVisible(this->isVisible());
	tower->setHeight(this->getHeight());
	tower->setWidth(this->getWidth());
	tower->setShootRate(getShootRate());
	tower->setPosition(this->getX(),this->getY());
	tower->showRange(this->isRangeVisible());
	tower->setRangeValue(getRangeValue());
	tower->setSplashRange(getSplashRange());
	return tower;
}

void MeteorTower::removeFromHeap()
{
	ArenaHeap::getPtr()->MeteorTowers.Delete(this);
}

Ammo * MeteorTower::createAmmo()
{
	MeteorAmmo * ammo = ArenaHeap::getPtr()->MeteorAmmos.New();
	ammo->init();
	ammo->setDamageValue(getDamageValue());
	ammo->setSpeed(getAmmoSpeed());
	ammo->setSplashRange(splashRange);

	return ammo;
}

void MeteorTower::setSplashRange(int range)
{
	splashRange = range;
}

int MeteorTower::getSplashRange()
{
	return splashRange;
}
