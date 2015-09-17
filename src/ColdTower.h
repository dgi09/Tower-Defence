#pragma once
#include "TowerBase.h"

class ColdTower : public TowerBase
{
	unsigned int slowingDuration;
	unsigned int speedDecrease;


public:
	ColdTower(void);
	~ColdTower(void);

	virtual void init();

	virtual TowerBase * copy();

	virtual Ammo * createAmmo();

	virtual void destroy();

	void setSlowingDuration(unsigned int slowingDuration);
	void setSpeedDecrease(unsigned int decrease);

	unsigned int getSlowingDuration();
	unsigned int getSpeedDecrease();

	virtual void removeFromHeap();

};

