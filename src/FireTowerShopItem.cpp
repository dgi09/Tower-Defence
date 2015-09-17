#include "FireTowerShopItem.h"
#include "Player.h"
#include "GUISystem.h"
#include "ToolManager.h"
#include "ArenaHeap.h"


FireTowerShopItem::FireTowerShopItem(void)
{
}


FireTowerShopItem::~FireTowerShopItem(void)
{
}

void FireTowerShopItem::updateState(PlayerStat & stat)
{
	if(stat.gold < itemCost)
	{
		button->loadImageFromFile("Data/ShopImages/fireTurretUnavailable.png");
		state = UNACTIVE;
	}
	else 
	{
		button->loadImageFromFile("Data/ShopImages/fireTurret.png");
		state = ACTIVE;
	}

	button->setWidth(buttonW);
	button->setHeight(buttonH);
}

void FireTowerShopItem::init()
{
	initGUI("Fire Tower","Data/ShopImages/fireTurret.png");

	button->subsribeEvent(PRESS,new MemberSubsciber<FireTowerShopItem>(&FireTowerShopItem::onClick,this));

	tower = ArenaHeap::getPtr()->FireTowers.New();

	tower->init();

}


void FireTowerShopItem::onDestroy()
{
	destroyGUI();


	tower->destroy();
	ArenaHeap::getPtr()->FireTowers.Delete(tower);

}

void FireTowerShopItem::onClick(Widget * sender)
{
	if(state == ACTIVE)
	{
		TowerCreationTool * tool = new TowerCreationTool();
		tool->setTower(tower);
		tool->setTowerCost(itemCost);
		ToolManager::getPtr()->setActiveTool(tool);
	}
}

void FireTowerShopItem::setDamage(double damage)
{
	tower->setDamageValue(damage);
}

void FireTowerShopItem::setAmmoSpeed(int speed)
{
	tower->setAmmoSpeed(speed);
}

void FireTowerShopItem::setRange(double range)
{
	tower->setRangeValue(range);
}

void FireTowerShopItem::setShootRate(int ms)
{
	tower->setShootRate(ms);
}

void FireTowerShopItem::setDOTDamage(double dotDamage)
{
	tower->setDOTDamage(dotDamage);
}

void FireTowerShopItem::setDOTDuration(int duration)
{
	tower->setDOTDuration(duration);
}

void FireTowerShopItem::setDOTPeriod(int period)
{
	tower->setDOTPeriod(period);
}

void FireTowerShopItem::postPropertySet()
{
	ic.init(itemCost,tower);
	ic.attach(info);
}
