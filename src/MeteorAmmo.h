#pragma once
#include "Ammo.h"


class MeteorAmmo : public Ammo
{
	int splashRange;
public:
	MeteorAmmo(void);
	~MeteorAmmo(void);

	virtual void onEnemyHit(EnemyBase * enemy);

	virtual void init();

	virtual void removeFromHeap();

	virtual void onEnemyDieBeforeHit();

	void setSplashRange(int range);
};

