#pragma once
#include "Effect.h"
#include "Damage.h"
#include "Timer.h"

class DOTEffect : public Effect
{
	unsigned int duration;
	int period;
	Timer timer;
	unsigned int currentSec;

	Damage damage;

public:
	DOTEffect(void);

	virtual void update(EnemyBase * enemy);
	void setDuration(int d);
	void setPeriod(int p);
	void setDamage(double d);

};

