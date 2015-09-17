#pragma once
#include "Effect.h"
#include "Timer.h"

class SlowEffect : public Effect
{
	unsigned int duration;
	bool set;
	unsigned int speedDecrese;
	Timer timer;
public:
	SlowEffect(void);
	~SlowEffect(void);

	virtual void update(EnemyBase * enemy);
	void setDuration(int duration);
	void setSpeedDecrease(unsigned int speedDecrease);
};

