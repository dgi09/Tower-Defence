#include "ShopItem.h"
#include "GUISystem.h"
#include "GamePlayMediator.h"


ShopItemState ShopItem::getState()
{
	return state;
}

void ShopItem::setState(ShopItemState state)
{
	this->state = state;
}

void ShopItem::setItemCost(unsigned int cost)
{
	itemCost = cost;
}

unsigned int ShopItem::getItemCost()
{
	return itemCost;
}

void ShopItem::setFont(TTF_Font * f)
{
	font = f;
}

Widget * ShopItem::getWidget()
{
	return container;
}


void ShopItem::setButtonSize(int width,int height)
{
	buttonH = height;
	buttonW = width;

}

void ShopItem::initGUI(std::string lblText,std::string buttonSkinFile)
{
	button = GUISystem::getPtr()->createButton();
	button->loadImageFromFile(buttonSkinFile.c_str());
	button->setWidth(buttonW);
	button->setHeight(buttonH);
	button->subsribeEvent(MOUSE_IN,new MemberSubsciber<ShopItem>(&ShopItem::onMouseIn,this));
	button->subsribeEvent(MOUSE_OUT,new MemberSubsciber<ShopItem>(&ShopItem::onMouseOut,this));

	button->setPosition(0,0);

	lblItemText = GUISystem::getPtr()->createLabel();
	lblItemText->setColor(255,255,255);
	lblItemText->setFont(font);
	lblItemText->setText(lblText);
	lblItemText->setPosition(button->getWidth() + 5,button->getHeight()/2 - lblItemText->getHeight()/2);

	container = new Container();
	container->setBGColor(0,0,0,0);
	container->setWidth(lblItemText->getX() + lblItemText->getWidth());
	container->setHeight(button->getHeight());

	container->addWidget(button);
	container->addWidget(lblItemText);

	info = new Container();
	info->setWidth(GamePlayMediator::getPtr()->getInfoPanel()->getWidget()->getWidth());
	info->setHeight(GamePlayMediator::getPtr()->getInfoPanel()->getWidget()->getHeight());
	info->setPosition(0,0);
	info->setBGColor(0,0,0,0);
}

void ShopItem::destroyGUI()
{
	container->removeAllWidgets();
	GUISystem::getPtr()->deleteWidget(button);
	GUISystem::getPtr()->deleteWidget(lblItemText);
	if(container != nullptr)
		delete container;
}




void ShopItem::onMouseIn(Widget * w)
{
	GamePlayMediator::getPtr()->getInfoPanel()->removeActiveContainer();
	GamePlayMediator::getPtr()->getInfoPanel()->setActiveContainer(info);
}

void ShopItem::onMouseOut(Widget * w)
{
	GamePlayMediator::getPtr()->getInfoPanel()->removeActiveContainer();
}
