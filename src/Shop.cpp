#include "Shop.h"
#include "StoneTowerShopItem.h"
#include "GUISystem.h"



Shop::Shop(void)
{

}


Shop::~Shop(void)
{

}


void Shop::setPlayer(Player * player)
{
	pl = player;
	stat.gold = pl->getGold();

}

void Shop::observeeChange(int type)
{
	if(type == (int)GoldChange)
		updateShopItemsState();
}

void Shop::init()
{
	container = new Container();

	layoutX = 10;
	
	container->setPosition(0,0);
	container->setWidth(158);
	container->setHeight(50);
	container->setBGColor(0,0,0,255);

	font = TTF_OpenFont("aparaj.ttf",27);
	itemsFont = TTF_OpenFont("aparaj.ttf",20);

	lblShotText = GUISystem::getPtr()->createLabel();
	lblShotText->setColor(255,255,255);
	lblShotText->setFont(font);
	lblShotText->setText("Shop");
	lblShotText->setPosition(container->getWidth()/2 - lblShotText->getWidth()/2,0);
	

	layoutY = lblShotText->getHeight() + 10;
	container->addWidget(lblShotText);

}

void Shop::addShopItem(ShopItem * item)
{

	item->setFont(itemsFont);

	Widget * widget = item->getWidget();
	widget->setPosition(layoutX,layoutY);
	layoutY += widget->getHeight() + 5;

	container->setHeight(layoutY);

	addElement(item);
}

void Shop::removeShopItem(ShopItem * item)
{
	removeElement(item);
}

void Shop::deleteShopItem(ShopItem * item)
{
	deleteElement(item);
}
void Shop::onDestroy()
{
	TTF_CloseFont(font);
	TTF_CloseFont(itemsFont);
}

void Shop::updateShopItemsState()
{
	stat.gold = pl->getGold();

	for(it = subElements.begin();it != subElements.end();++it)
	{
		ShopItem * shopItem = (ShopItem*)(*it);
		shopItem->updateState(stat);
	}

}

void Shop::itemPreInit(ShopItem * item)
{
	item->setFont(itemsFont);
	item->setButtonSize(40,40);
}


