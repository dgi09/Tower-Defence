#pragma once
#include "ShopItem.h"
#include "Button.h"
#include "Player.h"
#include "Container.h"
#include "Label.h"
#include "StoneTowerInfoContainer.h"

class TowerCreationTool;
class StoneTower;

class StoneTowerShopItem : public ShopItem
{
	StoneTower * tower;
	StoneTowerInfoContainer ic;

public:
	StoneTowerShopItem(void);
	~StoneTowerShopItem(void);

	virtual void updateState(PlayerStat & stat);
	virtual void init();
	virtual void onDestroy();

	void setDamage(double damage);
	void setAmmoSpeed(int speed);
	void setRange(double range);
	void setShootRate(int ms);

	void postPropertySet();
protected:
	void onClick(Widget * sender);

	

};

