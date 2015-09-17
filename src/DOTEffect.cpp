#include "DOTEffect.h"
#include "Effect.h"
#include "eEffect.h"
#include "EnemyBase.h"

DOTEffect::DOTEffect(void)
{
	iD = (unsigned int)DOT;
	damage.type = FIRE;
	timer.start();
	currentSec = 0;
}



void DOTEffect::update(EnemyBase * enemy)
{
	
	if(timer.getMSec() - currentSec >= period)
	{
		enemy->takeDamage(damage);
		currentSec = timer.getMSec();
	}

	if(timer.getMSec() >= duration)
	{
		enemy->removeEffect(this);
	}
}

void DOTEffect::setDuration(int d)
{
	duration = d;
}

void DOTEffect::setPeriod(int p)
{
	period = p;
}

void DOTEffect::setDamage(double d)
{
	damage.value = d;
}
