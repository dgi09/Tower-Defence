#pragma once
#include "ShopItem.h"
#include "ColdTower.h"
#include "Button.h"
#include "Splash.h"
#include "ColdTowerInfoContainer.h"


class ColdTowerShopItem : public ShopItem
{
	
	ColdTower * tower;
	ColdTowerInfoContainer ic;
public:
	ColdTowerShopItem(void);
	~ColdTowerShopItem(void);


	virtual void updateState(PlayerStat & stat);

	virtual void init();

	virtual void onDestroy();

	void setDamage(double damage);
	void setAmmoSpeed(int speed);
	void setRange(double range);
	void setShootRate(int ms);
	void setSlowDuration(int ms);
	void setSpeedDecrease(int speedDecrease);
	void postPropertySet();
protected:
	void onClick(Widget * sender);

	

};

