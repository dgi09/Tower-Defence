#pragma once
#include "TowerBase.h"
class StoneTower : public TowerBase
{

public:
	StoneTower(void);
	~StoneTower(void);

	void init();
	void destroy();

	virtual TowerBase * copy();
	virtual void removeFromHeap();

protected:
	Ammo * createAmmo();

	

};

