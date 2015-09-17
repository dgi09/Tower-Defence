#pragma once
#include "MenuContainer.h"
#include "Container.h"
#include "Player.h"
#include "IObserver.h"
#include "Label.h"
#include <SDL_ttf.h>

class Shop : public MenuContainer,public IObserver
{
	Player * pl;
	PlayerStat stat;

	int layoutX,layoutY;
	Label * lblShotText;
	TTF_Font * font;
	TTF_Font * itemsFont;


public:
	Shop(void);
	~Shop(void);

	void observeeChange(int type);

	void setPlayer(Player * player);
	void init();

	void addShopItem(ShopItem * item);
	void removeShopItem(ShopItem * item);
	void deleteShopItem(ShopItem * item);
	void onDestroy();


	void updateShopItemsState();
	void itemPreInit(ShopItem * item);
};

