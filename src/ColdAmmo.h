#pragma once
#include "Ammo.h"

class ColdAmmo : public Ammo
{
	unsigned int duration;
	unsigned int decrease;

public:
	ColdAmmo(void);
	~ColdAmmo(void);

	virtual void onEnemyHit(EnemyBase * enemy);

	virtual void init();

	virtual void onEnemyDieBeforeHit();

	void setSlowDuration(unsigned int duration);
	void setSpeedDecrease(unsigned int decrease);

	virtual void removeFromHeap();

};

