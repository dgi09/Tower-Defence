#include "Ammo.h"
#include "EnemyBase.h"
#include "GamePlayMediator.h"
#include "TexturePool.h"
#include <math.h>


Ammo::Ammo(void):Sprite()
{

}


Ammo::~Ammo(void)
{
	texture = NULL;
	if(target != NULL)
		target = NULL;
}

void Ammo::setDamageValue(double dmgValue)
{
	damage.value = dmgValue;
}
double Ammo::getDamageValue()
{
	return damage.value;
}

void Ammo::onEnemyHit(EnemyBase * enemy)
{
	enemy->takeDamage(damage);

}

void Ammo::setEnemyTarget(EnemyBase * target)
{
	if(target != NULL)
	{
		this->target = target;
	}
}

EnemyBase * Ammo::getEnemyTarget()
{
	return target;
}


void Ammo::update()
{
	if(target != NULL && target->alive())
	{
		double dirX = target->getX() - getX();
		double dirY = target->getY() - getY();
		double lenght = sqrt(dirX * dirX + dirY * dirY);

		dirX/= lenght;
		dirY/= lenght;

		move(dirX * speed,dirY*speed);

		if(colide(target))
		{
			onEnemyHit(target);
		}

	}
	else if(target->alive() == false)
	{
		onEnemyDieBeforeHit();
	}

}

int Ammo::getSpeed()
{
	return speed;
}
void Ammo::setSpeed(int speed)
{
	this->speed = speed;
}

void Ammo::init()
{
	damage.type = PHISICAL;
	setSpeed(5);

	texture = TexturePool::getPtr()->getTexture("Data/bullet.png",area.w,area.h);
}

void Ammo::onEnemyDieBeforeHit()
{

}

void Ammo::onArenaAdd(ArenaInternalMenager * mgr)
{
	mgr->addDrawableObject(this);
	mgr->addUpdateableObject(this);
}

void Ammo::onArenaRemove(ArenaInternalMenager * mgr)
{
	mgr->removeDrawableObject(this);
	mgr->removeUpdateableObject(this);

	removeFromHeap();
}
