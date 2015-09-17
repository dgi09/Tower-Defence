#include "MeteorTowerShopItem.h"
#include "Player.h"
#include "GUISystem.h"
#include <functional>
#include "ArenaHeap.h"
#include "TowerCreationTool.h"
#include "ToolManager.h"
#include "Container.h"
#include "Label.h"

MeteorTowerShopItem::MeteorTowerShopItem(void)
{

}


MeteorTowerShopItem::~MeteorTowerShopItem(void)
{

}


void MeteorTowerShopItem::updateState(PlayerStat & stat)
{
	if(stat.gold < itemCost)
	{
		state = UNACTIVE;
		button->loadImageFromFile("Data/ShopImages/meteorTurretUnavailable.png");
	}
	else 
	{
		state = ACTIVE;
		button->loadImageFromFile("Data/ShopImages/meteorTurret.png");
	}

	button->setWidth(buttonW);
	button->setHeight(buttonH);
}

void MeteorTowerShopItem::init()
{
	initGUI("Meteor Tower","Data/ShopImages/meteorTurret.png");
	button->subsribeEvent(PRESS,new MemberSubsciber<MeteorTowerShopItem>(&MeteorTowerShopItem::onClick,this));
	
	tower = ArenaHeap::getPtr()->MeteorTowers.New();

	tower->init();
}

void MeteorTowerShopItem::onDestroy()
{
	destroyGUI();

	tower->destroy();
	ArenaHeap::getPtr()->MeteorTowers.Delete(tower);
}


void MeteorTowerShopItem::onClick(Widget * sender)
{
	if(state == ACTIVE)
	{
		TowerCreationTool * tool = new TowerCreationTool();
		tool->setTower(tower);
		tool->setTowerCost(itemCost);

		ToolManager::getPtr()->setActiveTool(tool);
	}
}

void MeteorTowerShopItem::setSplashDamage(double damage)
{
	tower->setDamageValue(damage);
}

void MeteorTowerShopItem::setAmmoSpeed(int speed)
{
	tower->setAmmoSpeed(speed);
}

void MeteorTowerShopItem::setTowerRange(double range)
{
	tower->setRangeValue(range);
}

void MeteorTowerShopItem::setShootRate(int ms)
{
	tower->setShootRate(ms);
}

void MeteorTowerShopItem::setSplashRange(int range)
{
	tower->setSplashRange(range);
}

void MeteorTowerShopItem::postPropertySet()
{
	ic.init(itemCost,tower);
	ic.attach(info);
}
