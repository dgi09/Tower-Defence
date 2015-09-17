#pragma once
#include "IWaveInteractor.h"
#include "IArenaHeapObject.h"
#include "IArenaObject.h"
#include "Damage.h"

class Splash : public IWaveInteractor , public IArenaHeapObject, public IArenaObject
{
	Damage damage;
	int x,y;
	int range;

public:

	void init();
	void setDamageType(DamageType type);
	void setDamageValue(double value);
	double getDamageValue();

	void setPosition(int x,int y);
	void setRange(int range);
	int getRange();

	void wavesInteract(Wave ** waves,int size);

	virtual void removeFromHeap();

	virtual void onArenaAdd(ArenaInternalMenager * mgr);

	virtual void onArenaRemove(ArenaInternalMenager * mgr);

	Splash * copy();

};

