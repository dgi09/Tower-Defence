#pragma once

#include "TowerBase.h"

class FireTower : public TowerBase
{
	double dotDamage;
	int dotDuration;
	int dotPeriod;

public:
	FireTower(void);
	~FireTower(void);

	virtual void init();

	virtual TowerBase * copy();

	virtual Ammo * createAmmo();

	virtual void destroy();

	virtual void removeFromHeap();

	void setDOTDamage(double damage);
	double getDOTDamage();

	void setDOTDuration(int duration);
	int getDOTDuration();

	void setDOTPeriod(int period);
	int getDOTPeriod();

};

