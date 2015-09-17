#pragma once 

#include "MenuElement.h"
#include <SDL_ttf.h>
#include <string>
#include "Container.h"
#include "Label.h"
#include "Button.h"


struct PlayerStat;

enum ShopItemState 
{
	ACTIVE,
	UNACTIVE
};

class ShopItem : public MenuElement
{
protected:
	ShopItemState state;
	unsigned int itemCost;
	TTF_Font * font;
	Container * container;
	Button * button;
	Label * lblItemText;

	Container * info;

	int buttonW, buttonH;
public:

	virtual Widget * getWidget();
	virtual void updateState(PlayerStat & stat) = 0;
	virtual void init() = 0;
	virtual void onDestroy() = 0;
	virtual void postPropertySet() = 0;

	void setFont(TTF_Font * f);
	void setButtonSize(int width,int height);

	ShopItemState getState();
	void setState(ShopItemState state);

	void setItemCost(unsigned int cost);
	unsigned int getItemCost();

protected:
	void initGUI(std::string lblText,std::string buttonSkinFile);
	void destroyGUI();

	void onMouseIn(Widget * w);
	void onMouseOut(Widget * w);
};