#pragma once
#include "ShopItem.h"
#include "Button.h"
#include "TowerCreationTool.h"
#include "FireTower.h"
#include "FireTowerInfoContainer.h"

class FireTowerShopItem :public ShopItem
{
	
	FireTower * tower;
	FireTowerInfoContainer ic;
public:
	FireTowerShopItem(void);
	~FireTowerShopItem(void);

	virtual void updateState(PlayerStat & stat);

	virtual void init();

	virtual void onDestroy();

	void setDamage(double damage);
	void setAmmoSpeed(int speed);
	void setRange(double range);
	void setShootRate(int ms);
	void setDOTDamage(double dotDamage);
	void setDOTDuration(int duration);
	void setDOTPeriod(int period);

	void postPropertySet();
protected:
	void onClick(Widget * sender);

	

};

