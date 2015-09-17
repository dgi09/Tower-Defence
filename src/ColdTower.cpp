#include "ColdTower.h"
#include "TexturePool.h"
#include "ColdAmmo.h"
#include "ArenaHeap.h"

ColdTower::ColdTower(void) : TowerBase()
{
}


ColdTower::~ColdTower(void)
{

}

void ColdTower::init()
{
	initCommon();
	ammoDamage.type = COLD;
	texture = TexturePool::getPtr()->getTexture("Data/Towers/coldTurret.png",area.w,area.h);
}

TowerBase * ColdTower::copy()
{
	ColdTower * tower =	ArenaHeap::getPtr()->ColdTowers.New();

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
	tower->setSpeedDecrease(this->getSpeedDecrease());
	tower->setSlowingDuration(this->getSlowingDuration());

	return tower;
}

Ammo * ColdTower::createAmmo()
{
	ColdAmmo * ammo = ArenaHeap::getPtr()->ColdAmmos.New();

	ammo->init();
	ammo->setDamageValue(getDamageValue());
	ammo->setSlowDuration(slowingDuration);
	ammo->setSpeedDecrease(speedDecrease);
	ammo->setSpeed(getAmmoSpeed());

	return ammo;
}

void ColdTower::destroy()
{

}

void ColdTower::setSlowingDuration(unsigned int slowingDuration)
{
	this->slowingDuration = slowingDuration;
}

void ColdTower::setSpeedDecrease(unsigned int decrease)
{
	this->speedDecrease = decrease;
}

unsigned int ColdTower::getSlowingDuration()
{
	return slowingDuration;
}

unsigned int ColdTower::getSpeedDecrease()
{
	return speedDecrease;
}

void ColdTower::removeFromHeap()
{
	ArenaHeap::getPtr()->ColdTowers.Delete(this);
}
