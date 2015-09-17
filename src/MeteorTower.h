#pragma once
#include "TowerBase.h"


class MeteorTower : public TowerBase
{
	int splashRange;

public:
	MeteorTower(void);
	~MeteorTower(void);

	virtual void init();

	virtual void destroy();

	virtual TowerBase * copy();

	virtual void removeFromHeap();

	virtual Ammo * createAmmo();

	void setSplashRange(int range);
	int getSplashRange();
};

