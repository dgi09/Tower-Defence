#pragma once
#include "ShopItem.h"
#include "Button.h"
#include "Splash.h"
#include "Player.h"
#include "BombInfoContainer.h"

class BombShopItem : public ShopItem
{
	
	Splash * splash;
	BombInfoContainer ic;
public:
	BombShopItem(void);
	~BombShopItem(void);

	virtual void updateState(PlayerStat & stat);

	virtual void init();

	virtual void onDestroy();

	void setDamage(double damage);
	void setRange(int range);
	void postPropertySet();
protected:
	void onClick(Widget * sender);

	

};

