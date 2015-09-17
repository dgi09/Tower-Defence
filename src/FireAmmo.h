#pragma once
#include "Ammo.h"

class FireAmmo : public Ammo
{
	double dotDamage;
	int dotDuration;
	int dotPeriod;

public:
	FireAmmo(void);
	~FireAmmo(void);

	virtual void onEnemyHit(EnemyBase * enemy);

	virtual void init();

	void setDOTDamage(double damage);
	void setDOTDuration(int duration);
	void setDOPPeriod(int period);

	virtual void onEnemyDieBeforeHit();

	virtual void removeFromHeap();

};

