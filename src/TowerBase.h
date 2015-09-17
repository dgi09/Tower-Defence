#pragma once
#include "Sprite.h"
#include "Damage.h"
#include <vector>
#include "Ammo.h"
#include "Range.h"
#include "IWaveInteractor.h"
#include "IClickable.h"
#include "IArenaHeapObject.h"
#include "Timer.h"
#include "IArenaObject.h"


class Wave;

class TowerBase : public Sprite , public IWaveInteractor , public IClickable , public IArenaHeapObject , public IArenaObject
{
	
	int shootRate;

	int ammoSpeed;
	Timer timer;
	bool timerStarterd;

public:

	TowerBase(void);
	virtual ~TowerBase(void);

	virtual void wavesInteract(Wave ** waves,int size);
	virtual void init();
	virtual void destroy();

	void setDamageValue(double dmgValue);
	double getDamageValue();
	void setRangeValue(double val);
	double getRangeValue();

	bool isRangeVisible();

	void setAmmoSpeed(int ammoSpeed);
	int getAmmoSpeed();
	virtual void draw(SDL_Renderer * renderer);

	void showRange(bool val);

	void shoot(EnemyBase * enemy);
	void setShootRate(int ms);
	int getShootRate();

	SDL_Rect getInteractionArea();

	virtual void onClick();
	virtual void onOutOfFocus();
	virtual TowerBase * copy() = 0;

	virtual void removeFromHeap() = 0;
protected:

	virtual Ammo * createAmmo() = 0;
	virtual void onAreaChange();

	void initCommon();

	virtual void onArenaAdd(ArenaInternalMenager * mgr);

	virtual void onArenaRemove(ArenaInternalMenager * mgr);

	Damage ammoDamage;
	Range range;
};

