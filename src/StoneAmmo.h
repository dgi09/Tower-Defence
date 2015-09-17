#pragma once
#include "Ammo.h"

class StoneAmmo : public Ammo
{
public:
	StoneAmmo(void);
	~StoneAmmo(void);

	void init();
	void onEnemyHit(EnemyBase * enemy);

	virtual void onEnemyDieBeforeHit();

	virtual void removeFromHeap();

};

