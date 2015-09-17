#pragma once
#include "Sprite.h"
#include "Damage.h"
#include "IUpdateable.h"
#include "IArenaHeapObject.h"
#include "IArenaObject.h"

class EnemyBase;

class Ammo : public Sprite , public IUpdateable , public IArenaHeapObject , public IArenaObject
{
protected:
	Damage damage;
private:
	EnemyBase * target;
	int speed;

public:
	Ammo(void);
	virtual ~Ammo(void);

	void setDamageValue(double dmgValue);
	double getDamageValue();

	virtual void onEnemyHit(EnemyBase * enemy);
	
	void setEnemyTarget(EnemyBase * target);
	EnemyBase * getEnemyTarget();
	virtual void update();

	int getSpeed();
	void setSpeed(int speed);

	virtual void init();

	virtual void removeFromHeap() = 0;

	virtual void onArenaAdd(ArenaInternalMenager * mgr);

	virtual void onArenaRemove(ArenaInternalMenager * mgr);

protected:
	virtual void onEnemyDieBeforeHit();



};

