#include "SlowEffect.h"
#include "Damage.h"
#include "eEffect.h"
#include "EnemyBase.h"

SlowEffect::SlowEffect(void)
{
	iD = (unsigned int)SLOW;
	set = false;
}



void SlowEffect::update(EnemyBase * enemy)
{
	if(set == false)
	{
		unsigned int finalSpeed = enemy->getSpeed() - speedDecrese;
		enemy->setSpeed(finalSpeed);
		set = true;
		timer.start();
	}

	unsigned long mSec = timer.getMSec();

	if(mSec >= duration)
	{
		unsigned int finalSpeed = enemy->getSpeed() + speedDecrese;
		enemy->setSpeed(finalSpeed);
		enemy->removeEffect(this);
	}
}

void SlowEffect::setDuration(int duration)
{
	this->duration = duration;
}

void SlowEffect::setSpeedDecrease(unsigned int speedDecrease)
{
	this->speedDecrese = speedDecrease;
}
