#include "ColdTowerShopItem.h"
#include "GamePlayMediator.h"
#include "ArenaHeap.h"
#include <functional>
#include "GUISystem.h"
#include "TowerCreationTool.h"
#include "ToolManager.h"
#include "SplashCreationTool.h"


ColdTowerShopItem::ColdTowerShopItem(void)
{
}


ColdTowerShopItem::~ColdTowerShopItem(void)
{
}


void ColdTowerShopItem::updateState(PlayerStat & stat)
{
	if(stat.gold < itemCost)
	{
		button->loadImageFromFile("Data/ShopImages/coldTurretUnavailable.png");
		state = UNACTIVE;
	}
	else 
	{
		button->loadImageFromFile("Data/ShopImages/coldTurret.png");
		state = ACTIVE;
	}

	button->setWidth(buttonW);
	button->setHeight(buttonH);

}

void ColdTowerShopItem::init()
{

	initGUI("Cold Tower","Data/ShopImages/coldTurret.png");

	button->subsribeEvent(PRESS,new MemberSubsciber<ColdTowerShopItem>(&ColdTowerShopItem::onClick,this));

	tower = ArenaHeap::getPtr()->ColdTowers.New();

	tower->init();


}

void ColdTowerShopItem::onDestroy()
{
	destroyGUI();

	tower->destroy();
	tower->removeFromHeap();


}

void ColdTowerShopItem::onClick(Widget * sender)
{
	if(state == ACTIVE)
	{
		TowerCreationTool * tool = new TowerCreationTool();
		tool->setTower(tower->copy());
		tool->setTowerCost(itemCost);

		ToolManager::getPtr()->setActiveTool(tool);
	}
}

void ColdTowerShopItem::setDamage(double damage)
{
	tower->setDamageValue(damage);
}

void ColdTowerShopItem::setAmmoSpeed(int speed)
{
	tower->setAmmoSpeed(speed);
}

void ColdTowerShopItem::setRange(double range)
{
	tower->setRangeValue(range);
}

void ColdTowerShopItem::setShootRate(int ms)
{
	tower->setShootRate(ms);
}

void ColdTowerShopItem::setSlowDuration(int ms)
{
	tower->setSlowingDuration(ms);
}

void ColdTowerShopItem::setSpeedDecrease(int speedDecrease)
{
	tower->setSpeedDecrease(speedDecrease);
}

void ColdTowerShopItem::postPropertySet()
{
	ic.init(itemCost,tower);
	ic.attach(info);
}
