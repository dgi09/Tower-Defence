#include "BombShopItem.h"
#include "GUISystem.h"
#include "ArenaHeap.h"
#include <functional>
#include "ToolManager.h"
#include "SplashCreationTool.h"


void BombShopItem::updateState(PlayerStat & stat)
{
	if(stat.gold < itemCost)
	{
		state = UNACTIVE;
		button->loadImageFromFile("Data/ShopImages/bombItemUnavailable.png");
	}
	else 
	{
		state = ACTIVE;
		button->loadImageFromFile("Data/ShopImages/bombItem.png");
	}

	button->setWidth(buttonW);
	button->setHeight(buttonH);
}

void BombShopItem::init()
{
	initGUI("Bomb","Data/ShopImages/bombItem.png");

	button->subsribeEvent(PRESS,new MemberSubsciber<BombShopItem>(&BombShopItem::onClick,this));

	splash = ArenaHeap::getPtr()->Splashes.New();
	splash->init();
	splash->setDamageType(PHISICAL);

}

void BombShopItem::onDestroy()
{
	destroyGUI();	
	ArenaHeap::getPtr()->Splashes.Delete(splash);
}

void BombShopItem::onClick(Widget * sender)
{
	if(state == ACTIVE)
	{
		SplashCreationTool * tool = new SplashCreationTool();
		tool->setSplash(splash->copy());
		tool->setBombCost(itemCost);
		ToolManager::getPtr()->setActiveTool(tool);
	}
}

BombShopItem::BombShopItem(void)
{

}

BombShopItem::~BombShopItem(void)
{

}


void BombShopItem::setDamage(double damage)
{
	splash->setDamageValue(damage);
}

void BombShopItem::setRange(int range)
{
	splash->setRange(range);
}

void BombShopItem::postPropertySet()
{
	ic.init(itemCost,splash);
	ic.attach(info);
}
