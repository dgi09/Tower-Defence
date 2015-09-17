#pragma once
#include "ShopItem.h"
#include "Button.h"
#include "MeteorTower.h"
#include "MeteorTowerInfoContainer.h"

class MeteorTowerShopItem : public ShopItem
{
	MeteorTower * tower;

	MeteorTowerInfoContainer ic;
public:
	MeteorTowerShopItem(void);
	~MeteorTowerShopItem(void);


	virtual void updateState(PlayerStat & stat);

	virtual void init();

	virtual void onDestroy();

	void setSplashDamage(double damage);
	void setAmmoSpeed(int speed);
	void setTowerRange(double range);
	void setShootRate(int ms);
	void setSplashRange(int range);

	void postPropertySet();
protected:
	void onClick(Widget * sender);

	

};

