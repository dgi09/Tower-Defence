#include "StoneTowerShopItem.h"
#include "GUISystem.h"
#include <iostream>
#include <functional>

#include "TowerCreationTool.h"
#include "ToolManager.h"
#include "StoneTower.h"
#include "GamePlayMediator.h"
#include "ArenaHeap.h"
#include "Container.h"


StoneTowerShopItem::StoneTowerShopItem(void) : ShopItem()
{

}

StoneTowerShopItem::~StoneTowerShopItem(void)
{

}




void StoneTowerShopItem::updateState(PlayerStat & stat)
{
	if(stat.gold < itemCost)
	{
		button->loadImageFromFile("Data/ShopImages/turretUnavailable.png");
		state = UNACTIVE;

	}
	else 
	{
		button->loadImageFromFile("Data/ShopImages/turret.png");
		state = ACTIVE;
	}

	button->setWidth(buttonW);
	button->setHeight(buttonH);
}

void StoneTowerShopItem::init()
{

	initGUI("Stone Tower","Data/ShopImages/turret.png");
	button->subsribeEvent(PRESS,new MemberSubsciber<StoneTowerShopItem>(&StoneTowerShopItem::onClick,this));
	

	tower = ArenaHeap::getPtr()->StoneTowers.New();
	tower->init();
}

void StoneTowerShopItem::onClick(Widget * sender)
{
	if(state == ACTIVE)
	{
		TowerCreationTool * tool = new TowerCreationTool();
		tool->setTower(tower->copy());
		tool->setTowerCost(itemCost);
		ToolManager::getPtr()->setActiveTool(tool);
	}
	
}

void StoneTowerShopItem::onDestroy()
{
	destroyGUI();

	tower->destroy();
	ArenaHeap::getPtr()->StoneTowers.Delete(tower);
}

void StoneTowerShopItem::setDamage(double damage)
{
	tower->setDamageValue(damage);
}

void StoneTowerShopItem::setAmmoSpeed(int speed)
{
	tower->setAmmoSpeed(speed);
}

void StoneTowerShopItem::setRange(double range)
{
	tower->setRangeValue(range);
}

void StoneTowerShopItem::setShootRate(int ms)
{
	tower->setShootRate(ms);
}

void StoneTowerShopItem::postPropertySet()
{
	ic.init(itemCost,tower);	
	ic.attach(info);
}
