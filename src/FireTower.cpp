#include "FireTower.h"
#include "TexturePool.h"
#include "FireAmmo.h"
#include "ArenaHeap.h"

FireTower::FireTower(void) : TowerBase()
{

}

FireTower::~FireTower(void)
{

}


void FireTower::init()
{
	initCommon();
	ammoDamage.type = FIRE;
	texture = TexturePool::getPtr()->getTexture("Data/Towers/fireTurret.png",area.w,area.h);
}

TowerBase * FireTower::copy()
{
	FireTower * tower =	ArenaHeap::getPtr()->FireTowers.New();

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
	tower->setDOTDamage(getDOTDamage());
	tower->setDOTDuration(getDOTDuration());
	tower->setDOTPeriod(getDOTPeriod());

	return tower;
}

Ammo * FireTower::createAmmo()
{
	FireAmmo * ammo = ArenaHeap::getPtr()->FireAmmos.New();
	ammo->init();
	ammo->setDamageValue(getDamageValue());
	ammo->setDOTDamage(dotDamage);
	ammo->setDOPPeriod(dotPeriod);
	ammo->setDOTDuration(dotDuration);

	ammo->setSpeed(getAmmoSpeed());

	return ammo;
}

void FireTower::destroy()
{
	
}

void FireTower::removeFromHeap()
{
	ArenaHeap::getPtr()->FireTowers.Delete(this);
}

void FireTower::setDOTDamage(double damage)
{
	dotDamage = damage;
}

double FireTower::getDOTDamage()
{
	return dotDamage;
}

void FireTower::setDOTDuration(int duration)
{
	dotDuration = duration;
}

int FireTower::getDOTDuration()
{
	return dotDuration;
}

void FireTower::setDOTPeriod(int period)
{
	dotPeriod = period;
}

int FireTower::getDOTPeriod()
{
	return dotPeriod;
}
